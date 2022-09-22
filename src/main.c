#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main() {

    abre_janela(640, 480);

    while (janela_esta_aberta()) {

        cor(0xFFFF00);
        desenha_retangulo(0, 0, 320, 240);

    }

    fecha_janela();

}