#include "reservoir.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <climits>

double get_east_storage(std::string user_date){
   
   std::ifstream reservoir_file("Reservoir_Levels.tsv"); //file was not reading in correctly so I renamed it
   if (reservoir_file.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
   }
   
   std::string junk, date;
   double eastSt;
   getline(reservoir_file, junk);

   while (reservoir_file >> date >> eastSt){
      if (date == user_date){
         return eastSt;
         reservoir_file.close();
      }
      reservoir_file.ignore(INT_MAX, '\n');
   }
   return 0;
}

double get_min_east(){

   std::ifstream reservoir_file("Reservoir_Levels.tsv");

   double min_value, eastSt;
   std::string junk, date;

   min_value = 1000000; // arbitrary value greater than all values of corresponding column

   getline(reservoir_file, junk);

   while (reservoir_file >> date >> eastSt){
   
      if (min_value > eastSt){
         min_value = eastSt;
      }
      
      reservoir_file.ignore(INT_MAX, '\n');
   }   
   reservoir_file.close();
   return min_value;
}

double get_max_east(){

   std::ifstream reservoir_file("Reservoir_Levels.tsv");

   double max_value, eastSt;
   std::string junk, date;

   max_value = 0; // arbitrary value less than all values of corresponding column

   getline(reservoir_file, junk);

   while (reservoir_file >> date >> eastSt){
   
      if (max_value < eastSt){
         max_value = eastSt;
      }
      
      reservoir_file.ignore(INT_MAX, '\n');
   }
   reservoir_file.close();   
   return max_value;
}

std::string compare_basins(std::string date){

   std::ifstream reservoir_file("Reservoir_Levels.tsv"); //file was not reading in correctly so I renamed it
   if (reservoir_file.fail()) {
      std::cerr << "File cannot be opened for reading." << std::endl;
      exit(1); // exit if failed to open the file
   }
   
   std::string junk, dates;
   double eastSt, westSt, eastEl, westEl;
   getline(reservoir_file, junk);

   while (reservoir_file >> dates >> eastSt >> eastEl >> westSt >> westEl){

      if (dates == date){
         if (eastEl > westEl){
            return "East";
         }
         else if (westEl > eastEl){
            return "West";
         }
         else{
            return "Equal";
         }
         reservoir_file.close();
      }
      reservoir_file.ignore(INT_MAX, '\n');
   }
   return 0;
}