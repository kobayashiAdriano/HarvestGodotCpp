#include "../include/example_class.hpp"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ExampleClass::say_hello() {
    print("Hello from ExampleClass!");
}

void ExampleClass::_bind_methods() {
    ClassDB::bind_method(D_METHOD("say_hello"), &ExampleClass::say_hello);
}
