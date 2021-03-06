/******************************************/
/* BACKGAMMON                             */
/* Version 1.0 Beta Revision 5/OPT 1      */
/* David Kahler                           */
/******************************************/


/* -----------------------------------------
	 Defines
	 -----------------------------------------------------------------------*/
#define  FORFEIT       25
#define  NCHG         -25
#define  P1             1
#define  P2             2
#define  WIN           15

/* -----------------------------------------
	 All include headers
	 -----------------------------------------------------------------------*/
#include "include.c"

#include <time.h>

/* -----------------------------------------
	 Main
	 -----------------------------------------------------------------------*/
void main()
{
   int   places[25] = {5,0,0,0,-3,0,-5,0,0,0,0,2,-2,0,0,0,0,5,0,3,0,0,0,-5,0};
	int   n1,n2,off=0,off2=0,turn,win;
	char  player1[20],player2[20];

/* -----------------------------------------
	 Init number generator and display initial board
	 -----------------------------------------------------------------------*/
	srand(time(NULL));
	display_chars(off,off2,places);

/* -----------------------------------------
	 Ask player names and compare to database
	 -----------------------------------------------------------------------*/
	gotoxy(1,16);
	cout << "Player 1? ";
	cin >> player1;
	cout << "Player 2? ";
	cin >> player2;
	file_check(player1,player2);

/* -----------------------------------------
	 Determine who moves first
	 -----------------------------------------------------------------------*/
	do {
   	n1=(rand()%6)+1;
		n2=(rand()%6)+1;
		if (n1==n2)
			continue;
		cout << '\n' << player1 << " rolled " << n1;
		cout << '\n' << player2 << " rolled " << n2;
		if (n1>n2) {
			cout << "\n\n" << player1 << ", you go first!";
			turn=1;
			break;
		}
		else {
			cout << "\n\n" << player2 << ", you go first!";
			turn=2;
			break;
		}
	}  while (n1==n2);

	cout << " <Press a key>";
	getch();

/* -----------------------------------------
	 Main
	 -----------------------------------------------------------------------*/
	win=move(player1,player2,turn,off,off2,places);

/* -----------------------------------------
	 End game
	 -----------------------------------------------------------------------*/
	clrscr();
	if (off==WIN)
		cout << "Congratulations, " << player1 << ", you win!\n\n";
	else
		cout << "Congratulations, " << player2 << ", you win!\n\n";

/* -----------------------------------------
	 File Appendages
	 -----------------------------------------------------------------------*/
	file_chg(player1,player2,win);

}



