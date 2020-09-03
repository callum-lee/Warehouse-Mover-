/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* Callum Lee, clee335, 421729598 */

#include "project.h"

/* Initialise and Define Helper Functions */
void RotateBoard(int Board[10][10], int rotate);
void FindWorker(int Board[10][10], int* workerRow, int* workerCol);
void CheckSpace(int Board[10][10]);


/*
The TimeWorked function calculates the time length of a worker's shift in seconds. It
takes 4 inputs (first 2 inputs represent the first time and next 2 represent the second time).
Firstly, time A and time B are calculated by converting minutes into seconds and adding the
seconds.  As we do not know which pair of inputs is time in or time out, time A and B are calculated
so the larger value is subtracted by the smaller value (time out - time in).
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int timeA, timeB;
	timeA = minuteA * 60 + secondA;
	timeB = minuteB * 60 + secondB;

	if (timeA > timeB) {
		return timeA - timeB;
	}
	else {
		return timeB - timeA;
	}

}

/*
The WarehouseAddress function finds the next largest prime number given an upper boundary (excludes
upper boundary itself). This function takes the maximum input (upper boundary) and loops through every
value from the largest value (maximum-1) to to the smallest possible prime number which is 2. The outer
loop is initialised by variable i. This is then cycled through a nested loop (initialised by j) that loops
through every value from 2 to the largest possible factor which is the value (i/2). An if statement
is created to find if there are no remainders when the value (i) is divided by the factors (j). If there
is no remainder, then the number of factors increase. If there is a remainder after the inner loop is
executed, then factors=0 so the loop breaks and the value (i) which is the largest prime number under the
upper bound is returned. Else, the number of factors is set back to 0 and the next largest value is tested
through the inner loop and the process continues until the largest prime is found.
*/
int WarehouseAddress(int maximum)

{
	int i, j;
	int factors = 0;

	for (i = maximum - 1; i >= 2; i--) {
		for (j = 2; j < i; j++) {
			if (i % j == 0) {
				factors++;
			}

		}
		if (factors == 0) {
			return i;
		}
		else {
			factors = 0;
		}

	}

	return 0;

}

/*
The Advertise function shifts all the characters in a string to the left with the first value being
wrapped around into the last character. It takes 1 input which is the pointer to the string away
and returns the shifted array. firstly, the length of the string is calculated with strlen and the
first character is stored in a temporary value. The for loop then goes through each character of the
string from 0 to the last character and replaces the current character (i) with the one on the right
of it (i+1) which effectively shifts the character to the left. After the loop finishes, the last
character stores the temporary value which is the non modified words[0] character. It finally returns
the modified string with each character being shifted to the left.
*/
void Advertise(char* words)
{
	int i = 0;
	char temp = words[0];
	int length = strlen(words);

	for (i = 0; i < length; i++) {
		words[i] = words[i + 1];
	}

	words[length - 1] = temp;

}

/*
The WinningBid function has the values array input and the length of the array. It first rearranges
all the values inside in the array in an ascending order by looping through each value and swapping
to the end if it's a larger value. Then from this array, it is looped through to check each value and 
whether it has a repeated value. if there are no repeats (repeat=1 the value itself) then then loop 
breaks and returns the lowest unique bid. 
*/
int WinningBid(int* values, int length)
{

	int i, j, temp;
	int repeat = 0;

	for (i = 0; i < length; i++) {
		for (j = 0; j < length - 1; j++) {
			if (values[j] > values[j + 1]) {
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}


	for (i = 0; i < length; i++) {
		for (j = 0; j < length; j++) {

			if (values[i] == values[j]) {
				repeat++;
			}

			else {
			}
		}

		if (repeat == 1) {
			return values[i];
		}
		else {
			repeat = 0;
		}

	}

	return -1;
}

/*
The BoxDesign function had the width and input for a box. The asterix is filled around the width and height
to create a border with empty space in the middle. After then, the 4 conditions are tested when width and 
height are either odd and even so that X will be marked in the centre of the boxes. 1 for odd width and height,
4 for even width and height, 2 vertical ones for odd width and even height, 2 horiztonal ones for even width 
and odd height. 
*/
void BoxDesign(char* design, int width, int height)
{
	int i;

	for (i = 0; i < height * (width + 1); i++) {
		design[i] = '*';
	}

	for (i = width; i < height * (width + 1); i += (width + 1)) {
		design[i] = '\n';
	}

	for (i = width + 1; i < height * (width + 1) - width - 2; i++) {
		if (design[i] != '\n') {
			design[i] = ' ';
		}
		else {
		}
	}

	for (i = width + 1; i < height * (width + 1) - width - 2; i += (width + 1)) {
		design[i] = '*';
	}

	for (i = 2 * width; i < height * (width + 1) - width - 2; i += (width + 1)) {
		design[i] = '*';
	}


	if ((width <= 2) || (height <= 2)){
	}
	else {
		if (((height % 2) == 1) && ((width % 2) == 1)) {
			i = (height / 2) * (width + 1) + width / 2;
			design[i] = 'X';
		}
		else if (((height % 2) == 1) && ((width % 2) == 0)) {
			for (i = ((height / 2) * (width + 1) + width / 2 - 1); i <= ((height / 2) * (width + 1) + width / 2); i++)
				design[i] = 'X';
		}
		else if (((height % 2) == 0) && ((width % 2) == 1)) {
			for (i = ((height / 2 - 1) * (width + 1) + width / 2); i <= ((height / 2) * (width + 1) + width / 2); i += (width + 1)) {
				design[i] = 'X';
			}
		}
		else {

			for (i = ((height / 2 - 1) * (width + 1) + width / 2 - 1); i <= ((height / 2 - 1) * (width + 1) + width / 2); i++) {
				design[i] = 'X';
			}
			for (i = ((height / 2) * (width + 1) + width / 2 - 1); i <= ((height / 2) * (width + 1) + width / 2); i++) {
				design[i] = 'X';
			}

		}
	}


}

/*
The Worker Route takes the input of a 2D warehouse array. It first finds the location of the worker 
(row and col) as well as the location of the box (row and col) by looping through each row and each
column. Then it creates an intial condition in which nothing happens if they are in the same row or 
col and is one row and col apart. If this is not met, then it moves horizontally to the right if box
col is greater than worker col and left if it is less. Then it moves vertically up  if the box row is 
less than worker col and down if it is greater. All the values in the path is replaced by a 3.
*/
void WorkerRoute(int warehouse[10][10])
{
	int i, j;
	int workRow=0, workCol=0;
	int boxRow=0, boxCol=0;
	int tWorkRow = 0, tWorkCol = 0;
	int tBoxRow = 0, tBoxCol = 0;
	

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 1) {
				workRow = i;
				workCol = j;
			}
			else if (warehouse[i][j] == 2) {
				boxRow = i;
				boxCol = j;
			}
			else {
			}

		}

	}

	tWorkRow = workRow;
	tWorkCol = workCol;
	tBoxRow = boxRow;
	tBoxCol = boxCol;

	if (((boxRow==workRow)&&((boxCol==workCol+1)||(boxCol==workCol-1)))||((boxCol == workCol) && ((boxRow == workRow + 1) || (boxRow == workRow - 1)))){
	}

	else if (boxCol > workCol) {
		i = workRow;
		for (j = workCol + 1; j <= boxCol; j++) {
			warehouse[i][j] = 3;
		}
	}

	else if (boxCol < workCol) {
		i = workRow;
		for (j = workCol - 1; j >= boxCol; j--) {
			warehouse[i][j] = 3;
		}
	}

	workCol = boxCol;
	
	if (((boxRow == workRow) && ((boxCol == workCol + 1) || (boxCol == workCol - 1))) || ((boxCol == workCol) && ((boxRow == workRow + 1) || (boxRow == workRow - 1)))) {
	}

	else if (boxRow > workRow) {
		j = workCol;
		for (i = workRow+1; i <= boxRow-1; i++) {
			warehouse[i][j] = 3;
		}
	}

	else if (boxRow < workRow) {
		j = workCol;
		for (i = workRow-1; i >= boxRow+1; i--) {
			warehouse[i][j] = 3;
		}
	}

	else {
	}

	warehouse[tWorkRow][tWorkCol] = 1;
	warehouse[tBoxRow][tBoxCol] = 2;

	
}

/*
The Make Move Function moves the worker depending on the key that is entered. It then proceed to 
rotate the board (so only 1 direction needs to be checked which is up). Then it checks the space
above it and then rotates it back. The game is finished if there are no more targets, boxes or 
workers as all of the workers and boxes will be on a target. 
*/
int MakeMove(int warehouse[10][10], char move)
{
	int workerCount=0, boxCount=0, targetCount=0;
	int i, j;

	if (move == 'w') {
		CheckSpace(warehouse);
	}
	else if (move == 'a') {
		RotateBoard(warehouse, 1);
		CheckSpace(warehouse);
		RotateBoard(warehouse, 3);
	}
	else if (move == 's') {
		RotateBoard(warehouse, 2);
		CheckSpace(warehouse);
		RotateBoard(warehouse, 2);
	}
	else if (move == 'd') {
		RotateBoard(warehouse, 3);
		CheckSpace(warehouse);
		RotateBoard(warehouse, 1);
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 2) {
				targetCount++;
			}
			else if (warehouse[i][j] == 3) {
				boxCount++;
			}
			else if (warehouse[i][j] == 5) {
				workerCount++;
			}
			else {
			}
		}
	}

	if ((workerCount == 0) && (boxCount == 0) && (targetCount == 0)) {
		return 1;
	}
	else {
		workerCount = 0;
		boxCount = 0;
		targetCount = 0;
	}
	return 0;
}


/*
The RotateBoard Function rotates the values in the board depending on the move that is made. 
It goes through each row and value and produces the pattern that would result in moving the board
90 degrees clockwise and replaces it with a new board. The input array is then replaced with the output
and called back into the main function with a rotated and re-rotated board. 
*/
void RotateBoard(int Board[10][10], int rotate) {
	
	int i, j, k;
	int NewBoard[10][10] = { 0 };

	for (k = 1; k <= rotate; k++) {
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				NewBoard[j][9 - i] = Board[i][j];
			}
		}
		
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				Board[i][j] = NewBoard[i][j];
			}
		}
	}

}


/*
The FindWorker function takes an array and the pointers for the worker's row and column. 
This is done by scanning through each row and column to find whether the worker is on a space
or on a target then returns the final row and column positions. 
*/
void FindWorker(int Board[10][10],int *workRow,int *workCol) {

	int i, j;

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if ((Board[i][j] == 5)||(Board[i][j]==6)) {
				*workRow = i;
				*workCol = j;
			}
			else {
			}
		}
	}
}


/*
The CheckSpace Function checks the space and the spaces above it after the board is rotated. It is loaded
with several conditions that checks whether the space in front is a space, wall, target, box, box on target,etc.
It then uses these conditions to replace the current space, the space in front (moving direction) and 2 spaces 
in front (in case of obstacles) to make the move. 
*/
void CheckSpace(int Board[10][10]) {
	
	int oldWorkRow, oldWorkCol;
	int checkRow, checkCol;

	FindWorker(Board, &oldWorkRow, &oldWorkCol);

	checkCol = oldWorkCol;
	checkRow = oldWorkRow - 1;
	
	if (Board[oldWorkRow][oldWorkCol] == 5) {
		if (Board[checkRow][checkCol] == 0) {
			Board[checkRow][checkCol] = 5;
			Board[oldWorkRow][oldWorkCol] = 0;
		}

		else if (Board[checkRow][checkCol] == 1) {
		}

		else if (Board[checkRow][checkCol] == 2) {
			Board[checkRow][checkCol] = 6;
			Board[oldWorkRow][oldWorkCol] = 0;
		}

		else if (Board[checkRow][checkCol] == 3) {
			if (Board[checkRow - 1][checkCol] == 0) {
				Board[checkRow - 1][checkCol] = 3;
				Board[checkRow][checkCol] = 5;
				Board[oldWorkRow][checkCol] = 0;
			}
			else if (Board[checkRow - 1][checkCol] == 2) {
				Board[checkRow - 1][checkCol] = 4;
				Board[checkRow][checkCol] = 5;
				Board[oldWorkRow][checkCol] = 0;
			}
			else {
			}
		}

		else if (Board[checkRow][checkCol] == 4) {
			if (Board[checkRow - 1][checkCol] == 0) {
				Board[checkRow - 1][checkCol] = 3;
				Board[checkRow][checkCol] = 6;
				Board[oldWorkRow][checkCol] = 0;
			}
			else if (Board[checkRow - 1][checkCol] == 2) {
				Board[checkRow - 1][checkCol] = 4;
				Board[checkRow][checkCol] = 6;
				Board[oldWorkRow][checkCol] = 0;
			}
			else {
			}
		}
	}

	else if (Board[oldWorkRow][oldWorkCol] == 6) {
		if (Board[checkRow][checkCol] == 0) {
			Board[checkRow][checkCol] = 5;
			Board[oldWorkRow][oldWorkCol] = 2;
		}

		else if (Board[checkRow][checkCol] == 1) {
		}

		else if (Board[checkRow][checkCol] == 2) {
			Board[checkRow][checkCol] = 6;
			Board[oldWorkRow][oldWorkCol] = 2;
		}

		else if (Board[checkRow][checkCol] == 3) {
			if (Board[checkRow - 1][checkCol] == 0) {
				Board[checkRow - 1][checkCol] = 3;
				Board[checkRow][checkCol] = 5;
				Board[oldWorkRow][checkCol] = 2;
			}
			else if (Board[checkRow - 1][checkCol] == 2) {
				Board[checkRow - 1][checkCol] = 4;
				Board[checkRow][checkCol] = 5;
				Board[oldWorkRow][checkCol] = 2;
			}
			else {
			}
		}
		else if (Board[checkRow][checkCol] == 4) {
			if (Board[checkRow - 1][checkCol] == 0) {
				Board[checkRow - 1][checkCol] = 3;
				Board[checkRow][checkCol] = 6;
				Board[oldWorkRow][checkCol] = 2;
			}
			else if (Board[checkRow - 1][checkCol] == 2) {
				Board[checkRow - 1][checkCol] = 4;
				Board[checkRow][checkCol] = 6;
				Board[oldWorkRow][checkCol] = 2;
			}
			else {
			}
		}
		else {
		}
	}
	else {
	}
	
}
