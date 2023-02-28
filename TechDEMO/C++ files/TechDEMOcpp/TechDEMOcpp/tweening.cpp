#include "tweening.h"

using namespace godot;

enum EaseType { linear, EASE_IN_QUAD, EASE_OUT_QUAD, SmoothStepN, Bouncy, EASE_IN_OUT_QUAD, SmoothStep3, EASE_IN_SINE, EASE_OUT_SINE };

void tweening::_register_methods() {
	register_method((char*)"_process", &tweening::_process);
}

void tweening::_init() {}

tweening::tweening() {}

tweening::~tweening() {}

void tweening::_process(float delta)
{
	_input();
	tweens._process(delta);
}

void tweening::_input()
{

	Input* i = Input::get_singleton();

	if (i->is_action_just_pressed("Button1"))
		button1();
	if (i->is_action_just_pressed("Button2"))
		button2();
	if (i->is_action_just_pressed("Button3"))
		button3();
	if (i->is_action_just_pressed("Button4"))
		button4();
	if (i->is_action_just_pressed("Restart"))
		restart();
}
void tweening::button1() {
	//Showcase on $Ship1 using SmoothStepN on alpha
	// We can change the color(and alpha) through the modulate property
	tweens.tween(*Object::cast_to<Sprite>(get_node("Ship1")), "modulate", Color(1, 1, 1, 1), Color(1, 1, 1, 0), 5, EASE_IN_SINE);
	Godot::print("Button 1 pressed.");
}
void tweening::button2() {
	// Showcase on $Ship2 using funky bezier on alpha, rotation and position
	Sprite* ship = Object::cast_to<Sprite>(get_node("Ship2"));
	tweens.tween(*ship, "modulate", Color(1, 1, 1, 0), Color(1, 1, 1, 1), 5, EASE_OUT_QUAD);
	tweens.tween(*ship, "rotation", 0, 1440, 5, EASE_IN_OUT_QUAD);
	tweens.tween(*ship, "position", ship->get_position(), ship->get_position() + Vector2(-50, 50), 5, SmoothStepN);
	Godot::print("Button 2 pressed.");
}
void tweening::button3() {
	// Showcase on $Ship3 using spline on beziers utilizing on_end
	Sprite* ship = Object::cast_to<Sprite>(get_node("Ship3"));
	tweens.tween(*ship, "position", ship->get_position(), ship->get_position() + Vector2(200, -200), 5, EASE_IN_QUAD,
		[this](CustomTween* tween) {this->on_end_callback(tween);  }  // callback in a separate function
	);
	Godot::print("Button 3 pressed.");
}

void tweening::button4() {
	// Showcase of smooth spline movement on $Ship4, change position
	//       The spline must be built using single line of code, e.g. using the Builder pattern
	Sprite* ship4 = Object::cast_to<Sprite>(get_node("Ship4"));
	tweens.tween(*ship4, "position", ship4->get_position(), ship4->get_position() + Vector2(-100, -100), 5, EASE_IN_OUT_QUAD)
		->add_curve(ship4->get_position() + Vector2(-100, 0))
		->add_curve(ship4->get_position() + Vector2(0, -100))
		->add_curve(ship4->get_position());
	Godot::print("Button 4 pressed.");
}

void tweening::on_end_callback(CustomTween* tween) {
	tweens.tween(tween->sprite, "position", tween->endVal, tween->startVal, 5, EASE_OUT_QUAD);
}
// Restart the scene
void tweening::restart() {
	get_tree()->reload_current_scene();
	Godot::print("Scene restarted.");
}