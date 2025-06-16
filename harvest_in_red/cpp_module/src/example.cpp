#include "example.h"

#include <classes/engine.hpp>
#include <variant/utility_functions.hpp>

using namespace godot;

Example::Example() {
    // Construtor: pode deixar vazio por enquanto
}

Example::~Example() {
    // Destrutor: pode deixar vazio também
}

void Example::_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return; // Não executa no editor
    }

    // Exemplo de log simples
    UtilityFunctions::print("Rodando _process de Example!");
}

// Registrando a classe na Godot
void register_example_types() {
    ClassDB::register_class<Example>();
}

void unregister_example_types() {
    // Se precisar de alguma limpeza, faz aqui (normalmente fica vazio)
}
