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
        if (inicioCadena->get_data() != finalCadena->get_data()){
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

template <class T> 
void dll_t<T>::extract_all(const T& dato) {
    // 1. Es una DLL, usamos el nodo correcto
    dll_node_t<T>* nodo = get_head();
    
    // 2. Solo comprobamos que el nodo no sea nulo para llegar hasta el final
    while (nodo != nullptr) {
        
        // SALVAVIDAS: Guardamos el siguiente ANTES de que el nodo sea destruido
        dll_node_t<T>* siguiente = nodo->get_next();

        if(nodo->get_data() == dato) {
            
            // Fase 1: Arreglar al vecino izquierdo
            if (nodo->get_prev() != nullptr) {
                // Al anterior, le decimos que su siguiente es el siguiente de 'nodo'
                nodo->get_prev()->set_next(nodo->get_next());
            } else {
                // Si no hay anterior, era la cabeza
                head_ = nodo->get_next();
            }

            // Fase 2: Arreglar al vecino derecho
            if (nodo->get_next() != nullptr) {
                // Al siguiente, le decimos que su anterior es el anterior de 'nodo'
                nodo->get_next()->set_prev(nodo->get_prev());
            } else {
                // Si no hay siguiente, era la cola
                tail_ = nodo->get_prev();
            }

            // Destruimos el nodo de forma segura
            delete nodo;
            sz_--;
        }
        
        // 3. Avanzamos usando nuestro salvavidas, no el nodo destruido
        nodo = siguiente;
    }
}

// move to front: Extraer de una posición y poner en la primera posición
template <class T> 
void dll_t<T>::move_to_front(dll_node_t<T>* nodo) {
    // Si la lista está vacía, el nodo es nulo, o ya es la cabeza, no hacemos nada
    if (nodo == nullptr || nodo == head_) {
        return; 
    }

    // --- PASO 1: EXTRAER EL NODO DE SU POSICIÓN ACTUAL ---
    
    // Arreglar al vecino izquierdo (sabemos que tiene, porque no es la cabeza)
    nodo->get_prev()->set_next(nodo->get_next());
    
    // Arreglar al vecino derecho (puede que sea la cola)
    if (nodo->get_next() != nullptr) {
        nodo->get_next()->set_prev(nodo->get_prev());
    } else {
        // Era la cola, actualizamos tail_
        tail_ = nodo->get_prev();
    }

    // --- PASO 2: REINSERTARLO EN LA CABEZA ---
    
    // El 'siguiente' del nodo será la antigua cabeza
    nodo->set_next(head_);
    // Como ahora será el primero, no tiene anterior
    nodo->set_prev(nullptr);
    
    // La antigua cabeza ahora tiene a 'nodo' por detrás
    head_->set_prev(nodo);
    
    // Finalmente, el puntero principal de la clase apunta al nuevo nodo
    head_ = nodo;
}



// Fase 2: Dado un puntero a un nodo específico que ya pertenece a la lista doblemente enlazada
/*
Dado un puntero a un nodo específico de la lista doblemente enlazada, implementa el método
void swap_with_next(dll_node_t<T>* nodo). Debes intercambiar físicamente de posición ese nodo
con su vecino de la derecha, modificando únicamente las conexiones de los punteros
(está estrictamente prohibido usar el método set_data() para intercambiar los valores internos).
*/

template <class T>
void dll_t<T>::swap_with_next(dll_node_t<T>* nodo){
    
}