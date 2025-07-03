#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

float angle = 0.0f;
float speed = 1.0f;

void drawRectangle() {
    glBegin(GL_QUADS);
        glVertex3f(-0.15f, -0.15f, 0.0f);
        glVertex3f(-0.15f, 0.15f, 0.0f);
        glVertex3f(0.15f, 0.15f, 0.0f);
        glVertex3f(0.15f, -0.15f, 0.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
        glTranslated(-0.2f, 0.0f, 0.0f);
        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glColor3f(0.0f, 0.5f, 1.0f);
        drawRectangle();
    glPopMatrix();

    glFlush();
}

void update(int value) {
    angle += speed;
    if (angle > 360.0f) angle -= 360.0f;
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotating Shapes");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rotating Shapes");
    glutDisplayFunc(display);
    glutClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutTimerFunc(16, update, 0);
    glutMainLoop();
    return 0;
}
