// KULDEEP SINGH
// 190001030

#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

vector<pair<int, int>> Brehsenham_Circle_Points;
vector<pair<int, int>> Midpoint_Algo_Circle_Points;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // X-axis and Y-axis
    glColor3f(0, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(0, -500);
    glVertex2f(0, 500);

    glVertex2f(-500, 0);
    glVertex2f(500, 0);
    glEnd();

    /**** BRESENHAM ALGORITHM - Red points *****/
    glPointSize(15);
    glBegin(GL_POINTS);
    for (auto pt : Brehsenham_Circle_Points)
    {
        glColor3f(1, 0, 0);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    // glPointSize(3);
    // glBegin(GL_LINE_STRIP);
    // for (auto pt : Brehsenham_Circle_Points)
    // {
    //     glColor3f(1, 0, 0);
    //     glVertex2f(pt.first, pt.second);
    // }
    // glEnd();

    /**** MID-POINT ALGORITHM - White points  ****/
    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto pt : Midpoint_Algo_Circle_Points)
    {

        glColor3f(1, 1, 1);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();

    // glPointSize(2);
    // glBegin(GL_LINE);
    // for (auto pt : Midpoint_Algo_Circle_Points)
    // {
    //     glColor3f(1, 1, 1);
    //     glVertex2f(pt.first, pt.second);
    // }
    // glEnd();

    glFlush();
}

int main(int C, char *V[])
{
    int x1, y1, _radius;
    cout << "Enter X & Y coordinates of start point: ";
    cin >> x1 >> y1;

    cout << "Enter radius of Circle: ";
    cin >> _radius;
    cout << endl;

    /***** Bresenham Method for circle drawing *****/

    int pi = 3 - 2 * _radius; // initial decision parameter
    int x = 0, y = _radius;   // initial points

    Brehsenham_Circle_Points.push_back({0, _radius});
    while (x <= y)
    {
        x++;
        if (pi > 0)
        {
            y--;
            pi = pi + 4 * x - 4 * y + 10;
        }
        else
        {
            pi = pi + 4 * x + 6;
        }
        Brehsenham_Circle_Points.push_back({x, y});
    }
    int N = Brehsenham_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Brehsenham_Circle_Points.push_back({Brehsenham_Circle_Points[i].second, Brehsenham_Circle_Points[i].first});
    }
    N = Brehsenham_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Brehsenham_Circle_Points.push_back({-Brehsenham_Circle_Points[i].first, Brehsenham_Circle_Points[i].second});
    }
    N = Brehsenham_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Brehsenham_Circle_Points.push_back({Brehsenham_Circle_Points[i].first, -Brehsenham_Circle_Points[i].second});
    }
    N = Brehsenham_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Brehsenham_Circle_Points[i].first += x1, Brehsenham_Circle_Points[i].second += y1;
    }

    /***** Mid Point Circle drawing algorithm *****/

    int xi = 0, yi = _radius;
    int _pi = 1 - _radius; // initial decision parameter
    Midpoint_Algo_Circle_Points.push_back({0, _radius});
    while (xi <= yi)
    {
        xi++;
        if (_pi < 0)
        {
            _pi = _pi + 2 * xi + 3;
        }
        else
        {
            yi--;
            _pi = _pi + 2 * xi - 2 * yi + 5;
        }
        Midpoint_Algo_Circle_Points.push_back({xi, yi});
    }
    N = Midpoint_Algo_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Midpoint_Algo_Circle_Points.push_back({Midpoint_Algo_Circle_Points[i].second, Midpoint_Algo_Circle_Points[i].first});
    }
    N = Midpoint_Algo_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Midpoint_Algo_Circle_Points.push_back({-Midpoint_Algo_Circle_Points[i].first, Midpoint_Algo_Circle_Points[i].second});
    }
    N = Midpoint_Algo_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Midpoint_Algo_Circle_Points.push_back({Midpoint_Algo_Circle_Points[i].first, -Midpoint_Algo_Circle_Points[i].second});
    }
    N = Midpoint_Algo_Circle_Points.size();
    for (int i = 0; i < N; i++)
    {
        Midpoint_Algo_Circle_Points[i].first += x1, Midpoint_Algo_Circle_Points[i].second += y1;
    }

    glutInit(&C, V);
    glutInitWindowPosition(500, 100);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("BRESENHAM & MID-POINT - Circle Drawing Algos");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(Display);
    gluOrtho2D(-500, 500, -500, 500);
    glutMainLoop();
}
