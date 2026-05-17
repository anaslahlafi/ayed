// Lista de errores (para no repetirlos)

/*
En c++ un getter (get_atributo) sirve para leer un atributo. No para hacer una declaración
líneas como: "nodo->get_next() = puntero"; deben traducirse como "nodo->set_next(puntero)";
No existe "remove". Es delete.

Cuando quiero crear un puntero que tenga algo por defecto y no que me lleve a un puntero
hago la declaración sll_node_t<T>* = new sll_node_t<T>(DATO CONST)
*/ 