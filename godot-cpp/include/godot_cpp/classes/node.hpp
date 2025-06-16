/**************************************************************************/
/*  node.hpp                                                              */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

// THIS FILE IS GENERATED. EDITS WILL BE LOST.

#ifndef GODOT_CPP_NODE_HPP
#define GODOT_CPP_NODE_HPP

#include <godot_cpp/core/object.hpp>

#include <godot_cpp/core/class_db.hpp>

#include <type_traits>

namespace godot {

class Node : public Object {
	GDEXTENSION_CLASS(Node, Object)

public:
	enum ProcessMode {
		PROCESS_MODE_INHERIT = 0,
		PROCESS_MODE_PAUSABLE = 1,
	};

	static const int NOTIFICATION_ENTER_TREE = 10;
	static const int NOTIFICATION_EXIT_TREE = 11;

	void add_child(Node *p_node);
	void remove_child(Node *p_node);
	virtual void _process(double p_delta);

protected:
	template <typename T, typename B>
	static void register_virtuals() {
		Object::register_virtuals<T, B>();
		if constexpr (!std::is_same_v<decltype(&B::_process), decltype(&T::_process)>) {
			BIND_VIRTUAL_METHOD(T, _process);
		}
	}

public:
	template <typename T>
	T *get_node(const NodePath &p_path) const { return Object::cast_to<T>(get_node_internal(p_path)); }
};

} // namespace godot

VARIANT_ENUM_CAST(Node::ProcessMode);

#endif // ! GODOT_CPP_NODE_HPP
