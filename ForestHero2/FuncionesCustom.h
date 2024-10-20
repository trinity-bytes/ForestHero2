#pragma once
#include "windows.h" // acceder a la api de windows
#include "mmsystem.h" // para playsound
#include "iostream"
#include "random"

#pragma comment(lib, "winmm.lib") // libreria de PlaySound


int GenerarNumeroAleatorio(int m, int n) {
    // Verificar que m sea menor que n
    if (m >= n) {
        std::cerr << "Error: m debe ser menor que n" << std::endl;
        return m;  // Retornar m en caso de error
    }

    // Inicializar el generador de números aleatorios
    static std::mt19937 gen(std::time(0));

    // Crear una distribución uniforme en el rango [m, n]
    std::uniform_int_distribution<> dis(m, n);

    // Generar y retornar el número aleatorio
    return dis(gen);
}

//void reproducirMusicaMenu() {
//    detenerMusica();
//    PlaySound(TEXT("musicaMenuPrincipal.wav"), NULL, SND_ASYNC | SND_LOOP);
//}
//
//void reproducirSommidoSkibididevs() {
//    detenerMusica();
//    PlaySound(TEXT("sonidoSkibidiDevs.wav"), NULL, SND_SYNC);
//}
//
//void reproducirSonidoColisionBasura() {
//    PlaySound(TEXT("sonidoColisionBasura.wav"), NULL, SND_ASYNC);
//}
//
//void detenerMusica() {
//    PlaySound(NULL, 0, 0);  // Detener cualquier sonido en reproducción
//}