// Compile: g++ <filename>.cpp -lfreeglut -lopengl32 -lglu32 -o <exename>

#include <GL/glut.h>
#include <math.h>

// Camera
float camXOri = 20.0, camYOri = 20.0, camZOri = 20.0; // Original position
float camX = camXOri, camY = camYOri, camZ = camZOri; // Position
float camTheta = 0.0; // Angle (terhadap sumbu x di bidang xz)
float camPhi = 0.0; // Angle (terhadap sumbu bidang xz, 90 derajat berarti sejajar sumbu y)

// Mouse rotation thingy
float deltaTheta = 0.0, deltaPhi = 0.0;
int xOrigin = -1, yOrigin = -1;

void render(void)		/* function called whenever redisplay needed */
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT); // clear the drawing buffer.
	glLoadIdentity();
	gluLookAt(camX, camY, camZ,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);
	// Garis-garis sumbu
	glBegin(GL_LINES); 
		{ // Sumbu X, merah
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(-10.0, 0.0, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glVertex3f(9.75, 0.25, 0.0);
		glVertex3f(10.0, 0.0, 0.0);
		glVertex3f(9.75, -0.25, 0.0);
	 	// Sumbu Y, ijo
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0, -10.0, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glVertex3f(0.25, 9.75, 0.0);
		glVertex3f(0.0, 10.0, 0.0);
		glVertex3f(-0.25, 9.75, 0.0);
	 	// Sumbu Z, biru
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0.0, 0.0, -10.0);
		glVertex3f(0.0, 0.0, 10.0);
		glVertex3f(0.0, 0.0, 10.0);
		glVertex3f(0.0, 0.25, 9.75);
		glVertex3f(0.0, 0.0, 10.0);
		glVertex3f(0.0, -0.25, 9.75);}
	glEnd();
	// Kubus percobaan
	glBegin(GL_QUADS);	// begin query?
		{ glColor3f(0.0f,1.0f,0.0f);    // Color Green
		glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
		glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
		glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
		glColor3f(1.0f,0.5f,0.0f);    // Color Orange
		glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
		glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
		glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
		glColor3f(1.0f,0.0f,0.0f);    // Color Red    
		glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
		glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
		glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
		glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
		glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
		glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
		glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
		glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
		glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
		glColor3f(0.0f,0.0f,1.0f);    // Color Blue
		glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
		glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
		glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
		glColor3f(1.0f,0.0f,1.0f);    // Color Violet
		glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
		glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
		glVertex3f( 1.0f,-1.0f,-1.0f); }
	glEnd();				/* OpenGL draws the filled triangle */
	glFlush();				/* Complete any pending operations */
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) { // Only start motion if the left button is pressed
		if (state == GLUT_UP) { // When the button is released
			camTheta += deltaTheta;
			xOrigin = -1;
			yOrigin = -1;
		}
		else  { // state = GLUT_DOWN
			xOrigin = x;
			yOrigin = y;
		}
	}
}

void mouseMove(int x, int y) {
	// this will only be true when the left button is down
	if (xOrigin >= 0) {
		// update deltas
		deltaTheta = (x - xOrigin) * 0.002;
		deltaPhi = (y - yOrigin) * 0.002;
		// update camera's position
		camX = camXOri * cos(camTheta + deltaTheta) * cos(camPhi + deltaPhi);
		camY = camYOri * sin(camPhi + deltaPhi);
		camZ = camZOri * sin(camTheta + deltaTheta) * cos(camPhi + deltaPhi);
	}
}
	

void resizeWindow(int width, int height) {  // fungsi biar pas windownya diresize jadinya gak ngestretch
	glMatrixMode(GL_PROJECTION);  // Set a new projection matrix
	glLoadIdentity(); // Reset matrix
	gluPerspective(40.0, (GLdouble)width/(GLdouble)height, 0.5, 100.0);
	// Angle of view:40 degrees
	// Near clipping plane distance: 0.5
	// Far clipping plane distance: 20.0
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, width, height);  // Use the whole window for rendering
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);	

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,600);
	glutCreateWindow("Algeo");

	glClearColor(1.0, 1.0, 1.0, 1.0);	// background putih
	glutDisplayFunc(render);		
	glutReshapeFunc(resizeWindow);	
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	glutMainLoop();	// start processing events... 

	return 0; // execution never reaches this point 
}