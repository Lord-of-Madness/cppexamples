#pragma once

#include <Godot.hpp>
#include <Node2D.hpp>
#include <Input.hpp>
#include "Tweens.h"
#include<Node.hpp>
#include<SceneTree.hpp>

namespace godot {
	class tweening : public Node2D
	{

		// Godot structure
	private:
		GODOT_CLASS(tweening, Node2D)
	public:
		static void _register_methods();
		void _init();
		void _process(float delta);

		tweening();
		~tweening();


		// Gameplay variables
	public:


	private:
		Tweens tweens;



		// Gameplay methods
	public:
		void _input();

	private:
		void button1();
		void button2();
		void button3();
		void button4();
		void restart();
		void on_end_callback(CustomTween*);

	};
}
