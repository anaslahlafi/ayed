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



/*
¡Claro que sí! Para consolidar esta "Fase 2" (Cirugía Local) necesitamos ejercicios que no cambien toda la lista de golpe, pero que te obliguen a hacer conexiones de punteros muy precisas en medio de la estructura sin perder referencias.

Aquí tienes dos retos nuevos de nivel examen, uno para cada tipo de lista. Coge papel y boli para dibujar las cajas antes de picar el código.

### Reto 1 (SLL): Insertar *antes* de un objetivo (`insert_before_value`)

* **Enunciado:** Implementa un método `void insert_before_value(const T& target, const T& new_data)`. Este método debe buscar la **primera aparición** del valor `target` en la lista simplemente enlazada, e insertar un nuevo nodo con el valor `new_data` exactamente en la posición anterior a él. Si el `target` no existe en la lista, no se hace nada.
* **El Peligro (Riesgo de Segfault):** Al estar en una SLL (Lista Simplemente Enlazada), no tienes el método `get_prev()`. Si tu bucle avanza hasta pararse exactamente encima del nodo que contiene el `target`, ¡ya es demasiado tarde! No tendrás forma de enganchar el nuevo nodo por detrás porque habrás perdido la referencia al nodo anterior.
* **La Pista Quirúrgica:** 1. Tienes que evaluar siempre el `get_next()->get_data()`. Es decir, debes ir mirando "una baldosa por delante" de donde estás pisando.
2. ¡Cuidado con el caso especial! ¿Qué pasa si el `target` resulta ser exactamente la cabeza de la lista? Tendrás que insertar el nuevo nodo actualizando el puntero `head_` de la clase.

### Reto 2 (DLL): Intercambio de vecinos (`swap_with_next`)

* **Enunciado:** Dado un puntero a un nodo específico de la lista doblemente enlazada, implementa el método `void swap_with_next(dll_node_t<T>* nodo)`. Debes intercambiar físicamente de posición ese nodo con su vecino de la derecha, modificando únicamente las conexiones de los punteros (está estrictamente prohibido usar el método `set_data()` para intercambiar los valores internos).
* **El Peligro (Riesgo de Segfault):** Este es el ejercicio definitivo de precisión. Si te equivocas en el orden en el que reasignas las flechas, desconectarás la lista en dos partes o harás que un nodo apunte hacia sí mismo en bucle infinito.
* **La Pista Quirúrgica:**
1. Para hacer esto con seguridad matemática, intervienen hasta **4 nodos**: el vecino izquierdo del nodo, el nodo mismo, el vecino derecho del nodo, y el vecino que está a la derecha del vecino derecho.
2. Como siempre en una DLL, vigila los extremos. Si el `nodo` que te pasan es la cola (`tail_`), no tiene vecino derecho con el que intercambiarse (la función debería terminar sin hacer nada). Si el `nodo` es la cabeza, al intercambiarlo con el segundo, el segundo pasará a ser la nueva cabeza y deberás actualizar `head_`.
3. Te recomiendo crear un puntero auxiliar `dll_node_t<T>* vecino = nodo->get_next();` para que la lectura de tu código sea mucho más clara antes de empezar a cruzar las flechas.
*/