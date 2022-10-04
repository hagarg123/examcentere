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
  	CU_ASSERT_EQUAL(insertcandidatedata("C001,Shantanu Mukherjee,MH-CET,21/08/2022,25/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("C004,Srihari Varsha Rama Rao,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("B010,Sanjay,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("B002,Hemanth,UPSC,01/08/2022,01/08/2022"), 1);
	CU_ASSERT_EQUAL(insertcandidatedata("A004,Anusha Jain,CAT,15/10/2022,15/10/2022"), 1);
}

void insertcandidatedata_rainycases(void) 
{
	CU_ASSERT_EQUAL(insertcandidatedata("A012,Amit Kumar,SAT,01/09/2022,03/04/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("Kranti,"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("A011,Bhaskar Narayan,BITSAT,02/03/2023,16/03/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("C023,Kamelesh Rao,BITSAT,02/03/2023,16/03/2023"), 0);
    	CU_ASSERT_EQUAL(insertcandidatedata("Ganesh Apte,,02/03/2023,16/03/2023"), 0);
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
