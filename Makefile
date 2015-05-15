fecha.o: fecha.hh fecha.cc
	g++ -c fecha.cc
reloj.o: fecha.hh reloj.hh reloj.cc
	g++ -c reloj.cc
token.o: token.hh token.cc
	g++ -c token.cc
comanda.o: comanda.hh comanda.cc token.hh
	g++ -c comanda.cc
tarea.o: fecha.hh tarea.hh tarea.cc
	g++ -c tarea.cc
menu.o: fecha.hh tarea.hh menu.hh menu.cc
	g++ -c menu.cc
agenda.o: comanda.hh reloj.hh tarea.hh fecha.hh menu.hh token.hh agenda.hh agenda.cc
	g++ -c agenda.cc
program.o: agenda.hh program.cc
	g++ -c program.cc
program.exe: fecha.o reloj.o token.o comanda.o tarea.o menu.o agenda.o program.o
	g++ fecha.o reloj.o token.o comanda.o tarea.o menu.o agenda.o program.o -o program.exe
practica.tar: agenda.cc fecha.cc menu.hh tarea.cc agenda.hh fecha.hh program.cc tarea.hh reloj.cc menu.cc reloj.hh Makefile
	tar -cf practica.tar agenda.cc fecha.cc menu.hh tarea.cc agenda.hh fecha.hh program.cc tarea.hh reloj.cc menu.cc reloj.hh Makefile

