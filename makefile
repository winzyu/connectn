connectn.out: main.o board.o get_user_input.o game_status.o
	gcc -g -Wall -Werror -o connectn.out main.o board.o get_user_input.o game_status.o
main.o: main.c board.h get_user_input.h game_status.h
	gcc -g -Wall -Werror -c main.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
get_user_input.o: get_user_input.c board.h get_user_input.h
	gcc -g -Wall -Werror -c get_user_input.c
game_status.o: game_status.c game_status.h board.h
	gcc -g -Wall -Werror -c game_status.c
clean:
	rm -f *.o *.out
