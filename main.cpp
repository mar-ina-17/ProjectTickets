#include <iostream>
#include <fstream>
#include "Theatre.h"

int main()
{   
	Theatre te;
	te.displayHelp();
	te.generateHalls(4);
	te.callMenu();

	std::ofstream myfile ("file.txt");
  if (myfile.is_open())
  {
    myfile << te;
    myfile.close();
  }

    return 0;
}
