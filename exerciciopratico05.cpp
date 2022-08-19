// Luiz Carlos Bessa de Lima - 201821256

#include <GL/glut.h>

#define stripeImageWidth 32
GLubyte stripeImage[4 * stripeImageWidth];

static GLuint nomeTexto;

void makeStripeImage(void) {
    int j;

    for (j = 0; j < stripeImageWidth; j++) {
        stripeImage[4 * j] = (GLubyte)((j <= 4) ? 255 : 0);
        stripeImage[4 * j + 1] = (GLubyte)((j > 4) ? 255 : 0);
        stripeImage[4 * j + 2] = (GLubyte)0;
        stripeImage[4 * j + 3] = (GLubyte)255;
    }
}

static GLfloat xequalzero[] = {1.0, 0.0, 0.0, 0.0};
static GLfloat slanted[] = {1.0, 1.0, 1.0, 0.0};
static GLfloat* currentCoeff;
static GLenum currentPlane;
static GLint currentGenMode;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_SMOOTH);

    makeStripeImage();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glGenTextures(1, &nomeTexto);
    glBindTexture(GL_TEXTURE_1D, nomeTexto);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage1D(GL_TEXTURE_1D, 0, GL_RGBA, stripeImageWidth, 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, stripeImage);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    currentCoeff = xequalzero;
    currentGenMode = GL_OBJECT_LINEAR;
    currentPlane = GL_OBJECT_PLANE;
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, currentGenMode);
    glTexGenfv(GL_S, currentPlane, currentCoeff);

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_1D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glMaterialf(GL_FRONT, GL_SHININESS, 64.0);
}

GLfloat anguloX = -45.0f;
GLfloat anguloY = 30.0f;

void RenderScene(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glBindTexture(GL_TEXTURE_1D, nomeTexto);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.4f);
    glVertex3f(0.2f, 0.3f, 0.0f);
    glVertex3f(0.2f, 0.3f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.0f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0.4f, 0.0f, 0.4f);
    glVertex3f(0.4f, 0.2f, 0.4f);
    glEnd();

    glFlush();
}

void ChangeSize(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, width / height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(anguloY, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloX, 0.0f, 1.0f, 0.0f);
}

void keyboardEvent(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            anguloX += 10;
            break;
        case GLUT_KEY_RIGHT:
            anguloX -= 10;
            break;
        case GLUT_KEY_DOWN:
            anguloY -= 10;
            break;
        case GLUT_KEY_UP:
            anguloY += 10;
            break;
    }
    if (anguloX == -360) anguloX = 0;
    if (anguloY == -360) anguloY = 0;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(anguloY, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloX, 0.0f, 1.0f, 0.0f);
    RenderScene();
}

GLfloat pressionadoX;
GLfloat pressionadoY;
GLfloat pressionaX = anguloX;
GLfloat pressionaY = anguloY;

void cliqueMouse(int button, int state, int x, int y) {
    if (button != GLUT_LEFT_BUTTON) return;

    if (state == GLUT_DOWN) {
        pressionadoX = x;
        pressionadoY = y;
        pressionaX = anguloX;
        pressionaY = anguloY;
    }
}

void rotacaoMouse(int x, int y) {
    anguloX = pressionaX + ((x - pressionadoX) / 3.0) * 1.5;
    anguloY = pressionaY + ((y - pressionadoY) / 3.0) * 1.5;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -3.0f);
    glRotatef(anguloY, 1.0f, 0.0f, 0.0f);
    glRotatef(anguloX, 0.0f, 1.0f, 0.0f);
    RenderScene();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Exercicio - 05");
    glutSpecialFunc(keyboardEvent);
    glutMouseFunc(cliqueMouse);
    glutMotionFunc(rotacaoMouse);
    init();
    glutDisplayFunc(RenderScene);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();
    return 0;
}
