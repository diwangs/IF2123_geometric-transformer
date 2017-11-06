// Compile: g++ <filename>.cpp -lfreeglut -lopengl32 -lglu32 -o <exename>

#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>



void render(void)	{ /* function called whenever redisplay needed */
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT); // clear the drawing buffer.
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	// Kuotak percobaan
	glBegin(GL_QUADS); { // begin query? 
		glColor3f(0.0f, 0.0f, 1.0f);    // Color Green
		glVertex2f(105.0f, 105.0f);    // Top Right Of The Quad (Top)
		glVertex2f(5.0f, 105.0f);    // Top Left Of The Quad (Top)
		glVertex2f(5.0f, 5.0f);    // Bottom Left Of The Quad (Top)
		glVertex2f(105.0f, 5.0f);    // Bottom Right Of The Quad (Top)
	}
	// Kuotak percobaan
	glBegin(GL_POLYGON); { // begin query? 
		glColor3f(0.0f, 0.0f, 1.0f);    // Color Green
		glVertex2f(105.0f, 105.0f);    // Top Right Of The Quad (Top)
		glVertex2f(5.0f, 105.0f);    // Top Left Of The Quad (Top)
		glVertex2f(5.0f, 5.0f);    // Bottom Left Of The Quad (Top)
		glVertex2f(105.0f, 5.0f);    // Bottom Right Of The Quad (Top)
		glVertex2f(55.0f, 55.0f);    // Bottom Right Of The Quad (Top)
	}
	glEnd();				/* OpenGL draws the filled triangle */
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
	}
	glEnd();
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
	std::string a;
	std::cin >> a;
	std::cout << a << std::endl;
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

  Handle_Of_Thread_1 = CreateThread(NULL, 0, startLoop, &Data_Of_Thread_1, 0, NULL);  
  if (Handle_Of_Thread_1 == NULL)
      ExitProcess(Data_Of_Thread_1);
  Handle_Of_Thread_2 = CreateThread(NULL, 0, input, &Data_Of_Thread_2, 0, NULL);  
  if (Handle_Of_Thread_2 == NULL)
      ExitProcess(Data_Of_Thread_2);

  Array_Of_Thread_Handles[0] = Handle_Of_Thread_1;
  Array_Of_Thread_Handles[1] = Handle_Of_Thread_2;

  WaitForMultipleObjects(2, Array_Of_Thread_Handles, TRUE, INFINITE);
  CloseHandle(Handle_Of_Thread_1);
  CloseHandle(Handle_Of_Thread_2);

	return 0; // execution never reaches this point 
}