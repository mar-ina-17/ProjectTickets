#include <iostream>
#include <fstream>
#include "Theatre.h"


void open()
{
	char* fileName = new char[1000];
	std::cin >> fileName;
	
	std::ofstream file;
	file.open (fileName, std::ios::out | std::ios::in );
	if (file.is_open()) 
	{
		std::cout<<"Successfully opened "<<fileName<<std::endl;
	}
	else
	{
		std::ofstream newFile (fileName);
		newFile.open (fileName, std::ios::out | std::ios::in );
		std::cout<<"Successfully created and opened"<<fileName<<std::endl;
	}
}

int main()
{   
	open();

	Theatre te;
	te.displayHelp();
	te.generateHalls(4);
	te.callMenu();

    return 0;
}
