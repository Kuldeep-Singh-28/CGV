// KULDEEP SINGH
// 190001030

#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

void display()
{
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // SURFACE FOR BICYCLE
    glColor3f(0.5, 0.35, 0.18);
    glBegin(GL_QUADS);
    glVertex2f(-500, -400);
    glVertex2f(500, -400);
    glVertex2f(400, -150);
    glVertex2f(-400, -150);
    glEnd();

    // CIRCLE
    GLfloat x = -200;
    GLfloat y = -200;
    GLfloat a = 200;
    GLfloat b = -200;
    GLfloat radius = 100;

    int point_count = 1000;

    GLfloat twice_Pi = 20 * PI;

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    for (int i = 0; i < point_count; i++)
    {

        glVertex2f(
            x + (radius * cos(i * twice_Pi / point_count)),
            y + (radius * sin(i * twice_Pi / point_count)));
    }
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < point_count; i++)
    {
        glVertex2f(
            a + (radius * cos(i * twice_Pi / point_count)),
            b + (radius * sin(i * twice_Pi / point_count)));
    }
    glEnd();

    // BICYCLE BODY
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-200, -200);
    glVertex2f(0, -200);
    glVertex2f(200, 0);
    glVertex2f(0, 0);
    glEnd();

    // BICYCLE SEAT
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-25, 0);
    glVertex2f(25, 0);
    glVertex2f(25, 35);
    glVertex2f(-25, 30);
    glEnd();

    // CYCLE VERTICLE LINE
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(0, -200);

    glVertex2f(200, 0);
    glVertex2f(200, -200);
    glEnd();

    // CYCLE HANDLE handle
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
    glVertex2f(195, 50);
    glVertex2f(180, 35);
    glVertex2f(220, -40);
    glVertex2f(240, -20);
    glEnd();

    // CYCLE TIER's centre
    glColor3f(0, 0, 0);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex2f(-200, -200);
    glVertex2f(200, -200);
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

    glutInitWindowPosition(200, 100); // set window position
    glutInitWindowSize(600, 600);     // set window size
    glutCreateWindow("CYCLE");        // set title of window

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
