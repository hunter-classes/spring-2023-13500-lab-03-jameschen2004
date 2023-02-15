#include "reverseorder.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <vector>

void reverse_order(std::string date1, std::string date2){

   std::ifstream reservoir_file("Reservoir_Levels.tsv"); //file was not reading in correctly so I renamed it
   if (reservoir_file.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
   }
   std::string junk, dates;
   double eastSt, westSt, eastEl, westEl;
   int temp_num = 0;
   std::vector<double> westEl_vector;
   getline(reservoir_file, junk);

   while (reservoir_file >> dates >> eastSt >> eastEl >> westSt >> westEl){
        if (date1 == dates){
            temp_num = 1;
        }
        if (temp_num == 1){
            westEl_vector.insert(westEl_vector.begin(), westEl);
        }
        if (date2 == dates){
            temp_num = 0;
        }

        reservoir_file.ignore(INT_MAX, '\n');
    }
    for (int i=0; i<westEl_vector.size(); ++i)
    std::cout << westEl_vector[i] << ' ';
}



