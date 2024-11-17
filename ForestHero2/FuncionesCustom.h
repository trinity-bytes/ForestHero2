#pragma once
#include "windows.h" // acceder a la api de windows
#include "mmsystem.h" // para playsound
#include "iostream"
#include "random"

#pragma comment(lib, "winmm.lib") // libreria de PlaySound

int GenerarNumeroAleatorio(int m, int n) {
    if (m >= n) {
        return m;  // Retornar m en caso de error
    }

    static std::mt19937 gen(std::time(0));
    std::uniform_int_distribution<> dis(m, n);
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

void detenerMusica() {
    PlaySound(NULL, 0, 0);  // Detener cualquier sonido en reproducción
}

void reproducirMusicaMenu() {
    detenerMusica();
    PlaySound(TEXT("Resources/Sounds/musicaMenu.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void reproducirMusicaUltimoTramo() {
    detenerMusica();
    PlaySound(TEXT("Resources/Sounds/musicaUltimoTramo.wav"), NULL, SND_ASYNC | SND_LOOP);
}

void reproducirMusicaDerrota() {
    detenerMusica();
    PlaySound(TEXT("Resources/Sounds/musicaDerrota.wav"), NULL, SND_ASYNC | SND_LOOP);
}