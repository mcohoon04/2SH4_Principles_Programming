#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Questions.h"



char *my_strcat(const char * const str1, const char * const str2){

	/* this is the pointer holding the string to return */
		char *z = NULL;

		/*write your implementation here*/
		//calculate space needed to be allocated in memory
	    int n = strlen(str1)+strlen(str2)+1;
	    //allocate space in memory
	    z = malloc(n*sizeof(char));
	    //create variables for implementation in for loops
	    int i, k;

	    for(i = 0;i<strlen(str1);i++){
	        *(z+i) = str1[i];
	    }

	    for(k = 0;k<n;k++){
	        *(z+strlen(str1)+k) = str2[k];
	    }

	   //add null character to the end of concatinated string
	    *(z+n)= *"\0";

		/* finally, return the string*/
		return z;

}
