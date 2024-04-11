#ifndef RTS_TILECOLLISIONSHAPE2D
#define RTS_TILECOLLISIONSHAPE2D

#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/rectangle_shape2d.hpp>
#include<godot_cpp/classes/tile_map.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "UtilityMacros.hpp"
#include "ExtensionMethods.hpp"
#include <godot_cpp/classes/world2d.hpp>
#include<godot_cpp/classes/physics_direct_space_state2d.hpp>
#include<godot_cpp/classes/physics_shape_query_parameters2d.hpp>
#include<godot_cpp/variant/variant.hpp>
#include<godot_cpp/classes/scene_tree.hpp>
#include<godot_cpp/classes/character_body2d.hpp>

namespace godot {

	/// <summary>
	/// Collider used for CharacterBodies placed on Tilemaps
	/// Snaps to the Tilemap grid (in editor and in game)
	/// Looks for default TileMap named "Ground" under scene root
	/// </summary>
	class TileCollisionShape2D :public CollisionShape2D
	{
		GDCLASS(TileCollisionShape2D, CollisionShape2D)
	public:
		TileCollisionShape2D();
		~TileCollisionShape2D();
		void set_size(const Vector2& size);
		Vector2 get_size() const;
		TileMap* get_map() const { return map; }
		void set_map(TileMap*);
		void set_map_from_path(const NodePath& n);
		void updateParentPosition();
		void TaintGround();
		void RestoreGround() const;
		virtual void _ready()override;
		virtual void _process(const double delta) override;
		bool isTileMap(const Dictionary& x)const;
		/// <summary>
		/// Gets list of collisions at the target location with the area of rect exludes self
		/// </summary>
		/// <param name="place"> centerpoint of the checked area</param>
		/// <returns>intersected shapes</returns>
		TypedArray<Dictionary> get_collisions_at(Vector2 place) const {
			Ref<PhysicsShapeQueryParameters2D> query;
			query.instantiate();
			query->set_shape(rect);
			query->set_transform(Transform2D(0, place));
			TypedArray<Dictionary> x = get_world_2d()->get_direct_space_state()->intersect_shape(query, 50);
			for (int64_t i = 0;i<x.size();i++)
			{
				//PRINT("INFOSTART");
				//Variant z = x[i].get("collider_id");
				//PRINT(rect->get_instance_id());
				//PRINT(get_instance_id());
				//PRINT(get_parent()->get_instance_id());
				//PRINT((uint64_t)z == get_parent()->get_instance_id());
				//PRINT("__________");
				if ((uint64_t)(x[i].get("collider_id")) == get_parent()->get_instance_id()) { x.remove_at(i);  break; }
			}
			return x;

		}
		/// <summary>
		/// gets parent node position if possible
		/// </summary>
		/// <returns>position of the parent node, Vector.ZERO if unable</returns>
		Vector2 get_parent_position() const {
			if (get_parent() != nullptr && get_parent()->is_class(NAMEOF(Node2D))) {
				return ((Node2D*)get_parent())->get_position();
			}
			return Vector2(0, 0);
		}
		Vector2 get_parent_position_grided() {
			Vector2 size = rect->get_size();
			Vector2 rectmid = (size / 2) % 16;
			return ((get_parent_position() / 16).floor()) * 16 + rectmid;
		}
		void try_set_map() {
			if (get_map() != nullptr)return;
			Node* node = nullptr;

			if (Engine::get_singleton()->is_editor_hint()) {
				/*PRINT("We's bein' in le editour");
				PRINT(is_node_ready());
				PRINT(get_tree()->get_edited_scene_root()->get_class());
				PRINT(get_tree()->get_edited_scene_root()->is_class(NAMEOF(CharacterBody2D)));*/
				if (!get_tree()->get_edited_scene_root()->is_class(NAMEOF(CharacterBody2D))) {
					//PRINT("looking for map");
					//PRINT(get_tree()->get_edited_scene_root()->get_name());
					//PRINT(get_tree_string());
					node = get_tree()->get_edited_scene_root()->get_node_or_null("Ground");
					if (node == nullptr)node = get_tree()->get_edited_scene_root()->get_node_or_null("Map/Ground");
					//PRINT(node != nullptr);
				}
			}
			else {
				PRINT(get_tree()->get_current_scene()->get_name());
				node = get_tree()->get_current_scene()->get_node_or_null("Ground");
				if (node == nullptr)node = get_tree()->get_current_scene()->get_node_or_null("Map/Ground");
				//PRINT(node->get_name());
			}
			if (node != nullptr && node->is_class(NAMEOF(TileMap))) {
				set_map((TileMap*)node);
				PRINT("Map found");
			}
		}

	protected:
		static void _bind_methods();
		Ref<RectangleShape2D> rect;
		TileMap* map = nullptr;
		Vector2i size = Vector2i(0, 0);
		CellMatrix cm;
		Vector2 oldPosition = Vector2(0, 0);
		bool replacing = false;
		int TILESIZE = 16;
		bool ready = false;
		bool valid = false;
		//NodePath mappath;
	private:/*
		/// <summary>Assumes square tiles</summary>
		/// <returns>size of map's tiles or 0 if map is null</returns>
		int get_tile_size() const {
			if (map != nullptr)
				return map->get_tileset()->get_tile_size().x;
			else return 0;
		}*/
	};
	void TileCollisionShape2D::_bind_methods()
	{
		PROPERTYADD(PropertyInfo(Variant::VECTOR2, "TileSize", PROPERTY_HINT_NONE, "Size in px rounded to tiles"), get_size, set_size);
		PROPERTYADD(PropertyInfo(Variant::NODE_PATH, NAMEOF(map), PROPERTY_HINT_NODE_TYPE, "Map onto which we put obstacle"), get_map, set_map_from_path);
	}
	inline TileCollisionShape2D::TileCollisionShape2D()
	{
		PRINT("Constructor");
		rect.instantiate();
	}
	inline TileCollisionShape2D::~TileCollisionShape2D()
	{
		if (cm.atlascoords.size() != 0)RestoreGround();
	}
	void TileCollisionShape2D::updateParentPosition() {
		Node2D* parent = (Node2D*)get_parent();
		Vector2 new_position = get_parent_position_grided();
		if (get_collisions_at(new_position).size() == 0) {
			valid = true;
			parent->set_position(new_position);

			if (cm.atlascoords.size() != 0)RestoreGround();
			TaintGround();
		}
		else parent->set_position(oldPosition);
	}

	inline void TileCollisionShape2D::set_size(const Vector2& size)
	{
		//PRINT("SETING SIZE");
		this->size = size;
		rect->set_size(size * TILESIZE);
		//PRINT("RECT SIZE SET");
		if (ready)
			updateParentPosition();
		//PRINT("SIZE SET");

	}
	inline Vector2 TileCollisionShape2D::get_size() const
	{
		//PRINT("GETING SIZE");
		return size;
	}
	inline void TileCollisionShape2D::set_map(TileMap* tm)
	{
		//PRINT("SETING MAP");
		map = tm;
		updateParentPosition();
	}
	inline void TileCollisionShape2D::set_map_from_path(const NodePath& n)
	{
		//PRINT("SETING MAPfp");
		//mappath = n;
		Node* ptr = get_node_or_null(n);
		if (ptr != nullptr && ptr->is_class(NAMEOF(TileMap))) {
			set_map((TileMap*)ptr);
		}
		else {
			map = nullptr;
		}
	}
	inline void TileCollisionShape2D::TaintGround() {
		PRINT(map);
		if (replacing && map != nullptr) {
			PRINT("TAINTING");
			Vector2i pos((get_parent_position() / 16));
			int offx = 0;
			int offy = 0;
			if (get_parent_position().x < 0 && (size.x % 2 == 1 || pos.x == 0))offx = -1;
			if (get_parent_position().y < 0 && (size.y % 2 == 1 || pos.y == 0))offy = -1;
			cm = CellMatrix(pos + Vector2i(offx, offy), size);
			for (int h = 0; h < size.y; h++)
				for (int w = 0; w < size.x; w++) {
					Vector2i coords(pos.x + w + offx - size.x / 2, pos.y + h + offy - size.y / 2);
					cm.atlascoords[h][w] = map->get_cell_atlas_coords(0, coords);
					map->set_cell(0, coords, 33, Vector2i(14, 6));
				}
		}
	}
	inline void TileCollisionShape2D::RestoreGround() const {
		for (int h = 0; h < cm.height; h++)
			for (int w = 0; w < cm.width; w++) {
				map->set_cell(0, cm.coords + Vector2i(w - cm.width / 2, h - cm.height / 2), 33, cm.atlascoords[h][w]);
			}
	}

	inline bool godot::TileCollisionShape2D::isTileMap(const Dictionary& x) const
	{
		return ((Object*)x["collider"])->is_class(NAMEOF(TileMap));
	}

	inline void TileCollisionShape2D::_ready()
	{
		PRINT("Ready");
		ready = true;
		set_shape(rect);
		
		
		if (!Engine::get_singleton()->is_editor_hint()) {
			oldPosition = get_parent_position_grided();
			set_size(size);
			replacing = true;
			try_set_map();
			if (cm.atlascoords.size() == 0)TaintGround();
		}
		else {
			set_size(size);
		}
	}
	inline void TileCollisionShape2D::_process(const double delta) {

		try_set_map();

		if (get_parent()->is_class(NAMEOF(Node2D))) {
			Node2D* parent = (Node2D*)get_parent();
			if (oldPosition != parent->get_position() && map != nullptr) {
				updateParentPosition();
				oldPosition = parent->get_position();
			}
		}
	}
}
#endif //RTS_TILESCOLLISIONSHAPE2D