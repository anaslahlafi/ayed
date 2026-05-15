/*
                                                    Ejercicios de DLL
1.- Implementa void extract_all(const T& dato) que busque y elimine todos los nodos de la lista cuyo valor coincida con dato
*/

template <class T>
void dll_t<T>::extract_all(const T& dato){
    // Empezamos a buscar desde la cabeza
    dll_node_t<T>* n = get_head();

    while (n != nullptr){
        // Comparar dato con valor que hay en ese puntero
        if (n->get_data() == dato){
            dll_node_t<T>* siguiente = n->get_next();
            
            // Tenemos que eliminar este puntero: remove (nodo)
            // Comprobamos el lado izquierdo
            if (n->get_prev() != nullptr){  
                n->get_prev()->set_next(n->get_next());
            } else {
                // Es el primer elemento de la cadena
                head_ = n->get_next();
            }
            // Comprobamos el lado derecho
            if (n->get_next() != nullptr){
                n->get_next()->set_prev(n->get_prev());
            } else {
                tail_ = n->get_prev();
            }
            delete n;
            sz_ --;
            n = siguiente;
        } else{
            n ->n->get_next();
        }
    }
}


/*
Compueba si una palabra es palíndroma
*/

template <class T> bool dll_t<T>::is_palindrome() const {
    // Obtengo el inicio y el final de la cadena
    dll_node_t<T>* inicio = get_head();
    dll_node_t<T>* fin = get_tail();
    // Creo el while para seguir iterando
    while (inicio != fin && inicio->get_next() == fin->get_prev(())){
        // Compruebo los datos
        if (inicio->get_data() != fin->get_data()){
            return false;
        }
        // En cualquier otro caso, avanzamos en la cadena
        inicio = inicio->get_next;
        fin = fin->get_prev; 
    }
    return true;
}

template <class T> void dll_t::extract_all (const &T dato){
    // Tengo que recorrer una lista doblemente
    // si dato coincide con get_data() -> el puntero se elimina.
    // Inicializamos el nodo en la cabeza.
    dll_node_t<T>* nodo = get_head();
    // Empezamos a recorrer dll_node_t
    while (nodo->get_next() != nullptr){ // Si nodo != cola (última pos). Entramos dentro
        //Comprobamos dato
        if (nodo->get_data() == dato){
            // Tengo que eliminar. Compruebo lado izquierdo. Aplico remove(nodo)
            if (nodo->get_prev() != nullptr){
                // No estoy en medio
                nodo->get_prev=set_next(n->get_next);
            } else {
                // Estoy en la primera posición
                head_ = nodo->get_next();
            }
            // Ahora compruebo el lado derecho. lol.
            if (nodo->get_next != nullptr){
                // No estoy en el medio
                nodo->get_next=set_prev(n->get_prev);
            } else{
                tail_ = n->get_prev();
            }
        } else{
            nodo = get_next();
        } 

    }
}


template <class T> void dll_t<T>::concat(dll_t<T>& l2){
    // Obtengo el final de una lista
    dll_node_t<T>* finalLista = get_tail();
    // Obtengo inicio cola de listaDoce
    // dll_node_t<T>* inicioDoce = get_head(12);
    // Ahora conecto el final con el inicio 
    finalLista->get_next = set_next(12->get_head) // set_next(inicioDoce)
    
}