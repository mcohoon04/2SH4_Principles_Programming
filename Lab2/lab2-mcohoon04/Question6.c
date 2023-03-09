#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void efficient(const int source[], int val[], int pos[], int size){
	//variable i to be used to iterate through source & count is used as index in val/pos
	int i, count=0;

	//for loop used to iterate through array source
	for(i=0;i<size;i++){
		//condition to check if the element in source is not 0
		if(source[i]!=0){
			//set pos equal to index i and val equal to element i in source
			pos[count] = i;
			val[count] = source[i];
			//increment count
			count++;
		}
	}

}

void reconstruct(int source[], int m, const int val[], const int pos[], int n){
	//variable i to be used in for loop as index for arrays
    int i;
    
    //for loop used to set all elements in source to zero
    for(i=0;i<m;i++){
    	source[i]=0;
    }

    //for loop used to set element in index pos[i] of source equal to val[i]
    for(i=0;i<n;i++){
    	source[pos[i]]=val[i];
    }
	

}
