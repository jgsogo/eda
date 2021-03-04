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

