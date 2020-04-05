aptest: aptest.o guidance_control.o autopilot.o
	g++ -o aptest -g aptest.o autopilot.o guidance_control.o

aptest.o: aptest.cc
	g++ -g -c -Wall aptest.cc

guidance_control.o: guidance_control.cc guidance_control.h
	g++ -g -c -Wall guidance_control.cc

autopilot.o: autopilot.cc autopilot.h
	g++ -g -c -Wall autopilot.cc

clean:
	rm -f *.o aptest
