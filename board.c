#include <stdio.h>
#include <stdlib.h>
#include "board.h"

// creates a 2d array that represents the board
// @param row_dim is the height of the board
// @param col_dim is the width of the board
// returns the board that was created using the given dimensions
char** build_board(int row_dim, int col_dim){
	char** board = (char**)calloc(row_dim, sizeof(char*));
	for(int i = 0; i < row_dim; ++i){
		board[i] = (char*)calloc(col_dim, sizeof(char));
	}
	for(int j = 0; j < row_dim; ++j){
		for(int k = 0; k < col_dim; ++k){
			board[j][k] = '*';
		}
	}
	return board;
}

// prints out the board and the height and width of the board
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the width of the board
// retuns nothing
void print_board(char** board, int row_dim, int col_dim){
	for(int i = 0; i < row_dim; ++i){
		printf("%d ", row_dim - i - 1);
		for(int j = 0; j < col_dim; ++j){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("  ");
	for(int k = 0; k < col_dim; ++k){
		printf("%d ", k);
	}
	printf("\n");
}

// updates the board after inserting the new character at the specified position
// @param user_input is the column that the user wishes to put their piece in
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param current_char is the character of the current player
// returns nothing
void update_board(int user_input, char** *board, int row_dim, char current_char){
	for(int i = row_dim - 1; i >= 0; --i){
		if((*board)[i][user_input] == '*'){
			(*board)[i][user_input] = current_char;
			break;
		}else{
			continue;
		}
	}
}
