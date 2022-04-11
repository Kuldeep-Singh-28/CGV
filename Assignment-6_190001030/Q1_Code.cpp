// KULDEEP SINGH
// 190001030

#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

// When a key is pressed, this function is called.
bool left_Button = false; // check if Left-Mouse-Button is clicked

double rotateX = 0; // how far have the x and y axes been rotated with the mouse?
double rotateY = 0;
double diff_X = 0.0f; // temp variables
double diff_Y = 0.0f;

float diff_white_light = 0.8; // diffused light intensity
int xl = 0, yl = 0;


//Initializes 3D-rendering
void myinit() {
    glClearColor(0.41, 0.77, 0.91, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); // Allow for smooth shading.

}

// When the window is resized, this function is called.
void manage_Resize(int width, int height) {
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)width / (double)height, 1.0, 800.0);
}

//Draws the 3D house
void display_3DHouse() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -7.0f);
	
    glRotatef(rotateX, 1.0, 0.0, 0.0); // rotate abt x-axis
    glRotatef(rotateY, 0.0, 1.0, 0.0); // rotate abt y-axis

    // GROUND
    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4.0f, -1.5001f, 2.0f);
	glVertex3f(0.0f, -1.5001f, 2.0f);
	glVertex3f(0.0f, -1.5001f, -2.0f);
	glVertex3f(-4.0f, -1.5001f, -2.0f);

    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4.0f, -1.5001f, 2.0f);
	glVertex3f(0.0f, -1.5001f, 2.0f);
	glVertex3f(0.0f, -1.7001f, 2.0f);
	glVertex3f(-4.0f, -1.7001f, 2.0f);

    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4.0f, -1.5001f, -2.0f);
	glVertex3f(0.0f, -1.5001f, -2.0f);
	glVertex3f(0.0f, -1.7001f, -2.0f);
	glVertex3f(-4.0f, -1.7001f, -2.0f);

    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.5001f, -2.0f);
	glVertex3f(-4.0f, -1.5001f, -2.0f);
	glVertex3f(0.0f, -1.7001f, -2.0f);
	glVertex3f(-4.0f, -1.7001f, -2.0f);

	glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.5001f, -2.0f);
	glVertex3f(-4.0f, -1.5001f, -2.0f);
	glVertex3f(0.0f, -1.7001f, -2.0f);
	glVertex3f(-4.0f, -1.7001f, -2.0f);
   
    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -1.500f, 2.0f);
	glVertex3f(0.0f, -1.500f, -2.0f);
	glVertex3f(0.0f, -1.700f, -2.0f);
	glVertex3f(0.0f, -1.700f, 2.0f);
   
    glColor3f(0.39f, 0.41f, 0.44f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-4.0f, -1.500f, 2.0f);
	glVertex3f(-4.0f, -1.500f, -2.0f);
	glVertex3f(-4.0f, -1.700f, -2.0f);
	glVertex3f(-4.0f, -1.700f, 2.0f);


    //******** LEFT part ********

	// left wall	
	glColor3f(0.8f, 1.0f, 0.7f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-3.5f, -1.5f, 1.0f);
	glVertex3f(-1.5f, -1.5f, 1.0f);
	glVertex3f(-1.5f, 0.0f, 1.0f);
	glVertex3f(-3.5f, 0.0f, 1.0f);

	// left window
	glColor3f(0.65f, 0.41f, 0.16f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-2.5f, -1.01f, 1.0001f);
	glVertex3f(-1.99f, -1.01f, 1.0001f);
	glVertex3f(-1.99f, -0.61f, 1.0001f);
	glVertex3f(-2.5f, -0.61f, 1.0001f);


	//******** FRONT part ********

	// Front wall
    glColor3f(1.f, 0.99f, 0.82f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.5f, -1.5f, -1.0f);
	glVertex3f(-1.5f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.5f, 1.0f);

	// Door
	glColor3f(0.65f, 0.41f, 0.16f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.499f, -1.5f, -0.6f);
	glVertex3f(-1.499f, -0.3f, -0.6f);
	glVertex3f(-1.499f, -0.3f, 0.0f);
	glVertex3f(-1.499f, -1.5f, 0.0f);


	// Door noob
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.498f, -0.87f, -0.12f);
	glVertex3f(-1.498f, -0.94f, -0.12f);
	glVertex3f(-1.498f, -0.94f, -0.05f);
	glVertex3f(-1.498f, -0.87f, -0.05f);

	// Front window
	glColor3f(0.65f, 0.41f, 0.16f);
	glBegin(GL_QUADS);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.499f, -1.01f, 0.3f);
	glVertex3f(-1.499f, -0.61f, 0.3f);
	glVertex3f(-1.499f, -0.61f, 0.7f);
	glVertex3f(-1.499f, -1.01f, 0.7f);

	//******** RIGHT part ********
	
	// right wall
	glColor3f(0.8f, 1.0f, 0.9f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.5f, -1.5f, -1.0f);
	glVertex3f(-1.5f, -1.5f, -1.0f);
	glVertex3f(-1.5f, 0.0f, -1.0f);
	glVertex3f(-3.5f, 0.0f, -1.0f);

	//right window
	glColor3f(0.65f, 0.41f, 0.16f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-2.5f, -1.01f, -1.0001f);
	glVertex3f(-1.99f, -1.01f, -1.0001f);
	glVertex3f(-1.99f, -0.61f, -1.0001f);
	glVertex3f(-2.5f, -0.61f, -1.0001f);

	//******** BACK wall ********
	glColor3f(0.8f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glNormal3f(-1.01f, 0.0f, 0.0f);
	glVertex3f(-3.5f, -1.5f, -1.0f);
	glVertex3f(-3.5f, -1.5f, 1.0f);
	glVertex3f(-3.5f, 0.0f, 1.0f);
	glVertex3f(-3.5f, 0.0f, -1.0f);


	//******** Bottom ********
	glColor3f(0.0f, 0.70f, 0.0f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-3.8f, -1.5f, 1.3f);
	glVertex3f(-0.8f, -1.5f, 1.3f);
	glVertex3f(-0.8f, -1.5f, -1.3f);
	glVertex3f(-3.8f, -1.5f, -1.3f);


	//******** ROOF ********
	// left tri
    glColor3f(0.5f, 0.2f, 0.1f);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-3.5f, 0.0f, 1.1f);
	glVertex3f(-1.5f, 0.0f, 1.1f);
	glVertex3f(-2.55f, 1.0f, 0.0f);
	glVertex3f(-2.55f, 1.0f, 0.0f);

	// right tri
	glColor3f(0.5f, 0.2f, 0.3f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.5f, 0.0f, -1.1f);
	glVertex3f(-1.5f, 0.0f, -1.1f);
	glVertex3f(-2.55f, 1.0f, 0.0f);
	glVertex3f(-2.55f, 1.0f, 0.0f);

	// back tri
	glColor3f(0.65f, 0.41f, 0.16f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-3.5f, 0.0f, 1.1f);
	glVertex3f(-3.5f, 0.0f, -1.1f);
	glVertex3f(-2.55f, 1.0f, 0.0f);
	glVertex3f(-2.55f, 1.0f, 0.0f);

	// front tri
	glColor3f(0.5f, 0.2f, 0.2f);
	glBegin(GL_QUADS);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 0.0f, -1.1f);
	glVertex3f(-1.5f, 0.0f, 1.1f);
	glVertex3f(-2.55f, 1.0f, 0.0f);
	glVertex3f(-2.55f, 1.0f, 0.0f);


	glEnd();

	glutSwapBuffers();
}

// respond in response to mouse movement
void mouse_Motion(int curr_X, int curr_Y){
    if (left_Button){
        rotateX = curr_Y - diff_Y;
        rotateY = curr_X - diff_X;
        glutPostRedisplay();
    }
}

// Here we are detecting the mouse button action
void mouse_Func(int button, int state, int curr_X, int curr_Y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        left_Button = true; // set Left Mouse Button true
        diff_X = curr_X - rotateY;
        diff_Y = curr_Y - rotateX;
    }
    else
        left_Button = false;

    // Button 3 is reported by the wheel (scroll up) 
    if (button == 3){
        xl+=0.5;
        yl+=0.5;
        if (state == GLUT_UP) return; // GLUT_UP events that are duplicated are ignored.
        diff_white_light = diff_white_light * 1.1; // Boost the amount of diffused light
        if(diff_white_light > 1) // intensity <= 1
            diff_white_light = 1;
        glutPostRedisplay();
    }
    // Button 4 is reported by the wheel (scroll down)
    if (button == 4){
        xl-=0.5;
        yl-=0.5;
        if (state == GLUT_DOWN) return; // GLUT_DOWN events that are duplicated are ignored.
        diff_white_light = diff_white_light * 0.9; // lowering the intensity of diffused light
        glutPostRedisplay();

    }
}


int main(int argc, char** argv) {
	//Initializing the GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	//here, we creating the window
	glutInitWindowSize(800, 600);

	glutCreateWindow("3D-House | 190001030");
	myinit();

	//Set handler functions
	glutDisplayFunc(display_3DHouse);
	glutReshapeFunc(manage_Resize);

	//Set mouse functions
	glutMouseFunc(mouse_Func);
    glutMotionFunc(mouse_Motion);

	glutMainLoop();
	return 0;
}