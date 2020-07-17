#include "time.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h> 
#include <time.h> 
#include <windows.h>

/*
	calculates function time in order to do 
	callback in times
*/

#define RESET_LINE printf("\n") // printf's ugly asf 

void 
FunctionTime(void (_func)())
{  
	// create an instance of clock_t 
	clock_t t;  
	// calculate function time
    t = clock(); 
    _func();  
    t = clock() - t;
	int time = t;
	// sleep the amount of function time
	printf("Wait! Do not close!");
	Sleep(time); 
	
	RESET_LINE;
	for(int i = 0; i < time; i++)
	{ 
		printf("[%i/%i] \r", i , time );
		if( i == time - 1 )
			printf("[OK] Done! \r");
	}
	RESET_LINE;
}
