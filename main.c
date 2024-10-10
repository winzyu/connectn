/*
Plays the game Connect N, prompts user for the size of the board and the number of pieces in a row
needed to win.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "board.h"
#include "get_user_input.h"
#include "game_status.h"

int main(int argc, char* argv[]){
	if(argc < 4){
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	if(argc > 4){
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	if(atoi(argv[1]) == 0 || atoi(argv[2]) == 0 || atoi(argv[3]) == 0){
		printf("Invalid Input\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
	int board_row_dim, board_col_dim, num_pieces_needed_to_win, user_input;
	int current_turn = 1;
	char current_char = 'X';

	board_row_dim = atoi(argv[1]);
	board_col_dim = atoi(argv[2]);
	num_pieces_needed_to_win = atoi(argv[3]);

	char** board = build_board(board_row_dim, board_col_dim);
	print_board(board, board_row_dim, board_col_dim);

	while(!is_game_over(
		is_num_pieces_needed_to_win_in_row(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
		is_num_pieces_needed_to_win_in_col(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
		is_num_pieces_needed_to_win_in_diag_right(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
		is_num_pieces_needed_to_win_in_diag_left(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
		is_tie_game(board, board_row_dim, board_col_dim))){

		user_input = get_valid_int(board, board_row_dim, board_col_dim);
		if(is_valid_input(board, board_row_dim, board_col_dim, user_input)){
			update_board(user_input, &board, board_row_dim, current_char);
			print_board(board, board_row_dim, board_col_dim);
			change_turns(&current_turn, &current_char);
		}
	}
	announce_result(is_num_pieces_needed_to_win_in_row(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
									is_num_pieces_needed_to_win_in_col(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
									is_num_pieces_needed_to_win_in_diag_right(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
									is_num_pieces_needed_to_win_in_diag_left(board, board_row_dim, board_col_dim, current_char, num_pieces_needed_to_win),
									is_tie_game(board, board_row_dim, board_col_dim), current_turn);
	return 0;
}
