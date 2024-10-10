# Connect N
## Usage 
```bash
make
./connectn.out <num_rows> <num_columns> <number_of_pieces_in_a_row_needed_to_win>
```
## Sample Game
```bash
./connectn.out 3 3 2
2 * * *
1 * * *
0 * * *
  0 1 2
Enter a column between 0 and 2 to play in: 0
2 * * *
1 * * *
0 X * *
  0 1 2
Enter a column between 0 and 2 to play in: 1
2 * * *
1 * * *
0 X O *
  0 1 2
Enter a column between 0 and 2 to play in: 2
2 * * *
1 * * *
0 X O X
  0 1 2
Enter a column between 0 and 2 to play in: 2
2 * * *
1 * * O
0 X O X
  0 1 2
Player 2 Won!
```
