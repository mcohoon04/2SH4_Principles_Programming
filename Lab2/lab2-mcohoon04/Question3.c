#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr []){

	//variables i and j are to be used as the index in the 2D matrix
	//variable count is used to count the diagonals being scanned
	//index is used as the index of the array the diagonals are being scanned to
	//diagonals is used to hold the total number of diagonals being scanned
	int i, j, count, index=0, diagnols=2*N3-1;

	//for loop runs while count is less than the total number of diagonals
	for(count=0;count<diagnols;count++){
		//if count is less then the size of a row in the 2D array then i is equal to count and j is equal to 0
	    if(count<N3){
	        i = count;
	        j = 0;
	    }
	    //if count is equal to or greater then the size of a row in the 2D array then i is equal to the size minus one and j equals the remainder of (count+1)/size
	    else{
	        i = N3-1;
	        j = (count+1)%N3;
	    }
	    //a do while loop is used to scan a diagonal of the 2D array/matrix and place the values in a new 1D array
	    do{
	        arr[index] = mat[i][j];
	        //index values are increamented accordingly to the applied logic
	        index++;
	        i--;
	        j++;
	    }while(i>=0 && j<N3);
	}
}
