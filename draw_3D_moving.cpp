#include <gl\glut.h>
float s = 0.00, xr = 0, yr = 0, zr = 0;
void draw_3d_moving() {
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 1.0);
	if (xr == 0 && yr == 0 && zr == 0)
		s = 0;
	glRotated(s, xr, yr, zr);
	glMatrixMode(GL_MODELVIEW);
	glLineWidth(3);

	glutWireTeapot(250);

	glFlush();
	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y) {
	if (key == 'e' || key == 'E') exit(0);
	else if (key == 's' || key == 'S')s = 0.01;
	else if (key == 'h' || key == 'H')s = 0.5;
	else if (key == 'x' || key == 'X')xr = !xr;
	else if (key == 'y' || key == 'Y')yr = !yr;
	else if (key == 'z' || key == 'Z')zr = !zr;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowPosition(50, 50);
	glutInitWindowSize(600, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("darw_3D_moving");
	glOrtho(-300, 300, -300, 300, -300, 300);
	glRotated(60, 1, 0, 1);
	glutIdleFunc(draw_3d_moving);
	glutDisplayFunc(draw_3d_moving);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
