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
//ClassDB::add_property(NAMEOF(className), PropertyInfo(propertyType, NAMEOF(propertyName),propertyHint,), )

namespace godot {
	Vector2 operator%(Vector2 v, int m) {
		return Vector2(
			v.x - ((int)(v.x / m)) * m,
			v.y - ((int)(v.y / m)) * m
		);
	}
	class Obstacle :public StaticBody2D
	{
		GDCLASS(Obstacle, StaticBody2D)
	public:
		Obstacle();
		~Obstacle();
		virtual void _ready() override;
		//void set_position(const Vector2&);
		void set_pos() {
			Vector2 size(width * TILESIZE, height * TILESIZE);
			rect.ptr()->set_size(size);
			Vector2 rectmid = (size / 2) % 16;
			set_position(((get_position() / 16).floor()) * 16 + rectmid);
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
			Vector2i pos((get_position() / 16));
			if (BLACKMAGICENABLER && map != nullptr) {
				int offx = 0;
				int offy = 0;
				if (get_position().x <0 && (width%2==1||pos.x==0))offx=-1;
				if (  get_position().y < 0 && (height % 2 == 1|| pos.y == 0))offy=-1;
				for (int h = -height / 2; h < Math::ceil((float)height / 2) ; h++)
					for (int w = -width / 2; w < Math::ceil((float)width / 2) ; w++) {
						map->set_cell(0, Vector2i(pos.x + w+ offx, pos.y + h + offy), 33, Vector2i(14, 6));
					}
			}
		}
		void RestoreGround() {

		}
		Vector2 oldPosition = Vector2(0, 0);


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
	/*void Obstacle::set_position(const Vector2& v){
		PRINT("does it work like this?");
		return __super::set_position(v);
	}*/
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
