Actividad 00
------------

[=> Información general](../README.md)

En la [lección sobre algoritmos](https://jgsogo.es/eda/01.algorithms.html) se propone un ejercicio basado en la 
película de Inception. El ejercicio consiste en transformar una cadena texto en otra cadena donde 
aparecen los caracteres repetidos siguiendo algunas reglas:

 * Cada nivel (level) (cada sueño dentro del sueño) multiplica por un número entero (fator_temporal) 
   las veces que aparece cada una de las letras.
 * Los espacios no deben expandirse en ningún caso. La separación entre palabras se hará siempre con 
   un único espacio.

**Nota.-** Pueden encontrarse ejemplos e implementaciones parciales de la solución en las diapositivas 
correspondientes a la lección.

---

Para resolver este ejercicio deberás crear un [pull-request](../README.md#pull-request) a la rama
`actividades` de este repositorio modificando el fichero [message_dream.cpp](src/message_dream.cpp)
de tal forma que se satisfagan las condiciones enunciadas anteriormente.

El CI ejecutará los tests unitarios que puedes encontrar en el directorio `tests`. Puedes echarles
un vistazo también para ver cuáles son las salidas esperadas para un conjunto de entradas.

¡Espero ver esos pull-requests pronto!
