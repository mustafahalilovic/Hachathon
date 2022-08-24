#include <iostream>
#include <ctime>
#include <conio.h>
#include <cstdlib>
#define red 20
#define kolona 30
using namespace std;

// Deklaracija
// ---------------------------------
char polje[red][kolona], promjena;
bool kraj = false;
int score, velicinaZmije = 1, xHrana, yHrana, zmija[2][150];

void get()
{
	cout << ">>";
    promjena=getch();
	if(zmija[0][0]==xHrana && zmija[1][0]==yHrana)
	{
				velicinaZmije++;
				score++;
				xHrana = rand()%20;
				yHrana = rand()%30;
	}
	if(promjena!='0') {
		for(int i = velicinaZmije-1; i>0; i--)
		{
				zmija[0][i] = zmija[0][i-1];
				zmija[1][i] = zmija[1][i-1];
		} 
	}
	switch(promjena)
	{
		case 'W':
			zmija[0][0]--;
			if(zmija[0][0]<0) zmija[0][0]=19;
			break;
		case 'A':
			zmija[1][0]--;
			if(zmija[1][0]<0) zmija[1][0]=29;
			break;
		case 'S':
			zmija[0][0]++;
			if(zmija[0][0]>19) zmija[0][0]=0;
			break;
		case 'D':
			zmija[1][0]++;
			if(zmija[1][0]>29) zmija[1][0]=0;
			break;
	}
	if(promjena!='0') {
			for(int i = 1; i < velicinaZmije; i++)
			{
				if(zmija[0][0]==zmija[0][i] && zmija[1][0]==zmija[1][i])
				{
						kraj = true;
				}
			}
		}
	promjena='0';
}

void ispis(int n, int m, int z, int y)
{
	for(int i = 0; i < red; i++)
	{
		for(int j = 0; j < kolona; j++)
		{
			if(i==n && j==m) polje[i][j] = 'x';
			if(i==z && j==y) polje[i][j] = '*';
			
		}
	}
}

void pomjeraj()
{
	for(int i = 0; i < velicinaZmije; i++)
	{
		ispis(zmija[0][i], zmija[1][i], xHrana, yHrana);
	}
}

void reset()
{
	for(int i = 0; i < red; i++)
	{
		for(int j = 0; j < kolona; j++)
		{
			polje[i][j] = ' ';
		}
	}
}

void prikaz()
{
	cout << "***************************************" << endl;
	cout << "               SNAKE GAME              " << endl;
	cout << "***************************************" << endl;
	cout << "W-UP"    << endl;
	cout << "S-DOWN"  << endl;
	cout << "A-LEFT"  << endl;
	cout << "D-RIGHT" << endl;
	cout << "     --------------------------------   " << endl;
	for(int i = 0; i < red; i++)
	{   cout << "     |";
		for(int j = 0; j < kolona; j++)
		{
			cout << polje[i][j];
		} cout << "|" << endl;
	}
	cout << "     --------------------------------   " << endl;
	cout << "SCORE: " << score << endl;

}

int main()
{
	poc:
	srand(time(NULL));
	velicinaZmije = 1;
	score = 0;
	zmija[0][0] = 0; // x osa glave
	zmija[1][0] = 0; // y osa glave
	promjena = '0';
	xHrana = rand()%20;
	yHrana = rand()%30;
	reset();

	while(!kraj)
	{
		pomjeraj();
		prikaz();
		get();
		system("CLS");
		reset();
	}
	cout << "SCORE: " << score << endl;
	cout << "YOU LOSE!" << endl;
	system("PAUSE");
	system("CLS");
	kraj = false;
	goto poc;

	
	return 0;
}
