// KULDEEP SINGH
// 190001030

#include <bits/stdc++.h>
#include <GL/glut.h>
#include "imageio.h"

using namespace std;

/*
To run the program:

1. To create imageio.o file: g++ -c imageio.cpp -ltiff -lpng
2. TO RUN: g++ Q1_Code.cpp -o Q1 -lglut -lGLU -lGL imageio.o -ltiff -lpng

Using keyboard:

r/R 		Reset the cube to initial position
z/x 		Increase/Decrease diffuse intensity
a/s 		Zoom-in/out

Using Mouse:
drag + Rotate the cube + change the direction of rotation
Scrollwheel -> Zoom-in/out

*/

double rotate_x = 0, rotate_y = 0, zoom = 1;

int width, height;

int texImageWidth;
int texImageHeight;

// To load texture image
// Only works with.png and .tif files. If there are any errors, NULL is returned.
GLubyte *makeTexImage(char *file)
{
	int width, height;
	GLubyte *texImage;
	texImage = loadImageRGBA((char *)file, &width, &height);
	texImageWidth = width;
	texImageHeight = height;
	return texImage;
}

// To prints text
// The string is printed with a translation (x, y, z), a scaling factor s, and a rotation of rotate degrees along the y axis.
// To create a bold look, pointsize specifies the width of the line and point.
void Display_Stroke(GLfloat x, GLfloat y, GLfloat z, GLfloat s, GLfloat pointSize, GLfloat rotate, string text)
{
	string buffer = text;
	glPushMatrix();
	glTranslatef(x, y, z);
	glPointSize(pointSize);
	glLineWidth(pointSize);
	glRotatef(rotate, 0.0, 1.0, 0.0);
	glScalef(s, s, s);
	for (auto ch : buffer)
		glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, ch);
	glPopMatrix();
}

// Positions of lights
GLfloat front_left_light_position[] = {-1.0, 0.0, 1.0, 0.0};
GLfloat front_right_light_position[] = {1.0, 0.0, 1.0, 0.0};
GLfloat back_left_light_position[] = {-1.0, 0.0, -1.0, 0.0};
GLfloat back_right_light_position[] = {1.0, 0.0, -1.0, 0.0};

// Material properties
GLfloat yellow_ambient[] = {0.35, 0.26, 0.05, 1.0},
		yellow_diffuse[] = {0.80, 0.60, 0.15, 1.0},
		yellow_specular[] = {0.99, 0.94, 0.85, 1.0},
		yellow_shininess = 28.8;

GLfloat red_ambient[] = {0.2, 0.0, 0.0},
		red_diffuse[] = {0.6, 0.0, 0.0},
		red_specular[] = {0.7, 0.6, 0.6},
		red_shininess = 33.0;

GLfloat green_ambient[] = {0.0225, 0.1745, 0.0225},
		green_diffuse[] = {0.075, 0.61, 0.075},
		green_specular[] = {0.63, 0.73, 0.63},
		green_shininess = 77.8;

float diffuse_intensity = 0.5;
int select_Material = 0;

// Selects what should be displayed on the screen.
void material()
{
	if (select_Material == 0)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, yellow_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellow_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, yellow_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, yellow_shininess);
	}
	if (select_Material == 1)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, green_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, green_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, green_shininess);
	}
	if (select_Material == 2)
	{
		glMaterialfv(GL_FRONT, GL_AMBIENT, red_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, red_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, red_specular);
		glMaterialf(GL_FRONT, GL_SHININESS, red_shininess);
	}
}

// Display cube
void display(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	material(); // selecting material

	GLfloat light_diffuse[] = {diffuse_intensity, diffuse_intensity, diffuse_intensity, 1.0}; // Varing Diffuse light intersity

	// Enabling Lights
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);

	// Cube transformations
	glLoadIdentity();

	// Translate the cube
	glTranslatef(0.0f, 0.0f, 2.0f);

	glRotatef(rotate_y, 0.0, 1.0, 0.0);
	glRotatef(rotate_x, 1.0, 0.0, 0.0);
	glScalef(zoom, zoom, zoom);

	// Printing at front face
	Display_Stroke(-0.15, 0.40, 0.5, 0.0004, 2, 0, "-Front-");
	Display_Stroke(-0.35, 0.25, 0.5, 0.0009, 4, 0, "created");
	Display_Stroke(-0.1, 0.0, 0.5, 0.0009, 4, 0, "by");
	Display_Stroke(-0.45, -0.25, 0.5, 0.0012, 7.5, 0, "Kuldeep");

	// Printing at back face
	Display_Stroke(0.15, 0.40, -0.5, 0.0004, 2, 180, "-Back-");
	Display_Stroke(0.35, 0.25, -0.5, 0.0009, 4, 180, "created");
	Display_Stroke(0.1, 0.0, -0.5, 0.0009, 4, 180, "by");
	Display_Stroke(0.45, -0.25, -0.5, 0.0012, 7.5, 180, "Kuldeep");

	// Eabling Texture Environment
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	// Front
	glBegin(GL_QUADS);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Back
	glBegin(GL_QUADS);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Right
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	// Left
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Top
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	// Bottom
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

// Direction of rotation
int axis_x = 0, axis_y = 0;

// takes action on pressing keyboard key
void SpecialKeys(unsigned char key, int x, int y)
{
	if (key == 'r' or key == 'R')
	{ // Reset
		rotate_x = 0;
		rotate_y = 0;
	}
	if (key == 'z')
	{ // change intensity
		diffuse_intensity += 0.01;
	}
	if (key == 'x')
	{
		diffuse_intensity -= 0.01;
	}
	if (key == 'a' or key == 'A')
	{ // Zoom in/out
		zoom *= 1.021897148;
	}
	if (key == 's' or key == 'S')
	{
		zoom /= 1.021897148;
	}
	diffuse_intensity = min(diffuse_intensity, (float)1.0);
	diffuse_intensity = max(diffuse_intensity, (float)0.0);
	glutPostRedisplay();
}

// when a special keyboard key is pressed, it executes action.
// Rotate the cube (Also change the direction of rotation)       --- Using Keyboard
void keyboardRotate(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
	{
		rotate_y += 5;
		axis_y = 0;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		rotate_y -= 5;
		axis_y = 1;
	}
	if (key == GLUT_KEY_DOWN)
	{
		rotate_x -= 5;
		axis_x = 1;
	}
	if (key == GLUT_KEY_UP)
	{
		rotate_x += 5;
		axis_x = 0;
	}
	glutPostRedisplay();
}

int last_x = 0, last_y = 0;

// Rotate the cube (Also change the direction of rotation) --- Using Mouse
void mouseRotate(int x, int y)
{
	if (x > 600 or y > 600 or x < 0 or y < 0)
		return;
	if (abs(x - last_x) > 25 or abs(y - last_y) > 25)
	{
		last_x = x;
		last_y = y;
		return;
	}
	rotate_x += (last_y - y + 0.0) * 0.5;
	rotate_y += (last_x - x + 0.0) * 0.5;
	if ((last_y - y) > 0)
		axis_x = 0;
	if ((last_y - y) < 0)
		axis_x = 1;
	if ((last_x - x) > 0)
		axis_y = 0;
	if ((last_x - x) < 0)
		axis_y = 1;
	last_x = x;
	last_y = y;

	glutPostRedisplay();
}

// To show Zoom-in/out functionality (Also changed using Scrollwheel)
void mouseZoom(int btn, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (btn == 3)
		{
			zoom *= 1.021897148;
		}
		if (btn == 4)
		{
			zoom /= 1.021897148;
		}
	}
	glutPostRedisplay();
}

// To add Spin motion to the cube
void idleSpinFunc()
{
	if (axis_x == 0)
		rotate_x += 0.2;
	if (axis_x == 1)
		rotate_x -= 0.2;
	if (axis_y == 0)
		rotate_y += 0.2;
	if (axis_y == 1)
		rotate_y -= 0.2;
	glutPostRedisplay();
}

// Loading texture using imageio
void load_texture()
{
	unsigned int texture;
	glGenTextures(1, &texture);
	GLubyte *texImage = makeTexImage((char *)"colorful.png");
	if (!texImage)
	{
		printf("\n[-] Error in reading image \n");
		return;
	}
	glBindTexture(GL_TEXTURE_2D, texture);

	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texImageWidth, texImageWidth, 0, GL_RGBA, GL_UNSIGNED_BYTE, texImage);
	delete texImage;
}

void setupCamera(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);

	/* eye is at (0,0,5) */
	/* center is at (0,0,0) */
	/* Up vector is in positive Y direction */
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Initialize
void myInit()
{

	glClearColor(0.0, 0.1, 0.12, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	glLightfv(GL_LIGHT0, GL_POSITION, front_left_light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, front_right_light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, back_left_light_position);
	glLightfv(GL_LIGHT1, GL_POSITION, back_right_light_position);

	glEnable(GL_LIGHTING);

	// Camera view
	setupCamera(width, height);
}

// When any option in the menu is selected, this method is called.
void choose_Menu(int value)
{
	if (value == 999)
		exit(0);
	select_Material = value;
	glutPostRedisplay();
}

// Create Menu
void create_menu()
{
	glutCreateMenu(choose_Menu);
	glutAddMenuEntry("Yellow", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Quit", 999);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv)
{

	glutInit(&argc, argv);
	glutInitWindowPosition(700, 0); // set window position
	glutInitWindowSize(600, 600);	// set window size
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("3D - CUBE | 190001030"); // set window title

	// To display image
	load_texture();

	myInit();
	create_menu();
	glutDisplayFunc(display);
	glutReshapeFunc(setupCamera);

	// To set funtionalities like zoom-in/out, intensity and reset.
	glutKeyboardFunc(SpecialKeys);
	glutSpecialFunc(keyboardRotate);

	// To drag the cube using mouse
	glutMouseFunc(mouseZoom);
	glutMotionFunc(mouseRotate);

	// To spin the cube
	glutIdleFunc(idleSpinFunc);

	glutMainLoop();
	return 0;
}
