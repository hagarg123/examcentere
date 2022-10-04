final_run: main.o insertexamdata.o insertcandidatedata.o writetofile.o printhallticket.o
	gcc ../obj/main.o ../obj/insertexamdata.o ../obj/insertcandidatedata.o ../obj/writetofile.o ../obj/printhallticket.o -o ../bin/examcenter1 -lpthread

test_run: suite.o case.o insertexamdata.o insertcandidatedata.o printhallticket.o
	gcc ../obj/suite.o ../obj/case.o ../obj/insertexamdata.o ../obj/insertcandidatedata.o ../obj/printhallticket.o -o ../bin/examcenter2 -lcunit -lpthread

suite.o: ../src/suite.c
	gcc -o ../obj/suite.o -c ../src/suite.c

case.o: ../src/case.c
	gcc -o ../obj/case.o -c ../src/case.c

main.o: ../src/main.c
	gcc -o ../obj/main.o -c ../src/main.c

insertexamdata.o: ../src/insertexamdata.c
	gcc -o ../obj/insertexamdata.o -c ../src/insertexamdata.c


insertcandidatedata.o: ../src/insertcandidatedata.c
	gcc -o ../obj/insertcandidatedata.o -c ../src/insertcandidatedata.c

writetofile.o: ../src/writetofile.c
	gcc -o ../obj/writetofile.o -c ../src/writetofile.c

printhallticket.o: ../src/printhallticket.c
	gcc -o ../obj/printhallticket.o -c ../src/printhallticket.c

clean:
	@echo"cleaning files....."
	rm ../obj/main.o ../obj/insertexamdata.o ../obj/insertcandidatedata.o ../obj/writetofile.o ../obj/printhallticket.o
