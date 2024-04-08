#include "test.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <iostream>
#include "UtilityMacros.hpp"

using namespace godot;

void GDExample::_bind_methods() {
	ClassDB::bind_method(D_METHOD(NAMEOF(get_exportproperty)), &GDExample::get_exportproperty);
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
void godot::GDExample::SumoonMadness() const
{
	std::cout << "Hello World";
}
void godot::GDExample::set_exportproperty(const double val)
{
	exportproperty = val;
}
double godot::GDExample::get_exportproperty() const
{
	return exportproperty;
}
void GDExample::_process(double delta) {
	time_passed += delta;

	Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

	set_position(new_position);
}

void godot::GDEditorTest::_notification(int what)
{
}

void godot::GDEditorTest::_bind_methods()
{
	ClassDB::bind_method(D_METHOD(NAMEOF(SummonMadnessAGAIN)), &GDEditorTest::SummonMadnessAGAIN);
}

void godot::GDEditorTest::SummonMadnessAGAIN()
{
	std::cout << "MADNESS WILL CONSUME YOU!";
}

void godot::GDEditorTest::_edit(Object* p_object)
{
}

bool godot::GDEditorTest::_handles(Object* p_object) const
{
	return false;
}

void godot::GDEditorTest::_make_visible(bool p_visible)
{
}

void godot::GDEditorTest::_enter_tree()
{
	//__super::_enter_tree(); It seems enter_tree truly does nothign (haven't found any implementation other than mine anywhere)
}

void godot::GDEditorScriptTest::_bind_methods()
{
	ClassDB::bind_method(D_METHOD(NAMEOF(SummoningMadnessForAllEternity)), &GDEditorScriptTest::SummoningMadnessForAllEternity);
}
