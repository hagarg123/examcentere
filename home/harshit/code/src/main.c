#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h> //return info about directories
#include <pthread.h>
#include "../header/functions.h" //user based header file

#define SUCCESS 1
#define FAILURE 0
#define max 100
int flag=1;
extern pthread_mutex_t lock; 

int main(int argc, char *argv[]) 
{
	pthread_t thread_id[max]; //data type used to uniquely identify a thread

	char str[100], cid[10];
	int ret;

	if(argc < 4)
	{
		printf("\n\n\t!!!Please provide the required command line arguments");
		return FAILURE;
	}
	
	FILE *f;
	f = fopen(argv[1], "r"); //opening examcenters file stored in data in read mode
	if (f == NULL)
        	return FAILURE;
    	while(1)
    	{
       		if(fgets(str, 100, f) == NULL) //condition for last+1 line
      			break;
       		else
		{
			str[strlen(str)-1] = '\0'; //removing extra space after last character of string by assign NULL
			pthread_create(&thread_id[0], NULL, insertexamdata, (void* )str); //creating thread 
			pthread_join(thread_id[0], NULL); // joining thread
		}
	}
	fclose(f);

	for(int i=2; i<argc; i++)
	{
		pthread_create(&thread_id[i-1], NULL, processing_data, (void* )argv[i]);
		pthread_join(thread_id[i-1], NULL);
	}
	
	writetofile();

	printf("\n\nEnter the candidate id to display the hall ticket: ");
	fgets(cid, 10, stdin);
	cid[strlen(cid)-1] = '\0';
	ret = printhallticket(cid);

	if(ret == 0)
		printf("\n\n\t!!!The person with the candidate id %s is not in the list", cid);
	
	pthread_mutex_destroy(&lock);
	pthread_exit(NULL);

   	return SUCCESS;
}
