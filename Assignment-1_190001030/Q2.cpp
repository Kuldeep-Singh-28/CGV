// KULDEEP SINGH
// 190001030

#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

void display()
{
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Rectangle part of Hut
    glColor3f(1, 0.99, 0.82);
    glBegin(GL_QUADS);
    glVertex2f(-300, -300);
    glVertex2f(300, -300);
    glVertex2f(300, 100);
    glVertex2f(-300, 100);
    glEnd();

    // Top part of Hut
    glColor3f(0.5, 0.2, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2f(-400, 100);
    glVertex2f(400, 100);
    glVertex2f(0, 500);
    glEnd();

    // Left window of Hut
    glColor3f(0.79, 0.91, 0.96);
    glBegin(GL_QUADS);
    glVertex2f(-250, -100);
    glVertex2f(-140, -100);
    glVertex2f(-140, 0);
    glVertex2f(-250, 0);
    glEnd();

    // left window lines
    glColor3f(0.16, 0.4, 0.4);
    glBegin(GL_LINES);
    glVertex2f(-160, 0);
    glVertex2f(-160, -100);

    glVertex2f(-180, 0);
    glVertex2f(-180, -100);

    glVertex2f(-200, 0);
    glVertex2f(-200, -100);

    glVertex2f(-220, 0);
    glVertex2f(-220, -100);

    glVertex2f(-240, 0);
    glVertex2f(-240, -100);
    glEnd();

    // Right window of Hut
    glColor3f(0.79, 0.91, 0.96);
    glBegin(GL_QUADS);
    glVertex2f(140, -100);
    glVertex2f(250, -100);
    glVertex2f(250, 0);
    glVertex2f(140, 0);
    glEnd();

    // Right window lines
    glColor3f(0.16, 0.4, 0.4);
    glBegin(GL_LINES);
    glVertex2f(160, 0);
    glVertex2f(160, -100);

    glVertex2f(180, 0);
    glVertex2f(180, -100);

    glVertex2f(200, 0);
    glVertex2f(200, -100);

    glVertex2f(220, 0);
    glVertex2f(220, -100);

    glVertex2f(240, 0);
    glVertex2f(240, -100);
    glEnd();

    // Door of Hut
    glColor3f(0.65, 0.41, 0.16);
    glBegin(GL_QUADS);
    glVertex2f(-100, -300);
    glVertex2f(100, -300);
    glVertex2f(100, 0);
    glVertex2f(-100, 0);
    glEnd();

    // Door handle
    glPointSize(10);
    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    glVertex2f(80, -150);
    glEnd();

    glFlush();
}

void myinit()
{
    glClearColor(0.53, 0.81, 0.92, 0);
    gluOrtho2D(-600, 600, -600, 600);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // Initialize the init function
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowPosition(100, 100); // set window position
    glutInitWindowSize(600, 600);     // set window size
    glutCreateWindow("HUT");          // set title of window

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
