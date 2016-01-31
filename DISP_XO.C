/* -----------------------------------------
	 disp_xo.c -> Subprogram of Backgammon (dispchar.c)
	 -----------------------------------------------------------------------*/

void disp_x(int a,int places[25],int places_c)
{
	int b,c,g;

	if (!a)
		  c=12;
	else c= 3;

	for (g=0;places[places_c]!=g;g++) {
		if (!g)
			  b=wherex();
		else b=wherex()-1;

		gotoxy(b,c);
		if (!a) {
			c--;
			if (g<=5 && places[places_c]<=5)                // 5 checkers or less?
				cout << 'X';                                 // Disp X
			if (g<5 && places[places_c]>5) {                // More then 5?
				if (g==4)                                    // Counter at 4?
					g++;                                      // Increment
				cout << 'X';                                 // Disp X
			}
			if (places[places_c]>5 && g==5) {               // g==5 && >5 checkers?
				b=wherex()-1;                                // Reset cursor
				gotoxy(b,8);                                 // Go there
				cout << ((places[places_c]-g)+1);            // How many chkrs are
				break;                                       // being covered?
			}
		}
		else {
			if (places[places_c]>5 && !g)                   // If 1- and 5+ chkrs
				g++;
			c++;
			if (g<=5)
				cout << 'X';                                 // Disp an X
			if (places[places_c]>5 && g==5) {               // g==5 && chkrs>5
				b=wherex()-1;                                // Reset cursor
				gotoxy(b,7);                                 // Go there
				cout << ((places[places_c]-g)+1);            // How many chkrs are
				break;
			}
		}
	}
}

void disp_o(int a,int places[25],int places_c)
{
	int b,c,g;

	if (!a) {                                             // If cursor==bottom
		c=12;                                              // Set cursor to Y=12
		for (g=0;places[places_c]!=g;g--) {                // Start the loop
			if (!g)                                         // First run-through?
				b=wherex();                                  // Set b to cursor pos
			if (g!=0)                                       // 2+?
				b=wherex()-1;                                // Compensate cursor
			gotoxy(b,c);                                    // Go there
			c--;                                            // Bump down 1 Y
			if (g>=-5 && places[places_c]>=-5)              // If chkrs<=5
				cout << 'O';                                 // Disp an O
			if (g>=-5 && places[places_c]<-5) {             // If chkrs>5
				if (g==-4)                                   // If counters up to 4
					g--;                                      // Decrement
				cout << 'O';                                 // Disp an O
			}
			if (places[places_c]<-5 && g==-5) {             // If chkrs>5 && cnt==5
				b=wherex()-1;                                // Reset cursor
				gotoxy(b,8);                                 // Go there
				cout << abs((places[places_c]+abs(g))-1);    // How many chkrs are
				break;                                          // being covered?
			}
		}
	}
	if (a) {                                              // If cursor==top
		c=3;                                               // Set cursor to Y=3
		for (g=0;places[places_c]!=g;g--) {                // Start the loop
			if (!g)                                         // First run-through?
				b=wherex();                                  // Set b to cursor pos
			if (g!=0)                                       // 2+
				b=wherex()-1;                                // Compensate cursor
			if (places[places_c]<-5 && g==0)                // If chkrs<5
				g++;                                         // Increment g
			gotoxy(b,c);                                    // Go there
			c++;                                            // Bump up 1 Y
			if (g>=-5)                                      // If g >=-5
				cout << 'O';                                 // Disp an O
			if (places[places_c]<-5 && g==-5) {             // If chkrs<5 && g==-5
				b=wherex()-1;                                // Reset cursor
				gotoxy(b,7);                                 // Go there
				cout << abs((places[places_c]+abs(g))-1);    // How many chkrs are
				break;                                          // being covered?
			}
		}
	}
}