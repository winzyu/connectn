#ifndef GET_USER_INPUT
	#define GET_USER_INPUT
	#include <stdio.h>
	int get_valid_int(char** board, int row_dim, int col_dim);
	bool is_valid_format(int num_args_needed, int num_args_read);
	bool is_valid_input(char** board, int user_input, int num_args_read, int row_dim);
#endif
