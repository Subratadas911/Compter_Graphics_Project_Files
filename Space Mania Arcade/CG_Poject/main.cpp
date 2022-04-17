#include <windows.h>
#include <MMSystem.h>
#include <iostream>
#include <sstream>
using namespace std;
#include <GL/glut.h>
#include <math.h>
#include "BonusShape.cpp"
#include "Str_Shape.cpp"
#include "CldShape.cpp"
#include "RocketShape.cpp"
#include "Stone_Shape.cpp"
#include "Sat_Shape.cpp"


float RandomFloat(float min, float max){
   return ((max - min) * ((float)rand() / RAND_MAX)) + min;
}

void initGL() {
   glClearColor(0.02f, 0.050f, 0.1f, 0.0f);
}

void GmOverFunc()
{
   char const *strn = "GAME OVER";
   glColor3f(1.0f, 0.0f, 0.0f);
   glRasterPos3d(-0.1f, 0.0f, 0.0f);

   while(*strn)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strn++);
   }

}

void showText(int num)
{
   string str;
   stringstream ss;
   ss << num;
   ss >> str;
   char const *scrT = "Score: ";
   glColor3f (0.0f, 1.0f, 0.03f);
   glRasterPos3d(-1.0f, 0.88f, 0.0f);

   while(*scrT)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *scrT++);
   }

   char const *strn = str.c_str();
   glColor3f (1.0f, 1.0f, 1.0f);
   glRasterPos3d(-0.85f, 0.88f, 0.0f);

   while(*strn)
   {
      glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *strn++);
   }

}

GLfloat Satelite_X = 1.0f;
GLfloat Satelite_Y = -0.05f;

bool GmOver = false;
int score = 0;

GLfloat Left_Stone_Speed = 0.04f;
GLfloat Right_Stone_Speed = 0.05f;


GLfloat Star_Move = 0.9f;
bool Update_flag = true;

GLfloat Rocket_Pos = 0.0f;


GLfloat Bonus_BoxX = 0.50f;
GLfloat Bonus_BoxY = 1.0f;

GLfloat Pos_LeftStone = 1.0f;
GLfloat Pos_LeftStoneHorizoneVal = -0.1f;

GLfloat Pos_RightStone = 1.0f;
GLfloat Pos_RightStoneX = 0.7f;


void update(int value)
{
    bool flag = true;

    if(Update_flag == true)
    {
        if(Star_Move>=0.07)
        {
            Update_flag=false;
        }

        Star_Move+=0.002f;

    }
    else if (Update_flag == false)
    {
        if(Star_Move<=0.0)
        {
            Update_flag=true;
        }

        Star_Move-=0.002f;

    }


    if(score>60)
    {
        Left_Stone_Speed = 0.16f;Right_Stone_Speed = 0.15f;
    }
    else if(score>40)
    {
        Left_Stone_Speed = 0.12f;Right_Stone_Speed = 0.13f;
    }
    else if(score>20)
    {
        Left_Stone_Speed = 0.09f;Right_Stone_Speed = 0.09f;
    }


    if(Satelite_X < -1.0)
    {
        Satelite_X = 1.0f;
        Satelite_Y = -0.4f;

    }
    else{
        Satelite_X -= 0.01f;
        Satelite_Y += 0.01f;
    }




    if(Bonus_BoxY < -0.9)
    {
        Bonus_BoxY = 1.5f;
        Bonus_BoxX = RandomFloat(-0.9, 0.9);

    }
    else{
        Bonus_BoxY -= 0.1f;
    }



    if(Pos_LeftStone < -1.0)
    {
        Pos_LeftStone = 1.0f;
        score++;
        Pos_LeftStoneHorizoneVal = Rocket_Pos;
    }
    else{
        Pos_LeftStone -= Left_Stone_Speed;
    }



    if(Pos_RightStone < -1.0)
    {

        Pos_RightStone = 1.0f;
        Pos_RightStoneX = RandomFloat(-0.9, 0.9);
        score++;
    }
    else{
        Pos_RightStone -= Right_Stone_Speed;
    }





    if(Rocket_Pos+0.09 >= Pos_RightStoneX-0.20 && Rocket_Pos+0.09 <= Pos_RightStoneX+0.20 || Rocket_Pos-0.09 >= Pos_RightStoneX-0.20 && Rocket_Pos-0.09 <= Pos_RightStoneX+0.20)
    {
        if(Pos_RightStone+0.20<=-0.400000 && Pos_RightStone+0.20>=-0.900000 || Pos_RightStone-0.20<=-0.400000 && Pos_RightStone-0.20>=-0.900000)
        {
            flag = false;
            GmOver = true;
            cout<<"Collision Detected With Right Stone!"<<endl;

        }
    }

    if(Rocket_Pos+0.09 >= Pos_LeftStoneHorizoneVal-0.13 && Rocket_Pos+0.09 <= Pos_LeftStoneHorizoneVal+0.13 || Rocket_Pos-0.09 >= Pos_LeftStoneHorizoneVal-0.13 && Rocket_Pos-0.09 <= Pos_LeftStoneHorizoneVal+0.13)
    {
        if(Pos_LeftStone+0.13<=-0.400000 && Pos_LeftStone+0.13>=-0.900000 || Pos_LeftStone-0.13<=-0.400000 && Pos_LeftStone-0.13>=-0.900000)
        {
            flag = false;
            GmOver = true;
            cout<<"Collision Detected With Left Stone!"<<endl;
        }
    }


    if(Rocket_Pos-0.1<=Bonus_BoxX-0.06 && Rocket_Pos+0.1>=Bonus_BoxX-0.06 || Rocket_Pos-0.1<=Bonus_BoxX+0.06 && Rocket_Pos+0.1>=Bonus_BoxX+0.06)
    {
        if(Bonus_BoxY+0.06<=-0.400000 && Bonus_BoxY+0.06>=-0.900000 || Bonus_BoxY-0.06<=-0.400000 && Bonus_BoxY-0.06>=-0.900000)
        {
            score+=5;
             Bonus_BoxY = 10.5f;
             Bonus_BoxX = RandomFloat(-0.9, 0.9);
            cout<<"Collision Detected With Bonus Box!"<<endl;
        }
    }



	glutPostRedisplay();
	if(flag)
    {
        glutTimerFunc(100, update, 0);
    }
}
void Key_Press(unsigned char key, int x, int y) {
    if(GmOver == false)
    {
        switch (key)
        {
            case 'a':

                if(Rocket_Pos > -0.79)
                {
                Rocket_Pos -= 0.15f;
                }
                break;
            case 'd':
                if(Rocket_Pos<0.79)
                {
                Rocket_Pos += 0.15f;
                }
                break;


        }
        glutPostRedisplay();
    }

}

void display() {

   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   displayStar(Star_Move);
   glLoadIdentity();
   displaySatelite(Satelite_X, Satelite_Y,1.0);
   glLoadIdentity();
   displaySatelite2(-Satelite_X, -Satelite_Y,1.0);
   glLoadIdentity();
   displayCloud();
   glLoadIdentity();
   displayStone(Pos_LeftStoneHorizoneVal,Pos_LeftStone,Pos_RightStone,Pos_RightStoneX);
   glLoadIdentity();
   displayBonusBox(Bonus_BoxX,Bonus_BoxY);
   glLoadIdentity();
   rocketShow(Rocket_Pos);
   showText(score);
   if(GmOver==true)
   {
       GmOverFunc();
   }
   glFlush();
}


int main(int argc, char** argv)
{

   glutInit(&argc, argv);
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(400, 75);
   glutCreateWindow("Space Mania Arcade");
   glutDisplayFunc(display);

   initGL();

   glutKeyboardFunc(Key_Press);

   glutTimerFunc(500, update, 0);

   glutMainLoop();

   return 0;

}
