#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#define NAMEOF(name) #name

namespace godot {

	class GDExample : public Sprite2D {
		GDCLASS(GDExample, Sprite2D)

	private:
		double time_passed;
		double exportproperty;

	protected:
		static void _bind_methods();

	public:
		GDExample();
		~GDExample();
		void SumoonMadness();
		void set_exportproperty(const double val);
		double get_exportporperty();
		void _process(double delta) override;
	};

}

#endif