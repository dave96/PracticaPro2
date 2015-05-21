fecha.o: fecha.hh fecha.cc
	g++ -c fecha.cc -D_GLIBCXX_DEBUG
reloj.o: fecha.hh reloj.hh reloj.cc
	g++ -c reloj.cc -D_GLIBCXX_DEBUG
token.o: token.hh token.cc
	g++ -c token.cc -D_GLIBCXX_DEBUG
comanda.o: comanda.hh comanda.cc token.hh
	g++ -c comanda.cc -D_GLIBCXX_DEBUG
tarea.o: fecha.hh tarea.hh tarea.cc
	g++ -c tarea.cc -D_GLIBCXX_DEBUG
menu.o: fecha.hh tarea.hh menu.hh menu.cc
	g++ -c menu.cc -D_GLIBCXX_DEBUG
agenda.o: comanda.hh reloj.hh tarea.hh fecha.hh menu.hh token.hh agenda.hh agenda.cc
	g++ -c agenda.cc -D_GLIBCXX_DEBUG
program.o: agenda.hh program.cc
	g++ -c program.cc -D_GLIBCXX_DEBUG
program.exe: fecha.o reloj.o token.o comanda.o tarea.o menu.o agenda.o program.o
	g++ fecha.o reloj.o token.o comanda.o tarea.o menu.o agenda.o program.o -o program.exe
practica.tar: agenda.cc fecha.cc menu.hh tarea.cc agenda.hh fecha.hh program.cc tarea.hh reloj.cc menu.cc reloj.hh Makefile
	tar -cvf practica.tar agenda.cc fecha.cc menu.hh tarea.cc agenda.hh fecha.hh program.cc tarea.hh reloj.cc menu.cc reloj.hh Makefile jp_david.alvarez.robert_entrada.txt jp_david.alvarez.robert_sortida.txt jp_gonzalo.solera_entrada.txt jp_gonzalo.solera_sortida.txt equip.pdf html.zip

