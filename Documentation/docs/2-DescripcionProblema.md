# Descripción del problema

El problema planteado para el primer proyecto programado del curso de Estructuras 
de Datos del segundo semestre de 2022 consiste en la realización de un programa que 
registre datos del clima y tiempo de manera diaria, dentro del cual se pueda consultar 
información para conocer los reportes diarios y promedios mensuales y anuales del clima. 
Los objetivos de este proyecto consisten en el desarrollo de un programa en el lenguaje 
C++ (utilizando las ventajas de la orientación a objetos), la implementación de estructuras 
de datos dinámicas que permitan el acceso y ordenamiento de la información, y la 
implementación de un nuevo tipo de datos estudiado en clase: los punteros.

El programa del proyecto debe de presentar la capacidad de ingresar información sobre 
personas, lluvias, regiones, lugares y efimeridades. La inserción de personas y 
efimeridades debe de darse mediante una lista doble ordenada por nombre y por fecha, 
respectivamente. El grupo de lluvias y regiones debe de insertarse por medio de una 
lista simple, con inserción al inicio de esta. Finalmente, la inserción de lugares 
está preestablecida para darse mediante una lista circular, con inserción al inicio, 
y los registros de tiempo deben de hacerse en una sublista simple ordenada por fecha.

Dentro del programa se deben crear punteros programados para relacionar diversas listas 
entre sí, de forma que cada región se pueda relacionar con distintos lugares, y que 
cada lugar pueda relacionarse con los registros de tiempo. Además, se debe de relacionar 
cada persona con los registros del clima, mediante una sublista simple cuya inserción 
sea al inicio de esta. Cada uno de los objetos, que poseen características propias, 
deben de poder crear una relación con aquellos objetos correspondientes.

Existen reglas para la inserción y actualización de la información de las listas. 
El programa debe de permitir la inserción de los datos de todas las listas y 
sublistas, así como la modificación de estos datos. Debe permitir la eliminación 
de nodos en todas las listas y sublistas, y debe de validar que no se ingresen 
datos repetidos o erróneos (un ejemplo de esto sería el tiempo; las 26 horas, 
o 30 de febrero). Además, en el programa debe de haber por defecto un mínimo 
de 10 datos dentro de cada lista y sublista.

Las consultas del proyecto deben presentar información procesada a base de los 
datos obtenidos en las listas y las sublistas. El usuario debe poder consultar 
por la fecha completa con la salida de “sol” más temprana de un determinado 
año, así como el ocultamiento más tardío en el mismo año. El programa ha de 
presentar también las fechas que generan la mayor diferencia en minutos de la 
salida del sol en un determinado año, además de imprimir el mes que más extremos 
de lluvia y sequía ha tenido de un lugar y año específico. En el caso de un empate 
entre meses se deben imprimir todos los meses que tienen el empate máximo. Por 
último, el programa debe de poder determinar e imprimir la persona que más 
registros de tiempo posee relacionados.

Con respecto a los reportes, el usuario debe de poder consultar por la impresión de 
la información de todas las listas y su información relacionada, los horarios de la 
salida y la puesta del sol separado por meses de un año, la precipitación mensual 
promedio de cada lugar y región en un año determinado (mediante reportes separados), 
y las variables climatológicas de todos los lugares de una región específica durante 
un periodo de tiempo establecido. Además, debe determinar e imprimir si hay periodos 
en un año de cambios en tipos de días de lluvia, en los cuales se debe indicar la fecha 
de inicio y final del cada periodo encontrado (los periodos deben ser iguales o superiores 
a siete días seguidos). Finalmente, se debe de imprimir los porcentajes de la clasificación 
de la lluvia, los días de lluvia y los extremos de temperatura de cada mes para un año 
y lugar específico.