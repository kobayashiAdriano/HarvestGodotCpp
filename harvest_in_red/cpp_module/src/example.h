#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <classes/node.hpp>
#include <core/class_db.hpp>

namespace godot {

class Example : public Node {
    GDCLASS(Example, Node);

public:
    Example();
    ~Example();

    void _process(double delta);
};

}

#endif
