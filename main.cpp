#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

#define PI 3.14159265358979323846

GLfloat x, y, radius, twicePi;// for circle
int triangleAmount;

int frameNumber = 1; // for windmill

GLfloat position_b1 = -0.5f; // for boat1
GLfloat speed_b1 = 0.002f;

GLfloat position_b2 = -1.5f; // for boat2
GLfloat speed_b2 = 0.002f;

GLfloat position_r = -0.1f; // for river
GLfloat speed_r = 0.01f;

GLfloat position_s = 1.6f; // for smoke
GLfloat speed_s = 0.01f;

GLfloat position_c1 = 1.6f; // for car 1
GLfloat speed_c1 = 0.01f;

GLfloat position_c2 = 2.4f; // for car 2
GLfloat speed_c2 = 0.01f;

GLfloat position_c3 = -0.9f; // for car 3
GLfloat speed_c3 = 0.01f;

GLfloat position_c4 = 0.9f; // for car 4
GLfloat speed_c4 = 0.01f;

GLfloat position_rain = 0.0f; // for rain
GLfloat speed_rain = 0.05f;
GLfloat position_rain2 = 2.0f; // for rain
GLfloat speed_rain2 = 0.05f;

int cnt = 0, flag = 0, r = 0;

char *c;

void windmill(){
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    glTranslatef(1.6, 0.3, 0.0);
    glColor3ub(255, 102, 102); //base
    glBegin(GL_POLYGON);
        glVertex2f(-0.80f, 0.275f);
        glVertex2f(-0.80f, 0.25f);
        glVertex2f(-0.65f, 0.25f);
        glVertex2f(-0.65f, 0.275f);

    glEnd();

    glColor3ub(255, 255, 255); //body
    glBegin(GL_POLYGON);
        glVertex2f(-0.775f, 0.5f);
        glVertex2f(-0.79f, 0.275f);
        glVertex2f(-0.66f, 0.275f);
        glVertex2f(-0.675f, 0.5f);

    glEnd();

    glColor3ub(77, 38, 0); //door
    glBegin(GL_POLYGON);
        glVertex2f(-0.71f, 0.35f);
        glVertex2f(-0.71f, 0.275f);
        glVertex2f(-0.74f, 0.275f);
        glVertex2f(-0.74f, 0.35f);

    glEnd();

    glColor3ub(77, 38, 0); //window
    glBegin(GL_POLYGON);
        glVertex2f(-0.71f, 0.45f);
        glVertex2f(-0.71f, 0.4f);
        glVertex2f(-0.74f, 0.4f);
        glVertex2f(-0.74f, 0.45f);

    glEnd();

    glColor3ub(77, 38, 0); //head
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.79f, 0.5f);
        glVertex2f(-0.725f, 0.63f);
        glVertex2f(-0.66f, 0.5f);

    glEnd();

    glTranslatef(-0.725f, 0.55f, 0.0f);
    glRotated(frameNumber * (-180.0/500), 0, 0, 1);

    glColor3ub(204, 229, 255);//wing1
    glBegin(GL_POLYGON);
        glVertex2f(0.00f, 0.01f);
        glVertex2f(0.00f, 0.00f);
        glVertex2f(0.20f, 0.00f);
        glVertex2f(0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
        glVertex2f(0.03f, 0.05f);
        glVertex2f(0.03f, 0.01f);
        glVertex2f(0.20f, 0.01f);
        glVertex2f(0.20f, 0.05f);
    glEnd();

    glColor3ub(204, 229, 255); //wing2
    glBegin(GL_POLYGON);
        glVertex2f(0.00f, 0.01f);
        glVertex2f(0.00f, 0.00f);
        glVertex2f(-0.20f, 0.00f);
        glVertex2f(-0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
        glVertex2f(-0.03f, -0.04f);
        glVertex2f(-0.03f, -0.00f);
        glVertex2f(-0.20f, -0.00f);
        glVertex2f(-0.20f, -0.04f);
    glEnd();

    glRotatef(90,0.0f, 0.0f, 1.0f);
    glColor3ub(204, 229, 255); //wing3
    glBegin(GL_POLYGON);
        glVertex2f(0.00f, 0.01f);
        glVertex2f(0.00f, 0.00f);
        glVertex2f(0.20f, 0.00f);
        glVertex2f(0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
        glVertex2f(0.03f, 0.05f);
        glVertex2f(0.03f, 0.01f);
        glVertex2f(0.20f, 0.01f);
        glVertex2f(0.20f, 0.05f);
    glEnd();

    glColor3ub(204, 229, 255); //wing4
    glBegin(GL_POLYGON);
        glVertex2f(0.00f, 0.01f);
        glVertex2f(0.00f, 0.00f);
        glVertex2f(-0.20f, 0.00f);
        glVertex2f(-0.20f, 0.01f);
    glEnd();

    glColor3ub(255, 51, 51);
    glBegin(GL_POLYGON);
        glVertex2f(-0.03f, -0.04f);
        glVertex2f(-0.03f, -0.00f);
        glVertex2f(-0.20f, -0.00f);
        glVertex2f(-0.20f, -0.04f);
    glEnd();

    x=-0.0f; y=0.0f; radius =.02f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 51, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glLoadIdentity();
}

void tree() {
    // circle tree 1
    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-1.5f, 0.8f);
        glVertex2f(-1.5f, 0.55f);
    glEnd();
    x=-1.45f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.5f; y=0.85f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.55f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPointSize(5.0);
	glBegin(GL_POINTS); // fruits
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.53f, 0.85f);
        glVertex2f(-1.47f, 0.8f);
	glEnd();

    // circle tree 2
	glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(-0.8f, 0.57f);
    glEnd();
    x=-0.85f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.8f; y=0.85f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.75f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 153, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    // triangle tree 1
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.55f, 0.65f);
        glVertex2f(1.55f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(1.45f, 0.7f);
        glVertex2f(1.55f, 0.95f);
        glVertex2f(1.65f, 0.7f);
    glEnd();

	// triangle tree 2
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.2f, 0.65f);
        glVertex2f(-0.2f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.2f, 0.95f);
        glVertex2f(-0.1f, 0.7f);
    glEnd();

    // triangle tree 3
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.9f, 0.7f);
        glVertex2f(1.9f, 0.85f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 153, 51);
        glVertex2f(1.8f, 0.75f);
        glVertex2f(1.9f, 1.0f);
        glVertex2f(2.0f, 0.75f);
    glEnd();
}

void shop() {
    // left shop start
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 255, 255);
        glVertex2f(-1.95f, 0.5f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.55f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(128, 0, 0);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.95f, 0.85f);
        glVertex2f(-1.55f, 0.85f);
        glVertex2f(-1.55f, 0.75f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(255, 0, 0);
        glVertex2f(-2.0f, 0.65f);
        glVertex2f(-1.5f, 0.65f);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-2.0f, 0.7f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(0, 230, 230);
        glVertex2f(-1.9f, 0.5f);
        glVertex2f(-1.9f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(0, 230, 230);
        glVertex2f(-1.77f, 0.55f);
        glVertex2f(-1.77f, 0.62f);
        glColor3ub(0, 153, 153);
        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-1.52f, 0.5f);
        glVertex2f(-1.98f, 0.5f);

        glVertex2f(-1.524f, 0.504f);
        glVertex2f(-1.98f, 0.504f);

        glVertex2f(-1.9f, 0.5f); // door
        glVertex2f(-1.9f, 0.62f);

        glVertex2f(-1.9f, 0.62f);
        glVertex2f(-1.82f, 0.62f);

        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);

        glVertex2f(-1.82f, 0.5f);
        glVertex2f(-1.9f, 0.5f);

        glVertex2f(-1.82f, 0.55f);
        glVertex2f(-1.9f, 0.55f);

        glVertex2f(-1.77f, 0.55f); // window
        glVertex2f(-1.77f, 0.62f);

        glVertex2f(-1.77f, 0.62f);
        glVertex2f(-1.6f, 0.62f);

        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);

        glVertex2f(-1.6f, 0.55f);
        glVertex2f(-1.77f, 0.55f);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    c="BFC";
    glRasterPos2f(-1.8 , 0.78);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    // left shop end

    // right shop start
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 204, 102);
        glVertex2f(-0.75f, 0.5f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.75f, 0.85f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.3f, 0.85f);
        glVertex2f(-0.35f, 0.9f);
        glVertex2f(-0.6f, 0.9f);
        glVertex2f(-0.66f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // inside
        glColor3ub(77, 38, 0);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.73f, 0.75f);
        glVertex2f(-0.22f, 0.75f);
        glVertex2f(-0.22f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // product
        glColor3ub(255, 0, 0);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-0.7f, 0.65f);
        glVertex2f(-0.6f, 0.65f);
        glVertex2f(-0.6f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.65f, 0.65f);
        glVertex2f(-0.65f, 0.68f);
        glVertex2f(-0.6f, 0.68f);
        glVertex2f(-0.6f, 0.65f);
    glEnd();
    glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.55f, 0.6f);
        glVertex2f(-0.55f, 0.65f);
        glVertex2f(-0.45f, 0.65f);
        glVertex2f(-0.45f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON); // product
        glColor3ub(204, 0, 102);
        glVertex2f(-0.4f, 0.6f);
        glVertex2f(-0.4f, 0.65f);
        glVertex2f(-0.35f, 0.6f);
        glVertex2f(-0.35f, 0.65f);
    glEnd();
    glBegin(GL_POLYGON); // product
        glColor3ub(255, 204, 102);
        glVertex2f(-0.34f, 0.6f);
        glVertex2f(-0.34f, 0.66f);
        glVertex2f(-0.3f, 0.6f);
        glVertex2f(-0.3f, 0.66f);
    glEnd();

    glBegin(GL_POLYGON); // table
        glColor3ub(128, 64, 0);
        glVertex2f(-0.73f, 0.5f);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
        glVertex2f(-0.22f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(230, 115, 0);
        glVertex2f(-0.8f, 0.7f);
        glVertex2f(-0.15f, 0.7f);
        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.8f, 0.75f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-0.17f, 0.5f);
        glVertex2f(-0.77f, 0.5f);

        glVertex2f(-0.17f, 0.504f);
        glVertex2f(-0.77f, 0.504f);

        glColor3ub(255, 153, 51);
        glVertex2f(-0.73f, 0.6f);
        glVertex2f(-0.22f, 0.6f);
    glEnd();

    glColor3ub(255, 255, 0);
    c="Candy Shop";
    glRasterPos2f(-0.6 , 0.84);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);
    // right shop end
}

void house() {
    // left house start
    glBegin(GL_POLYGON); // body
        glColor3ub(224, 228, 231);
        glVertex2f(-1.4f, 0.5f);
        glVertex2f(-1.4f, 1.0f);
        glVertex2f(-0.9f, 1.0f);
        glVertex2f(-0.9f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // bottom-window 1
        glColor3ub(179, 230, 255);
        glVertex2f(-1.35f, 0.55f);
        glVertex2f(-1.35f, 0.65f);
        glColor3ub(0, 230, 230);
        glVertex2f(-1.25f, 0.65f);
        glVertex2f(-1.25f, 0.55f);
    glEnd();
    glBegin(GL_POLYGON); // bottom-window 2
        glColor3ub(179, 230, 255);
        glVertex2f(-1.05f, 0.55f);
        glVertex2f(-1.05f, 0.65f);
        glColor3ub(0, 230, 230);
        glVertex2f(-0.95f, 0.65f);
        glVertex2f(-0.95f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON); // top-window 1
        glColor3ub(179, 230, 255);
        glVertex2f(-1.35f, 0.85f);
        glVertex2f(-1.35f, 0.95f);
        glColor3ub(0, 230, 230);
        glVertex2f(-1.25f, 0.95f);
        glVertex2f(-1.25f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 2
        glColor3ub(179, 230, 255);
        glVertex2f(-1.2f, 0.85f);
        glVertex2f(-1.2f, 0.95f);
        glColor3ub(0, 230, 230);
        glVertex2f(-1.1f, 0.95f);
        glVertex2f(-1.1f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 3
        glColor3ub(179, 230, 255);
        glVertex2f(-1.05f, 0.85f);
        glVertex2f(-1.05f, 0.95f);
        glColor3ub(0, 230, 230);
        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.95f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(153, 153, 153);
        glVertex2f(-1.2f, 0.5f);
        glVertex2f(-1.2f, 0.65f);
        glVertex2f(-1.1f, 0.65f);
        glVertex2f(-1.1f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.17f, 0.58f);
	glEnd();

    glBegin(GL_LINES);
        glColor3ub(77, 195, 255);
        glVertex2f(-1.35f, 0.55f); // bottom-window 1
        glVertex2f(-1.35f, 0.65f);

        glVertex2f(-1.35f, 0.65f);
        glVertex2f(-1.25f, 0.65f);

        glVertex2f(-1.25f, 0.65f);
        glVertex2f(-1.25f, 0.55f);

        glVertex2f(-1.25f, 0.55f);
        glVertex2f(-1.35f, 0.55f);

        glVertex2f(-1.25f, 0.6f);
        glVertex2f(-1.35f, 0.6f);

        glVertex2f(-1.05f, 0.55f); // bottom-window 2
        glVertex2f(-1.05f, 0.65f);

        glVertex2f(-1.05f, 0.65f);
        glVertex2f(-0.95f, 0.65f);

        glVertex2f(-0.95f, 0.65f);
        glVertex2f(-0.95f, 0.55f);

        glVertex2f(-0.95f, 0.55f);
        glVertex2f(-1.05f, 0.55f);

        glVertex2f(-0.95f, 0.6f);
        glVertex2f(-1.05f, 0.6f);

        glVertex2f(-1.35f, 0.85f); // top-window 1
        glVertex2f(-1.35f, 0.95f);

        glVertex2f(-1.35f, 0.95f);
        glVertex2f(-1.25f, 0.95f);

        glVertex2f(-1.25f, 0.95f);
        glVertex2f(-1.25f, 0.85f);

        glVertex2f(-1.25f, 0.85f);
        glVertex2f(-1.35f, 0.85f);

        glVertex2f(-1.25f, 0.9f);
        glVertex2f(-1.35f, 0.9f);

        glVertex2f(-1.2f, 0.85f); // top-window 2
        glVertex2f(-1.2f, 0.95f);

        glVertex2f(-1.2f, 0.95f);
        glVertex2f(-1.1f, 0.95f);

        glVertex2f(-1.1f, 0.95f);
        glVertex2f(-1.1f, 0.85f);

        glVertex2f(-1.1f, 0.85f);
        glVertex2f(-1.2f, 0.85f);

        glVertex2f(-1.1f, 0.9f);
        glVertex2f(-1.2f, 0.9f);

        glVertex2f(-1.05f, 0.85f); // top-window 3
        glVertex2f(-1.05f, 0.95f);

        glVertex2f(-1.05f, 0.95f);
        glVertex2f(-0.95f, 0.95f);

        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.95f, 0.85f);

        glVertex2f(-0.95f, 0.85f);
        glVertex2f(-1.05f, 0.85f);

        glVertex2f(-0.95f, 0.9f);
        glVertex2f(-1.05f, 0.9f);

        glVertex2f(-1.2f, 0.5f); // door
        glVertex2f(-1.2f, 0.65f);

        glVertex2f(-1.2f, 0.65f);
        glVertex2f(-1.1f, 0.65f);

        glVertex2f(-1.1f, 0.65f);
        glVertex2f(-1.1f, 0.5f);

        glVertex2f(-1.1f, 0.5f);
        glVertex2f(-1.2f, 0.5f);

        // body
        glColor3ub(128, 128, 128);

        glVertex2f(-1.4f, 0.5f);
        glVertex2f(-1.4f, 1.0f);

        glVertex2f(-1.4f, 1.0f);
        glVertex2f(-0.9f, 1.0f);

        glVertex2f(-0.9f, 1.0f);
        glVertex2f(-0.9f, 0.5f);

        glColor3ub(128, 0, 0);
        glVertex2f(-0.87f, 0.5f);
        glVertex2f(-1.43f, 0.5f);

        glVertex2f(-0.87f, 0.504f);
        glVertex2f(-1.43f, 0.504f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(76, 174, 218);
        glVertex2f(-1.4f, 0.8f);
        glVertex2f(-1.45f, 0.75f);
        glVertex2f(-1.45f, 0.7f);
        glVertex2f(-0.85f, 0.7f);
        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.9f, 0.8f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.4f, 0.8f);
        glVertex2f(-1.45f, 0.75f);

        glVertex2f(-1.45f, 0.75f);
        glVertex2f(-1.45f, 0.7f);

        glVertex2f(-1.45f, 0.7f);
        glVertex2f(-0.85f, 0.7f);

        glVertex2f(-0.85f, 0.7f);
        glVertex2f(-0.85f, 0.75f);

        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.9f, 0.8f);

        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-1.4f, 0.8f);
    glEnd();
    // left house end

    // right house start
    glBegin(GL_POLYGON); // body
        glColor3ub(153, 51, 0);
        glVertex2f(-0.15f, 0.5f);
        glVertex2f(-0.15f, 0.8f);
        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // store room
        glColor3ub(153, 51, 0);
        glVertex2f(0.05f, 0.8f);
        glVertex2f(0.05f, 0.99f);
        glVertex2f(0.35f, 0.99f);
        glVertex2f(0.35f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
        glColor3ub(77, 184, 255);
        glVertex2f(0.05f, 0.6f);
        glVertex2f(0.05f, 0.7f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.15f, 0.7f);
        glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
        glColor3ub(77, 184, 255);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.2f, 0.7f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // store room window
        glColor3ub(77, 184, 255);
        glVertex2f(0.15f, 0.85f);
        glVertex2f(0.15f, 0.95f);
        glColor3ub(26, 140, 255);
        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(77, 77, 77);
        glVertex2f(-0.1f, 0.5f);
        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.65f);
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.03f, 0.6f);
	glEnd();

    glBegin(GL_POLYGON); // door shelter
        glColor3ub(230, 115, 0);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(-0.05f, 0.7f);
        glVertex2f(-0.12f, 0.65f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.15f, 0.85f); // store room window
        glVertex2f(0.15f, 0.95f);

        glVertex2f(0.15f, 0.95f);
        glVertex2f(0.25f, 0.95f);

        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.25f, 0.85f);

        glVertex2f(0.25f, 0.85f);
        glVertex2f(0.15f, 0.85f);

        glVertex2f(0.05f, 0.6f); // window 1
        glVertex2f(0.05f, 0.7f);

        glVertex2f(0.05f, 0.7f);
        glVertex2f(0.15f, 0.7f);

        glVertex2f(0.15f, 0.7f);
        glVertex2f(0.15f, 0.6f);

        glVertex2f(0.15f, 0.6f);
        glVertex2f(0.05f, 0.6f);

        glVertex2f(0.2f, 0.6f); // window 2
        glVertex2f(0.2f, 0.7f);

        glVertex2f(0.2f, 0.7f);
        glVertex2f(0.3f, 0.7f);

        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.3f, 0.6f);

        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.2f, 0.6f);

        glColor3ub(255, 153, 51);
        glVertex2f(-0.1f, 0.5f); // door
        glVertex2f(-0.1f, 0.65f);

        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.65f);

        glVertex2f(0.0f, 0.65f);
        glVertex2f(0.0f, 0.5f);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(-0.1f, 0.5f);

        glVertex2f(0.02f, 0.65f); // door shelter
        glVertex2f(-0.05f, 0.7f);

        glVertex2f(-0.05f, 0.7f);
        glVertex2f(-0.12f, 0.65f);

        glVertex2f(-0.12f, 0.65f);
        glVertex2f(0.02f, 0.65f);

        glVertex2f(0.36f, 0.8f); // roof railing
        glVertex2f(-0.16f, 0.8f);

        glVertex2f(0.36f, 0.84f);
        glVertex2f(-0.16f, 0.84f);

        glVertex2f(-0.14f, 0.8f);
        glVertex2f(-0.14f, 0.84f);

        glVertex2f(-0.1f, 0.8f);
        glVertex2f(-0.1f, 0.84f);

        glVertex2f(-0.05f, 0.8f);
        glVertex2f(-0.05f, 0.84f);

        glVertex2f(-0.0f, 0.8f);
        glVertex2f(-0.0f, 0.84f);

        glVertex2f(0.05f, 0.8f);
        glVertex2f(0.05f, 0.84f);

        glVertex2f(0.1f, 0.8f);
        glVertex2f(0.1f, 0.84f);

        glVertex2f(0.15f, 0.8f);
        glVertex2f(0.15f, 0.84f);

        glVertex2f(0.2f, 0.8f);
        glVertex2f(0.2f, 0.84f);

        glVertex2f(0.25f, 0.8f);
        glVertex2f(0.25f, 0.84f);

        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.3f, 0.84f);

        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, 0.84f);

        glVertex2f(-0.16f, 0.504f); // ground
        glVertex2f(0.36f, 0.504f);

        glVertex2f(-0.16f, 0.5f);
        glVertex2f(0.36f, 0.5f);

        glVertex2f(0.04f, 0.99f); // top roof
        glVertex2f(0.36f, 0.99f);

        glVertex2f(0.04f, 0.985f);
        glVertex2f(0.36f, 0.985f);
    glEnd();

    // right house end
}

void factory() {
    // funnel
    glBegin(GL_POLYGON);
        glColor3ub(163, 136, 151);
        glVertex2f(1.5f, -0.8f);
        glVertex2f(1.55f, -0.4f);
        glVertex2f(1.65f, -0.4f);
        glVertex2f(1.7f, -0.8f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(231, 222, 225);
        glVertex2f(1.54f, -0.5f);
        glVertex2f(1.55f, -0.45f);
        glVertex2f(1.65f, -0.45f);
        glVertex2f(1.66f, -0.5f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(1.5f, -0.8f);
        glVertex2f(1.55f, -0.4f);

        glVertex2f(1.55f, -0.4f);
        glVertex2f(1.65f, -0.4f);

        glVertex2f(1.65f, -0.4f);
        glVertex2f(1.7f, -0.8f);

        glVertex2f(1.7f, -0.8f);
        glVertex2f(1.5f, -0.8f);
    glEnd();

    // smoke
    glPushMatrix();
	glTranslatef(position_s, -0.05f, 0.0f);

    x=0.0f; y=-0.21f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(217, 217, 217);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.07f; y=-0.25f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(217, 217, 217);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.0f; y=-0.28f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(217, 217, 217);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();

    // body start
    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.45f, -2.0f);
        glVertex2f(1.45f, -0.7f);
        glVertex2f(1.65f, -0.55f);
        glVertex2f(1.65f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.65f, -2.0f);
        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.85f, -0.55f);
        glVertex2f(1.85f, -2.0f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(220, 170, 159);
        glVertex2f(1.85f, -2.0f);
        glVertex2f(1.85f, -0.7f);
        glVertex2f(2.05f, -0.55f);
        glVertex2f(2.05f, -2.0f);
    glEnd();
    // body end

    // roof
    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.45f, -0.7f);
        glVertex2f(1.45f, -0.66f);
        glVertex2f(1.6f, -0.55f);
        glVertex2f(1.65f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.65f, -0.66f);
        glVertex2f(1.8f, -0.55f);
        glVertex2f(1.85f, -0.55f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(192, 117, 124);
        glVertex2f(1.85f, -0.7f);
        glVertex2f(1.85f, -0.66f);
        glVertex2f(2.0f, -0.55f);
        glVertex2f(2.05f, -0.55f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
        glColor3ub(96, 82, 118);
        glVertex2f(1.5f, -0.78f);
        glVertex2f(1.5f, -0.7f);
        glVertex2f(1.6f, -0.7f);
        glVertex2f(1.6f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
        glColor3ub(96, 82, 118);
        glVertex2f(1.7f, -0.78f);
        glVertex2f(1.7f, -0.7f);
        glVertex2f(1.8f, -0.7f);
        glVertex2f(1.8f, -0.78f);
    glEnd();

    glBegin(GL_POLYGON); // window 3
        glColor3ub(96, 82, 118);
        glVertex2f(1.9f, -0.78f);
        glVertex2f(1.9f, -0.7f);
        glVertex2f(1.99f, -0.7f);
        glVertex2f(1.99f, -0.78f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(1.45f, -2.0f); // body
        glVertex2f(1.45f, -0.7f);

        glVertex2f(1.45f, -0.7f);
        glVertex2f(1.65f, -0.55f);

        glVertex2f(1.65f, -0.55f);
        glVertex2f(1.65f, -0.7f);

        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.85f, -0.55f);

        glVertex2f(1.85f, -0.55f);
        glVertex2f(1.85f, -0.7f);

        glVertex2f(1.85f, -0.7f);
        glVertex2f(2.05f, -0.55f);

        glVertex2f(2.05f, -0.55f);
        glVertex2f(2.05f, -0.7f);

        glVertex2f(1.45f, -0.7f); // roof
        glVertex2f(1.45f, -0.66f);

        glVertex2f(1.45f, -0.66f);
        glVertex2f(1.6f, -0.55f);

        glVertex2f(1.6f, -0.55f);
        glVertex2f(1.65f, -0.55f);

        glVertex2f(1.65f, -0.55f);
        glVertex2f(1.45f, -0.7f);

        glVertex2f(1.65f, -0.7f);
        glVertex2f(1.65f, -0.66f);

        glVertex2f(1.65f, -0.66f);
        glVertex2f(1.8f, -0.55f);

        glVertex2f(1.8f, -0.55f);
        glVertex2f(1.85f, -0.55f);

        glVertex2f(1.85f, -0.55f);
        glVertex2f(1.65f, -0.7f);

        glVertex2f(1.85f, -0.7f);
        glVertex2f(1.85f, -0.66f);

        glVertex2f(1.85f, -0.66f);
        glVertex2f(2.0f, -0.55f);

        glVertex2f(2.0f, -0.55f);
        glVertex2f(2.05f, -0.55f);

        glVertex2f(2.05f, -0.55f);
        glVertex2f(1.85f, -0.7f);

        glColor3ub(217, 217, 217);
        glVertex2f(1.5f, -0.78f); // window 1
        glVertex2f(1.5f, -0.7f);

        glVertex2f(1.5f, -0.7f);
        glVertex2f(1.6f, -0.7f);

        glVertex2f(1.6f, -0.7f);
        glVertex2f(1.6f, -0.78f);

        glVertex2f(1.6f, -0.78f);
        glVertex2f(1.5f, -0.78f);

        glVertex2f(1.6f, -0.74f);
        glVertex2f(1.5f, -0.74f);

        glVertex2f(1.55f, -0.7f);
        glVertex2f(1.55f, -0.78f);

        glVertex2f(1.7f, -0.78f); // window 2
        glVertex2f(1.7f, -0.7f);

        glVertex2f(1.7f, -0.7f);
        glVertex2f(1.8f, -0.7f);

        glVertex2f(1.8f, -0.7f);
        glVertex2f(1.8f, -0.78f);

        glVertex2f(1.8f, -0.78f);
        glVertex2f(1.7f, -0.78f);

        glVertex2f(1.8f, -0.74f);
        glVertex2f(1.7f, -0.74f);

        glVertex2f(1.75f, -0.7f);
        glVertex2f(1.75f, -0.78f);

        glVertex2f(1.9f, -0.78f); // window 3
        glVertex2f(1.9f, -0.7f);

        glVertex2f(1.9f, -0.7f);
        glVertex2f(1.99f, -0.7f);

        glVertex2f(1.99f, -0.7f);
        glVertex2f(1.99f, -0.78f);

        glVertex2f(1.99f, -0.78f);
        glVertex2f(1.9f, -0.78f);

        glVertex2f(1.99f, -0.74f);
        glVertex2f(1.9f, -0.74f);

        glVertex2f(1.95f, -0.7f);
        glVertex2f(1.95f, -0.78f);
    glEnd();

    glColor3ub(255, 217, 179);
    char *P="F A C T O R Y";
    glRasterPos2f(1.55f , -0.9);
    for(int i = 0; P[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, P[i]);
}

void fence() {
    glBegin(GL_LINES);
        glColor3ub(204, 0, 0);
        glVertex2f(-2.0f, 0.6f); // left
        glVertex2f(0.39f, 0.6f);

        glVertex2f(-2.0f, 0.53f);
        glVertex2f(0.39f, 0.53f);

        glVertex2f(-1.98f, 0.5f);
        glVertex2f(-1.98f, 0.63f);

        glVertex2f(-1.5f, 0.5f);
        glVertex2f(-1.5f, 0.63f);

        glVertex2f(-1.45f, 0.5f);
        glVertex2f(-1.45f, 0.63f);

        glVertex2f(-0.4f, 0.5f);
        glVertex2f(-0.4f, 0.63f);

        glVertex2f(-0.85f, 0.5f);
        glVertex2f(-0.85f, 0.63f);

        glVertex2f(-0.8f, 0.5f);
        glVertex2f(-0.8f, 0.63f);

        glVertex2f(-0.17f, 0.5f);
        glVertex2f(-0.17f, 0.63f);

        glVertex2f(0.37f, 0.5f);
        glVertex2f(0.37f, 0.63f);

        glVertex2f(2.0f, 0.6f); // right
        glVertex2f(1.42f, 0.6f);

        glVertex2f(2.0f, 0.53f);
        glVertex2f(1.42f, 0.53f);

        glVertex2f(1.95f, 0.5f);
        glVertex2f(1.95f, 0.63f);

        glVertex2f(1.9f, 0.5f);
        glVertex2f(1.9f, 0.63f);

        glVertex2f(1.85f, 0.5f);
        glVertex2f(1.85f, 0.63f);

        glVertex2f(1.8f, 0.5f);
        glVertex2f(1.8f, 0.63f);

        glVertex2f(1.75f, 0.5f);
        glVertex2f(1.75f, 0.63f);

        glVertex2f(1.7f, 0.5f);
        glVertex2f(1.7f, 0.63f);

        glVertex2f(1.65f, 0.5f);
        glVertex2f(1.65f, 0.63f);

        glVertex2f(1.6f, 0.5f);
        glVertex2f(1.6f, 0.63f);

        glVertex2f(1.55f, 0.5f);
        glVertex2f(1.55f, 0.63f);

        glVertex2f(1.5f, 0.5f);
        glVertex2f(1.5f, 0.63f);

        glVertex2f(1.45f, 0.5f);
        glVertex2f(1.45f, 0.63f);
    glEnd();
}

void road_footpath()
{
    // road start
    glBegin(GL_POLYGON); //Horizontal road
        glColor3ub(95, 96, 91);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON); //Vertical Road
        glColor3ub(95, 96, 91);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(0.4f, -1.0f);
    glEnd();
    //road end

    // footpath start
    glBegin(GL_POLYGON); //Left Upper Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(-2.0f, 0.3f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); //Left Down Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(-2.0f, -0.5f);
        glVertex2f(-2.0f, -0.3f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON); //Right Down Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(2.0f, -0.3f);
        glVertex2f(1.2f, -0.3f);
        glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON); //Right Upper Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, 0.3f);
        glVertex2f(1.2f, 0.3f);
        glVertex2f(1.2f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); //Left Down Vertical Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(0.4f, -1.0f);
        glVertex2f(0.6f, -1.0f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON); //Right Down Vertical Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(1.2f, -1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(1.4f, -0.3f);
        glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON); //Right Upper Vertical Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(1.2f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, 0.3f);
        glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON); //Left Upper Vertical Footpath
        glColor3ub(255, 179, 102);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(0.6f, 1.0f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.4f, 0.3f);
    glEnd();
    //footpath end

    // divider start
    glLineWidth(3.0f); //line divider wide
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255); //white color
        glVertex2f(-2.0f, 0.0f); //start from left
        glVertex2f(-1.8f, 0.0f); //1st divider

        glVertex2f(-1.7f, 0.0f); //2nd divider
        glVertex2f(-1.5f, 0.0f);

        glVertex2f(-1.4f, 0.0f); //3rd divider
        glVertex2f(-1.2f, 0.0f);

        glVertex2f(-1.1f, 0.0f); //4th divider
        glVertex2f(-0.9f, 0.0f);

        glVertex2f(-0.8f, 0.0f); //5th divider
        glVertex2f(-0.6f, 0.0f);

        glVertex2f(-0.5f, 0.0f); //6th divider
        glVertex2f(-0.3f, 0.0f);

        glVertex2f(-0.2f, 0.0f); //7th divider
        glVertex2f(0.0f, 0.0f);

        glVertex2f(1.7f, 0.0f); //Right side divider
        glVertex2f(1.9f, 0.0f);

        glVertex2f(0.9f, 0.8f); //Upper divider
        glVertex2f(0.9f, 0.97f);

        glVertex2f(0.9f, -0.97f); //Down divider
        glVertex2f(0.9f, -0.8f);
    glEnd();
        //divider end

        // zebra-crossing start
    glLineWidth(5.0f); //zebra crossing line width
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255); //white color
        glVertex2f(0.2f, 0.3f); //Left side 1st line
        glVertex2f(0.2f, -0.3f);

        glVertex2f(0.4f, -0.3f); //left side 2nd line
        glVertex2f(0.4f, 0.3f);

        glVertex2f(0.6f, 0.5f); //Upper side down line
        glVertex2f(1.2f, 0.5f);

        glVertex2f(0.6f, 0.7f); //Upper side upper line
        glVertex2f(1.2f, 0.7f);

        glVertex2f(1.4f, 0.3f); //Right side 1st line
        glVertex2f(1.4f, -0.3f);

        glVertex2f(1.6f, 0.3f); //Right side 2nd line
        glVertex2f(1.6f, -0.3f);

        glVertex2f(0.6f, -0.5f); //Down side upper line
        glVertex2f(1.2f, -0.5f);

        glVertex2f(0.6f, -0.7f); //Down side down line
        glVertex2f(1.2f, -0.7f);

        // left cross
        glVertex2f(0.2f, 0.3f); //start from upper 1st cross
        glVertex2f(0.4f, 0.2f);

        glVertex2f(0.2f, 0.2f); //2nd cross
        glVertex2f(0.4f, 0.1f);

        glVertex2f(0.2f, 0.1f); //3rd cross
        glVertex2f(0.4f, 0.0f);

        glVertex2f(0.2f, 0.0f); //4th cross
        glVertex2f(0.4f, -0.1f);

        glVertex2f(0.2f, -0.1f); //5th cross
        glVertex2f(0.4f, -0.2f);

        glVertex2f(0.2f, -0.2f); //6th cross
        glVertex2f(0.4f, -0.3f);

        // right cross
        glVertex2f(1.4f, 0.3f); //start from upper 1st cross
        glVertex2f(1.6f, 0.2f);

        glVertex2f(1.4f, 0.2f); //2nd cross
        glVertex2f(1.6f, 0.1f);

        glVertex2f(1.4f, 0.1f); //3rd cross
        glVertex2f(1.6f, 0.0f);

        glVertex2f(1.4f, 0.0f); //4th cross
        glVertex2f(1.6f, -0.1f);

        glVertex2f(1.4f, -0.1f); //5th cross
        glVertex2f(1.6f, -0.2f);

        glVertex2f(1.4f, -0.2f); //6th cross
        glVertex2f(1.6f, -0.3f);

        // bottom cross
        glVertex2f(0.7f, -0.5f); //start from left 1st cross
        glVertex2f(0.6f, -0.7f);

        glVertex2f(0.8f, -0.5f); //2nd cross
        glVertex2f(0.7f, -0.7f);

        glVertex2f(0.9f, -0.5f); //3rd cross
        glVertex2f(0.8f, -0.7f);

        glVertex2f(1.0f, -0.5f); //4th cross
        glVertex2f(0.9f, -0.7f);

        glVertex2f(1.1f, -0.5f); //5th cross
        glVertex2f(1.0f, -0.7f);

        glVertex2f(1.2f, -0.5f); //6th cross
        glVertex2f(1.1f, -0.7f);

        // top cross
        glVertex2f(0.6f, 0.5f); //start from left 1st cross
        glVertex2f(0.7f, 0.7f);

        glVertex2f(0.7f, 0.5f); //2nd cross
        glVertex2f(0.8f, 0.7f);

        glVertex2f(0.8f, 0.5f); //3rd cross
        glVertex2f(0.9f, 0.7f);

        glVertex2f(0.9f, 0.5f); //4th cross
        glVertex2f(1.0f, 0.7f);

        glVertex2f(1.0f, 0.5f); //5th cross
        glVertex2f(1.1f, 0.7f);

        glVertex2f(1.1f, 0.5f); //6th cross
        glVertex2f(1.2f, 0.7f);
    glEnd();
    //zebra crossing end

    glLineWidth(3.0f); // Footpath border width
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255); //white color

    // road border start
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255); //white color between footpath and green ground
        glVertex2f(-2.0f, 0.5f); //left upper border
        glVertex2f(0.4f, 0.5f);

        glVertex2f(0.4f, 0.5f); //vertical upper left border
        glVertex2f(0.4f, 1.0f);

        glVertex2f(1.4f, 1.0f); //vertical upper right border
        glVertex2f(1.4f, 0.5f);

        glVertex2f(1.4f, 0.5f); //Right upper border
        glVertex2f(2.0f, 0.5f);

        glVertex2f(2.0f, -0.5f); //Right down border
        glVertex2f(1.4f, -0.5f);

        glVertex2f(1.4f, -0.5f); //vertical down right border
        glVertex2f(1.4f, -1.0f);

        glVertex2f(0.4f, -1.0f); //vertical down left border
        glVertex2f(0.4f, -0.5f);

        glVertex2f(0.4f, -0.5f); //Left Down border
        glVertex2f(-2.0f, -0.5f);

        glColor3ub(230, 230, 230); //next to white color between footpath and road
        glVertex2f(-2.0f, 0.3f); //left upper white border
        glVertex2f(0.6f, 0.3f);

        glVertex2f(0.6f, 0.3f); //vertical upper left white border
        glVertex2f(0.6f, 1.0f);

        glVertex2f(1.2f, 1.0f); //vertical upper Right white border
        glVertex2f(1.2f, 0.3f);

        glVertex2f(1.2f, 0.3f); //Right upper white border
        glVertex2f(2.0f, 0.3f);

        glVertex2f(2.0f, -0.3f); //Right down white border
        glVertex2f(1.2f, -0.3f);

        glVertex2f(1.2f, -0.3f); //vertical down right white border
        glVertex2f(1.2f, -1.0f);

        glVertex2f(0.6f, -1.0f); //vertical down left white border
        glVertex2f(0.6f, -0.3f);

        glVertex2f(0.6f, -0.3f); //Left Down white border
        glVertex2f(-2.0f, -0.3f);
    glEnd();
    //road border end
}
//road_footpath function end

void traffic_light1() {
    // stand
    glBegin(GL_POLYGON); //Top
        glColor3ub(128, 0, 0);
        glVertex2f(0.45f, 0.38f);
        glVertex2f(0.45f, 0.42f);
        glVertex2f(0.55f, 0.42f);
        glVertex2f(0.55f, 0.38f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES); //above stand
        glColor3ub(153, 0, 0);
        glVertex2f(0.55f, 0.4f);
        glVertex2f(0.7f, 0.4f);

        glVertex2f(0.7f, 0.4f);
        glVertex2f(0.7f, 0.15f);
    glEnd();

    //light start
    glBegin(GL_POLYGON); //light box
        glColor3ub(204, 122, 0);
        glVertex2f(0.65f, 0.15f);
        glVertex2f(0.75f, 0.15f);
        glVertex2f(0.75f, -0.05f);
        glVertex2f(0.65f, -0.05f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES); //light small line
        glColor3ub(0, 0, 0);
        glVertex2f(0.65f, 0.15f); //top
        glVertex2f(0.75f, 0.15f);

        glVertex2f(0.75f, 0.15f); //right
        glVertex2f(0.75f, -0.05f);

        glVertex2f(0.75f, -0.05f); //bottom
        glVertex2f(0.65f, -0.05f);

        glVertex2f(0.65f, -0.05f); //left
        glVertex2f(0.65f, 0.15f);
        // side
        glVertex2f(0.65f, 0.1f); //left 1st
        glVertex2f(0.6f, 0.1f);

        glVertex2f(0.65f, 0.05f); //left 2nd
        glVertex2f(0.62f, 0.05f);

        glVertex2f(0.65f, 0.0f); //left 3rd
        glVertex2f(0.63f, 0.0f);

        glVertex2f(0.75f, 0.1f); //right 1st
        glVertex2f(0.8f, 0.1f);

        glVertex2f(0.75f, 0.05f);//right 2nd
        glVertex2f(0.78f, 0.05f);

        glVertex2f(0.75f, 0.0f); //right 3rd
        glVertex2f(0.77f, 0.0f);
    glEnd();

    x=0.7f; y=0.1f; radius =.02f; // red
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(204, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.7f; y=0.05f; radius =.02f; // yellow
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 204, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.7f; y=0.0f; radius =.02f; // green
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 128, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    // light end
}

void traffic_light2() {
    // stand
     glBegin(GL_POLYGON);
        glColor3ub(128, 0, 0);
        glVertex2f(1.28f, -0.35f);
        glVertex2f(1.32f, -0.35f);
        glVertex2f(1.32f, -0.45f);
        glVertex2f(1.28f, -0.45f);
    glEnd();
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 0, 0);
        glVertex2f(1.3f, -0.35f);
        glVertex2f(1.3f, -0.2f);

        glVertex2f(1.3f, -0.2f);
        glVertex2f(1.0f, -0.2f);
    glEnd();

    // light start
    glBegin(GL_POLYGON);
        glColor3ub(204, 122, 0);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, -0.3f);
        glVertex2f(0.9f, -0.3f);
    glEnd();
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(0, 0, 0);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(1.0f, -0.1f);

        glVertex2f(1.0f, -0.1f);
        glVertex2f(1.0f, -0.3f);

        glVertex2f(1.0f, -0.3f);
        glVertex2f(0.9f, -0.3f);

        glVertex2f(0.9f, -0.3f);
        glVertex2f(0.9f, -0.1f);
        // side
        glVertex2f(0.9f, -0.15f);
        glVertex2f(0.85f, -0.15f);

        glVertex2f(0.9f, -0.2f);
        glVertex2f(0.87f, -0.2f);

        glVertex2f(0.9f, -0.25f);
        glVertex2f(0.88f, -0.25f);

        glVertex2f(1.0f, -0.15f);
        glVertex2f(1.05f, -0.15f);

        glVertex2f(1.0f, -0.2f);
        glVertex2f(1.03f, -0.2f);

        glVertex2f(1.0f, -0.25f);
        glVertex2f(1.02f, -0.25f);
    glEnd();

    x=0.95f; y=-0.15f; radius =.02f; // red
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(204, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.95f; y=-0.2f; radius =.02f; // yellow
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 204, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.95f; y=-0.25f; radius =.02f; // green
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 128, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    // light end
}

void road_light() {
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);//down stand
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);//upper stand
        glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON); //light box
        glColor3ub(191, 191, 191);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //ground point stand
	glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
	glEnd();

    for(int i = 0; i < 3; i++) { //for other 3 road light
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
            glColor3ub(128, 128, 128);
            glVertex2f(-1.9f, 0.4f);
            glVertex2f(-1.8f, 0.4f);

            glVertex2f(-1.8f, 0.4f);
            glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(191, 191, 191);
            glVertex2f(-1.85f, 0.25f);
            glVertex2f(-1.8f, 0.25f);
            glVertex2f(-1.8f, 0.1f);
            glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3ub(89, 89, 89);
            glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
    glEnd();

    for(int i = 0; i < 3; i++){
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
            glColor3ub(128, 128, 128);
            glVertex2f(-1.6f, -0.4f);
            glVertex2f(-1.5f, -0.4f);

            glVertex2f(-1.5f, -0.4f);
            glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(191, 191, 191);
            glVertex2f(-1.5f, -0.1f);
            glVertex2f(-1.55f, -0.1f);
            glVertex2f(-1.55f, -0.25f);
            glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3ub(89, 89, 89);
            glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.4f, 0.4f);
        glVertex2f(1.5f, 0.4f);

        glVertex2f(1.5f, 0.4f);
        glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(1.5f, 0.1f);
        glVertex2f(1.45f, 0.1f);
        glVertex2f(1.45f, 0.25f);
        glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.7f, -0.4f);
        glVertex2f(1.8f, -0.4f);

        glVertex2f(1.8f, -0.4f);
        glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(1.8f, -0.1f);
        glVertex2f(1.75f, -0.1f);
        glVertex2f(1.75f, -0.25f);
        glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(0.5f, -0.7f);
        glVertex2f(0.5f, -0.6f);

        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.8f, -0.65f);
        glVertex2f(0.65f, -0.65f);
        glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.3f, -1.0f);
        glVertex2f(1.3f, -0.9f);

        glVertex2f(1.3f, -0.9f);
        glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(1.0f, -0.95f);
        glVertex2f(1.15f, -0.95f);
        glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(0.5f, 0.8f);
        glVertex2f(0.5f, 0.9f);

        glVertex2f(0.5f, 0.9f);
        glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(0.8f, 0.9f);
        glVertex2f(0.8f, 0.85f);
        glVertex2f(0.65f, 0.85f);
        glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.3f, 0.5f);
        glVertex2f(1.3f, 0.6f);

        glVertex2f(1.3f, 0.6f);
        glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(191, 191, 191);
        glVertex2f(1.0f, 0.6f);
        glVertex2f(1.0f, 0.55f);
        glVertex2f(1.15f, 0.55f);
        glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.3f, 0.5f);
    glEnd();
}

void boat1() {
    glPushMatrix();
	glTranslatef(position_b1,0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glColor3ub(255, 140, 26);
        glVertex2f(-0.05f, -0.75f);
        glVertex2f(-0.05f, -0.8f);
        glVertex2f(0.1f, -0.8f);
        glVertex2f(0.1f, -0.75f);
    glEnd();

    x=0.1f; y=-0.8f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 140, 26);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.05f; y=-0.8f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(179, 89, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    glBegin(GL_POLYGON);
        glColor3ub(102, 51, 0);
        glVertex2f(-0.25f, -0.8f);
        glVertex2f(0.25f, -0.8f);
        glVertex2f(0.15f, -0.85f);
        glVertex2f(-0.15f, -0.85f);
    glEnd();
    glPopMatrix();
}

void boat2() {
    glPushMatrix();
	glTranslatef(position_b2,0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glColor3ub(230, 230, 0);
        glVertex2f(-0.05f, -0.6f);
        glVertex2f(-0.05f, -0.65f);
        glVertex2f(0.1f, -0.65f);
        glVertex2f(0.1f, -0.6f);
    glEnd();

    x=0.1f; y=-0.65f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(153, 153, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=-0.05f; y=-0.65f; radius =.05f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(230, 230, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    glBegin(GL_POLYGON);
        glColor3ub(0, 0, 0);
        glVertex2f(-0.25f, -0.65f);
        glVertex2f(0.25f, -0.65f);
        glVertex2f(0.15f, -0.7f);
        glVertex2f(-0.15f, -0.7f);
    glEnd();

    glPopMatrix();
}

void car1() {
    glPushMatrix();
	glTranslatef(position_c1, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
        glColor3ub(230, 0, 0);
        glVertex2f(-0.2f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.2f, 0.05f);
        glVertex2f(-0.22f, 0.07f);
        glVertex2f(-0.22f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.18f, 0.06f);
        glVertex2f(-0.18f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(230, 0, 0);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.15f, 0.21f);
        glVertex2f(-0.15f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if(flag != 0) {
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(230, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.03f, 0.21f);

        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.07f, 0.06f);

        glVertex2f(-0.18f, 0.06f);
        glVertex2f(-0.15f, 0.09f);

        glVertex2f(-0.15f, 0.21f);
        glVertex2f(-0.18f, 0.24f);

        glVertex2f(-0.06f, 0.24f);
        glVertex2f(-0.06f, 0.21f);

        glVertex2f(-0.06f, 0.09f);
        glVertex2f(-0.06f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car2() {
    glPushMatrix();
	glTranslatef(position_c2, 0.0f, 0.0f);
	glRotatef(180, 0.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 204, 0);
        glVertex2f(-0.04f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.04f, 0.05f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.03f, 0.06f);
        glVertex2f(-0.03f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(255, 204, 0);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.07f, 0.21f);
        glVertex2f(-0.07f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if(flag != 0) {
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_POLYGON); // lorry
        glColor3ub(242, 242, 242);
        glVertex2f(-0.06f, 0.25f);
        glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.5f, 0.05f);
        glVertex2f(-0.5f, 0.25f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 204, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.03f, 0.21f);

        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.07f, 0.06f);

        glVertex2f(-0.03f, 0.24f);
        glVertex2f(-0.03f, 0.21f);

        glVertex2f(-0.03f, 0.09f);
        glVertex2f(-0.03f, 0.06f);

        glColor3ub(217, 217, 217);
        glVertex2f(-0.06f, 0.25f);
        glVertex2f(-0.06f, 0.05f);

        glVertex2f(-0.06f, 0.05f);
        glVertex2f(-0.5f, 0.05f);

        glVertex2f(-0.5f, 0.05f);
        glVertex2f(-0.5f, 0.25f);

        glVertex2f(-0.5f, 0.25f);
        glVertex2f(-0.06f, 0.25f);
    glEnd();

    glPopMatrix();
}

void car3() {
    glPushMatrix();
	glTranslatef(0.9, position_c3, 0.0f);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 255, 255);
        glVertex2f(-0.13f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.13f, 0.05f);
        glVertex2f(-0.15f, 0.07f);
        glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(255, 255, 255);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if(flag != 0) {
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.03f, 0.21f);

        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.07f, 0.06f);

        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.1f, 0.09f);

        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.13f, 0.24f);

        glVertex2f(-0.03f, 0.24f);
        glVertex2f(-0.03f, 0.21f);

        glVertex2f(-0.03f, 0.09f);
        glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void car4() {
    glPushMatrix();
	glTranslatef(0.9f, position_c4, 0.0f);
	glRotatef(270 ,0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON); // body
        glColor3ub(51, 102, 255);
        glVertex2f(-0.13f, 0.25f);
        glVertex2f(0.07f, 0.25f);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(-0.13f, 0.05f);
        glVertex2f(-0.15f, 0.07f);
        glVertex2f(-0.15f, 0.23f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(0, 0, 0);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.07f, 0.06f);
        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.13f, 0.24f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(51, 102, 255);
        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.03f, 0.21f);
        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.1f, 0.09f);
    glEnd();

    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.23f);
        glVertex2f(0.17f, 0.2f);
        glVertex2f(0.14f, 0.2f);
        glVertex2f(0.14f, 0.23f);
    glEnd();
    glBegin(GL_POLYGON); // light
        glColor3ub(242, 242, 242);
        glVertex2f(0.15f, 0.07f);
        glVertex2f(0.17f, 0.1f);
        glVertex2f(0.14f, 0.1f);
        glVertex2f(0.14f, 0.07f);
    glEnd();

    if(flag != 0) {
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.2f);
            glVertex2f(0.14f, 0.23f);
            glVertex2f(0.45f, 0.3f);
            glVertex2f(0.45f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON); // head-light
            glColor3ub(255, 255, 204);
            glVertex2f(0.17f, 0.1f);
            glVertex2f(0.14f, 0.07f);
            glVertex2f(0.45f, 0.0f);
            glVertex2f(0.45f, 0.2f);
        glEnd();
    }

    glBegin(GL_LINES);
        glColor3ub(51, 102, 255);
        glVertex2f(0.07f, 0.24f);
        glVertex2f(0.03f, 0.21f);

        glVertex2f(0.03f, 0.09f);
        glVertex2f(0.07f, 0.06f);

        glVertex2f(-0.13f, 0.06f);
        glVertex2f(-0.1f, 0.09f);

        glVertex2f(-0.1f, 0.21f);
        glVertex2f(-0.13f, 0.24f);

        glVertex2f(-0.03f, 0.24f);
        glVertex2f(-0.03f, 0.21f);

        glVertex2f(-0.03f, 0.09f);
        glVertex2f(-0.03f, 0.06f);
    glEnd();

    glPopMatrix();
}

void river() {
    glBegin(GL_POLYGON);
        glColor3ub(51, 204, 255);
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(-2.0f, -0.55f);
        glVertex2f(0.35f, -0.55f);
        glVertex2f(0.35f, -2.0f);
    glEnd();

    glPushMatrix();
	glTranslatef(position_r,0.0f, 0.0f);

    x=1.0f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=0.5f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    x=0.0f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.5f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.0f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.5f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-2.0f; y=-1.3f; radius =0.6f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 191, 255);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPopMatrix();
}

void redgreen1 () { //top traffic light
    x=0.7f; y=0.1f; radius =.02f; // red
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 51, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.95f; y=-0.25f; radius =.02f; // green
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 255, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void redgreen2 () { //bottom traffic light
    x=0.7f; y=0.0f; radius =.02f; // green
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 255, 0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	x=0.95f; y=-0.15f; radius =.02f; // red
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(255, 51, 51);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void rain() {
    glPushMatrix();
    glTranslatef(position_rain2, position_rain, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.9f);
        glVertex2f(0.05f, 0.85f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(0.05f, 0.65f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.05f, 0.45f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.05f, 0.25f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.0f, 0.1f);
        glVertex2f(0.05f, 0.05f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.9f);
        glVertex2f(0.0f, -0.85f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.7f);
        glVertex2f(0.0f, -0.65f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.5f);
        glVertex2f(0.0f, -0.45f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.3f);
        glVertex2f(0.0f, -0.25f);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.05f, -0.1f);
        glVertex2f(0.0f, -0.05f);
    glEnd();

    for(int i = 0; i < 100; i++) {
        glTranslatef(-0.2, 0.0, 0.0f);
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.9f);
            glVertex2f(0.05f, 0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.7f);
            glVertex2f(0.05f, 0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.05f, 0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.3f);
            glVertex2f(0.05f, 0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.1f);
            glVertex2f(0.05f, 0.05f);
        glEnd();

        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.9f);
            glVertex2f(0.0f, -0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.7f);
            glVertex2f(0.0f, -0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.5f);
            glVertex2f(0.0f, -0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.3f);
            glVertex2f(0.0f, -0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.1f);
            glVertex2f(0.0f, -0.05f);
        glEnd();
    }

    for(int i = 0; i < 100; i++) {
        glTranslatef(0.2, 0.0, 0.0f);
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.9f);
            glVertex2f(0.05f, 0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.7f);
            glVertex2f(0.05f, 0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.5f);
            glVertex2f(0.05f, 0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.3f);
            glVertex2f(0.05f, 0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.0f, 0.1f);
            glVertex2f(0.05f, 0.05f);
        glEnd();

        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.9f);
            glVertex2f(0.0f, -0.85f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.7f);
            glVertex2f(0.0f, -0.65f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.5f);
            glVertex2f(0.0f, -0.45f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.3f);
            glVertex2f(0.0f, -0.25f);
        glEnd();
        glBegin(GL_LINES);
            glColor3ub(255, 255, 255);
            glVertex2f(0.05f, -0.1f);
            glVertex2f(0.0f, -0.05f);
        glEnd();
    }
    glPopMatrix();
}

void start()
{
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque

    glBegin(GL_POLYGON); //set the 1st Project start window size and mixed color
        glColor3ub(255,255,0);
        glVertex2f(-2.0f, 2.0f);
        glColor3ub(147,112,219);
        glVertex2f(2.0f, 2.0f);
        glColor3ub(30,144,255);
        glVertex2f(2.0f, -2.0f);
        glColor3ub(70,130,180);
        glVertex2f(-2.0f, -2.0f);
    glEnd();

    glColor3ub(255, 255, 255); // color of "Traffic View of a signal"
    c="Traffic View of A Signal";
    glRasterPos2f(-0.3, 0.7);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    glColor3ub(0, 0, 0);
    c="Features: \n-> Press 'R' = Turn on RED signal for HORIZONTAL road and Turn on GREEN signal for VERTICAL road. \n-> Press 'G' = Turn on GREEN signal for HORIZONTAL road and Turn on RED signal for VERTICAL road.";
    float x = 0.3f;
    glRasterPos2f(-1.5, 0.3);
    for(int i = 0; c[i] !='\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
        if(c[i] == '\n')
            glRasterPos2f(-1.5, x = x-0.1);
    }

    glColor3ub(0, 0, 0);
    c="-> Press 'D' = Switch to DAY view. \n-> Press 'N' = Switch to NIGHT view. \n-> Press 'LMB' = Start RAIN. \n-> Press 'RMB' = Stop RAIN.";
    glRasterPos2f(-1.5, x = x-0.1);
    for(int i = 0; c[i] !='\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);
        if(c[i] == '\n')
            glRasterPos2f(-1.5, x = x-0.1);
    }

    glColor3ub(255, 0, 0); //color of "Press S to start the project"
    c="Press S to START the project";
    glRasterPos2f(-0.3, -0.7);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    glFlush();
}

void day()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON); //color the left up and down and right upper part
        glColor3ub(51, 204, 51); //light green color
        glVertex2f(2.0f, 1.0f);
        glVertex2f(2.0f, -1.0f);
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(-2.0f, 1.0f);
    glEnd();

    river();

    glBegin(GL_POLYGON); //color rest of the portion
        glColor3ub(51, 204, 51);
        glVertex2f(0.35f, -0.5f);
        glVertex2f(1.9f, -0.5f);
        glVertex2f(1.9f, -1.0f);
        glVertex2f(0.35f, -1.0f);
    glEnd();

	tree();
	road_footpath();
	car1();
    car2();
    car3();
    car4();
	traffic_light1();
	traffic_light2();
    road_light();
    factory();

    glPushMatrix();
        windmill();
    glPopMatrix();

    fence();
    shop();
    house();
    boat1();
    boat2();
    // shop open
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 204);
        glVertex2f(-1.72f, 0.57f);
        glVertex2f(-1.72f, 0.6f);
        glVertex2f(-1.65f, 0.6f);
        glVertex2f(-1.65f, 0.57f);
    glEnd();

    glColor3ub(255, 51, 0);
    c="open";
    glRasterPos2f(-1.715 , 0.58);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c[i]);
    // shop open

    if(cnt == 0)
        redgreen2();
    else
        redgreen1();

    if(r != 0)
        rain();

    glFlush();
}

void night() {
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    // Background
    glBegin(GL_POLYGON);
        glColor3ub(41, 163, 41);
        glVertex2f(2.0f, 1.0f);
        glVertex2f(2.0f, -1.0f);
        glVertex2f(-2.0f, -1.0f);
        glVertex2f(-2.0f, 1.0f);
    glEnd();


    river();

    glBegin(GL_POLYGON);
        glColor3ub(41, 163, 41);
        glVertex2f(0.35f, -0.5f);
        glVertex2f(1.9f, -0.5f);
        glVertex2f(1.9f, -1.0f);
        glVertex2f(0.35f, -1.0f);
    glEnd();
    // Objects

    /// tree start
    // circle tree 1
    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-1.5f, 0.8f);
        glVertex2f(-1.5f, 0.55f);
    glEnd();
    x=-1.45f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.5f; y=0.85f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-1.55f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	glPointSize(5.0);
	glBegin(GL_POINTS); // fruits
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.53f, 0.85f);
        glVertex2f(-1.47f, 0.8f);
	glEnd();

    // circle tree 2
	glLineWidth(10.0f);
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.8f, 0.8f);
        glVertex2f(-0.8f, 0.57f);
    glEnd();
    x=-0.85f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.8f; y=0.85f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	x=-0.75f; y=0.82f; radius =0.08f;
	triangleAmount = 50;
	twicePi = 2.0f * PI;
	glColor3ub(0, 102, 34);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(int i = 0; i <= triangleAmount;i++) {
			glVertex2f(
                x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

    // triangle tree 1
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.55f, 0.65f);
        glVertex2f(1.55f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 102, 34);
        glVertex2f(1.45f, 0.7f);
        glVertex2f(1.55f, 0.95f);
        glVertex2f(1.65f, 0.7f);
    glEnd();

	// triangle tree 2
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(-0.2f, 0.65f);
        glVertex2f(-0.2f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 102, 34);
        glVertex2f(-0.3f, 0.7f);
        glVertex2f(-0.2f, 0.95f);
        glVertex2f(-0.1f, 0.7f);
    glEnd();

    // triangle tree 3
    glBegin(GL_LINES);
        glColor3ub(153, 51, 51);
        glVertex2f(1.9f, 0.7f);
        glVertex2f(1.9f, 0.85f);
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3ub(0, 102, 34);
        glVertex2f(1.8f, 0.75f);
        glVertex2f(1.9f, 1.0f);
        glVertex2f(2.0f, 0.75f);
    glEnd();
    /// tree end

	/// road start
    glBegin(GL_POLYGON);
        glColor3ub(77, 77, 77);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(-2.0f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(77, 77, 77);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(0.4f, -1.0f);
    glEnd();

    // footpath
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(-2.0f, 0.3f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.6f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(-2.0f, -0.5f);
        glVertex2f(-2.0f, -0.3f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.6f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(2.0f, -0.5f);
        glVertex2f(2.0f, -0.3f);
        glVertex2f(1.2f, -0.3f);
        glVertex2f(1.2f, -0.5f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(2.0f, 0.5f);
        glVertex2f(2.0f, 0.3f);
        glVertex2f(1.2f, 0.3f);
        glVertex2f(1.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(0.4f, -1.0f);
        glVertex2f(0.6f, -1.0f);
        glVertex2f(0.6f, -0.3f);
        glVertex2f(0.4f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(1.2f, -1.0f);
        glVertex2f(1.4f, -1.0f);
        glVertex2f(1.4f, -0.3f);
        glVertex2f(1.2f, -0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(1.2f, 1.0f);
        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, 0.3f);
        glVertex2f(1.2f, 0.3f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 166, 77);
        glVertex2f(0.4f, 1.0f);
        glVertex2f(0.6f, 1.0f);
        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.4f, 0.3f);
    glEnd();

    // divider
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(-2.0f, 0.0f);
        glVertex2f(-1.8f, 0.0f);

        glVertex2f(-1.7f, 0.0f);
        glVertex2f(-1.5f, 0.0f);

        glVertex2f(-1.4f, 0.0f);
        glVertex2f(-1.2f, 0.0f);

        glVertex2f(-1.1f, 0.0f);
        glVertex2f(-0.9f, 0.0f);

        glVertex2f(-0.8f, 0.0f);
        glVertex2f(-0.6f, 0.0f);

        glVertex2f(-0.5f, 0.0f);
        glVertex2f(-0.3f, 0.0f);

        glVertex2f(-0.2f, 0.0f);
        glVertex2f(0.0f, 0.0f);

        glVertex2f(1.7f, 0.0f);
        glVertex2f(1.9f, 0.0f);

        glVertex2f(0.9f, 0.8f);
        glVertex2f(0.9f, 0.97f);

        glVertex2f(0.9f, -0.97f);
        glVertex2f(0.9f, -0.8f);
    glEnd();

    // zebra-crossing start
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.2f, -0.3f);

        glVertex2f(0.4f, -0.3f);
        glVertex2f(0.4f, 0.3f);

        glVertex2f(0.6f, 0.5f);
        glVertex2f(1.2f, 0.5f);

        glVertex2f(0.6f, 0.7f);
        glVertex2f(1.2f, 0.7f);

        glVertex2f(1.4f, 0.3f);
        glVertex2f(1.4f, -0.3f);

        glVertex2f(1.6f, 0.3f);
        glVertex2f(1.6f, -0.3f);

        glVertex2f(0.6f, -0.5f);
        glVertex2f(1.2f, -0.5f);

        glVertex2f(0.6f, -0.7f);
        glVertex2f(1.2f, -0.7f);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        // left cross
        glVertex2f(0.2f, 0.3f);
        glVertex2f(0.4f, 0.2f);

        glVertex2f(0.2f, 0.2f);
        glVertex2f(0.4f, 0.1f);

        glVertex2f(0.2f, 0.1f);
        glVertex2f(0.4f, 0.0f);

        glVertex2f(0.2f, 0.0f);
        glVertex2f(0.4f, -0.1f);

        glVertex2f(0.2f, -0.1f);
        glVertex2f(0.4f, -0.2f);

        glVertex2f(0.2f, -0.2f);
        glVertex2f(0.4f, -0.3f);

        // right cross
        glVertex2f(1.4f, 0.3f);
        glVertex2f(1.6f, 0.2f);

        glVertex2f(1.4f, 0.2f);
        glVertex2f(1.6f, 0.1f);

        glVertex2f(1.4f, 0.1f);
        glVertex2f(1.6f, 0.0f);

        glVertex2f(1.4f, 0.0f);
        glVertex2f(1.6f, -0.1f);

        glVertex2f(1.4f, -0.1f);
        glVertex2f(1.6f, -0.2f);

        glVertex2f(1.4f, -0.2f);
        glVertex2f(1.6f, -0.3f);

        // bottom cross
        glVertex2f(0.7f, -0.5f);
        glVertex2f(0.6f, -0.7f);

        glVertex2f(0.8f, -0.5f);
        glVertex2f(0.7f, -0.7f);

        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.8f, -0.7f);

        glVertex2f(1.0f, -0.5f);
        glVertex2f(0.9f, -0.7f);

        glVertex2f(1.1f, -0.5f);
        glVertex2f(1.0f, -0.7f);

        glVertex2f(1.2f, -0.5f);
        glVertex2f(1.1f, -0.7f);

        // top cross
        glVertex2f(0.6f, 0.5f);
        glVertex2f(0.7f, 0.7f);

        glVertex2f(0.7f, 0.5f);
        glVertex2f(0.8f, 0.7f);

        glVertex2f(0.8f, 0.5f);
        glVertex2f(0.9f, 0.7f);

        glVertex2f(0.9f, 0.5f);
        glVertex2f(1.0f, 0.7f);

        glVertex2f(1.0f, 0.5f);
        glVertex2f(1.1f, 0.7f);

        glVertex2f(1.1f, 0.5f);
        glVertex2f(1.2f, 0.7f);
    glEnd();
    // zebra-crossing end

    // road border
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glColor3ub(102, 102, 102);
        glVertex2f(-2.0f, 0.5f);
        glVertex2f(0.4f, 0.5f);

        glVertex2f(0.4f, 0.5f);
        glVertex2f(0.4f, 1.0f);

        glVertex2f(1.4f, 1.0f);
        glVertex2f(1.4f, 0.5f);

        glVertex2f(1.4f, 0.5f);
        glVertex2f(2.0f, 0.5f);

        glVertex2f(2.0f, -0.5f);
        glVertex2f(1.4f, -0.5f);

        glVertex2f(1.4f, -0.5f);
        glVertex2f(1.4f, -1.0f);

        glVertex2f(0.4f, -1.0f);
        glVertex2f(0.4f, -0.5f);

        glVertex2f(0.4f, -0.5f);
        glVertex2f(-2.0f, -0.5f);

        glColor3ub(230, 230, 230);
        glVertex2f(-2.0f, 0.3f);
        glVertex2f(0.6f, 0.3f);

        glVertex2f(0.6f, 0.3f);
        glVertex2f(0.6f, 1.0f);

        glVertex2f(1.2f, 1.0f);
        glVertex2f(1.2f, 0.3f);

        glVertex2f(1.2f, 0.3f);
        glVertex2f(2.0f, 0.3f);

        glVertex2f(2.0f, -0.3f);
        glVertex2f(1.2f, -0.3f);

        glVertex2f(1.2f, -0.3f);
        glVertex2f(1.2f, -1.0f);

        glVertex2f(0.6f, -1.0f);
        glVertex2f(0.6f, -0.3f);

        glVertex2f(0.6f, -0.3f);
        glVertex2f(-2.0f, -0.3f);
    glEnd();
    /// road end

	car1();
    car2();
    car3();
    car4();
	traffic_light1();
	traffic_light2();

    /// road-light start
    glLineWidth(3.0f);
    // left-up
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.9f, 0.4f);
        glVertex2f(-1.8f, 0.4f);

        glVertex2f(-1.8f, 0.4f);
        glVertex2f(-1.8f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.85f, 0.25f);
        glVertex2f(-1.8f, 0.25f);
        glVertex2f(-1.8f, 0.1f);
        glVertex2f(-1.85f, 0.1f);
    glEnd();
    glPointSize(10.0); //
	glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.9f, 0.4f);
	glEnd();

    for(int i = 0; i < 3; i++) {
        glTranslated(0.6, 0.0, 0.0);
        glBegin(GL_LINES);
            glColor3ub(128, 128, 128);
            glVertex2f(-1.9f, 0.4f);
            glVertex2f(-1.8f, 0.4f);

            glVertex2f(-1.8f, 0.4f);
            glVertex2f(-1.8f, 0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 0);
            glVertex2f(-1.85f, 0.25f);
            glVertex2f(-1.8f, 0.25f);
            glVertex2f(-1.8f, 0.1f);
            glVertex2f(-1.85f, 0.1f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3ub(89, 89, 89);
            glVertex2f(-1.9f, 0.4f);
        glEnd();
    }

    // left-down
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.6f, -0.4f);
        glVertex2f(-1.5f, -0.4f);

        glVertex2f(-1.5f, -0.4f);
        glVertex2f(-1.5f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(-1.5f, -0.1f);
        glVertex2f(-1.55f, -0.1f);
        glVertex2f(-1.55f, -0.25f);
        glVertex2f(-1.5f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(-1.6f, -0.4f);
    glEnd();

    for(int i = 0; i < 3; i++){
        glTranslated(-0.6, 0.0, 0.0);
        glBegin(GL_LINES);
            glColor3ub(128, 128, 128);
            glVertex2f(-1.6f, -0.4f);
            glVertex2f(-1.5f, -0.4f);

            glVertex2f(-1.5f, -0.4f);
            glVertex2f(-1.5f, -0.1f);
        glEnd();
        glBegin(GL_POLYGON);
            glColor3ub(255, 255, 0);
            glVertex2f(-1.5f, -0.1f);
            glVertex2f(-1.55f, -0.1f);
            glVertex2f(-1.55f, -0.25f);
            glVertex2f(-1.5f, -0.25f);
        glEnd();
        glBegin(GL_POINTS);
            glColor3ub(89, 89, 89);
            glVertex2f(-1.6f, -0.4f);
        glEnd();
    }

    // right-up
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.4f, 0.4f);
        glVertex2f(1.5f, 0.4f);

        glVertex2f(1.5f, 0.4f);
        glVertex2f(1.5f, 0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(1.5f, 0.1f);
        glVertex2f(1.45f, 0.1f);
        glVertex2f(1.45f, 0.25f);
        glVertex2f(1.5f, 0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.4f, 0.4f);
    glEnd();

    // right-down
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.7f, -0.4f);
        glVertex2f(1.8f, -0.4f);

        glVertex2f(1.8f, -0.4f);
        glVertex2f(1.8f, -0.1f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(1.8f, -0.1f);
        glVertex2f(1.75f, -0.1f);
        glVertex2f(1.75f, -0.25f);
        glVertex2f(1.8f, -0.25f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.7f, -0.4f);
    glEnd();

    // bottom-left
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(0.5f, -0.7f);
        glVertex2f(0.5f, -0.6f);

        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.8f, -0.6f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(0.8f, -0.6f);
        glVertex2f(0.8f, -0.65f);
        glVertex2f(0.65f, -0.65f);
        glVertex2f(0.65f, -0.6f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(0.5f, -0.7f);
    glEnd();

    // bottom-right
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.3f, -1.0f);
        glVertex2f(1.3f, -0.9f);

        glVertex2f(1.3f, -0.9f);
        glVertex2f(1.0f, -0.9f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(1.0f, -0.9f);
        glVertex2f(1.0f, -0.95f);
        glVertex2f(1.15f, -0.95f);
        glVertex2f(1.15f, -0.9f);
    glEnd();

    // top-left
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(0.5f, 0.8f);
        glVertex2f(0.5f, 0.9f);

        glVertex2f(0.5f, 0.9f);
        glVertex2f(0.8f, 0.9f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(0.8f, 0.9f);
        glVertex2f(0.8f, 0.85f);
        glVertex2f(0.65f, 0.85f);
        glVertex2f(0.65f, 0.9f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(0.5f, 0.8f);
    glEnd();

    // top-right
    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(1.3f, 0.5f);
        glVertex2f(1.3f, 0.6f);

        glVertex2f(1.3f, 0.6f);
        glVertex2f(1.0f, 0.6f);
    glEnd();
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 0);
        glVertex2f(1.0f, 0.6f);
        glVertex2f(1.0f, 0.55f);
        glVertex2f(1.15f, 0.55f);
        glVertex2f(1.15f, 0.6f);
    glEnd();
    glBegin(GL_POINTS);
        glColor3ub(89, 89, 89);
        glVertex2f(1.3f, 0.5f);
    glEnd();
    /// road-light end

    factory();

    glPushMatrix();
        windmill();
    glPopMatrix();

    fence();

    /// shop start
    // left shop start
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 255, 255);
        glVertex2f(-1.95f, 0.5f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.55f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(128, 0, 0);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-1.95f, 0.85f);
        glVertex2f(-1.55f, 0.85f);
        glVertex2f(-1.55f, 0.75f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(255, 0, 0);
        glVertex2f(-2.0f, 0.65f);
        glVertex2f(-1.5f, 0.65f);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(-1.55f, 0.75f);
        glVertex2f(-1.95f, 0.75f);
        glVertex2f(-2.0f, 0.7f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(255, 153, 51);
        glVertex2f(-1.9f, 0.5f);
        glVertex2f(-1.9f, 0.62f);
        glColor3ub(179, 119, 0);
        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // window
        glColor3ub(255, 153, 51);
        glVertex2f(-1.77f, 0.55f);
        glVertex2f(-1.77f, 0.62f);
        glColor3ub(179, 119, 0);
        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-1.52f, 0.5f);
        glVertex2f(-1.98f, 0.5f);

        glVertex2f(-1.524f, 0.504f);
        glVertex2f(-1.98f, 0.504f);

        glVertex2f(-1.9f, 0.5f); // door
        glVertex2f(-1.9f, 0.62f);

        glVertex2f(-1.9f, 0.62f);
        glVertex2f(-1.82f, 0.62f);

        glVertex2f(-1.82f, 0.62f);
        glVertex2f(-1.82f, 0.5f);

        glVertex2f(-1.82f, 0.5f);
        glVertex2f(-1.9f, 0.5f);

        glVertex2f(-1.82f, 0.55f);
        glVertex2f(-1.9f, 0.55f);

        glVertex2f(-1.77f, 0.55f); // window
        glVertex2f(-1.77f, 0.62f);

        glVertex2f(-1.77f, 0.62f);
        glVertex2f(-1.6f, 0.62f);

        glVertex2f(-1.6f, 0.62f);
        glVertex2f(-1.6f, 0.55f);

        glVertex2f(-1.6f, 0.55f);
        glVertex2f(-1.77f, 0.55f);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    c ="BFC";
    glRasterPos2f(-1.8 , 0.78);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);
    // left shop end

    // right shop start
    glBegin(GL_POLYGON); // body
        glColor3ub(255, 204, 102);
        glVertex2f(-0.75f, 0.5f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.75f, 0.85f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.2f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // roof
        glColor3ub(179, 89, 0);
        glVertex2f(-0.3f, 0.85f);
        glVertex2f(-0.35f, 0.9f);
        glVertex2f(-0.6f, 0.9f);
        glVertex2f(-0.66f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // shutter
        glColor3ub(102, 82, 0);
        glVertex2f(-0.73f, 0.5f);
        glVertex2f(-0.73f, 0.8);
        glVertex2f(-0.22f, 0.8);
        glVertex2f(-0.22f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(230, 115, 0);
        glVertex2f(-0.8f, 0.7f);
        glVertex2f(-0.15f, 0.7f);
        glVertex2f(-0.15f, 0.75f);
        glVertex2f(-0.2f, 0.8f);
        glVertex2f(-0.75f, 0.8f);
        glVertex2f(-0.8f, 0.75f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 0, 0);
        glVertex2f(-0.17f, 0.5f);
        glVertex2f(-0.77f, 0.5f);

        glVertex2f(-0.17f, 0.504f);
        glVertex2f(-0.77f, 0.504f);

        glColor3ub(255, 153, 51);
        glVertex2f(-0.73f, 0.53f);
        glVertex2f(-0.22f, 0.53f);

        glVertex2f(-0.73f, 0.56f);
        glVertex2f(-0.22f, 0.56f);

        glVertex2f(-0.73f, 0.59f);
        glVertex2f(-0.22f, 0.59f);

        glVertex2f(-0.73f, 0.62f);
        glVertex2f(-0.22f, 0.62f);

        glVertex2f(-0.73f, 0.65f);
        glVertex2f(-0.22f, 0.65f);

        glVertex2f(-0.73f, 0.68f);
        glVertex2f(-0.22f, 0.68f);
    glEnd();

    glBegin(GL_POLYGON); // shutter
        glColor3ub(255, 235, 153);
        glVertex2f(-0.4f, 0.58f);
        glVertex2f(-0.4f, 0.65f);
        glVertex2f(-0.25f, 0.65f);
        glVertex2f(-0.25f, 0.58f);
    glEnd();

    glColor3ub(102, 51, 0);
    c="closed";
    glRasterPos2f(-0.39, 0.6);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, c[i]);

    glColor3ub(255, 255, 0);
    c="Candy Shop";
    glRasterPos2f(-0.6 , 0.84);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);
    // right shop end
    /// shop end

    /// house start
    // left house start
    glBegin(GL_POLYGON); // body
        glColor3ub(224, 228, 231);
        glVertex2f(-1.4f, 0.5f);
        glVertex2f(-1.4f, 1.0f);
        glVertex2f(-0.9f, 1.0f);
        glVertex2f(-0.9f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON); // bottom-window 1
        glColor3ub(204, 255, 153);
        glVertex2f(-1.35f, 0.55f);
        glVertex2f(-1.35f, 0.65f);
        glColor3ub(128, 255, 0);
        glVertex2f(-1.25f, 0.65f);
        glVertex2f(-1.25f, 0.55f);
    glEnd();
    glBegin(GL_POLYGON); // bottom-window 2
        glColor3ub(204, 255, 153);
        glVertex2f(-1.05f, 0.55f);
        glVertex2f(-1.05f, 0.65f);
        glColor3ub(128, 255, 0);
        glVertex2f(-0.95f, 0.65f);
        glVertex2f(-0.95f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON); // top-window 1
        glColor3ub(204, 255, 153);
        glVertex2f(-1.35f, 0.85f);
        glVertex2f(-1.35f, 0.95f);
        glColor3ub(128, 255, 0);
        glVertex2f(-1.25f, 0.95f);
        glVertex2f(-1.25f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 2
        glColor3ub(204, 255, 153);
        glVertex2f(-1.2f, 0.85f);
        glVertex2f(-1.2f, 0.95f);
        glColor3ub(128, 255, 0);
        glVertex2f(-1.1f, 0.95f);
        glVertex2f(-1.1f, 0.85f);
    glEnd();
    glBegin(GL_POLYGON); // top-window 3
        glColor3ub(204, 255, 153);
        glVertex2f(-1.05f, 0.85f);
        glVertex2f(-1.05f, 0.95f);
        glColor3ub(128, 255, 0);
        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.95f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(153, 153, 153);
        glVertex2f(-1.2f, 0.5f);
        glVertex2f(-1.2f, 0.65f);
        glVertex2f(-1.1f, 0.65f);
        glVertex2f(-1.1f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-1.17f, 0.58f);
	glEnd();

    glBegin(GL_LINES);
        glColor3ub(77, 195, 255);
        glVertex2f(-1.35f, 0.55f); // bottom-window 1
        glVertex2f(-1.35f, 0.65f);

        glVertex2f(-1.35f, 0.65f);
        glVertex2f(-1.25f, 0.65f);

        glVertex2f(-1.25f, 0.65f);
        glVertex2f(-1.25f, 0.55f);

        glVertex2f(-1.25f, 0.55f);
        glVertex2f(-1.35f, 0.55f);

        glVertex2f(-1.25f, 0.6f);
        glVertex2f(-1.35f, 0.6f);

        glVertex2f(-1.05f, 0.55f); // bottom-window 2
        glVertex2f(-1.05f, 0.65f);

        glVertex2f(-1.05f, 0.65f);
        glVertex2f(-0.95f, 0.65f);

        glVertex2f(-0.95f, 0.65f);
        glVertex2f(-0.95f, 0.55f);

        glVertex2f(-0.95f, 0.55f);
        glVertex2f(-1.05f, 0.55f);

        glVertex2f(-0.95f, 0.6f);
        glVertex2f(-1.05f, 0.6f);

        glVertex2f(-1.35f, 0.85f); // top-window 1
        glVertex2f(-1.35f, 0.95f);

        glVertex2f(-1.35f, 0.95f);
        glVertex2f(-1.25f, 0.95f);

        glVertex2f(-1.25f, 0.95f);
        glVertex2f(-1.25f, 0.85f);

        glVertex2f(-1.25f, 0.85f);
        glVertex2f(-1.35f, 0.85f);

        glVertex2f(-1.25f, 0.9f);
        glVertex2f(-1.35f, 0.9f);

        glVertex2f(-1.2f, 0.85f); // top-window 2
        glVertex2f(-1.2f, 0.95f);

        glVertex2f(-1.2f, 0.95f);
        glVertex2f(-1.1f, 0.95f);

        glVertex2f(-1.1f, 0.95f);
        glVertex2f(-1.1f, 0.85f);

        glVertex2f(-1.1f, 0.85f);
        glVertex2f(-1.2f, 0.85f);

        glVertex2f(-1.1f, 0.9f);
        glVertex2f(-1.2f, 0.9f);

        glVertex2f(-1.05f, 0.85f); // top-window 3
        glVertex2f(-1.05f, 0.95f);

        glVertex2f(-1.05f, 0.95f);
        glVertex2f(-0.95f, 0.95f);

        glVertex2f(-0.95f, 0.95f);
        glVertex2f(-0.95f, 0.85f);

        glVertex2f(-0.95f, 0.85f);
        glVertex2f(-1.05f, 0.85f);

        glVertex2f(-0.95f, 0.9f);
        glVertex2f(-1.05f, 0.9f);

        glVertex2f(-1.2f, 0.5f); // door
        glVertex2f(-1.2f, 0.65f);

        glVertex2f(-1.2f, 0.65f);
        glVertex2f(-1.1f, 0.65f);

        glVertex2f(-1.1f, 0.65f);
        glVertex2f(-1.1f, 0.5f);

        glVertex2f(-1.1f, 0.5f);
        glVertex2f(-1.2f, 0.5f);

        // body
        glColor3ub(128, 128, 128);

        glVertex2f(-1.4f, 0.5f);
        glVertex2f(-1.4f, 1.0f);

        glVertex2f(-1.4f, 1.0f);
        glVertex2f(-0.9f, 1.0f);

        glVertex2f(-0.9f, 1.0f);
        glVertex2f(-0.9f, 0.5f);

        glColor3ub(128, 0, 0);
        glVertex2f(-0.87f, 0.5f);
        glVertex2f(-1.43f, 0.5f);

        glVertex2f(-0.87f, 0.504f);
        glVertex2f(-1.43f, 0.504f);
    glEnd();

    glBegin(GL_POLYGON); // shelter
        glColor3ub(76, 174, 218);
        glVertex2f(-1.4f, 0.8f);
        glVertex2f(-1.45f, 0.75f);
        glVertex2f(-1.45f, 0.7f);
        glVertex2f(-0.85f, 0.7f);
        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.9f, 0.8f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(128, 128, 128);
        glVertex2f(-1.4f, 0.8f);
        glVertex2f(-1.45f, 0.75f);

        glVertex2f(-1.45f, 0.75f);
        glVertex2f(-1.45f, 0.7f);

        glVertex2f(-1.45f, 0.7f);
        glVertex2f(-0.85f, 0.7f);

        glVertex2f(-0.85f, 0.7f);
        glVertex2f(-0.85f, 0.75f);

        glVertex2f(-0.85f, 0.75f);
        glVertex2f(-0.9f, 0.8f);

        glVertex2f(-0.9f, 0.8f);
        glVertex2f(-1.4f, 0.8f);
    glEnd();
    // left house end

    // right house start
    glBegin(GL_POLYGON); // body
        glColor3ub(153, 51, 0);
        glVertex2f(-0.15f, 0.5f);
        glVertex2f(-0.15f, 0.8f);
        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, 0.5f);
    glEnd();
    glBegin(GL_POLYGON); // store room
        glColor3ub(153, 51, 0);
        glVertex2f(0.05f, 0.8f);
        glVertex2f(0.05f, 0.99f);
        glVertex2f(0.35f, 0.99f);
        glVertex2f(0.35f, 0.8f);
    glEnd();

    glBegin(GL_POLYGON); // window 1
        glColor3ub(102, 153, 0);
        glVertex2f(0.05f, 0.6f);
        glVertex2f(0.05f, 0.7f);
        glColor3ub(85, 128, 0);
        glVertex2f(0.15f, 0.7f);
        glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // window 2
        glColor3ub(102, 153, 0);
        glVertex2f(0.2f, 0.6f);
        glVertex2f(0.2f, 0.7f);
        glColor3ub(85, 128, 0);
        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON); // store room window
        glColor3ub(102, 153, 0);
        glVertex2f(0.15f, 0.85f);
        glVertex2f(0.15f, 0.95f);
        glColor3ub(85, 128, 0);
        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON); // door
        glColor3ub(77, 77, 77);
        glVertex2f(-0.1f, 0.5f);
        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.65f);
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glPointSize(5.0); // door handle
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.03f, 0.6f);
	glEnd();

    glBegin(GL_POLYGON); // door shelter
        glColor3ub(230, 115, 0);
        glVertex2f(0.02f, 0.65f);
        glVertex2f(-0.05f, 0.7f);
        glVertex2f(-0.12f, 0.65f);
    glEnd();

    glBegin(GL_LINES);
        glColor3ub(255, 255, 255);
        glVertex2f(0.15f, 0.85f); // store room window
        glVertex2f(0.15f, 0.95f);

        glVertex2f(0.15f, 0.95f);
        glVertex2f(0.25f, 0.95f);

        glVertex2f(0.25f, 0.95f);
        glVertex2f(0.25f, 0.85f);

        glVertex2f(0.25f, 0.85f);
        glVertex2f(0.15f, 0.85f);

        glVertex2f(0.05f, 0.6f); // window 1
        glVertex2f(0.05f, 0.7f);

        glVertex2f(0.05f, 0.7f);
        glVertex2f(0.15f, 0.7f);

        glVertex2f(0.15f, 0.7f);
        glVertex2f(0.15f, 0.6f);

        glVertex2f(0.15f, 0.6f);
        glVertex2f(0.05f, 0.6f);

        glVertex2f(0.2f, 0.6f); // window 2
        glVertex2f(0.2f, 0.7f);

        glVertex2f(0.2f, 0.7f);
        glVertex2f(0.3f, 0.7f);

        glVertex2f(0.3f, 0.7f);
        glVertex2f(0.3f, 0.6f);

        glVertex2f(0.3f, 0.6f);
        glVertex2f(0.2f, 0.6f);

        glColor3ub(255, 153, 51);
        glVertex2f(-0.1f, 0.5f); // door
        glVertex2f(-0.1f, 0.65f);

        glVertex2f(-0.1f, 0.65f);
        glVertex2f(0.0f, 0.65f);

        glVertex2f(0.0f, 0.65f);
        glVertex2f(0.0f, 0.5f);

        glVertex2f(0.0f, 0.5f);
        glVertex2f(-0.1f, 0.5f);

        glVertex2f(0.02f, 0.65f); // door shelter
        glVertex2f(-0.05f, 0.7f);

        glVertex2f(-0.05f, 0.7f);
        glVertex2f(-0.12f, 0.65f);

        glVertex2f(-0.12f, 0.65f);
        glVertex2f(0.02f, 0.65f);

        glVertex2f(0.36f, 0.8f); // roof railing
        glVertex2f(-0.16f, 0.8f);

        glVertex2f(0.36f, 0.84f);
        glVertex2f(-0.16f, 0.84f);

        glVertex2f(-0.14f, 0.8f);
        glVertex2f(-0.14f, 0.84f);

        glVertex2f(-0.1f, 0.8f);
        glVertex2f(-0.1f, 0.84f);

        glVertex2f(-0.05f, 0.8f);
        glVertex2f(-0.05f, 0.84f);

        glVertex2f(-0.0f, 0.8f);
        glVertex2f(-0.0f, 0.84f);

        glVertex2f(0.05f, 0.8f);
        glVertex2f(0.05f, 0.84f);

        glVertex2f(0.1f, 0.8f);
        glVertex2f(0.1f, 0.84f);

        glVertex2f(0.15f, 0.8f);
        glVertex2f(0.15f, 0.84f);

        glVertex2f(0.2f, 0.8f);
        glVertex2f(0.2f, 0.84f);

        glVertex2f(0.25f, 0.8f);
        glVertex2f(0.25f, 0.84f);

        glVertex2f(0.3f, 0.8f);
        glVertex2f(0.3f, 0.84f);

        glVertex2f(0.35f, 0.8f);
        glVertex2f(0.35f, 0.84f);

        glVertex2f(-0.16f, 0.504f); // ground
        glVertex2f(0.36f, 0.504f);

        glVertex2f(-0.16f, 0.5f);
        glVertex2f(0.36f, 0.5f);

        glVertex2f(0.04f, 0.99f); // top roof
        glVertex2f(0.36f, 0.99f);

        glVertex2f(0.04f, 0.985f);
        glVertex2f(0.36f, 0.985f);
    glEnd();

    // right house end
    ///house end

    boat1();
    boat2();
    // shop open
    glBegin(GL_POLYGON);
        glColor3ub(255, 255, 204);
        glVertex2f(-1.72f, 0.57f);
        glVertex2f(-1.72f, 0.6f);
        glVertex2f(-1.65f, 0.6f);
        glVertex2f(-1.65f, 0.57f);
    glEnd();

    glColor3ub(255, 51, 0);
    c="close";
    glRasterPos2f(-1.715 , 0.58);
    for(int i = 0; c[i] !='\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c[i]);
    // shop open

    if(cnt == 0)
        redgreen2();
    else
        redgreen1();

    if(r != 0)
        rain();

    glFlush();
}

void update_car1(int value) {
    if(cnt == 0){
        speed_c1 = 0.01f;
        if(position_c1 > 2.7)
            position_c1 = -2.7f;

        position_c1 += speed_c1;
    }

    else {
        if(position_c1 > 0.0) {
            speed_c1 = 0.0f;
            position_c1 = 0.0;
        }
        position_c1 += speed_c1;
    }

	glutPostRedisplay();
	glutTimerFunc(10, update_car1, 0);
}

void update_car2(int value) {
    if(cnt == 0) {
        speed_c2 = 0.01f;
        if(position_c2 < -2.7)
            position_c2 = 2.7f;

        position_c2 -= speed_c2;
    }
    else {
        if(position_c2 < 1.8) {
            speed_c2 = 0.0f;
            position_c2 = 1.8;
        }
        position_c2 -= speed_c2;
    }

	glutPostRedisplay();
	glutTimerFunc(10, update_car2, 0);
}

void update_car3(int value) {
    if(cnt == 0) {
        if(position_c3 > -0.9) {
            speed_c3 = 0.0f;
            position_c3 = -0.9;
        }
        position_c3 += speed_c3;
    }

    else {
        speed_c3 = 0.01f;
        if(position_c3 > 1.7)
            position_c3 = -1.7f;

        position_c3 += speed_c3;
    }

	glutPostRedisplay();
	glutTimerFunc(10, update_car3, 0);
}

void update_car4(int value) {
    if(cnt == 0) {
        if(position_c4 < 0.9) {
            speed_c4 = 0.0f;
            position_c4 = 0.9;
        }
        position_c4 -= speed_c4;
    }

    else {
        speed_c4 = 0.01f;
        if(position_c4 < -1.7)
            position_c4 = 1.7f;

        position_c4 -= speed_c4;
    }

	glutPostRedisplay();
	glutTimerFunc(10, update_car4, 0);
}

void update_smoke(int value) {
    if(position_s > 2.1)
        position_s = 1.6f;

    position_s += speed_s;

	glutPostRedisplay();
	glutTimerFunc(100, update_smoke, 0);
}

void update_river(int value) {
    if(position_r < -0.5)
        position_r = 0.0f;

    position_r -= speed_r;

	glutPostRedisplay();
	glutTimerFunc(100, update_river, 0);
}

void update_boat1(int value) {
    if(position_b1 < -2.0)
        position_b1 = 0.0f;

    position_b1 -= speed_b1;

	glutPostRedisplay();
	glutTimerFunc(100, update_boat1, 0);
}

void update_boat2(int value) {
    if(position_b2 > 0.0)
        position_b2 = -2.0f;

    position_b2 += speed_b2;

	glutPostRedisplay();
	glutTimerFunc(100, update_boat2, 0);
}

void update_rain(int value) {
    if(position_rain < -0.1)
        position_rain = 0.3f;

    position_rain -= speed_rain;

    if(position_rain2 > 2.0)
        position_rain2 = 1.8f;

    position_rain2 += speed_rain2;

	glutPostRedisplay();
	glutTimerFunc(100, update_rain, 0);
}

void update_windmill(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30,update_windmill,0);
}

void button(unsigned char key, int x, int y) {

    switch (key) {
        case 's':
            glutDisplayFunc(day);
            break;
        case 'r':
            cnt++;
            break;

        case 'g':
            cnt = 0;
            break;

        case 'n':
            flag++;
            glutDisplayFunc(night);
            glutPostRedisplay();
            position_s = -5.0f;
            speed_s = 0.0f;
            break;

        case 'd':
            flag = 0;
            glutDisplayFunc(day);
            glutPostRedisplay();
            position_s = 1.6f;
            speed_s = 0.01f;
            break;
        case 'b':
            flag =0;
            glutDisplayFunc(start);
    }

}

void rain_button(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON) {
        r++;
        PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    }
    if(button == GLUT_RIGHT_BUTTON) {
        r = 0;
        PlaySound(NULL, NULL, SND_ASYNC|SND_FILENAME);
    }
}

void inigl() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    gluOrtho2D(-2, 2, -1, 1); // Set range of axis of display (left, right, bottom, top)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1430, 800); // Set the window's initial width & height
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("CG Project"); // Create a window with the given title

    glutDisplayFunc(start);

    inigl();
    glutTimerFunc(30, update_windmill,0);
    glutTimerFunc(100, update_boat1,0);
    glutTimerFunc(100, update_boat2, 0);
    glutTimerFunc(100, update_river, 0);
    glutTimerFunc(100, update_smoke, 0);
    glutTimerFunc(10, update_car1, 0);
    glutTimerFunc(10, update_car2, 0);
    glutTimerFunc(10, update_car3, 0);
    glutTimerFunc(10, update_car4, 0);
    glutTimerFunc(100, update_rain, 0);

    glutKeyboardFunc(button);
    glutMouseFunc(rain_button);

    glutMainLoop(); // Enter the event-processing loop

    return 0;
}
