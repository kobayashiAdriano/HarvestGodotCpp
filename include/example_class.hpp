#ifndef EXAMPLE_CLASS_HPP
#define EXAMPLE_CLASS_HPP

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/string.hpp>

namespace godot {

class ExampleClass : public Object {
    GDCLASS(ExampleClass, Object);

public:
    ExampleClass() = default;
    ~ExampleClass() = default;

    void _process(double delta);
    String hello();
};

} // namespace godot

#endif // EXAMPLE_CLASS_HPP
