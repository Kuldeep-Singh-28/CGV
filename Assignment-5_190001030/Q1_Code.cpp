// KULDEEP SINGH
// 190001030

#include <GL/gl.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

// Here, initialize the point's input & degree
int Number_Of_Inputs;
vector<pair<int, int>> bound_points;
int Choose_Degree;

// Initialize the border color & interior color
vector<float> Border_Color = {1, 1, 0};
vector<float> Fill_Color = {1, 0, 0};

// Boundary_Fill function used to fill interior color
void Boundary_Fill(int x, int y)
{
    float color[3];
    glReadPixels(x, y, 1.0, 1.0, GL_RGB, GL_FLOAT, color); // Reading the color of single pixel
    vector<float> cmp = {color[0], color[1], color[2]};
    if (cmp != Border_Color && cmp != Fill_Color)
    {

        glColor3f(Fill_Color[0], Fill_Color[1], Fill_Color[2]);
        glBegin(GL_POINTS);
        glVertex2f(x, y);
        glEnd();
        glFlush();

        // 4-neighbourhood approach
        if (Choose_Degree == 0)
        {
            Boundary_Fill(x + 1, y);
            Boundary_Fill(x, y - 1);
            Boundary_Fill(x - 1, y);
            Boundary_Fill(x, y + 1);
        }
        // 8-neighbourhood approach to overcome from diagonal pixel problem
        else
        {
            Boundary_Fill(x + 1, y);
            Boundary_Fill(x + 1, y - 1);
            Boundary_Fill(x, y - 1);
            Boundary_Fill(x - 1, y - 1);
            Boundary_Fill(x - 1, y);
            Boundary_Fill(x - 1, y + 1);
            Boundary_Fill(x, y + 1);
            Boundary_Fill(x + 1, y + 1);
        }
    }
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Here we draw polygon shape
    glLineWidth(3);
    glColor3f(1, 1, 0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < Number_Of_Inputs; i++)
    {
        glVertex2f(bound_points[i].first, bound_points[i].second);
    }
    glEnd();
    glFlush();

    // Filling color in the polygon shape
    int x, y;
    cout << "\nEnter a shape's inner point: ";
    cin >> x >> y;
    Boundary_Fill(x, y);

    glFlush();
}

int main(int C, char *V[])
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
    cout << "\nEnter `0` for a four-neighbourhood area, and `1` for an eight-neighbourhood area: ";
    cin >> Choose_Degree;
    if (Choose_Degree != 0 && Choose_Degree != 1)
    {
        cout << "\nImproper Neighbourhood degree!!!";
        exit(0);
    }

    glutInit(&C, V);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Boundary Filling Algorithm");
    glClearColor(0, 0, 0, 0);
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(draw);
    glutMainLoop();
}
