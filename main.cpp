// add your code as appropriate 
#include "reservoir.h"
#include <fstream>
#include <cstdlib>
#include <climits>

int main()
{
  ifstream fin("Current_Reservoir_Levels.tsv");
  if (fin.fail()) {
    cerr << "File cannot be opened for reading." << endl;
    exit(1); // exit if failed to open the file
  }
  string junk;        // new string variable
  getline(fin, junk); // read one line from the file 
  while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
    // this loop reads the file line-by-line
    // extracting 5 values on each iteration 
    
    fin.ignore(INT_MAX, '\n'); //skips to the end of line, 
                          //ignorring the remaining columns
                    
    std::cout << date << " " << eastSt << std::endl;
  }
  fin.close();

  return 0;
}
