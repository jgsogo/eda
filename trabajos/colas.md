Colas en los supermercados
==========================

Simular el sistema de colas de un supermercado. Se debe 
simular tanto el sistema convencional en el que cada caja tiene una
cola, como el sistema de cola única.

El programa deberá simular el paso del tiempo:
* cada cierto tiempo _generará_ un nuevo cliente. Este tiempo entre
clientes deberá ser un número aleatorio, con un máximo y un mínimo
que podrán configurarse mediante parámetros.
* en el caso convencional, se considerarán a su vez dos escenarios
(a seleccionar mediante otro parámetro): en un escenario los clientes
se asignan siempre a la caja que tiene la cola más corta, en el
otro escenario elegirán una caja al azar.
* el tiempo que un cliente tarda en pagar en cada caja también
será aleatorio, con un máximo y un mínimo que podrán configurarse
mediante parámetros.

El programa deberá almacenar en cada instante temporal el número
de clientes que están esperando y el número de clientes atendidos
hasta ese momento.

Opcionalmente se podrá implementar también un comportamiento adicional:
cuando el número de clientes supere cierto umbral, se activará
una caja adicional que empezará a atender clientes; y cuando el número
de clientes esperando baje de otro umbral, se procederá a cerrar una
caja. Ambos umbrales deberán ser también configurables mediante
parámetros.

Entregables:
* Código fuente desarrollado
* Memoria descriptiva breve, con los resultados de las diferentes
simulaciones.
