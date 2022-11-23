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

        preenchimento(true);

        cor(VERMELHO);
        desenha_circulo(200, 200, 10);

        cor(VERDE);
        desenha_circulo(220, 200, 20);

        cor(50, 50, 255);
        desenha_circulo(250, 200, 30);

        cor(180, 20, 160, 127);
        desenha_circulo(300, 200, 40);

        // cor(100, 100); // <-- Erro de compilação! A função cor() só aceita 1, 3 ou 4 parâmetros!
        // cor(100, 100, 100, 100, 100); // <-- Erro de compilação! A função cor() só aceita 1, 3 ou 4 parâmetros!

        cor(BRANCO);

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