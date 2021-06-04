#include <iostream>
#include <fstream>
#include "Theatre.h"

int main()
{   
	Theatre te;
	te.displayHelp();
	te.generateHalls(4);
	te.callMenu();

    return 0;
}
