#pragma once

#include <Godot.hpp>
#include <Node.hpp>
#include <Sprite.hpp>
#include <Math.hpp>
#include <vector>
#include <map>
#include <Color.hpp>
#include <functional>
#include <string>
namespace godot {
	/*
	* This things just refuses to work.
	#ifndef Suffering
	#define Suffering
		Color operator* (const float x, const Color c) { return Color(c.r * x, c.g * x, c.b * x, c.a * x); };
		Color operator* (const Color c, const float x) { return Color(c.r * x, c.g * x, c.b * x, c.a * x); };
	#endif // !Suffering
	*/

	class CustomTween : public Node
	{

		// Godot structure
	private:
		GODOT_CLASS(CustomTween, Node)
	public:
		static void _register_methods();
		void _init() {}
		void _process(float delta) {}

		CustomTween() {}
		CustomTween(Sprite& spri, const String& param, const  Variant& start, const  Variant& end, const  float dur, const int Easing, const std::function<void(CustomTween*)>& Fncref = [](CustomTween*) {});
		~CustomTween() {}


		// Gameplay variables
	public:
		template<typename T>
		class tMap {
		public:
			std::map<int, std::function<Variant(CustomTween*)>>dict{
				{0,[](CustomTween* t) {return t->linear<T>(); }},
				{1,[](CustomTween* t) {return t->EASE_IN_QUAD<T>(); }},
				{2,[](CustomTween* t) {return t->EASE_OUT_QUAD<T>(); }},
				{3,[](CustomTween* t) {return t->SmoothStepN<T>(); }},
				{4,[](CustomTween* t) {return t->Bouncy<T>(); }},
				{5,[](CustomTween* t) {return t->EASE_IN_OUT_QUAD<T>(); }},
				{6,[](CustomTween* t) {return t->SmoothStep3<T>(); }},
				{7,[](CustomTween* t) {return t->EASE_IN_SINE<T>(); }},
				{8,[](CustomTween* t) {return t->EASE_OUT_SINE<T>(); } }
			};
		};
		tMap<Color> colorDict;//I have no idea how to make it more polymorphic.
		tMap<float> floatDict;
		tMap<Vector2> Vector2Dict;
		std::function<void(CustomTween*)> _on_end;
		Sprite sprite;
		NodePath spritepath;
		Variant startVal;
		Variant endVal;
	private:
		float t = 0;
		float x = 0;
		std::vector<Variant> interverticies;
		size_t index = 0;
		float duration = 0;
		String parameter;
		Variant Easeinfnc;
		int intervals = 0;



		// Gameplay methods
	public:
		template<typename T>
		Variant linear()const { return(T)startVal + ((T)endVal - (T)startVal) * x; }
		template<typename T>
		Variant Bouncy()const { return (T)startVal * (1 - x) * (1 - x) + (T)endVal * x * x; };
		template<typename T>
		Variant EASE_IN_SINE()const { return (T)startVal + ((T)endVal - (T)startVal) * (real_t)(1 - cos((x * Math_PI) / 2)); };//conversion to real_t is there ot supress warnings. But I believe that shouldn't be an issue
		template<typename T>
		Variant EASE_OUT_SINE()const { return (T)startVal + ((T)endVal - (T)startVal) * (real_t)(sin((x * Math_PI) / 2)); };
		template<typename T>
		Variant EASE_IN_QUAD()const { return (T)startVal + ((T)endVal - (T)startVal) * (1 - (1 - x) * (1 - x)); };
		template<typename T>
		Variant EASE_OUT_QUAD()const { return (T)startVal + ((T)endVal - (T)startVal) * x * x; }
		template<typename T>
		Variant EASE_IN_CUBE()const { return (T)startVal + ((T)endVal - (T)startVal) * (1 - (1 - x) * (1 - x) * (1 - x)); }
		template<typename T>
		Variant EASE_OUT_CUBE()const { return (T)startVal + ((T)endVal - (T)startVal) * x * x * x; }
		template<typename T>
		Variant SmoothStep3()const { return (T)EASE_IN_QUAD<T>() * x + (T)EASE_OUT_QUAD<T>() * (1 - x); }
		template<typename T>
		Variant SmoothStepN()const { return (T)startVal + (((T)endVal - (T)startVal) * x * x * (3 - 2 * x)); }
		template<typename T>
		Variant EASE_IN_OUT_QUAD()const {
			T a = endVal;
			T b = startVal;
			if (x < 0.5) return b + (a - b) * 2 * x * x;
			else		 return b + (a - b) * (1 - (-2 * x + 2) * (-2 * x + 2) / 2);
		}
		void update(float delta);
		CustomTween* add_curve(const Variant& end);
		bool is_done()const { return t >= 1; }
	private:


	};
}
