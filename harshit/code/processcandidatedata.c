#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* processcandidatedata(void* file)
{
		char str[100];
		int ret;
		
		char *temp= (char*)file;
		
		FILE *f;
		f = fopen(temp, "r"); //opening candidate data here
		while(1)  		
		{
       			if(fgets(str, 100, f) == NULL)
      				break;
			else
			{
				str[strlen(str)-1] = '\0';
				ret = insertcandidatedata(str); //getting 0 or 1 by calling this function
				if(ret == 0)
				{ 
					if(flag)
					{
					  	printf("\n\nIncorrect Data ");
						flag=0;
					}
					printf("\nCandidate ID :%s", strtok(str, ","));
}
			}
		}
		fclose(f);
}
