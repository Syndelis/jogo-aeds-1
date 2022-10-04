#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    abre_janela(640, 480);
    toca_som_em_loop("assets/awesomeness.wav");

    while (janela_esta_aberta()) {
        cor(AMARELO);
        desenha_retangulo(0, 0, 320, 240);
        desenha_imagem(mouse_x, mouse_y, "assets/tux.png");

        fonte("assets/ubuntu.ttf", 32);
        desenha_texto(20, 20, "Esse é um teste!");

        desenha_imagem(320, 240, "assets/guy.gif");

        if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO))
            recomeca_som("assets/jump.wav");
        
    }

    fecha_janela();

}