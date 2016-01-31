/* -----------------------------------------
	 filechg.c -> Subprogram of Backgammon (gammon.cpp)
	 -----------------------------------------------------------------------*/

void file_chg(char player1[20],char player2[20],int win)
{
	int o,p,q,r;
	ifstream infile;
   ofstream outfile;

	infile.open("STATS.TXT",ios::in);
	if (infile) {
		for (o=0;!infile.eof();o++) {
			infile >> _array[o].name;
			infile >> _array[o].wins;
			infile >> _array[o].losses;
		}
	}
	else cout << "FILE ERROR";
	infile.close();

	p=q=o;
	for (;strcmp(_array[o].name,player1);o--) {}
	for (;strcmp(_array[p].name,player2);p--) {}

	r=p;
	if (win) {
		_array[o].wins++;
		_array[p].losses++;
		outfile.open("STATS.TXT",ios::out);
		if (outfile) {
			for (p=0;p<q-1;p++) {
				outfile << _array[p].name   << '\n';
				outfile << _array[p].wins   << '\n';
				outfile << _array[p].losses << '\n';
			}
		}
		else cout << "FILE ERROR";
		outfile.close();
	}
	else {
		_array[o].losses++;
		_array[p].wins++;
		r=p;
		outfile.open("STATS.TXT",ios::out);
		if (outfile) {
			for (p=0;p<q-1;p++) {
				outfile << _array[p].name   << '\n';
				outfile << _array[p].wins   << '\n';
				outfile << _array[p].losses << '\n';
			}
		}
      else cout << "FILE ERROR";
		outfile.close();
	}
	cout << player1 << " stats: " << _array[o].wins << '-'
		  << _array[o].losses;
	cout << '\n' << player2 << " stats: " << _array[r].wins << '-'
		  << _array[r].losses;
}