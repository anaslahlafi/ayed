/*
    Ejercicios SLL
    -- Fase 1: El objetivo aquí es aprender a iterar sin modificar la estructura principal.
*/

// get_middle
// Devuelve un puntero al nodo central de la SLL en una sola pasada.
sll_node_t<T>* sll_t<T>::get_middle() const {
    // Creamos dos punteros para recorrer la lista
    sll_node_t<T>* punteroLento = get_head(); // Avanza de uno en uno
    sll_node_t<T>* punteroRapido = get_head(); // Avanza de dos en dos
    // siempre que el que está primero en la lista, no apunte al final, iteremos
    while (punteroRapido->get_next != nullptr && punteroRapido->get_next() != nullptr){
        // Hacemos que punteroFast avance dos veces
        punteroRapido = punteroRapido->get_next->get_next;
        // Ahora, hacemos que punteroLento avance una vez
        punteroLento = punteroLento->get_next;
    }
    return punteroLento; // Devolvemos el puntero
}

/*
Fase 2: Aislar nodos y reconectarlos sin perder nada por el camino
*/

//removeduplicates: Asuminendo que la lista está ordenada, eliminar los datos duplicados.
// Ayuda de lógica, crear un nodo auxiliar antes de depurar nada.

// SEGUNDA IDEA - menos punteros (mejor solución desde mi punto de vista)
template <class T> void sll_t<T>::remove_duplicates()
    // establecemos el puntero en la primera posición.
    sll_node_t<T>* nodo = get_head();
    while (nodo != nullptr){
        if(nodo->get_data() == nodo->get_next()->get_data()){
            sll_node_t<T>* auxiliar = nodo->get_next();
            nodo->set_next(auxiliar->get_next());
            delete auxiliar;
        } else {
            // Solo avanzamos si no eran iguales
            nodo = nodo->get_next();
        }
}


template <class T>
void sll_t<T>::insert_before_value(const T& target, const T& new_data){
    // Nos ponemos en la primera posición de la lista enlazada
    sll_node_t<T>* nodo = get_head();
    // Siempre y cuando no este vacía o hayamos terminado de recorrerla
    while (nodo != nullptr){
        // Comprobamos el dato
        if (nodo->get_data() == target){
            // Aparece
            sll_node_t<T>* nuevoNodo;
            nuevoNodo->set_data(new_data);
            nuevoNodo->set_next(nodo->get_next);
            nodo->set_next(nuevoNodo);
            // Buscamos solo la primera aparición
            break;
        } else {
            // En caso de que no coincida el dato con la posición
            nodo = nodo->get_next();
        }
    }
}

template <class T>
void sll_t<T>::insert_before_value(const T& target, const T& new_data) {
    sll_node_t<T>* nodo = get_head();
    
    // 1. Caso base: Lista vacía
    if (nodo == nullptr) return; 
    
    // 2. Caso límite: El objetivo es la cabeza
    if (nodo->get_data() == target) {
        sll_node_t<T>* nuevoNodo = new sll_node_t<T>(new_data);
        nuevoNodo->set_next(nodo);
        head_ = nuevoNodo;
        return; 
    }
    
    // 3. Búsqueda y conexión en el medio/final
    while (nodo != nullptr && nodo->get_next() != nullptr) {
        if (nodo->get_next()->get_data() == target) {
            sll_node_t<T>* nuevoNodo = new sll_node_t<T>(new_data);
            nuevoNodo->set_next(nodo->get_next());
            nodo->set_next(nuevoNodo);
            break; // Aquí sí usamos break porque estamos dentro de un while
        } else {
            nodo = nodo->get_next();
        }
    }
}
