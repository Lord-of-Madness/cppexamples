#ifndef RTSObstacle
#define RTSObstacle
#include <godot_cpp/classes/static_body2d.hpp>
#include <godot_cpp/classes/collision_shape2d.hpp>
#include <godot_cpp/classes/rectangle_shape2d.hpp>
#include<godot_cpp/classes/tile_map.hpp>
#include<godot_cpp/variant/utility_functions.hpp>
#include<godot_cpp/classes/engine.hpp>
#include<godot_cpp/core/math.hpp>
#define NAMEOF(name) #name

#define METHODADD(funcName)\
ClassDB::bind_method(D_METHOD(NAMEOF(funcName)),&funcName)

#define PRINT(what)UtilityFunctions::print(what)

#define PROPERTYADD(propertyInfo,getFunc,setFunc) \
METHODADD(getFunc);\
METHODADD(setFunc);\
ADD_PROPERTY(propertyInfo,NAMEOF(setFunc), NAMEOF(getFunc))

namespace godot {
	Vector2 operator%(Vector2 v, int m) {
		return Vector2(
			v.x - ((int)(v.x / m)) * m,
			v.y - ((int)(v.y / m)) * m
		);
	}
	class CellMatrix {
	public:
		std::vector<std::vector<Vector2i>> atlascoords;
		Vector2i coords;
		int height;
		int width;
		CellMatrix(Vector2i root, int height, int width) {
			coords = root;
			this->height = height;
			this->width = width;
			atlascoords.reserve(height);
			for (int i = 0; i < height; i++) {
				atlascoords.push_back(std::vector<Vector2i>(width));
				for (int j = 0; j < width; j++)
					atlascoords[i].push_back(Vector2i());
			}
		}
		CellMatrix() {
			coords = Vector2i(0, 0);
			atlascoords = std::vector<std::vector<Vector2i>>();
		}
	};
	class Obstacle :public StaticBody2D
	{
		GDCLASS(Obstacle, StaticBody2D)
	public:
		Obstacle();
		~Obstacle();
		virtual void _ready() override;
		void set_pos() {
			Vector2 size(width * TILESIZE, height * TILESIZE);
			rect.ptr()->set_size(size);
			Vector2 rectmid = (size / 2) % 16;
			set_position(((get_position() / 16).floor()) * 16 + rectmid);
			if (cm.atlascoords.size() != 0)RestoreGround();
			TaintGround();
		}
		void set_height(const int h) {
			height = h;
			set_pos();
		}
		int get_height() const { return height; }
		void set_width(const int w) {
			width = w;
			set_pos();
		}
		int get_width() const { return width; }
		TileMap* get_map() { return map; }
		void set_mapx(TileMap* m) {
			map = m;
		}
		void set_map(const NodePath& n) {
			Node* ptr = get_node_or_null(n);
			if (ptr == nullptr) {
				map = nullptr;
			}
			else if (ptr->is_class(NAMEOF(TileMap))) {
				set_mapx((TileMap*)ptr);
			}
			else {
				map = nullptr;
			}
		}
		void TaintGround() {
			if (BLACKMAGICENABLER && map != nullptr) {
				Vector2i pos((get_position() / 16));
				int offx = 0;
				int offy = 0;
				if (get_position().x < 0 && (width % 2 == 1 || pos.x == 0))offx = -1;
				if (get_position().y < 0 && (height % 2 == 1 || pos.y == 0))offy = -1;
				cm = CellMatrix(pos+Vector2i(offx,offy), height, width);
				for (int h = 0; h < height; h++)
					for (int w = 0; w < width; w++) {
						Vector2i coords(pos.x + w + offx - width / 2, pos.y + h + offy - height / 2);
						cm.atlascoords[h][w] = map->get_cell_atlas_coords(0, coords);
						map->set_cell(0, coords, 33, Vector2i(14, 6));
					}
			}
		}
		void RestoreGround() {//CRASHES upon movement with sizes>1
			for (int h = 0; h < cm.height; h++)
				for (int w = 0; w < cm.width; w++) {
					map->set_cell(0, cm.coords+ Vector2i(w - cm.width / 2, h - cm.height / 2), 33, cm.atlascoords[h][w]);
				}
		}


		virtual void _process(double delta) override {
			if (oldPosition != get_position() && map != nullptr) {
				set_pos();
				oldPosition = get_position();
			}
		}
		bool BLACKMAGICENABLER = false;
		bool get_blackMagic()const { return BLACKMAGICENABLER; }
		void set_blackMagic(const bool b) {
			BLACKMAGICENABLER = b;
			if (b)TaintGround();
			else RestoreGround();
		}
	protected:
		static void _bind_methods();
	private:
		CellMatrix cm;
		Vector2 oldPosition = Vector2(0, 0);
		const unsigned int TILESIZE = 16;//could make it lookup the map tilesize
		int height = 1;
		int width = 1;
		CollisionShape2D collider;
		TileMap* map;
		Ref<RectangleShape2D> rect;

	};

	Obstacle::Obstacle()
	{
		rect.instantiate();
		collider.set_shape(rect);
	}
	Obstacle::~Obstacle()
	{
	}
	void Obstacle::_ready() {
		add_child(&collider);
		set_pos();
		set_map(get_parent()->get_path());
		if (!Engine::get_singleton()->is_editor_hint()) {
			set_blackMagic(true);
		}
	}
	inline void godot::Obstacle::_bind_methods()
	{
		PROPERTYADD(PropertyInfo(Variant::INT, NAMEOF(height), PROPERTY_HINT_RANGE, "0,999,1"), get_height, set_height);

		PROPERTYADD(PropertyInfo(Variant::INT, NAMEOF(width), PROPERTY_HINT_RANGE, "0,999,1"), get_width, set_width);
		PROPERTYADD(PropertyInfo(Variant::BOOL, NAMEOF(BLACKMAGICENABLER)), get_blackMagic, set_blackMagic);
		PROPERTYADD(PropertyInfo(Variant::NODE_PATH, NAMEOF(map), PROPERTY_HINT_NODE_TYPE, "Map onto which we put obstacle"), get_map, set_map);
	}
}
#endif // !RTSObstacle
