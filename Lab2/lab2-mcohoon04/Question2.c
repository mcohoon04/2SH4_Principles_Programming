#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"
#include "math.h"


int is_diag_dom(int mat[][N2]){

    //this is the flag that is returned to tell whether the mat is diagonally
	int isDiag=1;
	
	//write your code below
	//Return 1 if the matrix is diagonally dominant and 0 otherwise

	//variables to be used in for loop to represent the index in 2D matrix
	int i, j;

	//variables to hold the absolute value of the diagonal and the sum of the other elements in that row
	double sum, diagonal;

	//for loop runs increasing i by one each time while i is less then N2(the size of matrix)
	for(i=0;i<N2;i++){
		//calculates the absolute value of the diagonal entry in the row
		diagonal = fabs(mat[i][i]);
		//resets the value of sum for each iteration
		sum = 0;
		//for loop runs increasing j by one each time while j is less than N2(the size of matrix)
		for(j=0;j<N2;j++){
			//Checks if i does not equal j, i.e. if the entry is not diagonal
			if(i!=j){
				//calculates the absolute value of the sum of the non-diagonal values
				sum += fabs(mat[i][j]);
			}
		}

		//checks if the diagnol is ever less than or equal to the sum
		if(diagonal<=sum){
			//if the condition is true the flag variable isDiag is set to 0 and the loop is broken
			isDiag=0;
			break;
		}
	}

    return isDiag;
}
