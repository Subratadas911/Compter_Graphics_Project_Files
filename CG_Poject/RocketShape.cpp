void rocketShow(GLfloat r_posX)
{

   glTranslatef(r_posX, -0.9f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 0.0f);
      glVertex2f(-0.04f, 0.0f);
      glVertex2f(0.04f, 0.06f);
      glVertex2f(0.04f, 0.0f);
      glVertex2f(-0.04f, 0.06f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.15f);
      glVertex2f(-0.05f, 0.15f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(-0.05f, 0.15f);
      glVertex2f(-0.11f, -0.01f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.83f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.15f);
      glVertex2f(0.11f, -0.01f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.05f, 0.0f);
      glVertex2f(0.05f, 0.0f);
      glVertex2f(0.05f, 0.18f);
      glVertex2f(-0.05f, 0.18f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.03f, 0.0f);
      glVertex2f(0.03f, 0.0f);
      glVertex2f(0.03f, 0.18f);
      glVertex2f(-0.03f, 0.18f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.03f, 0.05f);
      glVertex2f(0.03f, 0.05f);
      glVertex2f(0.03f, 0.12f);
      glVertex2f(-0.03f, 0.12f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.67f, 0.0f);
   glBegin(GL_QUADS);
      glColor3f(0.0f, 0.0f, 0.0f);
      glVertex2f(-0.02f, 0.0f);
      glVertex2f(0.02f, 0.0f);
      glVertex2f(0.02f, 0.18f);
      glVertex2f(-0.02f, 0.18f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.49f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 0.0f, 0.0f);
      glVertex2f(-0.066f, 0.0f);
      glVertex2f(0.066f, 0.0f);
      glVertex2f(0.0f, 0.10f);
   glEnd();

   glLoadIdentity();
   glTranslatef(r_posX, -0.49f, 0.0f);
   glBegin(GL_TRIANGLES);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2f(-0.023f, 0.0f);
      glVertex2f(0.023f, 0.0f);
      glVertex2f(0.0f, 0.10f);
   glEnd();
   glLoadIdentity();
}

