#include "register_types.h"

#include "test.hpp"
#include"Obstacle.hpp"
#include"TileCollisionShape2D.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/ref.hpp>

namespace godot{

void initialize_RTS_module(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE) {
		GDREGISTER_CLASS(GDExample)
	}
	if (p_level == MODULE_INITIALIZATION_LEVEL_EDITOR) {
		GDREGISTER_CLASS(TileCollisionShape2D)
		GDREGISTER_CLASS(Obstacle)
		GDREGISTER_CLASS(GDEditorTest)
		//EditorPlugins::add_by_type<GDEditorTest>();
		GDREGISTER_CLASS(GDEditorScriptTest);
	}

	
}

void uninitialize_RTS_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_EDITOR) {
		//EditorPlugins::remove_by_type<GDEditorTest>();
		return;
	}
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT RTS_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_RTS_module);
		init_obj.register_terminator(uninitialize_RTS_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_EDITOR);

		return init_obj.init();
	}
}
}