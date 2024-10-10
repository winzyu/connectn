#ifndef BOARD
	#define BOARD
	#include <stdio.h>
	#include <stdbool.h>
	char** build_board(int row_dim, int col_dim);
	void print_board(char** board, int row_dim, int col_dim);
	void update_board(int user_input, char** *board, int row_dim, char current_char);
#endif
