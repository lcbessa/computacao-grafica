#include <GL/glut.h>
#include <stdlib.h>

#include <iostream>
int shoulder, elbow, hand, dedo1, pontaDedo1, dedo2, pontaDedo2 = 0;

float luzAmbiente[] = {0.0f, 0.0f, 0.0f, 0.0f};
float luzDifusa[] = {0.7f, 0.7f, 0.7f, 1.0f};
float luzEspecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
float posicaoLuz[] = {0.0f, 50.0f, 50.0f, 1.0f};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
}

void iluminacao() {
    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os par�metros da luz de n�mero 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}
bool ativado = true;

void display(void) {
    if (ativado) {
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHTING);
    } else {
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHTING);
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Chama fun��o de ilumina��o
    iluminacao();
    // Cabe�a
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 1.5, 1.0);
    glColor3f(1, 1, 1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Corpo
    glTranslatef(-1, -3.2, 0.0);
    glTranslatef(1.0, 0.0, 0.0);
    glColor3f(1, 1, 1);
    glPushMatrix();
    glScalef(3.0, 5, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Ombro
    glTranslatef(1.5, 1.5, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Cotovelo
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // M�o
    glTranslatef(1, 0.0, 0.0);
    glRotatef((GLfloat)hand, 0, 0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.4, 0.5);
    glutSolidCube(1.0);
    glPopMatrix();

    // Dedo 1
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0.0);
    glRotatef((GLfloat)dedo1, 0, 0, 1.0);
    glColor3f(0, 0, 1);
    glTranslatef(0.2, 0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Ponta do dedo 1
    glTranslatef(0.2, 0, 0.0);
    glRotatef((GLfloat)pontaDedo1, 0, 0, 1.0);
    glColor3f(0, 0, 1);
    glTranslatef(0.2, 0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    // Dedo 2
    glTranslatef(0.2, -0.1, 0.0);
    glRotatef((GLfloat)dedo2, 0, 0, 1.0);
    glColor3f(1, 0, 0);
    glTranslatef(0.2, 0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    // Ponta do dedo 2
    glTranslatef(0.2, 0, 0.0);
    glRotatef((GLfloat)pontaDedo2, 0, 0, 1.0);
    glColor3f(1, 0, 0);
    glTranslatef(0.2, 0, 0.0);
    glPushMatrix();
    glScalef(0.4, 0.1, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(120.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's':  // Bra�o -> sentido hor�rio
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':  // Bra�o -> sentido anti-hor�rio
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':  // Antebra�o -> sentido hor�rio
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':  // Antebra�o -> sentido anti-hor�rio
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'a':  // M�o -> sentido hor�rio
            hand = (hand - 5) % 360;
            glutPostRedisplay();
            break;
        case 'A':  // M�o -> sentido anti-hor�rio
            hand = (hand + 5) % 360;
            glutPostRedisplay();
            break;
        case 'q':  // Dedo 2 -> sentido hor�rio
            dedo2 = (dedo2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'Q':  // Dedo 2 -> sentido anti-hor�rio
            dedo2 = (dedo2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':  // Ponta do dedo 1 -> sentido hor�rio
            pontaDedo2 = (pontaDedo2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'D':  // Ponta do dedo 1 -> sentido anti-hor�rio
            pontaDedo2 = (pontaDedo2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'f':  // Dedo 1 -> sentido hor�rio
            dedo1 = (dedo1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':  // Dedo 1 -> sentido anti-hor�rio
            dedo1 = (dedo1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':  // Ponta do dedo 1 -> sentido hor�rio
            pontaDedo1 = (pontaDedo1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'W':  // Ponta do dedo 1 -> sentido anti-hor�rio
            pontaDedo1 = (pontaDedo1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'i':  // Iluminação
            ativado = !ativado;
            glutPostRedisplay();
            break;
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Exercicio - 03 - Parte 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER)
              << std::endl;

    glutMainLoop();
    return 0;
}
