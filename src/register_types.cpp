#include "../include/example_class.hpp"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

void initialize_example_module(godot::ModuleInitializationLevel p_level) {
    if (p_level == godot::MODULE_INITIALIZATION_LEVEL_SCENE) {
        godot::ClassDB::register_class<ExampleClass>();
    }
}

void uninitialize_example_module(godot::ModuleInitializationLevel p_level) {
}

extern "C" {
GDExtensionBool GDE_EXPORT example_module_init(const GDExtensionInterface *p_interface, godot::GDExtensionClassLibraryPtr p_library, godot::GDExtensionInitialization *r_initialization) {
    godot::GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);
    init_obj.register_initializer(initialize_example_module);
    init_obj.register_terminator(uninitialize_example_module);
    init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}
