#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include "CustomTween.h"
#include <vector>
namespace godot {
	class Tweens : public Node
	{

		// Godot structure
	private:
		GODOT_CLASS(Tweens, Node)
	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		Tweens();
		~Tweens();


		// Gameplay variables
	public:
		std::vector<CustomTween> tweens;
	private:

		// Gameplay methods
	public:
		CustomTween* tween(Sprite&, const  String&, const  Variant&, const  Variant&, const  float, const  int, const  std::function<void(CustomTween*)> & = [](CustomTween* a) {});
	private:

	};
}
