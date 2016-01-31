/* -----------------------------------------
	 fcheck.c -> Subprogram of Backgammon (gammon.cpp)
	 -----------------------------------------------------------------------*/

void file_check(char player1[20],char player2[20])
{
	int o,p;
	ifstream infile;
   ofstream outfile;

/* -----------------------------------------
	 Create file if it does not exist
	 -----------------------------------------------------------------------*/
	outfile.open("STATS.TXT",ios::app);
	outfile.close();

/* -----------------------------------------
	 Input database into array
	 -----------------------------------------------------------------------*/
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

/* -----------------------------------------
	 Search for player names
	 -----------------------------------------------------------------------*/
	p=o;
	for (;o!=-1;o--) {
		if (!strcmp(_array[o].name,player1))
			break;
	}
	for (;p!=-1;p--) {
		if (!strcmp(_array[p].name,player2))
			break;
	}

/* -----------------------------------------
	 Append names to database if they are not found
	 -----------------------------------------------------------------------*/
	if (o==-1) {
		outfile.open("STATS.TXT",ios::app);
		if (outfile) {
			outfile << player1 << '\n';
			outfile << "0\n0\n";
		}
		else cout << "FILE ERROR";
		outfile.close();
	}
	if (p==-1) {
		outfile.open("STATS.TXT",ios::app);
		if (outfile) {
			outfile << player2 << '\n';
			outfile << "0\n0\n";
		}
      else cout << "FILE ERROR";
		outfile.close();                                
	}
}