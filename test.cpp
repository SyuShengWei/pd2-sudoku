#include <iostream>
#include "Sudoku.h"
using namespace std ;
int main ()
{
	Sudoku Su;
	Su.readIn();
	Su.solve();
	cout<<endl;
 	//Su.giveQuestion();
 	cout<<endl;
 	//Su.readIn();
	//Su.transform();
	cout<<endl;
	return 0;
}
