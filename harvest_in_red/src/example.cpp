#include <classes/node3d.hpp>
#include <core/class_db.hpp>
#include <godot.hpp>

using namespace godot;

class Example : public Node3D {
    GDCLASS(Example, Node3D);

public:
    void _ready() {
        Godot::print("Módulo C++ carregado com sucesso!");
    }
};

void initialize_example(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    ClassDB::register_class<Example>();
}

void uninitialize_example(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {

// Entry point obrigatório
GDExtensionBool GDE_EXPORT example_library_init(const GDExtensionInterface *p_interface,
                                                GDExtensionClassLibraryPtr p_library,
                                                GDExtensionInitialization *r_initialization) {
    static GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);
    init_obj.register_initializer(initialize_example);
    init_obj.register_terminator(uninitialize_example);
    init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);
    return init_obj.init();
}
}
