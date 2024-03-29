#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/editor_plugin.hpp>
#include <godot_cpp/classes/editor_interface.hpp>
#include <godot_cpp/classes/editor_script.hpp>
#define NAMEOF(name) #name

namespace godot {

	class GDExample : public Sprite2D {//EXAMPLE Node
		GDCLASS(GDExample, Sprite2D)

	private:
		double time_passed;
		double exportproperty;

	protected:
		static void _bind_methods();

	public:
		GDExample();
		~GDExample();
		void SumoonMadness() const;
		void set_exportproperty(const double val);
		double get_exportproperty() const;
		void _process(double delta) override;
	};

	class GDEditorTest : public EditorPlugin {//EXAMPLE PLUGIN
		GDCLASS(GDEditorTest, EditorPlugin)

	private:
	protected:
		void _notification(int what);
	public:
		static void _bind_methods();
		GDEditorTest() {}
		~GDEditorTest() {}
		void SummonMadnessAGAIN();
		virtual String _get_plugin_name() const override { return "Test"; }
		virtual bool _has_main_screen() const override { return false; }
		virtual void _edit(Object* p_object) override;
		virtual bool _handles(Object* p_object) const override;
		virtual void _make_visible(bool p_visible) override;
		virtual void _enter_tree()override;

	};

	class GDEditorScriptTest : public EditorScript {//EXAMPLE EditorScript
		GDCLASS(GDEditorScriptTest, EditorScript)
	protected:
	public:
		static void _bind_methods();
		GDEditorScriptTest(){}
		~GDEditorScriptTest() {}
		void SummoningMadnessForAllEternity() {
			std::cout << "BOW DOWN BEFORE THE GOD OF DEATH, thot!";
		}
		virtual void _run()override {
			SummoningMadnessForAllEternity();
		}

	};

}

#endif