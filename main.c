#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "time.h"
#include "memtest.h"

/*

	 MemC
	****  
	 MemoryTest Program inspired by old BIOS
	 ****
	  XorGentlem4n@github.com
*/

#define next true	
typedef _Bool bool;
unsigned int sleep(unsigned int nb_sec);
void FunctionTime(void (_func)());
void virtual_test(void);
void physical_test(void);

bool 
Wait()
{
	return 1;
}
 
int 
main(int arg, char *arc[])
{
	if(arg >= 2)
		return 0;
	  
	printf("Status  \t\t\t  	    Memory \n");
	printf("******  \t\t\t  	    ****** \n");
	 	
	FunctionTime(virtual_test);
	FunctionTime(physical_test);
	
	// wait for user input to finish the program.
	while(Wait())
	{
		printf("Done! You can exit by pressing CTRL + C! \r"); 
	}
}
