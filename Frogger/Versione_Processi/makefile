all: compile linking
	@rm *.o
	@chmod +x Frog_Process
	@echo "Ora puoi eseguire"

compile:
	@echo "Sto compilando" 
	@gcc -c source/menu.c -o menuP.o
	@gcc -c source/colorazione.c -o colorazioneP.o
	@gcc -c source/rana.c -o ranaP.o
	@gcc -c source/tronco.c -o troncoP.o
	@gcc -c source/macchina.c -o macchinaP.o
	@gcc -c source/tempo.c -o tempoP.o
	@gcc -c source/inzio_gioco.c -o inzio_giocoP.o
	@gcc -c source/controllo.c -o controlloP.o
	@gcc -c source/scelta_difficolta.c -o scelta_difficoltaP.o
	@gcc -w -c source/suono.c -o suonoP.o
	@gcc -w -c source/global.c -o globalP.o

linking:
	@echo "Sto Linkando"
	@gcc *.o -lncurses -lpthread -o Frog_Process