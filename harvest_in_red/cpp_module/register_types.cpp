#include "register_types.h"

#include "src/example.h"


using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    ClassDB::register_class<Example>();
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    // Limpeza, se precisar (normalmente vazio)
}

extern "C" {

// Macro obrigatória para Godot reconhecer o módulo
GDExtensionBool GDE_EXPORT example_library_init(const GDExtensionInterface *p_interface, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
    static GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

    init_obj.register_initializer(initialize_example_module);
    init_obj.register_terminator(uninitialize_example_module);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_obj.init();
}

}
