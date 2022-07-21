#include <GL/glut.h>
#include <stdlib.h>

#include <iostream>
static int leftFirst = GL_TRUE;

float color1 = 0.75;
float color2 = 0.75;
float color3 = 0.75;

/*  Initialize alpha blending function.
 */
static void init(void) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glShadeModel(GL_FLAT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

static void drawLeftTriangle(void) {
    /* draw yellow triangle on LHS of screen */

    glBegin(GL_TRIANGLES);
    glColor4f(1, 0, 0.0, color1);
    glVertex3f(0.1, 0.9, 0.0);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.7, 0.5, 0.0);
    glEnd();
}

static void drawRightTriangle(void) {
    /* draw cyan triangle on RHS of screen */

    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 0.0, 1.0, color2);
    glVertex3f(0.9, 0.9, 0.0);
    glVertex3f(0.3, 0.5, 0.0);
    glVertex3f(0.9, 0.1, 0.0);
    glEnd();
}
static void drawDownTriangle(void) {
    /* draw yellow triangle on LHS of screen */

    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 1, 0.0, color3);
    glVertex3f(0.1, 0.1, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.9, 0.1, 0.0);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    if (leftFirst) {
        drawLeftTriangle();
        drawRightTriangle();
    } else {
        drawRightTriangle();
        drawLeftTriangle();
    }
    drawDownTriangle();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(0.0, 1.0, 0.0, 1.0 * (GLfloat)h / (GLfloat)w);
    else
        gluOrtho2D(0.0, 1.0 * (GLfloat)w / (GLfloat)h, 0.0, 1.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 't':
        case 'T':
            leftFirst = !leftFirst;
            glutPostRedisplay();
            break;
        case 'a':
            color1 += 0.4;
            glutPostRedisplay();
            break;
        case 's':
            color1 -= 0.4;
            glutPostRedisplay();
            break;
        case 'd':
            color2 += 0.4;
            glutPostRedisplay();
            break;
        case 'f':
            color2 -= 0.4;
            glutPostRedisplay();
            break;
        case 'g':
            color3 += 0.4;
            glutPostRedisplay();
            break;
        case 'h':
            color3 -= 0.4;
            glutPostRedisplay();
            break;
        case 27: /*  Escape key  */
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Exercicio - 03 - Parte 1");
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER)
              << std::endl;

    glutMainLoop();
    return 0;
}
