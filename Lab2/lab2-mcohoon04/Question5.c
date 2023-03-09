#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void string_copy(const char source[], char destination[], int n){
	//variable to be used in for loop as index
	int i;

	//for loop is used to increase index value so string can be copied
	for(i=0;i<n-1;i++){
		//condition to check if null variable is seen before length of string is done
		if(source[i]=='\0'){
			break;
		}
		destination[i] = source[i];
	}
	//adds the null character to the end
	destination[-1] = '\0';
}
