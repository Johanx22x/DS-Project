__**Reglas de estilo de código para el proyecto**__

- Nombres de funciones en `camelCase`.
**__Bueno__**:
```cpp
int sumarNumerosPrimos(int a, int b);
```
**__Malo__**:
```cpp
int SumarNumerosPrimos(int a, int b);
int sumar_numeros_primos(int a, int b);
```

- Nombres de clases en `PascalCase`.
**__Bueno__**:
```cpp
class BecaPrestamo;
```
**__Malo__**:
```cpp
class beca_prestamo;
class becaPrestamo;
```

- Constantes en mayúsculas.
**__Bueno__**:
```cpp
const int PI = 3.14; 
```
**__Malo__**:
```cpp
const int pi = 3.14;
```

- Nada de variables globales.
**__Bueno__**:
```cpp
int main() {
  const int PI = 3.14;
  return 0;
}
```
**__Malo__**:
```cpp
const int PI = 3.14;
int main() {
  return 0;
}
```

- **Dejar espacios.**
**__Bueno__**:
```cpp
std::cout << "Hola\n";

if (condicion == 0);

for (int i = 0; i < 10; i++);
```
**__Malo__**:
```cpp
std::cout<<"Hola\n";

if(condition==0);

for(int i=0;i<10;i++);
```

- Usar sentido común.
**__Bueno__**:
```cpp
bool flag = true;

if (flag);
```
**__Malo__**:
```cpp
bool flag = true;

if (flag == true); // No es necesario comprobar si algo true es true
```

- Usar buena indentación.
**__Bueno__**:
```cpp
int main() {
    int cont = 2;
    if (cont == 2) {
        return -1;
    }
    return 0;
}
```
**__Malo__**:
```cpp
int main() {
int cont = 2;
if (cont == 2) {
return -1;
}
return 0;
}
```

- Implementar Guard Clauses.
**__Bueno__**:
```cpp
void CreateUser(string userName, string password) {
  if (userName == null)
    throw new NullArgumentException(nameof(userName));
  if (password == null)
    throw new NullArgumentException(nameof(password));
  // Do something...
}
```
**__Malo__**:
```cpp
void CreateUser(string userName, string password) {
  if (userName == null) {
    // Do something...
  } else {
    // Do something else...
    if (password == null) {
      // Do something...
    } else {
      // Do something else...
    }
  }
}
```

- No utilizar efectos secundarios.
**__Bueno__**:
```cpp
int add(int n1, int n2) {
    return n1 + n2;
}
```
**__Malo__**:
```cpp
int add(int n1, int n2) {
    std::cout << n1 + n2 << "\n";
    return n1 + n2;
}
// Las funciones deben de ejecutar solo logica, y no producir efectos secundarios como salida a la pantalla
```
