// KULDEEP SINGH
// 190001030

#include <GL/glut.h>
#include <GL/glu.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Here, initialize the point's input & degree
int Number_Of_Inputs;
vector<pair<int, int>> bound_points;

// left edges and right edges
int leftEdge[600], rightEdge[600], x, y;

void Fill_Intersection(int x1, int y1, int x2, int y2)
{
    float x, slope;

    if (y1 > y2)
        swap(x1, x2), swap(y1, y2);

    if (y1 == y2)
        slope = (x2 - x1);
    else
        slope = (x2 - x1) / (y2 - y1);

    x = x1;
    for (int y = y1; y <= y2; y++)
    {
        if (x < leftEdge[y])
            leftEdge[y] = x;
        if (x > rightEdge[y])
            rightEdge[y] = x;

        x += slope;
    }
}

void Scanline_Fill()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Here we draw polygon shape
    glLineWidth(4);
    glColor3f(1, 1, 0);
    for (int i = 0; i < 600; i++)
        leftEdge[i] = 600, rightEdge[i] = 0;

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < Number_Of_Inputs; i++)
        glVertex2i(bound_points[i].first, bound_points[i].second);

    glEnd();

    for (int i = 0; i < Number_Of_Inputs; i++)
        Fill_Intersection(bound_points[i].first, bound_points[i].second, bound_points[(i + 1) % Number_Of_Inputs].first, bound_points[(i + 1) % Number_Of_Inputs].second);

    // Filling color in the polygon shape
    for (int y = 0; y < 600; y++)
    {
        for (int x = leftEdge[y]; x < rightEdge[y]; x++)
        {
            glColor3f(1, 0, 0);
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();
        }
    }

    glFlush();
}

int main(int argc, char *argv[])
{
    cout << "Enter the total number of points in the shape: ";
    cin >> Number_Of_Inputs;
    cout << "\n*** Points should be entered in a clockwise direction. ***\n";
    for (int i = 0; i < Number_Of_Inputs; i++)
    {
        int x, y;
        cout << "Point-" << i + 1 << " : ";
        cin >> x >> y;
        bound_points.push_back({x, y});
    }

    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Scan-line Filling Algorithm");
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(Scanline_Fill);
    glutMainLoop();
    return 0;
}
