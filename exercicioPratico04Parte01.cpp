#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <iostream>

static int x0, x1, y0, y1;
static bool para = false;

void waiting(int n) {
    glutPostRedisplay();
    if (!para)
        glutTimerFunc(1000, waiting, 0);
}

void algoritmo_bresenham(int x0, int x1, int y0, int y1) {
    int dX = x1 - x0,
        dY = y1 - y0,
        ix = 1, iy = 1,
        e, x, y, i;

    if (dX < 0) {
        ix = -ix;
    }
    if (dY < 0) {
        iy = -iy;
    }

    dX = abs(dX);
    dY = abs(dY);

    x = x0;
    y = y0;
    if (dX > dY) {
        e = (dY << 1) - dX;
        glBegin(GL_POINTS);
        for (i = 0; i < dX; i++) {
            glVertex2i(x, y);

            if (e < 0) {
                e += dY << 1;
            } else {
                y += iy;
                e += (dY - dX) << 1;
            }

            x += ix;
        }
        glEnd();
    } else {
        e = (dX << 1) - dY;
        glBegin(GL_POINTS);
        for (i = 0; i < dY; i++) {
            glVertex2i(x, y);

            if (e < 0) {
                e += dX << 1;
            } else {
                x += ix;
                e += (dX - dY) << 1;
            }

            y += iy;
        }
        glEnd();
    }
}

void display(void) {
    glColor3f(1, 0, 0);
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 700.0, 0.0, 700.0);

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        default:
            if (!para) {
                para = true;
            } else {
                para = false;
            }
            glutPostRedisplay();

            break;
    }
}

void idle(void) {
    srand(time(NULL));
    x0 = rand() % 700;
    x1 = rand() % 700;
    y0 = rand() % 700;
    y1 = rand() % 700;

    if (!para) {
        waiting(0);
        algoritmo_bresenham(x0, x1, y0, y1);
    }

    display();
}

int main(int argc, char** argv) {
    srand((unsigned int)time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("Exercicio - 04 - Parte 1");
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    // Escrever informacoes sobre a versao de OpenGL em uso porque pode ser util saber.
    std::cout << "Usando OpenGL '" << glGetString(GL_VERSION) << "' implementado por '"
              << glGetString(GL_VENDOR) << "' em arquitetura '" << glGetString(GL_RENDERER)
              << std::endl;

    glutMainLoop();
    return 0;
}