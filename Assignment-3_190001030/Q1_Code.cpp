// KULDEEP SINGH
// 190001030

#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

vector<pair<int, int>> Bresenham_Points;
vector<pair<int, int>> Midpoint_Algo_Points;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // X-axis and Y-axis
    glColor3f(0, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(0, -50);
    glVertex2f(0, 50);

    glVertex2f(-50, 0);
    glVertex2f(50, 0);
    glEnd();

    // BRESENHAM ALGORITHM - Red points denotes to Bresenham
    glPointSize(10);
    glBegin(GL_POINTS);
    for (auto point : Bresenham_Points)
    {
        glColor3f(1, 0, 0);
        glVertex2f(point.first, point.second);
    }
    glEnd();
    // glPointSize(3);
    // glBegin(GL_LINE_STRIP);
    // for (auto point : Bresenham_Points)
    // {
    //     glColor3f(1, 0, 0);
    //     glVertex2f(point.first, point.second);
    // }
    // glEnd();

    // MID-POINT ALGORITHM - White points with white strip denotes to Mid-point algo
    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto point : Midpoint_Algo_Points)
    {

        glColor3f(1, 1, 1);
        glVertex2f(point.first, point.second);
    }
    glEnd();
    glPointSize(2);
    glBegin(GL_LINE_STRIP);
    for (auto point : Midpoint_Algo_Points)
    {
        glColor3f(1, 1, 1);
        glVertex2f(point.first, point.second);
    }
    glEnd();

    glFlush();
}

int main(int C, char *V[])
{
    int x1, y1, xn, yn;
    int a1, a2, b1, b2;

    cout << "Enter initial & final points. (Ex: x1, y1, xn, yn)\n";
    cin >> x1 >> y1;
    cin >> xn >> yn;

    if (x1 > xn)
    {
        swap(x1, xn);
        swap(y1, yn);
    }
    else if (x1 == xn)
    {
        cout << " A straight line will be drawn parallel to the y-axis. Do you want to keep going? y or n" << endl;
        char ch;
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            for (int yi = min(y1, yn); yi <= max(y1, yn); yi++)
            {
                int xi = x1;
                Bresenham_Points.push_back({xi, yi});
                Midpoint_Algo_Points.push_back({xi, yi});
            }

            glutInit(&C, V);
            glutInitWindowPosition(400, 400);
            glutInitWindowSize(600, 600);
            glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
            glutCreateWindow("BRESENHAM & MID-POINT - Line Drawing Algos");
            glClearColor(0, 0, 0, 0);
            glutDisplayFunc(Display);
            gluOrtho2D(-50, 50, -50, 50);
            glutMainLoop();
        }

        return 0;
    }

    // Bresenham Method
    a1 = x1, a2 = xn, b1 = y1, b2 = yn;
    int dy = yn - y1, dx = xn - x1;
    //  if |m|<=1
    if (dx >= dy)
    {
        int pi = 2 * dy - dx; // to see if yi should be increased
        Bresenham_Points.push_back({x1, y1});
        int yi = y1;
        for (int xi = x1 + 1; xi <= xn; xi++)
        {
            if (pi >= 0)
            {
                yi = yi + 1;
                pi = pi + 2 * dy - 2 * dx;
            }
            else if (pi < 0)
            {
                pi = pi + 2 * dy;
            }
            Bresenham_Points.push_back({xi, yi});
        }
    } // if |m|>1 : x and y can be swapped
    else
    {
        swap(dx, dy);
        swap(x1, y1);
        swap(xn, yn);
        if (x1 > xn)
        {
            swap(x1, xn);
            swap(y1, yn);
        }
        dx = xn - x1;
        dy = yn - y1;

        int pi = 2 * dy - dx; // p0;
        Bresenham_Points.push_back({y1, x1});
        int yi = y1;
        for (int xi = x1 + 1; xi <= xn; xi++)
        {
            if (pi >= 0)
            {
                yi = yi + 1;
                pi = pi + 2 * dy - 2 * dx;
            }
            else if (pi < 0)
            {
                pi = pi + 2 * dy;
            }
            Bresenham_Points.push_back({yi, xi});
        }
    }

    // Mid Point Line drawing algorithm
    x1 = a1, xn = a2, y1 = b1, yn = b2;
    //  if |m|<=1
    dx = xn - x1;
    dy = yn - y1;

    if (dx >= dy)
    {
        double di = dy - dx / 2.0; // to determine the position of the midpoint
        int yi = y1;
        Midpoint_Algo_Points.push_back({x1, y1});
        for (int xi = x1 + 1; xi <= xn; xi++)
        {
            if (di >= 0)
            {
                yi = yi + 1.0;
                di = di + dy - dx;
            }
            else if (di < 0)
            {
                di = di + dy;
            }
            Midpoint_Algo_Points.push_back({xi, yi});
        }
    }
    // if |m|>1 : x and y can be swapped
    else
    {
        swap(dx, dy);
        swap(x1, y1);
        swap(xn, yn);
        if (x1 > xn)
        {
            swap(x1, xn);
            swap(y1, yn);
        }
        if (x1 > xn)
        {
            swap(x1, xn);
            swap(y1, yn);
        }
        dx = xn - x1;
        dy = yn - y1;
        double di = dy - dx / 2.0;
        int yi = y1;
        Midpoint_Algo_Points.push_back({y1, x1});
        for (int xi = x1 + 1; xi <= xn; xi++)
        {
            if (di >= 0)
            {
                yi = yi + 1.0;
                di = di + dy - dx;
            }
            else if (di < 0)
            {
                di = di + dy;
            }
            Midpoint_Algo_Points.push_back({yi, xi});
        }
    }
    glutInit(&C, V);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("BRESENHAM & MID-POINT - Line Drawing Algos");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(Display);
    gluOrtho2D(-50, 50, -50, 50);
    glutMainLoop();
}
