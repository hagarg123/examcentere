#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "../header/struct.h"

#define SUCCESS 1
#define FAILURE 0

pthread_mutex_t lock;

struct examcenter *head_exam = NULL;
struct examcenter *tail_exam = NULL;

struct candidate *head_candidate  = NULL;
struct candidate *tail_candidate  = NULL;

int insertcandidatedata(char *str)
{
	
	FILE *fw;
	fw = fopen("/home/harshit/code/reports/InvalidCandidates.txt", "a");
	if (fw == NULL)
        	return FAILURE;

	char *candidate_id, *nam, *eid, *stdate, *endate, temp[100];
	strcpy(temp, str);	
	int ct=0;
	
	char *token = strtok(temp, ",");		
	while (token != NULL) 
	{
		ct++;
		switch(ct)
		{
			case 1: candidate_id = calloc(strlen(token),sizeof(char)); 
				strcpy(candidate_id, token); 
				break;
			case 2: nam = calloc(strlen(token),sizeof(char)); 
				strcpy(nam, token); 
				break;
			case 3: eid = calloc(strlen(token),sizeof(char)); 
				strcpy(eid, token); 
				break;
			case 4: stdate = calloc(strlen(token),sizeof(char)); 
				strcpy(stdate, token); 
				break;
			case 5: endate = calloc(strlen(token),sizeof(char)); 
				strcpy(endate, token); 
				break;
		}
		token = strtok(NULL, ",");
	}

	if(ct == 5)
	{
		struct examcenter *temp = NULL;
		int flag = 0;
   		for(temp = head_exam; temp != NULL; temp = temp->next) 
   		{
			if(strcmp(temp->examid, eid) == 0)
			{		
				pthread_mutex_lock(&lock);
				flag = 1;
				break;
			}
		}	
	   	if(flag == 1)
	   	{
				struct candidate *newlink = calloc(1, sizeof(struct candidate)); //dyanmic memory allocation

				newlink->examcno = calloc(strlen(temp->examcno),sizeof(char));
				newlink->examcno = temp->examcno;
	
				newlink->examid = calloc(strlen(temp->examid),sizeof(char));
				newlink->examid = temp->examid;
	
				newlink->college_name = calloc(strlen(temp->college_name),sizeof(char));
				newlink->college_name = temp->college_name;
	
				newlink->address = calloc(strlen(temp->address),sizeof(char));
				newlink->address = temp->address;
	
				newlink->candidateid = calloc(strlen(candidate_id),sizeof(char));
				newlink->candidateid = candidate_id;
	
				newlink->name = calloc(strlen(nam),sizeof(char));
				newlink->name = nam;

				newlink->start_date = calloc(strlen(stdate),sizeof(char));
				newlink->start_date = stdate;
	
				newlink->end_date = calloc(strlen(endate),sizeof(char));
				newlink->end_date = endate;
   		
				newlink->next = NULL;
 
				if(head_candidate == NULL)
					head_candidate = tail_candidate = newlink;
				else
				{
					tail_candidate->next = newlink;
					tail_candidate = newlink;
				}
   		}
		else
		{
			fputs(str, fw);
			fputs("\n\n", fw);
			
			return FAILURE;
		}

		pthread_mutex_unlock(&lock);
	}
	else
	{
		fputs(str, fw);
		fputs("\n\n", fw);
		
		return FAILURE;
	}
	
	fclose(fw);

	return SUCCESS;
}

void* processing_data(void* file)
{
		char str[100];
		int ret;
		
		char *temp= (char*)file;
		int flag=1;
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
					  	printf("\n\nIncorrect Data  ");
						flag=0;
					}
					printf("\nCandidate ID :%s", strtok(str, ","));
}
			}
		}
		fclose(f);
}
