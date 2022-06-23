#include <GL/glut.h>  // a glut inclui a gl.h

#include <cmath>
#include <iostream>
#define PI 3.14159265359

struct PontoXY {
    GLfloat x;
    GLfloat y;
};
void circulo(int raio, int x, int y, int min = 0, int max = 360) {
    float theta;
    for (int i = min; i < max; i++) {
        theta = i * PI / (max / 2);
        glVertex2f(x + raio * cos(theta), y + raio * sin(theta));
    }
}
void parede() {
    PontoXY P1, P2, P3, P4;
    P1.x = P1.y = P2.x = P4.y = 5;
    P2.y = P3.x = P3.y = P4.x = 495;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void porta() {
    PontoXY P1, P2, P3, P4;
    P1.x = P2.x = 25;
    P1.y = P4.y = 5;
    P2.y = P3.y = 10;
    P3.x = P4.x = 70;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void janela() {
    PontoXY P1, P2, P3, P4;
    P1.x = P2.x = 205;
    P1.y = P4.y = 495;
    P2.y = P3.y = 490;
    P3.x = P4.x = 295;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void cama() {
    PontoXY P1, P2, P3, P4;

    P1.x = P2.x = 290;
    P1.y = P4.y = 320;
    P2.y = P3.y = 425;
    P3.x = P4.x = 480;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void travesseiro() {
    PontoXY P1, P2, P3, P4, P5;

    P1.x = P2.x = 440;
    P1.y = P4.y = 330;
    P2.y = P3.y = 415;
    P3.x = P4.x = 470;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void mesa() {
    PontoXY P1, P2, P3, P4;
    P1.x = P2.x = 5;
    P1.y = P4.y = 250;
    P2.y = P3.y = 470;
    P3.x = P4.x = 100;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
}
void criadoMudo() {
    PontoXY P1, P2, P3, P4;
    P1.x = P2.x = 450;
    P1.y = P4.y = 250;
    P2.y = P3.y = 300;
    P3.x = P4.x = 495;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();
    glBegin(GL_POLYGON);
    circulo(2.1, 448, 275);
    glEnd();
}
void guardaRoupas() {
    PontoXY P1, P2, P3, P4;

    P1.x = P2.x = 270;
    P1.y = P4.y = 10;
    P2.y = P3.y = 40;
    P3.x = P4.x = 480;

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);

    glVertex2f(P1.x, P1.y);
    glVertex2f(P2.x, P2.y);
    glVertex2f(P3.x, P3.y);
    glVertex2f(P4.x, P4.y);
    glEnd();

    glBegin(GL_POLYGON);
    circulo(2.1, 322, 42);
    glEnd();

    glBegin(GL_POLYGON);
    circulo(2.1, 427, 42);
    glEnd();
}
void RenderScene() {
    // Limpa a janela com a cor especificada como cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);
    parede();
    porta();
    janela();
    cama();
    travesseiro();
    mesa();
    criadoMudo();
    guardaRoupas();
    // Flush dos comandos de desenho que estejam no "pipeline" da OpenGL
    // para conclusao da geracao da imagem
    glFlush();
}

// Inicializa aspectos do rendering
void SetupRC() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // cor de fundo da janela
    gluOrtho2D(0, 500, 0, 500);
}
// Parte principal - ponto de inicio de execucao
// Cria janela
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Especifica a funcao de callback de desenho
int main(int argc, char* argv[]) {
    // Procedimento de inicializacao da GLUT
    glutInit(&argc, argv);

    // Indica que deve ser usado um unico frame buffer e representacao de cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);

    // Cria uma janela com o titulo especificado
    glutCreateWindow("Exercicio-01");

    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
    glutDisplayFunc(RenderScene);

    // Executa a inicializacao de parametros de exibicao
    SetupRC();

    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER)
              << "'.\nExtensoes disponiveis: " << glGetString(GL_EXTENSIONS) << std::endl;

    // Entra no loop de tratamento de eventos da GLUT
    glutMainLoop();
    return 0;
}
