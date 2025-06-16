#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>

namespace godot {

class ExampleClass : public Node {
    GDCLASS(ExampleClass, Node);

public:
    ExampleClass() = default;
    ~ExampleClass() = default;

    void _process(double delta);
};

}

#endif // EXAMPLE_CLASS_H
