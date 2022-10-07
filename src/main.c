#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    abre_janela(640, 480);
    toca_som_em_loop("assets/awesomeness.wav");

    double fator_zoom = 1;

    while (janela_esta_aberta()) {

        cor(AMARELO);
        preenchimento(false);

        desenha_retangulo(0, 0, 320, 240);

        zoom(mouse_x, mouse_y, fator_zoom);
        desenha_imagem(mouse_x, mouse_y, "assets/tux.png");
        reseta_zoom();

        cor(VERMELHO);
        preenchimento(true);
        desenha_circulo(200, 200, 10);

        fonte("assets/ubuntu.ttf", 32);
        desenha_texto(20, 20, "Esse é um teste!");

        desenha_imagem(320, 240, "assets/guy.gif");

        if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();

        if (botao_mouse_acabou_de_ser_apertado(BOTAO_ESQUERDO))
            toca_som("assets/jump.wav");
        
        fator_zoom += roda_do_mouse * 0.1;

    }

    fecha_janela();

}