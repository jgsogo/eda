Actividad 08
------------

Propuesta en el [capítulo sobre pilas (`stacks`)](https://jgsogo.es/eda/08.stacks.html#/7).

Utiliza un stack para comprobar si una secuencia de 
paréntesis y corchetes es correcta (todos los que se 
abren se cierran en el orden correspondiente).

```cpp
bool check_braces(const std::string& braces);

int main() {
    check_braces("([](()))[]");  // --> true
    check_braces("([())]");  // --> false
}
```

