/*
Sumeed Jawad Kanwar
22I-2651
SE - B
Semester Project
*/

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unistd.h>

using namespace std;

//Function prototypes
void mainMenu();
void gameMenu();
void displayBoard();
void MouseClicked(int button, int state, int x, int y);

/* Function sets canvas size (drawing area) in pixels...
*  that is what dimensions (x and y) your game will have
*  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)*
*/
void SetCanvasSize(int width, int height)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//Global Variable
//Integer decleration
int xI = 1020, yI = 600;
int turn = 1;
int score = 0;
int mscore = 0;
int balance = 1000;
//Battleships pre positioning
int shipspos[10][2]=
{
	{420, 420},
	{420, 360},
	{540, 360},
	{420, 300},
	{510, 300},
	{600, 300},
	{420, 240}, 
	{480, 240},
	{540, 240},
	{600, 240},
};
//Character arrays decleration
char playerfront[10][10];
char computerfront[10][10];
//Boolein decleration
static bool check;
bool colorcheck = false;
bool attack = true;
bool shipplacement = false;
bool namecheck = false;
bool bombing = false;
bool playerturn = false;
bool ship1 = false;
bool ship2 = false;
bool ship3 = false;
bool ship4 = false;
bool ship5 = false;
bool ship6 = false;
bool ship7 = false;
bool ship8 = false;
bool ship9 = false;
bool ship10 = false;
bool flag = true;
bool options = true;
//String decleration
string name = "";
string colour;

void DrawObject()
{
	DrawSquare(xI, yI, 20, colors[WHITE]);
	DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
	glutPostRedisplay();
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
*/
void NonPrintableKeys(int key, int x, int y)
{
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();
}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
* is pressed from the keyboard
* This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
* program coordinates of mouse pointer when key was pressed.
*/
void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (namecheck == false)
	{
		if (key == 'b' || key == 'B') //Key for placing the bomb
	{
		//do something if b is pressed
		cout << "b pressed" << endl;
		if (colorcheck == false || check == true)
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutDisplayFunc(mainMenu);
			check = false;
			glutPostRedisplay();
		}
		
	}
		if (key == 'm' || key == 'M')
		{
			cout << "M pressed" << endl;
			if (ship1 == true)
			{
				shipspos[0][0] = shipspos[0][0] - (shipspos[0][0] % 30);
				shipspos[0][1] = shipspos[0][1] - (shipspos[0][1] % 30);
				if (shipspos[0][0] < 90 || shipspos[0][0] > 290 || shipspos[0][1] > 480 || shipspos[0][1] < 180)
				{
					shipspos[0][0] = 420;
					shipspos[0][1] = 420;
				}
				ship1 = false;
				playerfront[0][0]= shipspos[0][0];
				playerfront[0][1]= shipspos[0][1];
			}
			else if (ship2 == true)
			{
				shipspos[1][0] = shipspos[1][0] - (shipspos[1][0] % 30);
				shipspos[1][1] = shipspos[1][1] - (shipspos[1][1] % 30);
				if (shipspos[1][0] < 90 || shipspos[1][0] > 320 || shipspos[1][1] > 480 || shipspos[1][1] < 180)
				{
					shipspos[1][0] = 420;
					shipspos[1][1] = 360;
				}
				ship2 = false;
				playerfront[1][0]= shipspos[1][0];
				playerfront[1][1]= shipspos[1][1];
			}
			else if (ship3 == true)
			{
				shipspos[2][0] = shipspos[2][0] - (shipspos[2][0] % 30);
				shipspos[2][1] = shipspos[2][1] - (shipspos[2][1] % 30);
				if (shipspos[2][0] < 90 || shipspos[2][0] > 320 || shipspos[2][1] > 480 || shipspos[2][1] < 180)
				{
					shipspos[2][0] = 540;
					shipspos[2][1] = 360;
				}
				ship3 = false;
				playerfront[2][0]= shipspos[2][0];
				playerfront[2][1]= shipspos[2][1];
			}
			else if (ship4 == true)
			{
				shipspos[3][0] = shipspos[3][0] - (shipspos[3][0] % 30);
				shipspos[3][1] = shipspos[3][1] - (shipspos[3][1] % 30);
				if (shipspos[3][0] < 90 || shipspos[3][0] > 350 || shipspos[3][1] > 480 || shipspos[3][1] < 180)
				{
					shipspos[3][0] = 420;
					shipspos[3][1] = 300;
				}
				ship4 = false;
				playerfront[3][0]= shipspos[3][0];
				playerfront[3][1]= shipspos[3][1];
			}
			else if (ship5 == true)
			{
				shipspos[4][0] = shipspos[4][0] - (shipspos[4][0] % 30);
				shipspos[4][1] = shipspos[4][1] - (shipspos[4][1] % 30);
				if (shipspos[4][0] < 90 || shipspos[4][0] > 350 || shipspos[4][1] > 480 || shipspos[4][1] < 180)
				{
					shipspos[4][0] = 510;
					shipspos[4][1] = 300;
				}
				ship5 = false;
				playerfront[4][0]= shipspos[4][0];
				playerfront[4][1]= shipspos[4][1];
			}
			else if (ship6 == true)
			{
				shipspos[5][0] = shipspos[5][0] - (shipspos[5][0] % 30);
				shipspos[5][1] = shipspos[5][1] - (shipspos[5][1] % 30);
				if (shipspos[5][0] < 90 || shipspos[5][0] > 350 || shipspos[5][1] > 480 || shipspos[5][1] < 180)
				{
					shipspos[5][0] = 600;
					shipspos[5][1] = 300;
				}
				ship6 = false;
				playerfront[5][0]= shipspos[5][0];
				playerfront[5][1]= shipspos[5][1];
			}
			else if (ship7 == true)
			{
				shipspos[6][0] = shipspos[6][0] - (shipspos[6][0] % 30);
				shipspos[6][1] = shipspos[6][1] - (shipspos[6][1] % 30);
				if (shipspos[6][0] < 90 || shipspos[6][0] > 390 || shipspos[6][1] > 480 || shipspos[6][1] < 180)
				{
					shipspos[6][0] = 420;
					shipspos[6][1] = 240;
				}
				ship7 = false;
				playerfront[6][0]= shipspos[6][0];
				playerfront[6][1]= shipspos[6][1];
			}
			else if (ship8 == true)
			{
				shipspos[7][0] = shipspos[7][0] - (shipspos[7][0] % 30);
				shipspos[7][1] = shipspos[7][1] - (shipspos[7][1] % 30);
				if (shipspos[7][0] < 90 || shipspos[7][0] > 390 || shipspos[7][1] > 480 || shipspos[7][1] < 180)
				{
					shipspos[7][0] = 480;
					shipspos[7][1] = 240;
				}
				ship8 = false;
				playerfront[7][0]= shipspos[7][0];
				playerfront[7][1]= shipspos[7][1];
			}
			else if (ship9 == true)
			{
				shipspos[8][0] = shipspos[8][0] - (shipspos[8][0] % 30);
				shipspos[8][1] = shipspos[8][1] - (shipspos[8][1] % 30);
				if (shipspos[8][0] < 90 || shipspos[8][0] > 390 || shipspos[8][1] > 480 || shipspos[8][1] < 180)
				{
					shipspos[8][0] = 560;
					shipspos[8][1] = 240;
				}
				ship9 = false;
				playerfront[8][0]= shipspos[8][0];
				playerfront[8][1]= shipspos[8][1];
			}
			else if (ship10 == true)
			{
				shipspos[9][0] = shipspos[9][0] - (shipspos[9][0] % 30);
				shipspos[9][1] = shipspos[9][1] - (shipspos[9][1] % 30);
				if (shipspos[9][0] < 90 || shipspos[9][0] > 390 || shipspos[9][1] > 480 || shipspos[9][1] < 180)
				{
					shipspos[9][0] = 600;
					shipspos[9][1] = 240;
				}
				ship10 = false;
				playerfront[9][0]= shipspos[9][0];
				playerfront[9][1]= shipspos[9][1];
			}
		}
	}
	else
	{
		if (key == static_cast<char>(8))
	{
		name = "";
	}
	else
	{
		name +=key;
	}
	glutPostRedisplay();
	}
	glutPostRedisplay();
}

/*
* This function is called after every 1000.0/FPS milliseconds
* (FPS is defined on in the beginning).
* You can use this function to animate objects and control the
* speed of different moving objects by varying the constant FPS. *
*/
void Timer(int m)
{

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
*/
void MousePressedAndMoved(int x, int y)
{
	if (ship1 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[0][0] = x;
		shipspos[0][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship2 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[1][0] = x;
		shipspos[1][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship3 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[2][0] = x;
		shipspos[2][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship4 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[3][0] = x;
		shipspos[3][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship5 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[4][0] = x;
		shipspos[4][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship6 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[5][0] = x;
		shipspos[5][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship7 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[6][0] = x;
		shipspos[6][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship8 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[7][0] = x;
		shipspos[7][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship9 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[8][0] = x;
		shipspos[8][1] = 600 - y;
		glutPostRedisplay();

	}
	if (ship10 == true)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		shipspos[9][0] = x;
		shipspos[9][1] = 600 - y;
		glutPostRedisplay();

	}
	// cout << x << " " << y << endl;
	glutPostRedisplay();
}

//Function to show game ended and balance
void endgame ()
{
	glClearColor(0.196078431372549, 0.803921568627451,
				0.196078431372549, 1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Text to display balance
	balance = balance + score;
	string tbalance;
	stringstream text;
		text << balance;
		tbalance = text.str();
		string totalbalance = "Your balance is ";
		totalbalance = totalbalance + tbalance;
	DrawString(600, 250, totalbalance, colors[BLACK]);
	//Game end message
	DrawString(600, 300, "Game Ended", colors[BLACK]);
	glutSwapBuffers();
}

//Function for Battle and turns 
void Battle ()
{
	glClearColor(1, 0.270588235294118, 0, 1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Player's grid
	int xaxis = 90, yaxis = 480;
	//Displaying the grid
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		{
			if ((playerfront[a][b] == '0') || (playerfront[a][b] == '1'))
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[AQUA]);
			}
			else if (playerfront[a][b] == 'X')
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[BROWN]);
			}
			else if (playerfront[a][b] == 'M')
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[TEAL]);
			}
		}
	}
	//Battleships
	DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[BROWN],20);
	DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[BROWN],20);
	DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[BROWN],20);
	DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[BROWN],20);
	DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[BROWN],20);
	DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[BROWN],20);
	DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[BROWN],20);
	//Grid struture
	for (int c = 1; c <= 11; c++)
	{
		//Horizontal lines
		DrawLine(90,yaxis - ((c -2) * 30), 390, yaxis - ((c -2) * 30), 2, colors[BLACK]);
		//Verticle lines
		DrawLine(xaxis + (30 * (c-1)), 210, xaxis + (30 * (c-1)), 510, 2, colors[BLACK]);
	}
	//Computer's grid
	xaxis = 600;
	yaxis = 480;
	//Displaying the grid
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		{
			if ((computerfront[a][b] == '0') || (computerfront[a][b] == '1'))
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[AQUA]);
			}
			else if (computerfront[a][b] == 'X')
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[BROWN]);
			}
			else if (computerfront[a][b] == 'M')
			{
				DrawSquare((xaxis + (b * 30)), (yaxis - (a * 30)) , 30, colors[TEAL]);
			}
		}
	}
	//Grid structure
	for (int c = 1; c <= 11; c++)
	{
		//Horizontal lines
		DrawLine(600,yaxis - ((c -2) * 30), 900, yaxis - ((c -2) * 30), 2, colors[BLACK]);
		//Verticle lines
		DrawLine(xaxis + (30 * (c-1)), 210, xaxis + (30 * (c-1)), 510, 2, colors[BLACK]);
	}
	//Text to display score
	string tscore;
	stringstream text;
		text << score;
		tscore = text.str();
		string totalscore = "Total score is ";
		totalscore = totalscore + tscore;
	DrawString(600, 540, totalscore, colors[BLACK]);
	//Turn check	
	if (turn >= 200)
	{
		bombing = false;
		glutDisplayFunc(endgame);
	}
		//Condition to check who's turn it is
		if ((turn % 2) == 1)
		{
			playerturn = true;
			//Display turn message
			DrawString(150, 540, "Your turn", colors[BLACK]);
		}
	 	else if ((turn % 2) == 0)
	 	{
			//Display turn message
			DrawString(200, 540, "Computer's turn", colors[BLACK]);
			//Randomizing computer's turn
			int computerturnx = rand() % 10;
			int computerturny = rand() % 10;
			//Condition if battleship is present
			if (playerfront[computerturnx][computerturny] == '1')
			{
				cout << "computer hit" << endl;
				playerfront[computerturnx][computerturny] = 'X';
				turn = turn + 1;
				glutDisplayFunc(Battle);
			}
			//Condition if battleship is not present
			else if (playerfront[computerturnx][computerturny] == '0')
			{
				cout << "computer miss" << endl;
				playerfront[computerturnx][computerturny] = 'M';
				turn = turn + 1;
				glutDisplayFunc(Battle);
			}
			//Condition if already attacked
			else
			{
				glutDisplayFunc(Battle);
			}
	 	}
	glutSwapBuffers();
}

//Function for preparing all the things for battle
void Attackmenu ()
{
	glClearColor(0.254901960784314,
				0.411764705882353, 0.882352941176471, 1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Declaring and initializing array
	char playerback[10][10];
	for (int a = 0; a < 10; a++)
	{
		for (int b = 0; b < 10; b++)
		{
			playerback[a][b] = '0';
		}
	}
	//Converting battleship positions into 10 by 10 array
	for(int c = 0; c < 10; c++)
	{
		int xax = ((shipspos[c][0] - 90)/ 30);
		int yax = (10 - ((shipspos[c][1] - 180) / 30));
		
		if (c < 1)
		{
			playerback[yax][xax] = '1';
			playerback[yax][xax + 1] = '1';
			playerback[yax][xax + 2] = '1';
			playerback[yax][xax + 3] = '1';
		}
		else if (c < 3)
		{
			playerback[yax][xax] = '1';
			playerback[yax][xax + 1] = '1';
			playerback[yax][xax + 2] = '1';
		}
		else if (c < 6)
		{
			playerback[yax][xax] = '1';
			playerback[yax][xax + 1] = '1';
		}
		else
		{
			playerback[yax][xax] = '1';
		}
	}
	//Transfering the front hand code to the back hand
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		{
			playerfront[a][b]= playerback[a][b];
		}
	}
	//Player's grid
	int xaxis = 90, yaxis = 480;
	//Displaying the grid
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		DrawSquare((xaxis + (a * 30)), (yaxis - (b * 30)) , 30, colors[AQUA]);
	}
	//Battleships placement
	//size 4
	DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[BROWN],20);
	//size 3
	DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[BROWN],20);
	DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[BROWN],20);
	//size 2
	DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[BROWN],20);
	DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[BROWN],20);
	DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[BROWN],20);
	//size 1
	DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[BROWN],20);
	DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[BROWN],20);
	//Grid structure
	for (int c = 1; c <= 11; c++)
	{
		//Horizontal lines
		DrawLine(90,yaxis - ((c -2) * 30), 390, yaxis - ((c -2) * 30), 2, colors[BLACK]);
		//Verticle lines
		DrawLine(xaxis + (30 * (c-1)), 210, xaxis + (30 * (c-1)), 510, 2, colors[BLACK]);
	}
	//Computer's grid
	xaxis = 600, yaxis = 480;
	//Displaying the grid
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		DrawSquare((xaxis + (a * 30)), (yaxis - (b * 30)) , 30, colors[AQUA]);
	}
	//Grid structure
	for (int c = 1; c <= 11; c++)
	{
		//Horizontal lines
		DrawLine(600,yaxis - ((c -2) * 30), 900, yaxis - ((c -2) * 30), 2, colors[BLACK]);
		//Verticle lines
		DrawLine(xaxis + (30 * (c-1)), 210, xaxis + (30 * (c-1)), 510, 2, colors[BLACK]);
	}
	//Randomizing computer's battleships 
	int random = rand() % 4;
	//Condition for different placements
	if (random == 0)
	{
		//Battleship placement array
		char computerback[10][10] =
		{
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '1', '1', '1', '1', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '1', '1', '0'},
			{'0', '0', '1', '1', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '1', '1', '0'},
			{'0', '1', '1', '1', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}
		};
		//Transfering the front hand code to the back hand
		for (int e = 0; e < 10; e++)
		{
			for (int f = 0; f < 10;f++)
			{
				computerfront[e][f] = computerback[e][f];
			}
		}
		//Seting the conditions true to progress onto attack
		bombing = true;
		attack = true;
		//Calling the battle function
		glutDisplayFunc(Battle);
	}
	//Same is carried out with different battleships placement
	else if (random == 1)
	{
		char computerback[10][10] =
		{
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '1', '1', '1', '1', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '1', '0', '0'},
			{'0', '0', '1', '1', '1', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '1', '0', '0', '0'},
			{'0', '0', '0', '1', '1', '0', '0', '0', '0', '0'},
			{'1', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
			{'0', '0', '0', '0', '1', '1', '0', '0', '0', '0'},
			{'0', '0', '1', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '1', '1', '1', '0', '0'}
		};
		for (int e = 0; e < 10; e++)
		{
			for (int f = 0; f < 10;f++)
			{
				computerfront[e][f] = computerback[e][f];
			}
		}
		bombing = true;
		attack = true;
		glutDisplayFunc(Battle);
	}
	//Same is carried out with different battleships placement
	else if (random == 2)
	{
		char computerback[10][10] =
		{
			{'0', '0', '0', '0', '1', '1', '1', '0', '0', '0'}, 
			{'0', '1', '0', '0', '0', '0', '0', '0', '1', '0'}, 
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, 
			{'1', '0', '0', '0', '0', '0', '0', '0', '1', '0'}, 
			{'0', '0', '0', '1', '1', '1', '1', '0', '0', '0'}, 
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, 
			{'0', '1', '1', '0', '0', '1', '1', '1', '0', '0'}, 
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}, 
			{'0', '0', '0', '1', '1', '0', '0', '0', '0', '0'}, 
			{'0', '0', '0', '0', '0', '0', '0', '0', '1', '1'}
		};
		for (int e = 0; e < 10; e++)
		{
			for (int f = 0; f < 10;f++)
			{
				computerfront[e][f] = computerback[e][f];
			}
		}
		bombing = true;
		attack = true;
		glutDisplayFunc(Battle);
	}
	//Same is carried out with different battleships placement
	else if (random == 3)
	{
		char computerback[10][10] =
		{
			{'1', '1', '1', '1', '0', '0', '1', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'1', '0', '1', '1', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
			{'0', '1', '1', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
			{'0', '0', '0', '1', '1', '1', '0', '0', '0', '0'},
			{'1', '1', '0', '0', '0', '0', '0', '0', '0', '0'}
		};
		for (int e = 0; e < 10; e++)
		{
			for (int f = 0; f < 10;f++)
			{
				computerfront[e][f] = computerback[e][f];
			}
		}
		bombing = true;
		attack = true;
		glutDisplayFunc(Battle);
	}
	
	glutSwapBuffers();

}

void optionsmenu ()
{
	glClearColor(0.501960784313726, 0, 0.501960784313726, 1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glColor3f(1,1,1);
	glRasterPos3f(960, 560, 0); // for position
	char back[] = "Back";
	for (int i=0; i<strlen(back); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, back[i]);
	}

	DrawString ( 100, 550, "Press 'm' to place battleships", colors[BLACK]);
	DrawString ( 100, 500, "Press 'b' to go back to the menu", colors[BLACK]);

	glutSwapBuffers();
}

//Function for balance
void viewbalance ()
{
	glClearColor(1, 0.843137254901961, 0, 1);
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Back button
	DrawSquare( 950, 550, 40, colors[DARK_MAGENTA]);
	glColor3f(1,1,1);
	glRasterPos3f(960, 560, 0); // for position
	char back[] = "Back";
	for (int i=0; i<strlen(back); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, back[i]);
	}

	//Balance
	DrawString ( 50, 550, "Balance = 1000", colors[BLACK]);

	//Mine
	DrawCircle(120, 450, 20, colors[DARK_GRAY]);
	DrawSquare(400, 410, 50, colors[GOLD]);
	DrawString(405, 420, "100", colors[BLACK]);
	glColor3f(1,1,1);
	glRasterPos3f(100, 400, 0); // for position
	char mine[] = "Mine";
	for (int i=0; i<strlen(mine); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, mine[i]);
	}

	//Bomber
	DrawRectangle(100, 350, 50, 10, colors[DARK_GRAY]);
	DrawSquare(400, 310, 50, colors[GOLD]);
	DrawString(405, 320, "200", colors[BLACK]);
	glColor3f(1,1,1);
	glRasterPos3f(100, 300, 0); // for position
	char bomber[] = "Bomber";
	for (int i=0; i<strlen(bomber); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, bomber[i]);
	}
	
	//Submarine
	DrawRoundRect(100, 250, 50, 20, colors[DARK_GRAY], 25);
	DrawSquare(400, 210, 50, colors[GOLD]);
	DrawString(405, 220, "250", colors[BLACK]);
	glColor3f(1,1,1);
	glRasterPos3f(100, 200, 0); // for position
	char submarine[] = "Submarine";
	for (int i=0; i<strlen(submarine); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, submarine[i]);
	}

	glutSwapBuffers();
}

//Function for leaderboard
void leaderboard ()
{
	glClearColor(1, 0.549019607843137, 0, 1); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Back button
	DrawSquare( 950, 550, 40, colors[DARK_MAGENTA]);
	glColor3f(1,1,1);
	glRasterPos3f(960, 560, 0); // for position
	char back[] = "Back";
	for (int i=0; i<strlen(back); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, back[i]);
	}

	//Leaderboard
	DrawString( 100, 550, "Leaderboard", colors[BLACK]);
	//Printing leaderboard
	string file;
	ifstream Leaderboard;
		Leaderboard.open("Leaderboard.txt");
		getline(Leaderboard, file);
		for (int i = 0, a = 1, b = 0; i != file.length(); i++, a = a + 15)
		{
			//Condition to seperate the list
			if (file[i] == '.')
			{
				b = b + 50;
				a = 0;
			}
			//Part of the same line
			else
			{
				glRasterPos3f(50 + a, 450 - b, 0); // for position
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, file[i]);
			string text = "";
			}
		}
	
	glutSwapBuffers();
}

//Function for mouse moved
void MouseMoved(int x, int y)
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
* */
void MouseClicked(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		// start game , temporary approach
		// glutDisplayFunc(gameMenu);
	}
	//Game button
	if(x >= 380 && x <= 580 && y >= 280 && y <= 305 && check == false)
	{
		glutDisplayFunc(gameMenu);
		check = true;
		
	}
	else if (x >= 380 && x <= 580 && y >= 230 && y <= 260 && check == false)
	{
		glutDisplayFunc(leaderboard);
		check = true;
	}
	//Balance button
	else if (x >= 380 && x<= 580 && y >= 330  && y <= 360 && check == false)
	{
		glutDisplayFunc(viewbalance);
		check = true;
	}
	//Options Button
	else if (x >= 330 && x<= 405 && y >= 175  && y <= 200 && options == false)
	{
		glutDisplayFunc(viewbalance);
		options = true;
	}
	//Back button
	if (x >= 950 && x <= 990 && y >= 10 & y <= 50 && (colorcheck == false || check == true))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glutDisplayFunc(mainMenu);
			check = false;
			glutPostRedisplay();
		
	}
	//Color button
	if (x >= 150 && x <= 260 && y >= 225 & y <= 255 && colorcheck == false)
	{
		colorcheck = true;
		colour = "RED";
	}
	else if (x >= 150 && x <= 260 && y >= 280 & y <= 310 && colorcheck == false)
	{
		colorcheck = true;
		colour = "BLUE";
	}
	else if (x >= 150 && x <= 260 && y >= 330 & y <= 360 && colorcheck == false)
	{
		colorcheck = true;
		colour = "YELLOW";
	}
	else if (x >= 150 && x <= 260 && y >= 380 & y <= 410 && colorcheck == false)
	{
		colorcheck = true;
		colour = "GREEN";
	}
	//Ship placement
	if (shipplacement == true)
	{
		if (x >= (shipspos[0][0]) && x <= (shipspos[0][0] + 120) && y >= (600 - (shipspos[0][1] + 30)) && y <= (600- shipspos[0][1]) && ship1 == false)
	{
		ship1 = true;
	}
	if (x >= (shipspos[1][0]) && x <= (shipspos[1][0] + 90) && y >= (600 - (shipspos[1][1] + 30)) && y <= (600- shipspos[1][1]) && ship2 == false)
	{
		ship2 = true;
	}
	if (x >= (shipspos[2][0]) && x <= (shipspos[2][0] + 90) && y >= (600 - (shipspos[2][1] + 30)) & y <= (600- shipspos[2][1]) && ship3 == false)
	{
		ship3 = true;
	}
	if (x >= (shipspos[3][0]) && x <= (shipspos[3][0] + 60) && y >= (600 - (shipspos[3][1] + 30)) & y <= (600- shipspos[3][1]) && ship4 == false)
	{
		ship4 = true;
	}
	if (x >= (shipspos[4][0]) && x <= (shipspos[4][0] + 60) && y >= (600 - (shipspos[4][1] + 30)) & y <= (600- shipspos[4][1]) && ship5 == false)
	{
		ship5 = true;
	}
	if (x >= (shipspos[5][0]) && x <= (shipspos[5][0] + 60) && y >= (600 - (shipspos[5][1] + 30)) & y <= (600- shipspos[5][1]) && ship6 == false)
	{
		ship6 = true;
	}
	if (x >= (shipspos[6][0]) && x <= (shipspos[6][0] + 30) && y >= (600 - (shipspos[6][1] + 30)) & y <= (600- shipspos[6][1]) && ship7 == false)
	{
		ship7 = true;
	}
	if (x >= (shipspos[7][0]) && x <= (shipspos[7][0] + 30) && y >= (600 - (shipspos[7][1] + 30)) & y <= (600- shipspos[7][1]) && ship8 == false)
	{
		ship8 = true;
	}
	if (x >= (shipspos[8][0]) && x <= (shipspos[8][0] + 30) && y >= (600 - (shipspos[8][1] + 30)) & y <= (600- shipspos[8][1]) && ship9 == false)
	{
		ship9 = true;
	}
	if (x >= (shipspos[9][0]) && x <= (shipspos[9][0] + 30) && y >= (600 - (shipspos[9][1] + 30)) & y <= (600- shipspos[9][1]) && ship10 == false)
	{
		ship10 = true;
	}
	}
	//Randomizing battleships
	if (x >= 220 && x <= 310 && y >= 420 && y <= 450 && attack == false)
	{

		int randomize = rand() % 4;
		//Condition for auto
		if (randomize == 0)
		{
			shipspos[0][0] = 90;
			shipspos[0][1] = 480;
			shipspos[1][0] = 180;
			shipspos[1][1] = 420;
			shipspos[2][0] = 180;
			shipspos[2][1] = 240;
			shipspos[3][0] = 90;
			shipspos[3][1] = 210;
			shipspos[4][0] = 120;
			shipspos[4][1] = 300;
			shipspos[5][0] = 150;
			shipspos[5][1] = 360;
			shipspos[6][0] = 90;
			shipspos[6][1] = 360;
			shipspos[7][0] = 300;
			shipspos[7][1] = 330;
			shipspos[8][0] = 300;
			shipspos[8][1] = 420;
			shipspos[9][0] = 270;
			shipspos[9][1] = 480;
		}
		else if (randomize == 1)
		{
			shipspos[0][0] = 270;
			shipspos[0][1] = 210;
			shipspos[1][0] = 270;
			shipspos[1][1] = 360;
			shipspos[2][0] = 120;
			shipspos[2][1] = 240;
			shipspos[3][0] = 120;
			shipspos[3][1] = 450;
			shipspos[4][0] = 330;
			shipspos[4][1] = 480;
			shipspos[5][0] = 90;
			shipspos[5][1] = 330;
			shipspos[6][0] = 240;
			shipspos[6][1] = 300;
			shipspos[7][0] = 240;
			shipspos[7][1] = 480;
			shipspos[8][0] = 360;
			shipspos[8][1] = 420;
			shipspos[9][0] = 90;
			shipspos[9][1] = 390;
		}
		else if (randomize == 2)
		{
			shipspos[0][0] = 180;
			shipspos[0][1] = 360;
			shipspos[1][0] = 240;
			shipspos[1][1] = 300;
			shipspos[2][0] = 210;
			shipspos[2][1] = 480;
			shipspos[3][0] = 120;
			shipspos[3][1] = 300;
			shipspos[4][0] = 180;
			shipspos[4][1] = 240;
			shipspos[5][0] = 210;
			shipspos[5][1] = 480;
			shipspos[6][0] = 90;
			shipspos[6][1] = 390;
			shipspos[7][0] = 330;
			shipspos[7][1] = 450;
			shipspos[8][0] = 330;
			shipspos[8][1] = 390;
			shipspos[9][0] = 120;
			shipspos[9][1] = 450;
		}
		else if (randomize == 3)
		{
			shipspos[0][0] = 150;
			shipspos[0][1] = 390;
			shipspos[1][0] = 270;
			shipspos[1][1] = 270;
			shipspos[2][0] = 210;
			shipspos[2][1] = 480;
			shipspos[3][0] = 120;
			shipspos[3][1] = 300;
			shipspos[4][0] = 120;
			shipspos[4][1] = 210;
			shipspos[5][0] = 210;
			shipspos[5][1] = 480;
			shipspos[6][0] = 90;
			shipspos[6][1] = 390;
			shipspos[7][0] = 330;
			shipspos[7][1] = 450;
			shipspos[8][0] = 330;
			shipspos[8][1] = 390;
			shipspos[9][0] = 90;
			shipspos[9][1] = 480;
		}
		
			
	}
	//Attack button
	if (x >= 120 && x <= 210 && y >= 430 && y <= 460 && attack == false)
	{
		glutDisplayFunc(Attackmenu);
			attack = false;
			shipplacement = false;
			glutPostRedisplay();
	}
	//Bombing
	if (bombing == true)
	{
		int xaxis = 600, yaxis = 90;
		for (int a = 0; a < 10; a++)
		{
			for (int b = 0; b < 10; b++)
			{
				if (x >= (xaxis + (30 * b)) && x <= (xaxis + (30 * (b + 1))) && y >= (yaxis + (30 * a)) && y <= (yaxis + (30 * (a +1))) && playerturn == true)
				{
					if (computerfront[a][b] == '1')
					{
						cout << "hitting" << endl;
						computerfront[a][b] = 'X';
						playerturn = false;
						turn = turn + 1;
						score = score + 60;
						mscore = 0;
						glutDisplayFunc(Battle);
						glutPostRedisplay();
					}
					else if (computerfront[a][b] == '0')
					{
						cout << "missing" << endl;
						computerfront[a][b] = 'M';
						playerturn = false;
						turn = turn + 1;
						mscore = mscore + 1;
						if (mscore == 2)
						{
							score = score - 20; 
						} 
						glutPostRedisplay();
						glutDisplayFunc(Battle);
					}
					else
					{
						glutDisplayFunc(Battle);
					}
				}
			}	
		}
		
	}
	cout << "\n\n\n coordinates \n ";
	cout << x << endl;
	cout << y << endl;
	glutPostRedisplay();
}

//Function taking name and color
void gameMenu()
{

	namecheck = true;

	glClearColor( 0.545098039215686, 0, 0.545098039215686, 1 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Back Button
	DrawSquare( 955, 550, 30, colors[DARK_MAGENTA]);
	glColor3f(1,1,1);
	glRasterPos3f(960, 560, 0); // for position
	char back[] = "Back";
	for (int i=0; i<strlen(back); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, back[i]);
	}

	//Taking name
	DrawString( 100, 450, "Enter your name:", colors[BLACK]);
	int a = 0;
	if (namecheck == true)
	for (int i = 0; i != name.length(); i++)
	{
		glColor3f(0,1,0);
		glRasterPos3f(290 + a, 450 , 0); // for position
		//Character Size
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, name[i]);
		a = a + 15;
	}

	//Color
	DrawString(100, 400,"Pick Color", colors[WHITE]);
	//Red
	DrawRectangle(150, 345, 110, 30, colors[RED]);
	DrawString(155, 350,"RED", colors[WHITE]);
	//Blue
	DrawRectangle(150, 295, 110, 30, colors[BLUE]);
	DrawString(155, 300,"BLUE", colors[WHITE]);
	//Yellow
	DrawRectangle(150, 245, 110, 30, colors[YELLOW]);
	DrawString(155, 250,"YELLOW", colors[WHITE]);
	//Green
	DrawRectangle(150, 195, 110, 30, colors[GREEN]);
	DrawString(155, 200,"GREEN", colors[WHITE]);
	//Statement to check if color is picked 
	if (colorcheck == true)
	{
		glutDisplayFunc(displayBoard);
		namecheck = false;
	}

	glutSwapBuffers();
}

//Function to place battleships
void DisplayGrid()
{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim red and 1 means pure red and so on.

	glClearColor(0.254901960784314,
				0.411764705882353, 0.882352941176471, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	attack = false;
	shipplacement = true;

	//BOX
	int xaxis = 90, yaxis = 480;
	for(int a = 0; a < 10; a++)
	{
		for(int b = 0; b < 10; b++)
		DrawSquare((xaxis + (a * 30)), (yaxis - (b * 30)) , 30, colors[AQUA]);
	}

	//Battleship
	//BLUE
	if (colour == "BLUE")
	{
		//size 4
		DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[DARK_BLUE],20);
		//size 3
		DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[DARK_BLUE],20);
		//size 2
		DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[DARK_BLUE],20);
		//size 1
		DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[DARK_BLUE],20);
		DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[DARK_BLUE],20);
	}
	else if (colour == "RED")
	{
		//size 4
		DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[RED],20);
		//size 3
		DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[RED],20);
		DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[RED],20);
		//size 2
		DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[RED],20);
		DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[RED],20);
		DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[RED],20);
		//size 1
		DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[RED],20);
		DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[RED],20);
		DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[RED],20);
		DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[RED],20);
	}
	else if (colour == "YELLOW")
	{
		//size 4
		DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[YELLOW],20);
		//size 3
		DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[YELLOW],20);
		//size 2
		DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[YELLOW],20);
		//size 1
		DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[YELLOW],20);
		DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[YELLOW],20);
	}
	else if (colour == "GREEN")
	{
		//size 4
		DrawRoundRect(shipspos[0][0],shipspos[0][1],120,25,colors[GREEN],20);
		//size 3
		DrawRoundRect(shipspos[1][0],shipspos[1][1],90,25,colors[GREEN],20);
		DrawRoundRect(shipspos[2][0],shipspos[2][1],90,25,colors[GREEN],20);
		//size 2
		DrawRoundRect(shipspos[3][0],shipspos[3][1],60,25,colors[GREEN],20);
		DrawRoundRect(shipspos[4][0],shipspos[4][1],60,25,colors[GREEN],20);
		DrawRoundRect(shipspos[5][0],shipspos[5][1],60,25,colors[GREEN],20);
		//size 1
		DrawRoundRect(shipspos[6][0],shipspos[6][1],30,25,colors[GREEN],20);
		DrawRoundRect(shipspos[7][0],shipspos[7][1],30,25,colors[GREEN],20);
		DrawRoundRect(shipspos[8][0],shipspos[8][1],30,25,colors[GREEN],20);
		DrawRoundRect(shipspos[9][0],shipspos[9][1],30,25,colors[GREEN],20);
	}
	
	
	//Attack button
	DrawRectangle (120, 150, 90, 30, colors[DARK_RED]);
	DrawString (122, 154, "Attack", colors[BLACK]);
	DrawString (124, 155, "Attack", colors[WHITE]);
	//Random button
	DrawRectangle (220, 150, 90, 30, colors[DARK_RED]);
	DrawString (222, 154, "Random", colors[BLACK]);
	DrawString (224, 155, "Random", colors[WHITE]);

	glutSwapBuffers(); // do not modify this line..
	
}

//Function for moving objects
void displayBoard()
{
	//Pointers to move objects on realtime
	int * n = new int;
	int * m = new int;

	*n = 14;
	*m = 24;

	glutDisplayFunc(DisplayGrid);

}

//Fucntion for main menu
void mainMenu()
{
	glClearColor(0.254901960784314, 0.411764705882353, 0.882352941176471, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//Title
	glColor3f(1,1,1);
	glRasterPos3f(300, 500, 0); // for position
	char msg[] = "Battleship Horizon";
	for (int i=0; i < strlen(msg); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[i]);
	}
	//Main menu
	glColor3f(1,1,1);
	glRasterPos3f(350, 400, 0); // for position
	char msg1[] = "Main Menu";
	for (int i=0; i<strlen(msg1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg1[i]);
	}

	//Leaderboard button
	DrawRoundRect(380,345,200,25,colors[BROWN],15);
	glColor3f(1,1,1);
	glRasterPos3f(400, 350, 0); // for position
	char msg2[] = "View Leaderboard";
	for (int i=0; i<strlen(msg2); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg2[i]);
	}

	//Start game button
	DrawRoundRect(380,295,200,25,colors[BROWN],15);
	glColor3f(1,1,1);
	glRasterPos3f(400, 300, 0); // for position
	char msg3[] = "Start New Game";
	for (int i = 0; i<strlen(msg3); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg3[i]);
	}

	//Balance button
	DrawRoundRect(380,245,200,25,colors[BROWN],15);
	glColor3f(1,1,1);
	glRasterPos3f(400, 250, 0); // for position
	char msg4[] = "View Balance";
	for (int i = 0; i<strlen(msg4); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg4[i]);
	}

	//Options button
	DrawRoundRect(330,195,75,15,colors[BROWN],10);
	glColor3f(1,1,1);
	glRasterPos3f(350, 200, 0); // for position
	char msg5[] = "Options";
	for (int i = 0; i<strlen(msg5); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, msg5[i]);
	}		

	glutSwapBuffers();
}

/*
 * our gateway main function
 * */
int main(int argc, char*argv[])
{

	int width = 1020, height = 600; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(100, 100); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Horizon"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
	
	glutDisplayFunc(mainMenu);
	// glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	//glutKeyboardFunc(GetName);
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */