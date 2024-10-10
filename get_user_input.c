#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "get_user_input.h"
#include "board.h"

// prompts the user for a column to place their piece in, if input is invalid it will prompt again
// @param user_input is the column the user wishes to put their piece in
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// returns the integer that the user entered
int get_valid_int(char** board, int row_dim, int col_dim){
	int num;
  const int num_args_needed = 1;
  int num_args_read;
  do{
    printf("Enter a column between 0 and %d to play in: ", col_dim-1);
    num_args_read = scanf(" %d", &num);
  }while(!is_valid_format(num_args_read, num_args_needed) && !is_valid_input(board, row_dim, col_dim, num));

  return num;
}

// checks whether the input ends with a newline
// @param num_args_needed is the number of arguments that needs to match what the computer read
// @param num_args_read is the number of arguments that was read by the computer
// returns true if the number of arguments needed matches the number of arguments read by the computer, false otherwise
bool is_valid_format(int num_args_needed, int num_args_read){
	bool is_correct_format = num_args_needed == num_args_read;
	char character;
	do{
		scanf("%c", &character);
		if(!isspace(character)){
			is_correct_format = false;
		}
	}while(character != '\n');
	return is_correct_format;
}

// checks if the user input fits within the dimensions of the board
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// @param user_input is the column the user wishes to place their piece in
// returns nothing
bool is_valid_input(char** board, int row_dim, int col_dim, int user_input){
	if(user_input >= 0 && user_input < col_dim){
		for(int i = row_dim - 1; i >= 0; --i){
			if(board[i][user_input] == '*'){
				return true;
				break;
			}
		}
	}
	return false;
}
