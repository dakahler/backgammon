/* -----------------------------------------
	 bar.c -> Subprogram of Backgammon (dispchar.c)
	 -----------------------------------------------------------------------*/

void bar_xo(int places[25])
{
/* -----------------------------------------
	 Determines the display of bar checkers (if applicable)
	 -----------------------------------------------------------------------*/
	int i=0,k,j;

	if (places[24]<0)
		k=3;
	if (places[24]>0)
		k=12;

	while (places[24]!=i) {
		j=24;
		gotoxy(j,k);
		if (places[24]<0) {
			cout << 'O';
			i--; k++;
		}
		if (places[24]>0) {
			cout << 'X';
			i++; k--;
		}
	}
}