#include <iostream>
#include <vector>
#include <string>
using namespace std;



int getDigits(int number){
	int digits = 0;
	while(number>0) {
		number/=10;
		digits+=1;
	}
	return digits;
}
int main ()
{
  //cout << (unsigned)-1;
  //return 0;
  string whitespace = "";
  int timesTableSize;
  int bufferWhitespace = 1;
  timesTableSize = 16;
  int maxDigits = getDigits(timesTableSize*timesTableSize);
  vector< vector<int> > grid(timesTableSize, vector<int>(timesTableSize));
  for(unsigned int row=0;row<grid.size();row++){
	  for(unsigned int col = 0;col<grid[row].size();col++){
		  int numberInSpot = (row+1)*(col+1);
		  grid[row][col] = numberInSpot;
		  int whiteSpaceNeeded = maxDigits-getDigits(numberInSpot);
		  for(int i=0;i<whiteSpaceNeeded+bufferWhitespace;i++){
			  whitespace.append(" ");
		  }
		  cout <<whitespace<< grid[row][col];
		  whitespace = "";

	  }
	  for(int i=0;i<bufferWhitespace;i++){
	    cout << endl;
	  }
  }
}
