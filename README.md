# 🔄 Push_swap

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr)
[![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Algorithm](https://img.shields.io/badge/Algorithm-Sorting-brightgreen)](https://github.com/yourusername/push_swap)

> *Un proyecto de algoritmia que desafía la eficiencia: ordenar datos con el mínimo número de operaciones posibles.*

## 🔗 Subject
[Subject](./pushSwapProject.pdf)

## 📋 Tabla de Contenidos
- [🎯 Descripción](#-descripción)
- [⚡ Características](#-características)
- [🛠️ Instalación](#️-instalación)
- [🚀 Uso](#-uso)
- [📊 Operaciones Disponibles](#-operaciones-disponibles)
- [🧠 Algoritmo](#-algoritmo)
- [📈 Pruebas de Rendimiento](#-pruebas-de-rendimiento)
- [🎁 Bonus](#-bonus)
- [🤝 Contribuciones](#-contribuciones)

## 🎯 Descripción

**Push_swap** es un proyecto de la escuela 42 que consiste en ordenar datos en un stack utilizando un conjunto limitado de instrucciones y usando el menor número posible de acciones. El desafío principal es implementar algoritmos eficientes que optimicen el proceso de ordenación.

### El Reto
- **Input**: Una lista de números enteros desordenados
- **Output**: La secuencia más corta de instrucciones para ordenarlos
- **Restricción**: Solo puedes usar operaciones específicas de manipulación de stacks

## ⚡ Características

- ✅ **Algoritmo optimizado** para diferentes tamaños de entrada
- ✅ **Validación completa** de argumentos de entrada
- ✅ **Gestión de errores** robusta
- ✅ **Checker incluido** para verificar la corrección del algoritmo
- ✅ **Cumple con la Norma** de 42
- ✅ **Sin memory leaks**

## 🛠️ Instalación

```bash
# Clonar el repositorio
git clone https://github.com/yourusername/push_swap.git
cd push_swap

# Compilar el proyecto
make

# Compilar con bonus (checker)
make bonus
```

## 🚀 Uso

### Programa Principal
```bash
# Ejecutar push_swap con una lista de números
./push_swap 2 1 3 6 5 8

# Salida esperada:
sa
pb
pb
pb
sa
pa
pa
pa
```

### Verificar con Checker
```bash
# Verificar si la solución es correcta
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG

# Salida esperada: OK
```

### Contar Operaciones
```bash
# Contar el número de operaciones generadas
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

## 📊 Operaciones Disponibles

| Operación | Descripción |
|-----------|-------------|
| `sa` | Intercambia los dos primeros elementos del stack **a** |
| `sb` | Intercambia los dos primeros elementos del stack **b** |
| `ss` | Ejecuta `sa` y `sb` simultáneamente |
| `pa` | Mueve el primer elemento de **b** al top de **a** |
| `pb` | Mueve el primer elemento de **a** al top de **b** |
| `ra` | Rota hacia arriba todos los elementos de **a** |
| `rb` | Rota hacia arriba todos los elementos de **b** |
| `rr` | Ejecuta `ra` y `rb` simultáneamente |
| `rra` | Rota hacia abajo todos los elementos de **a** |
| `rrb` | Rota hacia abajo todos los elementos de **b** |
| `rrr` | Ejecuta `rra` y `rrb` simultáneamente |

## 🧠 Algoritmo

Mi implementación utiliza una estrategia híbrida optimizada basada en el análisis de [este artículo](https://medium.com/@ayogun/push-swap-c1f5d2d41e97):

### Estrategia por Tamaño

- **≤ 3 elementos**: Algoritmo de fuerza bruta optimizado
- **≤ 5 elementos**: Algoritmo específico con pre-ordenación
- **> 5 elementos**: Algoritmo de chunks/bloques con optimizaciones

### Optimizaciones Implementadas

1. **Análisis de costos**: Calcula el costo de mover cada elemento
2. **Movimientos combinados**: Utiliza operaciones simultáneas (`rr`, `rrr`, `ss`)
3. **Estrategia de chunks**: Divide los datos en bloques para reducir operaciones
4. **Heurísticas inteligentes**: Toma decisiones basadas en el estado actual

## 📈 Pruebas de Rendimiento

### Objetivos del Proyecto

| Cantidad | Operaciones Máximas | Estado |
|----------|-------------------|--------|
| 3 números | ≤ 3 operaciones | ✅ |
| 5 números | ≤ 12 operaciones | ✅ |
| 100 números | < 700 operaciones | ✅ |
| 500 números | < 5500 operaciones | ✅ |

### Resultados Promedio

```bash
# Ejemplo de testing
python3 test_push_swap.py 100 100  # 100 tests con 100 números
Average: 645 operations
Max: 687 operations
Min: 598 operations
```

## 🎁 Bonus

### Checker Program

El programa `checker` verifica si una secuencia de operaciones ordena correctamente el stack:

```bash
./checker 3 2 1 0
rra
pb
sa
rra
pa
# Salida: OK
```

**Funcionalidades del Checker:**
- ✅ Lee operaciones desde stdin
- ✅ Valida la corrección de la secuencia
- ✅ Manejo completo de errores
- ✅ Retroalimentación clara (OK/KO/Error)

## 🤝 Contribuciones

Este proyecto fue desarrollado como parte del curriculum de 42 Málaga. Si encuentras algún bug o tienes sugerencias de mejora, no dudes en:

1. 🍴 Hacer fork del proyecto
2. 🌟 Crear una branch para tu feature
3. 📝 Commit tus cambios
4. 🚀 Push a la branch
5. 🔄 Abrir un Pull Request

## 📚 Recursos Útiles

- [Push_swap Tutorial](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Guía detallada del algoritmo
- [42 Docs](https://harm-smits.github.io/42docs/) - Documentación no oficial de 42
- [Visualizador Push_swap](https://github.com/o-reo/push_swap_visualizer) - Tool para visualizar el algoritmo

---

<div align="center">

*Si este proyecto te fue útil, considera darle una ⭐*

</div>
