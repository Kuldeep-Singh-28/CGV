// KULDEEP SINGH
// 190001030

#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

void display()
{
    // Clear the screen buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Earth
    glColor3f(0.69, 0.53, 0.25);
    glBegin(GL_QUADS);
    glVertex2f(-100, -570);
    glVertex2f(100, -570);
    glVertex2f(90, -540);
    glVertex2f(-90, -540);
    glEnd();

    // Rectangle part of Tree
    glColor3f(0.53, 0.29, 0.17);
    glBegin(GL_QUADS);
    glVertex2f(-50, -550);
    glVertex2f(50, -550);
    glVertex2f(50, 100);
    glVertex2f(-50, 100);
    glEnd();

    // Top layer of Tree
    glColor3f(0.0, 0.62, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-200, 100);
    glVertex2f(200, 100);
    glVertex2f(0, 450);
    glEnd();

    // Middle layer of Tree
    glColor3f(0.0, 0.62, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-300, -100);
    glVertex2f(300, -100);
    glVertex2f(0, 300);
    glEnd();

    // Bottom layer of Tree
    glColor3f(0.0, 0.62, 0.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(-390, -300);
    glVertex2f(390, -300);
    glVertex2f(0, 150);
    glEnd();

    // boundary for tree
    glColor3f(0.16, 0.4, 0.4);
    glBegin(GL_LINES);

    // Vertical lines
    glVertex2f(0, -480);
    glVertex2f(0, -570);

    glVertex2f(-20, -480);
    glVertex2f(-20, -570);

    glVertex2f(-40, -480);
    glVertex2f(-40, -570);

    glVertex2f(-60, -480);
    glVertex2f(-60, -570);

    glVertex2f(-80, -480);
    glVertex2f(-80, -570);

    glVertex2f(-100, -480);
    glVertex2f(-100, -570);

    glVertex2f(20, -480);
    glVertex2f(20, -570);

    glVertex2f(40, -480);
    glVertex2f(40, -570);

    glVertex2f(60, -480);
    glVertex2f(60, -570);

    glVertex2f(80, -480);
    glVertex2f(80, -570);

    glVertex2f(100, -480);
    glVertex2f(100, -570);

    glVertex2f(-55, -450);
    glVertex2f(-55, -540);

    glVertex2f(-70, -450);
    glVertex2f(-70, -540);

    glVertex2f(-90, -450);
    glVertex2f(-90, -540);

    glVertex2f(55, -450);
    glVertex2f(55, -540);

    glVertex2f(70, -450);
    glVertex2f(70, -540);

    glVertex2f(90, -450);
    glVertex2f(90, -540);

    // horizontal line
    glVertex2f(-100, -570);
    glVertex2f(100, -570);
    glVertex2f(-100, -480);
    glVertex2f(100, -480);

    // line in range of -90,50 & 50,90
    glVertex2f(-90, -540);
    glVertex2f(-50, -540);
    glVertex2f(90, -540);
    glVertex2f(50, -540);
    glVertex2f(-90, -450);
    glVertex2f(-50, -450);
    glVertex2f(90, -450);
    glVertex2f(50, -450);

    // Angled line
    glVertex2f(-100, -570);
    glVertex2f(-90, -540);
    glVertex2f(90, -540);
    glVertex2f(100, -570);
    glVertex2f(-100, -480);
    glVertex2f(-90, -450);
    glVertex2f(90, -450);
    glVertex2f(100, -480);

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
    glutCreateWindow("TREE");         // set title of window

    myinit();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
