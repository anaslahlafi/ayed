/*
    Ejercicios DLL
    -- Fase 1: El objetivo aquí es aprender a iterar sin modificar la estructura principal.
*/

template<Class T> bool dll_t<T>::is_palindrome() const {
    // Obtenemos el principio y el final de la cadena
    dll_node_t<T>* inicioCadena = get_head(); 
    dll_node_t<T>* finalCadena = get_tail();
    // Si la lista está vacía, no hay nada que comprobar
    if (inicioCadena == nullptr) return true;
    // Ahora, iteramos teniendo en cuenta la condición
    while (while inicioCadena != finalCadena && inicioCadena->get_prev() != finalCadena){
        // Si los datos coinciden 
        if (inicioCadena->get_data != finalCadena->get_data){
            return false;
        }
        // Acercamos los iteradores al medio
        inicioCadena = inicioCadena->get_next();
        finalCadena = finalCadena->get_prev();
    }
    // Devolvemos la característica en verdadero, si no entramos en el for.
    return true;
}
/*
    Fase 2: Aislar nodos y reconectarlos sin perder nada por el camino
*/

template <class T> dll_t::void extract_all(const T& dato){
    // crear el puntero para recorrer la lista
    sll_node_t<T>* nodo = get_head();
    while ()
}