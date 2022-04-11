// KULDEEP SINGH
// 190001030

#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

vector<pair<int, int>> poly_points;
vector<pair<int, int>> dda_points;

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

    // Polynomial
    glPointSize(10);
    glBegin(GL_POINTS);
    for (auto pt : poly_points)
    {
        glColor3f(1, 0, 0);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    // glPointSize(3);
    // glBegin(GL_LINE_STRIP);
    // for (auto pt : poly_points)
    // {
    //     glColor3f(1, 0, 0);
    //     glVertex2f(pt.first, pt.second);
    // }
    // glEnd();

    // DDA
    glPointSize(5);
    glBegin(GL_POINTS);
    for (auto pt : dda_points)
    {

        glColor3f(1, 1, 1);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();
    glPointSize(2);
    glBegin(GL_LINE_STRIP);
    // glColor3f(1, 1, 1);
    for (auto pt : dda_points)
    {
        glColor3f(1, 1, 1);
        glVertex2f(pt.first, pt.second);
    }
    glEnd();

    glFlush();
}

int main(int C, char *V[])
{
    int x1, y1, xn, yn;
    cout << "Enter Start & end points. (Ex: x1, y1, xn, yn)\n";
    cin >> x1 >> y1;
    cin >> xn >> yn;

    if (x1 > xn)
    {
        swap(x1, xn);
        swap(y1, yn);
    }
    else if (x1 == xn)
    {
        cout << " Straight line parallel to y-axis will be formed/nDo you want to continue? y or n" << endl;
        char ch;
        cin >> ch;

        if (ch == 'y' || ch == 'Y')
        {
            for (int yi = min(y1, yn); yi <= max(y1, yn); yi++)
            {
                int xi = x1;
                poly_points.push_back({xi, yi});
                dda_points.push_back({xi, yi});
            }
            glutInit(&C, V);
            glutInitWindowPosition(400, 400);
            glutInitWindowSize(500, 500);
            glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
            glutCreateWindow("DDA & POLY - Line Drawing Algos");
            glClearColor(0, 0, 0, 0);
            glutDisplayFunc(Display);
            gluOrtho2D(-50, 50, -50, 50);
            glutMainLoop();
        }
        return 0;
    }

    double intercept = (xn * y1 - yn * x1) / (double)(xn - x1);
    double slope = (double)(yn - y1) / (double)(xn - x1);

    // Polynomial Method
    // if |m|<=1
    // if |m| > 1
    if (abs(slope) > 1)
    {
        for (int xi = x1; xi <= xn; xi++)
        {
            int yi = round(slope * (double)xi + intercept);
            poly_points.push_back({xi, yi});
        }
    } // if |m|>1
      // if |m| <= 1
    else
    {
        if (slope > 0)
        {
            for (int yi = y1; yi <= yn; yi++)
            {
                int xi = round(((double)yi - intercept) / slope);
                poly_points.push_back({xi, yi});
            }
        }
        else
        {
            for (int yi = y1; yi >= yn; yi--)
            {
                int xi = round((yi - intercept) / slope);
                poly_points.push_back({xi, yi});
            }
        }
    }

    // Digital Differential Analyzer Method
    // if |m|<1
    // if |m| > 1
    if (abs(slope) > 1)
    {
        double Prev_yi = y1;
        dda_points.push_back({x1, y1});
        for (int xi = x1 + 1; xi <= xn; xi++)
        {
            int yi = round(slope + (double)Prev_yi);
            Prev_yi = slope + (double)Prev_yi;
            dda_points.push_back({xi, yi});
        }
    }
    else
    {
        double Prev_xi = x1;
        double inv_Slope = 1.0 / slope;
        dda_points.push_back({x1, y1});
        if (slope > 0)
        {
            for (int yi = y1 + 1; yi <= yn; yi++)
            {
                double c = inv_Slope + Prev_xi;
                int xi = round(c);
                Prev_xi = c;
                dda_points.push_back({xi, yi});
            }
        }
        else
        {
            for (int yi = y1 - 1; yi >= yn; yi--)
            {
                double c = -inv_Slope + Prev_xi;
                int xi = round(c);
                Prev_xi = c;
                dda_points.push_back({xi, yi});
            }
        }
    }
    glutInit(&C, V);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("DDA & POLY - Line Drawing Algos (Q2)");
    glClearColor(0, 0, 0, 0);
    glutDisplayFunc(Display);
    gluOrtho2D(-50, 50, -50, 50);
    glutMainLoop();
}