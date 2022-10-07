#include "CUnit/Basic.h"
#include "../header/functions.h"

int init_suite_insertcandidatedata(void) 
{
	return 0;
}

int clean_suite_insertcandidatedata(void) 
{
	return 0;
}

void insertcandidatedata_sunnycases(void) 
{
  	CU_ASSERT_EQUAL(insertcandidatedata("C001,Harshit Garg,MH-CET,21/08/2022,25/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("C004,Sudhanshu sadhwani,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("B010,Subhashree,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("B002,Subhadeep,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("A004,Sudarshan Timisha,CAT,15/10/2022,15/10/2022"), 1);
}

void insertcandidatedata_rainycases(void) 
{
	CU_ASSERT_EQUAL(insertcandidatedata("A012,Ayeshkanta,SAT,01/09/2022,03/04/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("Nikita,"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("A011,Yuvraj,BITSAT,02/03/2023,16/03/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("C023,Laxmi kant,BITSAT,02/03/2023,16/03/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("Jonas Edward,,02/03/2023,16/03/2023"), 0);
}

int init_suite_printhallticket(void) 
{
	return 0;
}

int clean_suite_printhallticket(void) 
{
	return 0;
}

void printhallticket_sunnycases(void)
{
	CU_ASSERT_EQUAL(printhallticket("A004"), 1);
	CU_ASSERT_EQUAL(printhallticket("B002"), 1);
	CU_ASSERT_EQUAL(printhallticket("C001"), 1);
}

void printhallticket_rainycases(void)
{
	CU_ASSERT_EQUAL(printhallticket("A011"), 0);
	CU_ASSERT_EQUAL(printhallticket("B005"), 0);
}
