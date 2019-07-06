#include<Windows.h>
#include<stdio.h>
#include<GL\glut.h>
#include<math.h>
int X = 0,rx,ry, Xc, Yc;
void display() {
	glColor3f(0.5, 0.0, 1.0);
	glPointSize(3);
	glBegin(GL_POINTS);
	//the first point
	int x = X, y = ry, ry2 = ry*ry, rx2 = rx*rx,doublerx2=2*rx2,doublery2=2*ry2;
	int pk = ry2 - rx2*ry + (1 / 4 * ry2);
	glVertex2d(Xc + x, Yc + y);
	glVertex2d(Xc - x, Yc + y);
	glVertex2d(Xc + x, Yc - y);
	glVertex2d(Xc - x, Yc - y);
	if (pk < 0) {
		x += 1;
	}
	else {
		x += 1;
		y -= 1;
	}
	glVertex2d(Xc + x, Yc + y);
	glVertex2d(Xc - x, Yc + y);
	glVertex2d(Xc + x, Yc - y);
	glVertex2d(Xc - x, Yc - y);
	int fx,fy;
	fx = doublery2*x;
	fy = doublerx2*y;
	while (fx<fy)
	{
		if (pk < 0) {
			pk = pk + fx + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		else
		{
			pk = pk + fx - fy + ry2;
			if (pk < 0) {
				x += 1;
			}
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2*x;
		fy = doublerx2*y;
	}
	float x0 = x, y0 = y;
	int pk1 = ry2*pow((x0 + 0.5), 2) + rx2*pow((y0 - 1), 2) - (rx2 * ry2);
	if (pk1 > 0)
		y -= 1;
	else {
		x += 1;
		y -= 1;
	}
	fx = doublery2*x;
	fy = doublerx2*y;
	while (y!=0)
	{
		if (pk1 > 0) {
			pk1 = pk1 - fy+rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		else {
			pk1 = pk1 +fx - fy + rx2;
			if (pk1 > 0)
				y -= 1;
			else {
				x += 1;
				y -= 1;
			}
		}
		glVertex2d(Xc + x, Yc + y);
		glVertex2d(Xc - x, Yc + y);
		glVertex2d(Xc + x, Yc - y);
		glVertex2d(Xc - x, Yc - y);
		fx = doublery2*x;
		fy = doublerx2*y;
	}
	glEnd();
	glFlush();
}
void main(int argc, char** argv)
{
	printf("Entre the radiaus rx and ry :  ");
	scanf_s("%d%d", &rx,&ry);
	printf("Entre value of Xc and Yc : ");
	scanf_s("%d%d", &Xc, &Yc);
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Circle");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(display);
	glutMainLoop();

}