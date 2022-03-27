#include <windows.h>

#include <GL/glut.h>



GLfloat i = 0.0f;
GLfloat j= 0.0f;


void initGL()

{

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

}



void Idle()

{

    glutPostRedisplay();

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();



    glPushMatrix();

    glRotatef(i,0.,0.0,1.0);





    glTranslatef(0.0f, 0.0f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(1.0f, 1.f, 0.0f);

      glVertex2f(-0.1f, -0.1f);

      glVertex2f( 0.1f, -0.1f);

      glVertex2f( 0.1f,  0.01f);

      glVertex2f(-0.1f,  0.01f);

   glEnd();


      glLoadIdentity();

glRotatef(j,0.,0.0,1.0);

glTranslatef(-0.2f, 0.f, 0.0f);

   glBegin(GL_QUADS);

      glColor3f(1.0f, 0.0f, 1.0f);

      glVertex2f(-0.1f, -0.1f);

      glVertex2f( 0.1f, -0.1f);

      glVertex2f( 0.1f,  0.01f);

      glVertex2f(-0.1f,  0.01f);


       glEnd();


      glLoadIdentity();


    glPopMatrix();





    i+=0.09f;
    j+=0.09f;


    glFlush();

}



int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitWindowSize(320, 320);

    glutCreateWindow("Model Transform");

    glutDisplayFunc(display);//

    initGL();

    glutIdleFunc(Idle);

    glutMainLoop();

    return 0;}
