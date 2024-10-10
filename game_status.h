#ifndef GAME_STATUS
	#define GAME_STATUS
	#include <stdio.h>
	char get_temp_char(char current_char);
	bool is_tie_game(char** board, int row_dim, int col_dim);
	bool is_num_pieces_needed_to_win_in_diag_left(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win);
	bool is_num_pieces_needed_to_win_in_diag_right(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win);
	bool is_num_pieces_needed_to_win_in_col(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win);
	bool is_num_pieces_needed_to_win_in_row(char** board, int row_dim, int col_dim, char current_char, int num_pieces_needed_to_win);
	bool is_game_over(bool is_num_pieces_needed_to_win_in_row,
										bool is_num_pieces_needed_to_win_in_col,
										bool is_num_pieces_needed_to_win_in_diag_right,
										bool is_num_pieces_needed_to_win_in_diag_left,
										bool is_tie_game);
	void change_turns(int *current_turn, char *current_char);
	void announce_result(bool is_num_pieces_needed_to_win_in_row,
											 bool is_num_pieces_needed_to_win_in_col,
											 bool is_num_pieces_needed_to_win_in_diag_right,
											 bool is_num_pieces_needed_to_win_in_diag_left,
											 bool is_tie_game,
											 int current_turn);

#endif
