#include "../include/example_class.hpp"

#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ExampleClass::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    UtilityFunctions::print("ExampleClass _process running");
}
