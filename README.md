# Sistemas-paralelos


Te hago un resumen claro y completo de la **sintaxis básica de C**, incluyendo lo más importante que te suelen pedir en la facu 👇

---

# 🔹 1. Estructura básica de un programa en C

```c
#include <stdio.h>

int main() {
    // código
    return 0;
}
```

* `#include`: importa librerías
* `main()`: punto de entrada
* `return 0;`: indica ejecución correcta

---

# 🔹 2. Variables y tipos de datos

```c
int edad = 20;
float altura = 1.75;
char letra = 'A';
double precio = 99.99;
```

Tipos comunes:

* `int` → enteros
* `float` → decimales
* `double` → decimales más precisos
* `char` → un carácter

---

# 🔹 3. Asignaciones

```c
int a = 5;
a = 10;      // asignación normal
a += 3;      // a = a + 3
a -= 2;
a *= 4;
a /= 2;
```

---

# 🔹 4. Operadores

### Aritméticos

```c
+  -  *  /  %
```

### Relacionales

```c
==  !=  >  <  >=  <=
```

### Lógicos

```c
&&   // AND
||   // OR
!    // NOT
```

---

# 🔹 5. Condicionales

## if

```c
if (edad >= 18) {
    printf("Mayor de edad");
}
```

## if - else

```c
if (edad >= 18) {
    printf("Mayor");
} else {
    printf("Menor");
}
```

## if - else if

```c
if (nota >= 9) {
    printf("Excelente");
} else if (nota >= 6) {
    printf("Aprobado");
} else {
    printf("Desaprobado");
}
```

## switch

```c
switch (opcion) {
    case 1:
        printf("Uno");
        break;
    case 2:
        printf("Dos");
        break;
    default:
        printf("Otro");
}
```

---

# 🔹 6. Bucles (estructuras repetitivas)

## while

```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

## do while

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);
```

## for

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

---

# 🔹 7. Arrays (vectores)

```c
int numeros[5] = {1, 2, 3, 4, 5};

printf("%d", numeros[0]); // acceso
```

También:

```c
int numeros[5];
numeros[0] = 10;
```

---

# 🔹 8. Matrices (arrays multidimensionales)

```c
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Acceso:

```c
printf("%d", matriz[1][2]); // fila 1, columna 2 → 6
```

Recorrido típico:

```c
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matriz[i][j]);
    }
}
```

---

# 🔹 9. Funciones

```c
int suma(int a, int b) {
    return a + b;
}
```

Uso:

```c
int resultado = suma(3, 4);
```

---

# 🔹 10. Entrada y salida

```c
printf("Hola mundo");

int edad;
scanf("%d", &edad);
```

⚠️ Importante:

* `&` → dirección de memoria (muy importante en C)

---

# 🔹 11. Punteros (básico)

```c
int a = 10;
int *p = &a;

printf("%d", *p); // 10
```

* `*p` → valor apuntado
* `&a` → dirección de memoria

---

# 🔹 12. Structs (estructuras)

```c
struct Persona {
    char nombre[50];
    int edad;
};

struct Persona p1;
p1.edad = 20;
```

---

# 🔹 13. Strings

En C no hay tipo string, se usan arrays de `char`:

```c
char nombre[] = "Nahuel";
```

---

# 🔹 14. Comentarios

```c
// una línea

/* múltiples
   líneas */
```

---

# 🔥 Resumen rápido tipo machete

* `if / else / switch` → decisiones
* `for / while / do while` → repetición
* `[]` → arrays
* `[i][j]` → matrices
* `&` → dirección
* `*` → puntero
* `struct` → estructuras

---
