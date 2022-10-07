final_run: main.o insertexamdata.o processing_data.o insertcandidatedata.o writetofile.o printhallticket.o
	gcc ../obj/main.o ../obj/insertexamdata.o ../obj/processing_data.o ../obj/insertcandidatedata.o ../obj/writetofile.o ../obj/printhallticket.o -o ../bin/examcenter1 -lpthread

test_run: suite.o sunny_rainy_testcase.o insertexamdata.o insertcandidatedata.o printhallticket.o
	gcc ../obj/suite.o ../obj/sunny_rainy_testcase.o ../obj/insertexamdata.o ../obj/insertcandidatedata.o ../obj/printhallticket.o -o ../bin/examcenter2 -lcunit -lpthread

suite.o: ../src/suite.c
	gcc -o ../obj/suite.o -c ../src/suite.c

sunny_rainy_testcase.o: ../src/sunny_rainy_testcase.c
	gcc -o ../obj/sunny_rainy_testcase.o -c ../src/sunny_rainy_testcase.c

main.o: ../src/main.c
	gcc -o ../obj/main.o -c ../src/main.c

insertexamdata.o: ../src/insertexamdata.c
	gcc -o ../obj/insertexamdata.o -c ../src/insertexamdata.c

processing_data.o: ../src/processing_data.c
	gcc -o ../obj/processing_data.o -c ../src/processing_data.c

insertcandidatedata.o: ../src/insertcandidatedata.c
	gcc -o ../obj/insertcandidatedata.o -c ../src/insertcandidatedata.c

writetofile.o: ../src/writetofile.c
	gcc -o ../obj/writetofile.o -c ../src/writetofile.c

printhallticket.o: ../src/printhallticket.c
	gcc -o ../obj/printhallticket.o -c ../src/printhallticket.c

clean:
	@echo"cleaning files....."
	rm ../obj/main.o ../obj/insertexamdata.o ../obj/insertcandidatedata.o ../obj/writetofile.o ../obj/printhallticket.o
