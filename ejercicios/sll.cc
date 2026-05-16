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
template <class T> sll_node_t<T>* sll_t::removeduplicates(){
    sll_node_t<T>* nodo_inicial = get_head();
    // Recorrer la lista enlazada. Existe lista y no se ha acabado.
    while (nodo_inicial != nullptr && nodo_inicial->get_next() != nullptr){
        if (nodo_inicial->get_data() == nodo_inicial->get_next()->get_data()){
            // Si estoy en la primera posición  
            if (nodo_inicial->get_prev() == nullptr){
                // Muevo el cabezal de head una posición hacía delante
                // crear un puntero auxiliar
                // establecer el nuevo get_prev == nullptr
                // eliminar el otro
                sll_node_t<T>* auxiliar = nodo_inicial;
                nodo_inicial->get_next() = head_;
                nodo_inicial->get_next() = set_prev(nullptr);
                // hacemos rm
                remove auxiliar;                
            }
        // Resto de casos
            sll_node_t<T>* auxiliar = nodo_inicial;
            nodo_inicial->get_next() = set_prev(nodo_inicial->get_prev());
            // ejecutamos el remove
            remove auxiliar;
    }
    // Incrementamos el iterador 
    nodo_inicial = nodo_inicial->get_next();
    }
}

