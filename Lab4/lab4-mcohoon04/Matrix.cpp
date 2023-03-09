
#include "Matrix.h"
#include <iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;

Matrix::Matrix(){
 rowsNum=3;
 colsNum=3;
 matrixData=NULL;
 matrixData = (int**)malloc(rowsNum*sizeof(int*));

    // Allocate rows for fake "2D array":
    for (int i = 0 ; i < rowsNum ; ++i )
    {
       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
    }

    for (int i = 0 ; i < rowsNum ; ++i )
    	for (int j = 0 ; j < colsNum ; ++j )
    		matrixData[i][j]=0;
}

Matrix::Matrix( int row, int col ){

	/*
	* constructs a row-by-col matrix with
	* all elements equal to 0; if row ≤ 0, the number of rows of the matrix is set to
	* 3; likewise, if col ≤ 0 the number of columns of the matrix is set to 3.
	*/
	if(row>0){
			rowsNum=row;
	}
	else{
		rowsNum=3;
	}
	if(col>0){
		colsNum=col;
	}
	else{
		colsNum=3;
	}

	 matrixData=NULL;
	 matrixData = (int**)malloc(rowsNum*sizeof(int*));

	    // Allocate rows for fake "2D array":
	    for (int i = 0 ; i < rowsNum ; ++i )
	    {
	       matrixData[i] = (int*) malloc(colsNum*sizeof(int));
	    }
	    //initialize values of 2D array to 0
	    for (int i = 0 ; i < rowsNum ; ++i )
	    	for (int j = 0 ; j < colsNum ; ++j )
	    		matrixData[i][j]=0;
}


Matrix::Matrix(int row, int col, int** table){

	/*
	* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
	* element in each position as array table.
	*/
	colsNum=col;
	rowsNum=row;
	matrixData=NULL;
	matrixData = (int**)malloc(rowsNum*sizeof(int*));

	 // Allocate rows for fake "2D array":
	 for (int i = 0 ; i < rowsNum ; ++i ){
		 matrixData[i] = (int*) malloc(colsNum*sizeof(int));
		    }
	 //set values of array equal to that of variable table
	 for (int i = 0 ; i < rowsNum ; ++i )
		    for (int j = 0 ; j < colsNum ; ++j )
		    	matrixData[i][j]=table[i][j];
	
}

int Matrix::getElement(int i, int j){
	 //Check to see if index ij is in bounds
	 if((i>=rowsNum || i<0)||(j>=colsNum || j<0)){
		 //throw exception if ij is not in bounds
		 throw std::out_of_range("Invalid indexes.");
			}
	 //return element at index ij if ij is in bounds
	 return matrixData[i][j];
	}



bool Matrix::setElement(int x, int i, int j){
	//checks if index ij is inbounds
	if((i>=rowsNum || i<0)||(j>=colsNum || j<0)){
		//returns false if out of bounds
		return false;
	}
	else{
		//sets element at index ij equal to x if inbounds and then returns true
		matrixData[i][j]=x;
	    return true;
	    }
}


Matrix Matrix::copy(){

	//create object copy of class Matrix using constructor that takes arguments i, j, and table
	Matrix copy =  Matrix(rowsNum,colsNum,matrixData);

    return  copy;


}


void Matrix::addTo( Matrix m ){
	if(m.rowsNum==rowsNum && m.colsNum==colsNum){
		for(int i=0;i<rowsNum;i++){
			for(int j=0;j<colsNum;j++){
				matrixData[i][j]=m.getElement(i,j)+matrixData[i][j];
	            }
	        }
	    }
	else{
		throw std::invalid_argument("Invalid operation");
	}
}


Matrix Matrix::subMatrix(int i, int j){

	/* The exception detail message should read: "Submatrix not defined"*/

	//Check to see if index ij is in bounds
	if((i>=rowsNum || i<0)||(j>=colsNum || j<0)){
		//throw exception if ij is not in bounds
		throw std::out_of_range("Submatrix not defined");
	}
	//create and return the new sub-matrix object
	Matrix subM = Matrix (i+1,j+1,matrixData);
    return  subM;
}


int Matrix::getsizeofrows(){

	
	/* update below return */
	return -1;
}


int Matrix::getsizeofcols(){



	/* update below return */
    return -1;
}


bool Matrix::isUpperTr(){

	//Utilizes a a nested for loop to check if any elements
	//below the main diagonal are not zero.
	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<i;j++){
			if(matrixData[i][j]){
				//return false if one of these elements is non-zero
				return false;
			}
		}
	}
	//otherwise return true
	return true;
}


string Matrix::toString(){
	//Create variable of type string to output
	string output;
	//utilize nested for loops to iterate through matrixData
	for(int i=0;i<rowsNum;i++){
		for(int j=0;j<colsNum;j++){
			//add the current element of matrixData to the
			//end of the string(i.e. append) followed by a space
			output.append(to_string(matrixData[i][j]));
			output.append(" ");
		}
		//add a new line after every row
		output.append("\n");
	}


	return output;
}
