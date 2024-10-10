#include <stdio.h>
#include <stdlib.h>
#include "board.h"

// checks if the game is over either by a connect N or a tie game
// @param is_num_pieces_needed_to_win_in_row checks if there is a connect N in a row
// @param is_num_pieces_needed_to_win_in_col checks if there is a connect N in a column
// @param is_num_pieces_needed_to_win_in_diag_right checks if there is a connect N in a right diagonal
// @param is_num_pieces_needed_to_win_in_diag_left checks if there is a connect N in a left diagonal
// returns true if there is a connect N in a row, column, diagonal left, diagonal right or tie game, otherwise false
bool is_game_over(bool is_num_pieces_needed_to_win_in_row,
									bool is_num_pieces_needed_to_win_in_col,
									bool is_num_pieces_needed_to_win_in_diag_right,
									bool is_num_pieces_needed_to_win_in_diag_left,
									bool is_tie_game){
	return is_num_pieces_needed_to_win_in_row ||
				 is_num_pieces_needed_to_win_in_col ||
				 is_num_pieces_needed_to_win_in_diag_right ||
				 is_num_pieces_needed_to_win_in_diag_left ||
				 is_tie_game;
}

// swaps the current character to the other player's character
// @param current_char is the character of the current player
// returns the character of the other player (not current)
char get_temp_char(char current_char){
	char temp_char;
	if(current_char == 'X'){
		temp_char = 'O';
	}else{
		temp_char = 'X';
	}
	return temp_char;
}

// checks whether the board is full of characters of the players'
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// returns true if the board is full of the players' characters, otherwise false
bool is_tie_game(char** board, int row_dim, int col_dim){
	int check = 0;
	for(int i = 0; i < row_dim; ++i){
		for(int j = 0; j < col_dim; ++j){
			if(board[i][j] != '*'){
				++check;
			}
		}
	}
	if(check == row_dim * col_dim){
		return true;
	}
	return false;
}

// checks if there is a connect N in a left diagonal
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// @param current_char is the character of the current player
// @param num_pieces_needed_to_win is the number of pieces needed to create a connect N
// returns true if there is a connect N in a left diagonal, otherwise false
bool is_num_pieces_needed_to_win_in_diag_left(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win){
	int check_diag = 0;
	char temp_char = get_temp_char(current_char);
	for(int row = 0; row < row_dim; ++row){
		for(int col = 0; col < col_dim; ++col){
			for(int left = 0; left <= col; ++left){
				if((row+left) < row_dim && left <= col && board[row+left][col-left] == temp_char){
					++check_diag;
					if(check_diag == num_pieces_needed_to_win){
						return true;
					}
				}else{
					check_diag = 0;
				}
			}
			check_diag = 0;
		}
	}
	return false;
}

// checks if there is a connect N in a right diagonal
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// @param current_char is the character of the current player
// @param num_pieces_needed_to_win is the number of pieces needed to create a connect N
// returns true if there is a connect N in a right diagonal, otherwise false
bool is_num_pieces_needed_to_win_in_diag_right(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win){
	int check_diag = 0;
	char temp_char = get_temp_char(current_char);
	for(int row = 0; row < row_dim; ++row){
		for(int col = 0; col < col_dim; ++col){
			for(int right = 0; (right+col) < col_dim; ++right){
				if((row+right) < row_dim && (col+right) < col_dim && board[row+right][col+right] == temp_char){
					++check_diag;
					if(check_diag == num_pieces_needed_to_win){
						return true;
					}
				}else{
					check_diag = 0;
				}
			}
			check_diag = 0;
		}
	}
	return false;
}

// checks if there is a connect N in a column
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// @param current_char is the character of the current player
// @param num_pieces_needed_to_win is the number of pieces needed to create a connect N
// returns true if there is a connect N in a column, otherwise false
bool is_num_pieces_needed_to_win_in_col(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win){
	int check_cols = 0;
	char temp_char = get_temp_char(current_char);
	for(int col = 0; col < col_dim; ++col){
		for(int row = 0; row < row_dim; ++row){
			if(board[row][col] == temp_char){
				++check_cols;
				if(check_cols == num_pieces_needed_to_win){
					return true;
				}
			}else{
				check_cols = 0;
			}
		}
		check_cols = 0;
	}
	return false;
}

// checks if there is a connect N in a row
// @param board is the 2d array of characters that represents the board
// @param row_dim is the height of the board
// @param col_dim is the length of the board
// @param current_char is the character of the current player
// @param num_pieces_needed_to_win is the number of pieces needed to create a connect N
// returns true if there is a connect N in a row, otherwise false
bool is_num_pieces_needed_to_win_in_row(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win){
	int check_rows = 0;
	char temp_char = get_temp_char(current_char);
	for(int row = 0; row < row_dim; ++row){
		for(int col = 0; col < col_dim; ++col){
			if(board[row][col] == temp_char){
				++check_rows;
				if(check_rows == num_pieces_needed_to_win){
					return true;
				}
			}else{
				check_rows = 0;
			}
		}
		check_rows = 0;
	}
	return false;
}

// passes the turn to the other player and changes the current character
// @param current_turn is whose turn it is of the 2 players
// @param current_char is the character of the current player
// returns nothing
void change_turns(int *current_turn, char *current_char){
	if(*current_turn == 1){
		*current_turn = 2;
		*current_char = 'O';
	}else{
		*current_turn = 1;
		*current_char = 'X';
	}
}

// prints out if there was a win and if so who or if the game was a tie
// @param is_num_pieces_needed_to_win_in_row checks if there is a connect N in a row
// @param is_num_pieces_needed_to_win_in_col checks if there is a connect N in a column
// @param is_num_pieces_needed_to_win_in_diag_right checks if there is a connect N in a right diagonal
// @param is_num_pieces_needed_to_win_in_diag_left checks if there is a connect N in a left diagonal
// @param current_turn is whose turn it is of the 2 players
// returns nothing
void announce_result(bool is_num_pieces_needed_to_win_in_row,
										 bool is_num_pieces_needed_to_win_in_col,
										 bool is_num_pieces_needed_to_win_in_diag_right,
										 bool is_num_pieces_needed_to_win_in_diag_left,
										 bool is_tie_game,
										 int current_turn){
	int temp_val;
	if(current_turn == 1){
		temp_val = 2;
	}else{
		temp_val = 1;
	}
	if(is_num_pieces_needed_to_win_in_row ||
		 is_num_pieces_needed_to_win_in_col ||
	 	 is_num_pieces_needed_to_win_in_diag_right ||
	 	 is_num_pieces_needed_to_win_in_diag_left){
		printf("Player %d Won!\n", temp_val);
	}else{
		if(is_tie_game){
			printf("Tie game!\n");
		}
	}
}
