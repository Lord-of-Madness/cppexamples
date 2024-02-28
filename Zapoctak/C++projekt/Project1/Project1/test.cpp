#include "test.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <iostream>

using namespace godot;

void GDExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD(NAMEOF(get_exportproperty)), &GDExample::get_exportporperty);
	ClassDB::bind_method(D_METHOD(NAMEOF(set_exportproperty), "value"), &GDExample::set_exportproperty);
	ClassDB::add_property("GDExample", PropertyInfo(Variant::FLOAT, "ExportProperty"), NAMEOF(set_exportproperty), NAMEOF(get_exportproperty));
	ClassDB::bind_method(D_METHOD(NAMEOF(SummonMadness)), &GDExample::SumoonMadness);
}

GDExample::GDExample() {
	// Initialize any variables here.
	time_passed = 0.0;
	exportproperty = 0;
}

GDExample::~GDExample() {
	// Add your cleanup here.
}
void godot::GDExample::SumoonMadness()
{
	std::cout << "Hello World";
}
void godot::GDExample::set_exportproperty(const double val)
{
	exportproperty = val;
}
double godot::GDExample::get_exportporperty()
{
	return exportproperty;
}
void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

	set_position(new_position);
}
