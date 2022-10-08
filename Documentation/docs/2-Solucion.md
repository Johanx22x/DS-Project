## Solucion del problema 

Para la solución del problema planteado en el primer proyecto programado del 
curso de Estructuras de Datos del segundo semestre de 2022, se utilizaron las 
estructuras de listas, sublistas, clases y plantillas para el manejo y acceso 
de la información. Se decidió realizar un diagrama de clases UML que caracterice 
a cada lista y sublista con sus atributos respectivos, así como la relación 
entre las listas. 

Como se puede observar en la Figura 1, se tienen las diversas listas y sublistas 
establecidas en la descripción del problema, y, añadido a éstas, se encuentra una 
clase denominada “Proxy”. Este objeto consiste en un intermediario entre las distintas 
listas que ayuda a conectar mediante punteros los datos de los nodos que requieren crear 
relaciones entre sí. El objeto Proxy posee una estructura de enlace a los nodos que 
conecta, además de que es una sublista, por lo que tiene un nodo siguiente. Esta 
integración al programa permite relacionar en ambas direcciones dos listas, de 
forma que cada clase posee un nuevo Proxy que acepta varios tipos de datos, 
permitiendo adquirir todos los atributos requeridos para las consultas y 
los reportes.

En cuanto a la lógica para realizar el programa, se estableció una división de 
tareas para cada integrante del grupo, con el objetivo de cumplir las tareas 
establecidas antes de la fecha de entrega del proyecto. Se trabajó el sistema 
mediante la aplicación de programación modular, con diversos archivos 
interconectados que componen el programa.

Para la resolución de consultas y reportes, se construyó el programa de manera 
que itere por las listas para encontrar y extraer los datos necesarios, de acuerdo 
con lo solicitado, y se conformaron en conjuntos de datos que serían posteriormente 
enviados a imprimir. Sin embargo, algunas de las consultas o reportes requieren 
de algunas fechas especificadas o información determinada, por lo que se verificó 
para estos casos que se acepte la entrada de datos por parte del usuario dependiendo 
del interés de este, validando la entrada de datos para que concuerde con los 
parámetros e imprimiendo el conjunto de datos requerido.

En el caso de las consultas en específico, se accedió a los datos guardados en las 
listas y se buscó, mediante la validación de parámetros de la información, los 
extremos consultados por el usuario. En la consulta de los extremos de la salida y 
entrada del sol, se pide al usuario por el año del cual se desea consultar el dato, 
y, dentro de los datos que posean en el atributo de fecha el valor del año ingresado, 
se extrae la hora y fecha del momento más temprano y más tarde de la salida y 
ocultamiento del sol, respectivamente. Luego se procede a imprimir los datos en 
la interfaz del usuario, concluyendo con la consulta.

Los procesos realizados para imprimir los reportes conllevan una mayor complejidad 
que aquellos requeridos para las consultas. Por esta parte, se buscaron en las listas 
del programa los datos pertinentes al reporte consultado por el usuario. Estos datos 
se ordenan en conjuntos de datos que son procesados para ser validados y confirmar 
su relevancia en el reporte, mediante cálculos y parámetros. Finalmente, se muestran 
al usuario en el formato establecido por los lineamientos del proyecto.

![[Diagrama de clases del sistema]()](images/uml_diagram.png){#fig:diagram}
