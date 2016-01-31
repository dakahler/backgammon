/* -----------------------------------------
	 dispchar.c -> Subprogram of Backgammon (gammon.cpp)
	 -----------------------------------------------------------------------*/

void display_chars(int off,int off2,int places[25])
{
	int a,b,places_c,x=3,y=12;

	clrscr();
	display();

/* -----------------------------------------
	 Display loop
	 -----------------------------------------------------------------------*/
	for (places_c=0;places_c<=23;places_c++) {
		b=0;
		gotoxy(x,y);
		if  (y==12)
			  a=0;
		else a=1;
		if  (places[places_c]<0)
			  disp_o(a,places,places_c);
		if  (places[places_c]>0)
			  disp_x(a,places,places_c);

		if ((x==18 && y==3) || (x==45 && y==3)) {
			x-=3;
			b=2;
		}
		if (x==30 && y==12) {
			x+=3;
			b=2;
		}
		if (x!=18 && x!=45 && x!=30 && b!=2) {
			if (y==12)
				x+=3;
			if (y==3)
				x-=3;
			b=1;
		}
		if (x==18 && y==12 && !b)
			x+=12;
		if (x==45 && y==12 && !b)
			y=3;
		if (x==30 && y==3 && !b)
			x-=12;
	}

/* -----------------------------------------
	 Bar calculations
	 -----------------------------------------------------------------------*/
	if (places[24]!=0)
		bar_xo(places);

/* -----------------------------------------
	 Bear-off calculations
	 -----------------------------------------------------------------------*/
	if (off>0) {
		gotoxy(50,1);
		cout << "X-off = " << off;
	}
	if (off2>0) {
		gotoxy(50,3);
		cout << "O-off = " << off2;
	}
}