Actividad 04
------------

Propuesta en el [capítulo sobre listas (`LinkedList`)](https://jgsogo.es/eda/07.lists-class.html#/9).

Añade una función a tu clase DoubleLinkedList 
para iterar la lista desde el final al principio

```cpp
class DoubleLinkedList {
    public:
        // ...
        void for_each_reverse(std::function<void (TipoDato&)> action) const;
        // ...
}
```

En este ejercicio tendrás que modificar únicamente los
ficheros `DoubleLinkedList.cpp` y `ElementoListaDoble.cpp` para
implementar los métodos que están declarados en sus respectivos
ficheros de cabecera (`DoubleLinkedList.h` y `ElementoListaDoble.h`).

En el directtorio `tests` se encuentran varios tests que se
ejecutarán automáticamente para probar el funcionamiento de las
funciones que se habrán implementado en la clase `Stack`.

¡Suerte!
