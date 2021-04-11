Algoritmos de ordenación
========================

Los algoritmos de ordenación son una pieza fundamental en
muchos programas, ya sea como fin en si mismo o como paso 
intermedio para implementar otras funcionalidades. 

A lo largo del curso hemos visto diferentes algoritmos de
ordenación y hemos hablado sobre la complejidad de estos
algoritmos, tanto en términos de tiempo como en términos de
espacio. Según sus características unos algoritmos son
más adecuados para unos escenarios que para otros.

En este trabajo se propone realizar una **comparación entre
varios algoritmos de ordenación**. Deberán implementarse varios
algoritmos de ordenación y compararse los
tiempos que tardan en ordenar diferentes vectores de números.

Objetivos del trabajo:
* Implementar al menos 6 algoritmos de ordenación.
* Añadir a la comparación (**además**) el [algoritmo `std::sort`
de la librería estándard](https://en.cppreference.com/w/cpp/algorithm/sort).
* Medir los tiempos que tarda cada uno de ellos en ordenar
diferentes vectores (utiliza vectores que ofrezcan tiempos 
significativos, quizá con cien mil o un millón de elementos):
  + Un vector de números aleatorios.
  + Un vector ya ordenado.
  + Un vector ordenado en orden inverso.
  + Un vector con todos sus números iguales.

Entregables:
* Código fuente desarrollado.
* Una memoria donde se muestren los resultados obtenidos y
un análisis de los mismos: ¿se corresponden los tiempos
obtenidos con los esperados según la complejidad teórica?
¿los resultados son diferentes según la ordenación inicial
del vector?
