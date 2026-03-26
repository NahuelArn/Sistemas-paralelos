

---

# 🔧 Flags de optimización de GCC

El compilador GCC tiene varios niveles con `-O`:

## 🧩 Niveles principales

| Flag     | Qué hace                                       |
| -------- | ---------------------------------------------- |
| `-O0`    | ❌ Sin optimización (default)                   |
| `-O1`    | ✔ Optimización básica                          |
| `-O2`    | ✔✔ Optimización estándar (recomendada)         |
| `-O3`    | 🚀 Máxima optimización (puede aumentar tamaño) |
| `-Ofast` | ⚠️ Muy agresiva (puede romper precisión IEEE)  |

---

# ⚙️ ¿Qué optimizaciones aplica?

## 🔹 `-O1`

* Eliminación de código muerto
* Optimización de expresiones simples
* Mejora de uso de registros

---

## 🔹 `-O2`

Incluye todo lo anterior +:

* **Loop optimization** (mejora bucles)
* **Inline functions**
* Eliminación de redundancias
* Mejor uso de memoria

💡 Este es el más usado en producción.

---

## 🔹 `-O3`

Incluye todo lo anterior +:

* 🔁 **Loop unrolling** (desenrolla bucles)
* 🧠 **Vectorización (SIMD)**
* 📈 Reordenamiento agresivo

👉 Para multiplicación de matrices, esto impacta MUCHO.

---

## 🔹 `-Ofast`

* Ignora algunas reglas de precisión (IEEE 754)
* Más rápido pero menos seguro

---


---

# 📊 Qué vas a observar (IMPORTANTE)

## 🟢 Ganancia vs sin optimización (`-O0`)

Para matrices grandes (ej: 500x500, 1000x1000):

* `-O1` → ~1.2x a 1.5x más rápido
* `-O2` → ~2x a 4x más rápido
* `-O3` → ~3x a 8x más rápido

💡 En multiplicación de matrices se nota mucho porque:

* Hay MUCHOS bucles anidados
* El compilador optimiza accesos a memoria y CPU

---

## 🔵 Ganancia entre niveles

| Comparación | Mejora típica        |
| ----------- | -------------------- |
| O1 vs O0    | Baja-media           |
| O2 vs O1    | Alta                 |
| O3 vs O2    | Media (a veces poca) |

👉 Importante:

* `O2 → O3` **no siempre mejora mucho**
* A veces incluso puede empeorar (por caché o tamaño de código)

---


---

### ✔ ¿Qué optimizaciones aplica el compilador?

El compilador aplica optimizaciones como:

* Eliminación de código innecesario
* Optimización de bucles
* Inline de funciones
* Vectorización y desenrollado de bucles (en niveles altos)

---

### ✔ ¿Ganancia respecto a sin optimización?

La versión sin optimización (`-O0`) es significativamente más lenta.
Se observan mejoras de hasta **3x–8x** en matrices grandes al usar `-O3`.

---

### ✔ ¿Ganancia entre niveles?

* `-O1` mejora levemente
* `-O2` ofrece la mejor relación rendimiento/estabilidad
* `-O3` puede mejorar más, pero con ganancias menores adicionales

---




































---

# 📊 Tus resultados (ordenados)

| Nivel  | Tiempo (real) |
| ------ | ------------- |
| **O0** | ~0.93 s       |
| **O1** | ~0.10 s       |
| **O2** | ~0.097 s      |
| **O3** | ~0.098 s      |

| Versión | Tiempo        |
| ------- | ------------- |
| O0      | MUY lento     |
| O1      | mejora        |
| O2      | mucho mejor   |
| O3      | el más rápido |
---

# 🔍 ¿Qué observamos?

## 🚀 1. Mejora enorme de O0 → O1

* Pasaste de **0.93 s → 0.10 s**
* 🔥 ≈ **9 veces más rápido**

👉 Esto es lo más importante del experimento

✔ Explicación:

* Se optimizan los bucles
* Mejor uso de CPU
* Se elimina trabajo innecesario

---

## ⚖️ 2. O1 → O2 → O3 casi no cambian

* O1: 0.101 s
* O2: 0.097 s
* O3: 0.098 s

👉 Diferencia mínima

✔ Explicación:

* Ya con O1 el código quedó bastante optimizado
* Tu Raspberry no aprovecha tanto:

  * vectorización avanzada
  * optimizaciones agresivas

---

# 🧠 Interpretación CLAVE 

👉 La mayor ganancia ocurre en los primeros niveles de optimización.

👉 Los niveles más altos:

* agregan optimizaciones más complejas
* pero **no siempre mejoran mucho el rendimiento**

---

# ✍️ Rta

## ✔ ¿Qué optimizaciones aplica el compilador?

El compilador aplica:

* Eliminación de código innecesario
* Optimización de bucles
* Uso eficiente de registros
* Inline de funciones
* En niveles altos, desenrollado de bucles y vectorización

---

## ✔ ¿Cuál es la ganancia respecto a sin optimización?

Se observa una mejora muy significativa:

> El tiempo de ejecución pasa de aproximadamente **0.93 segundos a 0.10 segundos**, lo que representa una mejora de casi **9 veces**.

---

## ✔ ¿Cuál es la ganancia entre niveles?

* De `-O0` a `-O1` hay una mejora muy grande
* De `-O1` a `-O2` la mejora es pequeña
* De `-O2` a `-O3` prácticamente no hay diferencia

Esto indica que las optimizaciones más importantes se aplican en los primeros niveles.

---



