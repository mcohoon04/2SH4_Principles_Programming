#include <stdio.h>
#include <stdlib.h>

#include<math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    /*vector3 should store the sum of vector1 and vector2. 
	You may assume that all three arrays have the size equal to n
	*/
	//write your code below
	
	//Initializing variables
	int i;
	//Using a for loop to execute vector summation well the count variable i is less than the sixe of tbhe arrays
	for(i=0;i<size;i++){
		vector3[i]=vector1[i]+vector2[i];
	}
	
}

double scalar_prod(double vector1[],double vector2[],int size)
{
	// this is the variable holding the scalar product of the two vectors
    double prod=0;

	//write your code below to calculate the prod value
    //initializing variable tp be used in for loop
	int i;
	
	//for loop being used to iterate through the arrays and calculate scalar product
	for(i=0;i<size;i++){
		prod+=vector1[i]*vector2[i];
	}
	
	// return the result
    return prod;
}

double norm2(double vector1[], int size)
{
	//this is the variable holding the L2 norm of the passed vector
    double L2=0;
	
	//write your code here
	// you should call function scalar_prod().
    //Creates variable scalar to hold the scalar product of the vector with itself
	double scalar = scalar_prod(vector1,vector1,size);
	//Sets L2 equal to square root of the just calculated scalar product
	L2 = sqrt(scalar);

	//finally, return the L2 norm 
    return L2;
}
