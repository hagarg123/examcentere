#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header/struct.h"

#define SUCCESS 1
#define FAILURE 0

extern struct examcenter *head_exam;
extern struct examcenter *tail_exam;

extern struct candidate *head_candidate;
extern struct candidate *tail_candidate;

int writetofile() 
{
   	struct examcenter* temp1 = NULL;
   	struct candidate* temp2 = NULL;
	
   	for(temp1 = head_exam; temp1 != NULL; temp1 = temp1->next) 
   	{	
		char file[100] = "/home/harshit/code/reports/";
		strcat(file, temp1 -> examcno);
		strcat(file,"_list.txt");

		FILE *fw;
		fw = fopen(file, "a");
		if (fw == NULL)
        		return FAILURE;

		for(temp2 = head_candidate; temp2 != NULL; temp2 = temp2 -> next)
		{
			if(strcmp(temp1->examcno, temp2-> examcno) == 0)
			{
         			fputs(temp2->examcno, fw); fputs("  ", fw);
         			fputs(temp2->examid, fw); fputs("  ", fw);
				fputs(temp2->candidateid, fw); fputs("  ", fw);
				fputs(temp2->name, fw); fputs("  ", fw);
				fputs(temp2->college_name, fw); fputs("  ", fw);
				fputs(temp2->address, fw); fputs("  ", fw);
				fputs(temp2->start_date, fw); fputs("  ", fw);
				fputs(temp2->end_date, fw); fputs("\n\n", fw);
			}
	      	}

		fclose(fw);	
   	}
}
