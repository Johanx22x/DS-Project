## Solucion del problema 

Para la solución del problema planteado en el primer proyecto programado del 
curso de Estructuras de Datos del segundo semestre de 2022, se utilizaron las 
estructuras de listas, sublistas, clases y plantillas para el manejo y acceso 
de la información. Se decidió realizar un diagrama de clases UML que caracterice 
a cada lista y sublista con sus atributos respectivos, así como la relación 
entre las listas. 

![[Diagrama de clases del sistema]()](images/Diagrama.png){#fig:diagram}

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
