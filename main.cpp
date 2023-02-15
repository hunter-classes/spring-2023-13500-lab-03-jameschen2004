#include "reservoir.h"
#include "reverseorder.h"
#include <string>
#include <iostream>

int main(){

  std::cout << "The east storage capacity on 01/01/2018 is " << get_east_storage("01/01/2018") << " gallons. \n";
  std::cout << "The east storage capacity on 06/05/2018 is " << get_east_storage("06/05/2018") << " gallons. \n";
  std::cout << "----------------------------------------------------------------------------- \n";
  std::cout << "The minimum storage in the East basin in 2018 is " << get_min_east() << " gallons. \n";
  std::cout << "The maximum storage in the East basin in 2018 is " << get_max_east() << " gallons. \n";
  std::cout << "----------------------------------------------------------------------------- \n";
  std::cout << "On 01/01/2018, the " << compare_basins("01/01/2018") << " basin was higher.\n";
  std::cout << "On 06/05/2018, the " << compare_basins("06/05/2018") << " basin was higher.\n";
  std::cout << "On 01/08/2018, the " << compare_basins("01/08/2018") << " basin was higher.\n";
  std::cout << "----------------------------------------------------------------------------- \n";
  std::cout << "The West basin elevation for all days in the interval \n01/01/2018 to 01/10/2018 in reverse chronological order is \n";
  reverse_order("01/01/2018","01/10/2018");
  std::cout << "\n"; 
  std::cout << "The West basin elevation for all days in the interval \n02/01/2018 to 02/14/2018 in reverse chronological order is \n";
  reverse_order("02/01/2018","02/14/2018");
  std::cout << "\n"; 
  return 0;
}

