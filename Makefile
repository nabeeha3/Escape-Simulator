Assignment5:	main.o Escape.o Hero.o List.o Participant.o random.o Snorc.o MoveBehaviour.o Ninja.o 
				RescuedBehaviour.o VillanBehaviour.o EscapeeBehaviour.o RescuerBehaviour.o 
	g++ -g -o Assignment5 main.o Escape.o Hero.o List.o Participant.o random.o Snorc.o MoveBehaviour.o Ninja.o 
				RescuedBehaviour.o VillanBehaviour.o EscapeeBehaviour.o RescuerBehaviour.o 

main.o:			main.cc Escape.h
	g++ -c main.cc

Escape.o:		Escape.cc Escape.h Snorc.h List.h Hero.h Ninja.h
	g++ -c Escape.cc

Hero.o:		Hero.cc Hero.h Participant.h
	g++ -c Hero.cc

List.o:	List.cc List.h 
	g++ -c List.cc

Ninja.o: Ninja.cc Ninja.h Participant.h
	g++ -c Ninja.cc

Participant.o:	Participant.cc Participant.h MoveBehaviour.h EscapeeBehaviour.h RescuedBehaviour.h RescuerBehaviour.h VillanBehaviour.h
	g++ -c Participant.cc

random.o:		random.cc
	g++ -c random.cc

Snorc.o:		Snorc.cc Snorc.h Participant.h
	g++ -c Snorc.cc

MoveBehaviour.o:	MoveBehaviour.cc MoveBehaviour.h defs.h
	g++ -c MoveBehaviour.h

EscapeeBehaviour.o:	EscapeeBehaviour.cc EscapeeBehaviour.h MoveBehaviour.h
	g++ -c EscapeeBehaviour.h

RescuerBehaviour.o:	RescuerBehaviour.cc RescuerBehaviour.h MoveBehaviour.h
	g++ -c RescuerBehaviour.h

RescuedBehaviour.o:	RescuedBehaviour.cc RescuedBehaviour.h MoveBehaviour.h
	g++ -c RescuedBehaviour.h

VillanBehaviour.o:	VillanBehaviour.cc VillanBehaviour.h MoveBehaviour.h
	g++ -c VillanBehaviour.h

clean:
	rm -f *.o Assignment5
