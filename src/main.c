#include <jogo.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DISTANCIA_DA_TELA 20
#define LARGURA_JODADOR 15
#define ALTURA_JOGADOR 100

#define VELOCIDADE_JOGADOR 5
#define VELOCIDADE_BOLA 1

int placar_0 = 0, placar_1 = 0;
int bola_x, bola_y, bola_dx, bola_dy;

int jogador_0_pos, jogador_1_pos;

void inicia_jogadores() {
    jogador_0_pos = jogador_1_pos = largura_janela / 2;
}

void processa_jodares() {

    const int limite_inferior = altura_janela - ALTURA_JOGADOR;
    const int limite_superior = 0;

    jogador_0_pos += VELOCIDADE_JOGADOR * (tecla_pressionada('S') - tecla_pressionada('W'));
    jogador_1_pos += VELOCIDADE_JOGADOR * (tecla_pressionada(BAIXO) - tecla_pressionada(CIMA));

    if (jogador_0_pos < limite_superior) jogador_0_pos = limite_superior;
    else if (jogador_0_pos > limite_inferior) jogador_0_pos = limite_inferior;

    if (jogador_1_pos < limite_superior) jogador_1_pos = limite_superior;
    else if (jogador_1_pos > limite_inferior) jogador_1_pos = limite_inferior;

}

void inicia_bola() {

    bola_x = largura_janela / 2;
    bola_y = altura_janela / 2;

    bola_dx = 1 - ((rand() & 1) << 1);
    bola_dy = 1 - ((rand() & 1) << 1);

}

void processa_bola() {

    bola_x += bola_dx;
    bola_y += bola_dy;

    if (bola_y < 0 || bola_y > altura_janela) {
        bola_dy *= -1;
        recomeca_som("assets/bip.wav");
    }

    if (bola_x < 0) {
        placar_1++;
        inicia_bola();
        recomeca_som("assets/coin.wav");
    }

    else if (bola_x > largura_janela) {
        placar_0++;
        inicia_bola();
        recomeca_som("assets/coin.wav");
    }

    if (
        (
            bola_y >= jogador_0_pos && bola_y <= jogador_0_pos + ALTURA_JOGADOR &&\
            bola_x <= DISTANCIA_DA_TELA + LARGURA_JODADOR && bola_x > DISTANCIA_DA_TELA
        ) || (
            bola_y >= jogador_1_pos && bola_y <= jogador_1_pos + ALTURA_JOGADOR &&\
            bola_x >= largura_janela - DISTANCIA_DA_TELA - LARGURA_JODADOR && bola_x < largura_janela - DISTANCIA_DA_TELA
        )
    ) {
        bola_dx *= -1;
        recomeca_som("assets/bip.wav");
    }

}

int main() {

    abre_janela(640, 480);

    srand(time(NULL));

    inicia_bola();
    inicia_jogadores();

    while (janela_esta_aberta()) {

        fonte("assets/ubuntu.ttf", 20);
        desenha_texto(largura_janela / 2, DISTANCIA_DA_TELA, "PONG");

        desenha_texto(DISTANCIA_DA_TELA, DISTANCIA_DA_TELA, "%d", placar_0);
        desenha_texto(largura_janela - DISTANCIA_DA_TELA, DISTANCIA_DA_TELA, "%d", placar_1);

        processa_jodares();
        processa_bola();

        desenha_retangulo(
            DISTANCIA_DA_TELA,
            jogador_0_pos,
            LARGURA_JODADOR,
            ALTURA_JOGADOR
        );

        desenha_retangulo(
            largura_janela - DISTANCIA_DA_TELA - LARGURA_JODADOR,
            jogador_1_pos,
            LARGURA_JODADOR,
            ALTURA_JOGADOR
        );

        desenha_circulo(bola_x, bola_y, 10);

        if (tecla_acabou_de_ser_apertada(ESC))
            janela_deve_fechar();

    }

    fecha_janela();

}