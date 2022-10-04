#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <pthread.h>
#include "CUnit/Basic.h"
#include "../header/suite.h"
#include "../header/functions.h"

#define SUCCESS 1
#define FAILURE 0
#define nt 100

extern pthread_mutex_t lock;

int main() 
{
	pthread_t thread_id[nt];

	char str[100], cid[10];
	int ret;
	
	FILE *f;
	f = fopen("/home/harshit/code/data/examcenters.txt", "r");
	if (f == NULL)
        	return FAILURE;
    	while(1)
    	{
       		if(fgets(str, 100, f) == NULL)
      			break;
       		else
		{
			str[strlen(str)-1] = '\0';
			pthread_create(&thread_id[0], NULL, insertexamdata, (void* )str);
			pthread_join(thread_id[0], NULL);

		}
	}
	fclose(f);
	
	CU_pSuite pSuite1 = NULL;
  	CU_pSuite pSuite2 = NULL;

	if (CUE_SUCCESS != CU_initialize_registry())
		return CU_get_error();

	pSuite1 = CU_add_suite("suite insertcandidatedata...", init_suite_insertcandidatedata, clean_suite_insertcandidatedata);
  
	if (NULL == pSuite1) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}
  
	pSuite2 = CU_add_suite("suite printhallticket...", init_suite_printhallticket, clean_suite_printhallticket);
	
	if (NULL == pSuite2) 
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}

  	if ((NULL == CU_add_test(pSuite1, "Test for insertcandidatedata() in sunny cases", insertcandidatedata_sunnycases)) || (NULL == CU_add_test(pSuite1, "Test for insertcandidatedata() in rainy cases", insertcandidatedata_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}

	if ((NULL == CU_add_test(pSuite2, "Test for printhallticket() in sunny cases", printhallticket_sunnycases)) || (NULL == CU_add_test(pSuite2, "Test for printhallticket() in rainy cases", printhallticket_rainycases)))
  	{
    		CU_cleanup_registry();
    		return CU_get_error();
  	}

  	CU_basic_set_mode(CU_BRM_VERBOSE);
  	CU_basic_run_tests();
  	CU_cleanup_registry();
	
	pthread_exit(NULL);
  	
	return CU_get_error();
}

