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

En este directorio ya se encuentran declaradas todas las clases
con los métodos necesarios, así que sólo tendrás que escribir
su implementación en los correspondientes ficheros `.cpp`.

Como siempre, la _test suite_ ejecutará automáticamente los tests
que se encuentran en el directorio `tests` con cada 
modificación (_commit_) que se realice en el correspondiente
_pull-request_.

¡Suerte!
