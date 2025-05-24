# ForestHero2 🌲🎮

## Descripción

ForestHero2 es un juego 2D desarrollado en **C++** con **C++/CLI** y **Windows Forms**. El objetivo principal del juego es controlar a un guardián del bosque para protegerlo y reforestarlo. El jugador deberá recolectar semillas y agua, plantar árboles y enfrentarse a enemigos para mantener el bosque saludable y alcanzar el mayor puntaje posible.

## 📜 Índice

*   [Descripción](#descripción)
*   [Índice](#-índice)
*   [Características](#-características)
*   [Tecnologías Utilizadas](#-tecnologías-utilizadas)
*   [Cómo Jugar](#-cómo-jugar)
*   [Cómo Compilar y Ejecutar](#-cómo-compilar-y-ejecutar)
*   [Contribuidores](#-contribuidores)
*   [Créditos](#-créditos)

## ✨ Características

*   **Jugabilidad Dinámica:** Controla al Guardián del Bosque en un entorno desafiante.
*   **Recolección y Gestión de Recursos:** Junta semillas y agua, esenciales para la reforestación.
*   **Mecánica de Reforestación:** Planta árboles para recuperar el bosque y ganar puntos.
*   **Sistema de Combate:** Enfréntate a enemigos que amenazan la salud del bosque.
*   **Power-Ups y Coleccionables:** Encuentra ítems como corazones (vidas extra) y ten cuidado con la basura.
*   **Aliados:** En momentos difíciles, un aliado podría aparecer para ayudarte.
*   **Puntuación y Tiempo:** Lucha contra el reloj y consigue la máxima puntuación.
*   **Interfaz Gráfica Amigable:**
    *   Menú Principal intuitivo.
    *   Pantalla de Juego con información vital (vidas, puntos, tiempo, etc.).
    *   Secciones de Instrucciones y Créditos.
    *   Pantallas de Victoria y Derrota.
*   **Experiencia Auditiva:**
    *   Música para el menú principal.
    *   Música ambiental durante el juego.
    *   Música especial para el clímax del juego.
    *   Sonidos de victoria y derrota.

## 🛠️ Tecnologías Utilizadas

*   **Lenguaje de Programación:** C++ (compilado con C++14)
*   **Interfaz Gráfica:** C++/CLI y Windows Forms (System::Windows::Forms)
*   **Gestión de Gráficos:** System::Drawing (Bitmap, Graphics, BufferedGraphics)
*   **Manejo de Archivos:** `fstream` para la persistencia de puntuaciones.
*   **Sonido:** Probablemente `System::Media::SoundPlayer` o similar para la reproducción de archivos .wav (inferido).

## 🎮 Cómo Jugar

*   **Movimiento:**
    *   `W`: Mover hacia Arriba
    *   `A`: Mover hacia la Izquierda
    *   `S`: Mover hacia Abajo
    *   `D`: Mover hacia la Derecha
*   **Acciones:**
    *   `M`: Plantar un árbol (necesitas semillas y agua).
    *   `P`: Disparar una semilla (si tienes semillas).
*   **Objetivo:**
    *   Recolecta semillas y agua.
    *   Planta árboles para aumentar el porcentaje de reforestación.
    *   Evita o derrota a los enemigos.
    *   No dejes que tus vidas lleguen a cero.
    *   Consigue la mayor cantidad de puntos antes de que se acabe el tiempo o cumplas el objetivo de reforestación.
*   **Pausa (Sugerido):**
    *   `U`: Detener Timers (Pausar el juego)
    *   `Y`: Reactivar Timers (Reanudar el juego)
*   **Salir:**
    *   `Esc`: Cerrar el juego.

## 🚀 Cómo Compilar y Ejecutar

Este proyecto está desarrollado en C++ utilizando C++/CLI y Windows Forms, por lo que se recomienda usar Visual Studio.

1.  **Clona el repositorio (si aplica) o descarga los archivos del proyecto.**
2.  **Abre el archivo de solución (`.sln`)** con Visual Studio.
    *   Si no hay un `.sln`, abre el archivo de proyecto (`.vcxproj`).
3.  **Configura el Entorno:**
    *   Asegúrate de que el proyecto esté configurado para compilar con el estándar C++14.
    *   Verifica que las referencias a ensamblados de .NET (como `System`, `System.Windows.Forms`, `System.Drawing`) estén correctamente configuradas.
4.  **Restaura Dependencias (si aplica):** Si el proyecto usa alguna librería externa gestionada por un administrador de paquetes, restáuralas. (No parece ser el caso según el código visto).
5.  **Selecciona la Configuración de Compilación:**
    *   **Debug:** Para desarrollo y depuración.
    *   **Release:** Para la versión final optimizada.
6.  **Construye la Solución:**
    *   En Visual Studio: `Build > Build Solution` (o presiona `Ctrl+Shift+B`).
7.  **Ejecuta el Proyecto:**
    *   En Visual Studio: `Debug > Start Debugging` (o presiona `F5`) o `Debug > Start Without Debugging` (o presiona `Ctrl+F5`).

*(Por favor, actualiza esta sección con los pasos específicos y cualquier pre-requisito adicional para tu proyecto, como versiones específicas de Visual Studio o SDKs de .NET Framework).*

## 👥 Contribuidores

-  Oscar Lizandro Vasquez Llave
-  Mauricio Teran Zavala

## 🙏 Créditos

*(En desarrollo)*