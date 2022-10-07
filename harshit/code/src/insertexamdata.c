#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h> //return info about directories
#include <pthread.h>
#include "../header/struct.h" //user based header file

extern struct examcenter *head_exam; //using struct here predefined in struct header file
extern struct examcenter *tail_exam;

void* insertexamdata(void* str)
{	
	char *exam_center_number, *exam_id, *college, *addr;
	int choice=0;
	
	char *temp= (char*)str;

	char *token = strtok(temp, ":"); //using for seperate string			
	while (token != NULL) 
	{
		choice++;
		switch(choice)
		{
			case 1: exam_center_number = calloc(strlen(token),sizeof(char)); 
				strcpy(exam_center_number, token); 
				break;
			case 2: exam_id = calloc(strlen(token),sizeof(char)); 
				strcpy(exam_id, token); 
				break;
			case 3: college = calloc(strlen(token),sizeof(char)); 
				strcpy(college, token); 
				break;
			case 4: addr = calloc(strlen(token),sizeof(char)); 
				strcpy(addr, token); 
				break;
		}
		token = strtok(NULL, ":");//move to next string
	}
	//making a linklist here
	struct examcenter *newlink = calloc(1, sizeof(struct examcenter));//using dyanmic memory allocation
	//copy the data to linkedlist from the file
	newlink->examcno = calloc(strlen(exam_center_number),sizeof(char));
	newlink->examcno = exam_center_number;

	newlink->examid = calloc(strlen(exam_id),sizeof(char));
	newlink->examid = exam_id;
	
	newlink->college_name = calloc(strlen(college),sizeof(char));
	newlink->college_name = college;
	
	newlink->address = calloc(strlen(addr),sizeof(char));
	newlink->address = addr;
   	
	newlink->next = NULL; //last element pointing to NULL
	
	pthread_mutex_init(&newlink->lock, NULL);

	if(head_exam == NULL)
		head_exam = tail_exam = newlink; //
	else
	{
		tail_exam->next = newlink;
		tail_exam = newlink;
	}

}
