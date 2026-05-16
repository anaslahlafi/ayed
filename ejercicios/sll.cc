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
