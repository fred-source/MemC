#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>

#include "time.h"
#include "memtest.h"

#define RESET_LINE printf("\n")

typedef struct{
	MEMORYSTATUSEX mem;
}Memory;

// global structure access
Memory PtrData; 
	 
void 
physical_test()
{
	// Init the struct size
	PtrData.mem.dwLength = sizeof (PtrData.mem);
	
	// check pointer to MEMORYSTATUSEX 
	if(!GlobalMemoryStatusEx (&PtrData.mem)){
		printf("/ERROR : 0x%u" , GetLastError());
		exit(-1);
	}
	 
	RESET_LINE;
	for(int i = 0; i < PtrData.mem.dwMemoryLoad; i++)
	{
		Sleep(30);
		printf (("Memory In use \t\t\t       %*ld%\r"),7, i + 1);
	}
	
	RESET_LINE;
	Sleep(1000);
	
	// you won't see this
	printf (("There are %*I64d total Mbytes of physical memory.\r"),7,PtrData.mem.ullTotalPhys/1048576 );
			
	for(int i = 0; i < PtrData.mem.ullTotalPhys/1048576; i++)
	{ 
		printf (("Total physical memory \t\t\t  %*I64d \r"),7,i); 
	}
	
	RESET_LINE;
	Sleep(1000);
	for(int i = 0; i < PtrData.mem.ullAvailPhys/1048576; i++)
	{ 
		printf (("Free physical memory \t\t\t  %*I64d \r"),7, i);
	}
	RESET_LINE;
}

void 
virtual_test()
{ 

	PtrData.mem.dwLength = sizeof (PtrData.mem);
 
	if(!GlobalMemoryStatusEx (&PtrData.mem)){
		printf("/ERROR : 0x%u" , GetLastError());
		exit(-1);
	}
	
	printf (("total virtual memory \t\t 	 %*I64d \n"),7, PtrData.mem.ullTotalVirtual/1048576);
	Sleep(1000); 
	printf (("free virtual memory  \t\t 	 %*I64d \n"),7, PtrData.mem.ullAvailVirtual/1048576);
}