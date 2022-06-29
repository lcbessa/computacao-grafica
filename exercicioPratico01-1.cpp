#include <GL/glut.h>  // a glut inclui a gl.h

#include <cmath>
#include <cstdlib>  // para usar a funcao exit
#include <iostream>
#define PI 3.14159265359

struct PontoXY {
    GLfloat x;
    GLfloat y;
    GLfloat angulo;
    GLfloat escala;
    // construtor padrao, vai construir o objeto na origem
    PontoXY() {
        x = 0;
        y = 0;
        angulo = 0;
        escala = 1;
    }
    void setPonto(GLfloat x1, GLfloat y1) {
        x = x1;
        y = y1;
        angulo = 0;
        escala = 1;
    }
};
PontoXY vetorDePontos[5];
int pontoMovel = 1;

void quadrilatero(float x, float y, float tamanho, float larguraX, float larguraY) {
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x - (tamanho * larguraX), y + (tamanho * larguraY));
    glVertex2f(x + (tamanho * larguraX), y + (tamanho * larguraY));
    glVertex2f(x + (tamanho * larguraX), y - (tamanho * larguraY));
    glVertex2f(x - (tamanho * larguraX), y - (tamanho * larguraY));
    glEnd();
}
void parede() {
    quadrilatero(0, 0, 0.96, 1, 1);
}
void janela() {
    glPushMatrix();
    glTranslatef(0, 0.947, 0);
    quadrilatero(0, 0, 0.2, 1, 0.06);
    glPopMatrix();
}
void porta() {
    glPushMatrix();
    glTranslatef(-0.800, -0.947, 0);
    quadrilatero(0, 0, 0.2, 0.4, 0.05);
    glPopMatrix();
}
void cama(PontoXY ponto) {
    glPushMatrix();
    glTranslatef(ponto.x, ponto.y, 0.0f);
    glRotatef(ponto.angulo, 0.0f, 0.0f, 1.0);
    glScalef(ponto.escala, ponto.escala, 0.0f);
    quadrilatero(0.551, 0.450, 0.2, 1.85, 0.995);
    quadrilatero(0.814, 0.450, 0.2, 0.300, 0.8);
    glPopMatrix();
}
void mesa(PontoXY ponto) {
    glPushMatrix();
    glTranslatef(ponto.x, ponto.y, 0.0f);
    glRotatef(ponto.angulo, 0.0f, 0.0f, 1.0);
    glScalef(ponto.escala, ponto.escala, 0.0f);
    quadrilatero(-0.745, 0.400, 0.2, 1, 2.2);
    glPopMatrix();
}
void criadoMudo(PontoXY ponto) {
    glPushMatrix();
    glTranslatef(ponto.x, ponto.y, 0.0f);
    glRotatef(ponto.angulo, 0.0f, 0.0f, 1.0);
    glScalef(ponto.escala, ponto.escala, 0.0f);
    quadrilatero(0.830, 0.056, 0.2, 0.5, 0.5);
    glPopMatrix();
}
void guardaRoupas(PontoXY ponto) {
    glPushMatrix();
    glTranslatef(ponto.x, ponto.y, 0.0f);
    glRotatef(ponto.angulo, 0.0f, 0.0f, 1.0f);
    glScalef(ponto.escala, ponto.escala, 0.0f);
    quadrilatero(0.406, -0.853, 0.2, 2, 0.4);
    glPopMatrix();
}
void opcoesMouse(int botao, int estado, int x, int y) {
    if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
        printf("%f , %f\n", -1 + (float)x / (float)(glutGet(GLUT_WINDOW_WIDTH) / 2), +1 - (float)y / (float)(glutGet(GLUT_WINDOW_HEIGHT) / 2));
    }
    glutPostRedisplay();
}
void mostrarMenu() {
    using std::cout;
    cout << "\nDurante a execucao, voce pode usar as seguintes teclas:\n"
         << " v Voltar  os objetos para posição original\n"
         << " a Mover para direita\n"
         << " d Mover para esquerda\n"
         << " w Mover para cima\n"
         << " s Mover para baixo\n"
         << " l Rotacionar para esquerda\n"
         << " r Rotacionar para direita\n"
         << " + Aumentar um objeto\n"
         << " - Diminuir um objeto\n"
         << " 1: Cama\n"
         << " 2: Mesa\n"
         << " 3: Criado-Mudo\n"
         << " 4: Guardas Roupas\n"
         << " ESC: Para sair do programa\n\n";
}
void keyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            vetorDePontos[pontoMovel].x -= 0.1f;
            break;
        case 's':
            vetorDePontos[pontoMovel].y -= 0.1f;
            break;
        case 'd':
            vetorDePontos[pontoMovel].x += 0.1f;
            break;
        case 'w':
            vetorDePontos[pontoMovel].y += 0.1f;
            break;
        case 'r':
            vetorDePontos[pontoMovel].angulo -= 1;
            break;
        case 'l':
            vetorDePontos[pontoMovel].angulo += 1;
            break;
        case '+':
            vetorDePontos[pontoMovel].escala += 0.1;
            break;
        case '-':
            vetorDePontos[pontoMovel].escala -= 0.1;
            break;
        case '1':
            pontoMovel = 1;
            break;
        case '2':
            pontoMovel = 2;
            break;
        case '3':
            pontoMovel = 3;
            break;
        case '4':
            pontoMovel = 4;
            break;
        case 27:
            exit(0);
            break;
    }

    if (vetorDePontos[pontoMovel].y < -1.0f)
        vetorDePontos[pontoMovel].y = -1.0f;

    if (vetorDePontos[pontoMovel].y > 1.0f)
        vetorDePontos[pontoMovel].y = 1.0f;

    if (vetorDePontos[pontoMovel].x < -1.0f)
        vetorDePontos[pontoMovel].x = -1.0f;

    if (vetorDePontos[pontoMovel].x > 1.0f)
        vetorDePontos[pontoMovel].x = 1.0f;

    glutPostRedisplay();
}
// void basic(float x, float y, float angulo, float escala) {
//     glPushMatrix();
//     glTranslatef(x, y, 0.0f);
//     glRotatef(angulo, 0.0f, 0.0f, 1.0);
//     glScalef(escala, escala, 0.0f);
//     glBegin(GL_LINE_LOOP);
//     glColor3f(1.0f, 1.0f, 1.0f);
//     glVertex2f(0 - 0.1f, 0 + 0.1f);
//     glVertex2f(0 + 0.1f, 0 + 0.1f);
//     glVertex2f(0 + 0.1f, 0 - 0.1f);
//     glVertex2f(0 - 0.1f, 0 - 0.1f);
//     glEnd();
//     glPopMatrix();
// }
// void basic2(float x, float y, float angulo, float escala) {
//     glPushMatrix();
//     glTranslatef(x, y, 0.0f);
//     glRotatef(angulo, 0.0f, 0.0f, 1.0);
//     glScalef(escala, escala, 0.0f);

//     glBegin(GL_LINE_LOOP);
//     glColor3f(0.0f, 1.0f, 1.0f);
//     glVertex2f(0 - 0.1f, 0 + 0.1f);
//     glVertex2f(0 + 0.5f, 0 + 0.5f);
//     glVertex2f(0 + 0.5f, 0 - 0.5f);
//     glVertex2f(0 - 0.1f, 0 - 0.1f);
//     glEnd();

//     glBegin(GL_LINE_LOOP);
//     glVertex2f(0 - 0.2f, 0 + 0.2f);
//     glVertex2f(0 + 0.2f, 0 + 0.2f);
//     glVertex2f(0 + 0.2f, 0 - 0.2f);
//     glVertex2f(0 - 0.2f, 0 - 0.2f);
//     glEnd();
//     glPopMatrix();
// }

void renderScene() {
    // Limpa a janela com a cor especificada como cor de fundo
    glClear(GL_COLOR_BUFFER_BIT);

    // basic(vetorDePontos[1].x, vetorDePontos[1].y, vetorDePontos[1].angulo, vetorDePontos[1].escala);

    parede();
    janela();
    porta();
    cama(vetorDePontos[1]);
    mesa(vetorDePontos[2]);
    criadoMudo(vetorDePontos[3]);
    guardaRoupas(vetorDePontos[4]);
    glutPostRedisplay();

    // Flush dos comandos de desenho que estejam no "pipeline" da OpenGL
    // para conclusao da geracao da imagem
    glFlush();
}

// Inicializa aspectos do rendering
// void setupRC() {
//     glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // cor de fundo da janela
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
// }
// Parte principal - ponto de inicio de execucao
// Cria janela
// Inicializa aspectos relacionados a janela e a geracao da imagem
// Especifica a funcao de callback de desenho
int main(int argc, char* argv[]) {
    // Procedimento de inicializacao da GLUT
    glutInit(&argc, argv);

    mostrarMenu();

    // Indica que deve ser usado um unico frame buffer e representacao de cores RGB
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);

    // Cria uma janela com o titulo especificado
    glutCreateWindow("Exercicio-01");

    // Especifica a funcao que vai tratar teclas comuns (letras, numeros)
    glutKeyboardFunc(keyboardFunc);

    glutMouseFunc(opcoesMouse);

    // Especifica para a OpenGL que funcao deve ser chamada para geracao da imagem
    glutDisplayFunc(renderScene);

    // Executa a inicializacao de parametros de exibicao
    // setupRC();

    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER) << std::endl;

    // Entra no loop de tratamento de eventos da GLUT
    glutMainLoop();
    return 0;
}
