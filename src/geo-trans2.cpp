// Compile: g++ <filename>.cpp -lfreeglut -lopengl32 -lglu32 -o <exename>

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "inc/poly2.h"
#include "inc/titik2.h"
void transform(std::string cmd);

// Globals
Poly2 polygon(1);

void render(void)	{ /* function called whenever redisplay needed */
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT); // clear the drawing buffer.
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glBegin(GL_POLYGON); {
		glColor3f(1.0f, 0.0f, 0.0f);
		for (int i = 0; i < polygon.getEdge(); i++) {
			glVertex2f(polygon.getCorner(i).getX(), polygon.getCorner(i).getY());
		}
	} glEnd();
	// Garis-garis sumbu
	glBegin(GL_LINES); { // Sumbu X, merah
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f(-500.0, 0.0);
		glVertex2f(500.0, 0.0);
		glVertex2f(500.0, 0.0);
		glVertex2f(490.0, 10.0);
		glVertex2f(500.0, 0.0);
		glVertex2f(490.0, -10.0);
	 	// Sumbu Y, ijo
		glColor3f(0.0f,1.0f,0.0f);
		glVertex2f(0.0, -500.0);
		glVertex2f(0.0, 500.0);
		glVertex2f(0.0, 500.0);
		glVertex2f(10.0, 490.0);
		glVertex2f(0.0, 500.0);
		glVertex2f(-10.0, 490.0);
	} glEnd();
	glFlush();				/* Complete any pending operations */
}

void resizeWindow(int width, int height) {  // fungsi biar pas windownya diresize jadinya gak ngestretch
		GLfloat aspect = (GLfloat)width / (GLfloat)height;
		// Set the viewport to cover the new window
		glViewport(0, 0, width, height);
		// Set the aspect ratio of the clipping area to match the viewport
		glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
		glLoadIdentity();  // Reset the projection matrix
		if (width >= height) {
			// aspect >= 1, set the height from -1 to 1, with larger width
			gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
		} else {
			// aspect < 1, set the width to -1 to 1, with larger height
			gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
		}
}

DWORD WINAPI input(LPVOID param) {
	// Saves original polygon for reset
	Poly2 original(polygon.getEdge());
	for (int i = 0; i < original.getEdge(); i++) {
		original.setCorner(i, polygon.getCorner(i));
	}
	
	std::string cmd;
	int n;
	while (1 < 2) {
		std::cin >> cmd;
		if (cmd == "multiple") {
			std::cin >> n;
			for (int i = 0; i < n; i++) {
				std::cout << "... "; std::cin >> cmd;
				transform(cmd);
			}
		} else if (cmd == "reset") {
			for (int i = 0; i < polygon.getEdge(); i++) {
				polygon.setCorner(i, original.getCorner(i));
			}
		} else if (cmd == "exit") {exit(0);} 
		else {transform(cmd);}
		glutPostRedisplay();
		cmd = "";
	}
}

void redisplay() {
	glutSwapBuffers();
	glutPostRedisplay();
	glutSwapBuffers();
}

void transform(std::string cmd) {
	float cx, cy, deg, cz; // Recycleable
	std::string parameter;
	if (cmd == "translate") {
		std::cin >> cx >> cy;
		Poly2 before(polygon.getEdge());
		for (int i=0; i<polygon.getEdge(); i++) {
			before.setCorner(i, polygon.getCorner(i));
		}
		for (int step=0; step<=ANIMATION_STEP; step++) {
			for (int i=0; i<polygon.getEdge(); i++) {
				polygon.setCorner(i, before.getCorner(i));
			}
			polygon.animateTranslate(cx, cy, step);
			redisplay();
			Sleep(100);
		}
	} else if (cmd == "dilate") {
		std::cin >> cx;
		polygon.dilate(cx);
	} else if (cmd == "rotate") {
		std::cin >> deg >> cx >> cy;
		polygon.rotate(deg, cx, cy);
	} else if (cmd == "reflect") {
		std::cin >> parameter;
		if (parameter == "x") {polygon.reflectByLine(0);}
		else if (parameter == "y") {polygon.reflectByLine(1);}
		else if (parameter == "y=x" || parameter == "x=y") {polygon.reflectByLine(2);}
		else if (parameter == "y=-x" || parameter == "x=-y") {polygon.reflectByLine(3);}
		else { // doesn't work
			sscanf(parameter.c_str(), "(%f,%f)", &cx, &cy);
			polygon.reflectByPoint(cx, cy);
		}
	} else if (cmd == "shear") {
		std::cin >> parameter >> cx;
		(parameter == "x") ? polygon.shearByX(cx) : polygon.shearByY(cx);
	} else if (cmd == "stretch") {
		std::cin >> parameter >> cx;
		(parameter == "x") ? polygon.stretchByX(cx) : polygon.stretchByY(cx);
	} else if (cmd == "custom") {
		std::cin >> cx >> cy >> deg >> cz;
		polygon.customTransform(cx, cy, deg, cz);
	} else {std::cout << "Invalid command" << std::endl;}
}

DWORD WINAPI startLoop(LPVOID param) {
 	int argc = 1;
	glutInit(&argc, NULL);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Algeo");

	glClearColor(1.0, 1.0, 1.0, 1.0);	// background putih
	glutDisplayFunc(render);		
	glutReshapeFunc(resizeWindow);	

	glutMainLoop();
}

int main(int argc, char *argv[]) {

  int Data_Of_Thread_1 = 1;
  int Data_Of_Thread_2 = 2;

  HANDLE Handle_Of_Thread_1 = 0;
  HANDLE Handle_Of_Thread_2 = 0;
	HANDLE Array_Of_Thread_Handles[3];

	int n;
	std::cout << "   ____                    _____ _      \n";
	std::cout << "  / __ \\                  / ____| |     \n";
	std::cout << " | |  | |_ __   ___ _ __ | |  __| |     \n";
	std::cout << " | |  | | '_ \\ / _ \\ '_ \\| | |_ | |     \n";
	std::cout << " | |__| | |_) |  __/ | | | |__| | |____ \n";
	std::cout << "  \\____/| .__/ \\___|_| |_|\\_____|______|\n";
	std::cout << "        | |                             \n";
	std::cout << "        |_|                             \n\n";
	std::cout << "Segi berapa? "; std::cin >> n;
	polygon.setEdge(n);
	float x, y;	Titik2 titikTemp(0.0, 0.0);
 	for (int i = 0; i < n; i++) {
		std::cin >> x >> y;
		titikTemp.setX(x);
		titikTemp.setY(y);
		polygon.setCorner(i, titikTemp);
	}

  Handle_Of_Thread_1 = CreateThread(NULL, 0, startLoop, NULL, 0, NULL);  
  if (Handle_Of_Thread_1 == NULL) ExitProcess(0);
  Handle_Of_Thread_2 = CreateThread(NULL, 0, input, &Data_Of_Thread_2, 0, NULL);  
  if (Handle_Of_Thread_2 == NULL) ExitProcess(0);

  Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;
	Array_Of_Thread_Handles[1] = Handle_Of_Thread_2;

  WaitForMultipleObjects(2, Array_Of_Thread_Handles, TRUE, INFINITE);
  CloseHandle(Handle_Of_Thread_1);
  CloseHandle(Handle_Of_Thread_2);

	return 0; // execution never reaches this point 
}