all: compile linking
	@rm *.o
	@chmod +x Frog_Thread
	@echo "Ora puoi eseguire"

compile:
	@echo "Sto compilando"
	@gcc -c source/controllo.c -o controlloT.o
	@gcc -c source/colorazione.c -o colorazioneT.o
	@gcc -c source/menu.c -o menuT.o
	@gcc -c source/global.c -o globalT.o
	@gcc -c source/rana.c -o ranaT.o
	@gcc -w -c source/tronco.c -o troncoT.o
	@gcc -w -c source/macchina.c -o macchinaT.o
	@gcc -c source/tempo.c -o tempoT.o
	@gcc -c source/inizio_game.c -o inizio_gameT.o
	@gcc -w -c source/suono.c -o suonoT.o
	@gcc -c source/scelta_difficolta.c -o scelta_difficoltaT.o

linking:
	@echo "Sto Linkando"
	@gcc *.o -lncurses -lpthread -o Frog_Thread

