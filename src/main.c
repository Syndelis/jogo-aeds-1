#include <jogo.h>

int main() {

    abre_janela(640, 480);

    while (janela_aberta()) {

        glBegin(GL_QUADS);
            glColor4f(1, 0, 0, 1);
            glVertex2f(0, 0);
            glVertex2f(0, 240);
            glVertex2f(320, 240);
            glVertex2f(320, 0);
        glEnd();

    }

    fecha_janela();

}