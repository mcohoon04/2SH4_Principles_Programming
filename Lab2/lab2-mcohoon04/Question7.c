#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

int is_in_array(int array[], int value, int size){
	int flag=0, i;

	//size = *(&array+1)-array;

	for(i=0;i<size;i++){
		if(array[i]==value){
			flag=1;
			break;
		}
	}

	return flag;
}
void addEff(int val1[], int val2[], int val3[], int pos1[], int pos2[], int pos3[], int k1, int k2){
	int i, j, count=0;

	for(i=0;i<k1;i++){
		for(j=0;j<k2;j++){
			if(pos1[i]==pos2[j]){
				val3[count] = val1[i]+val2[j];
				pos3[count]= pos1[i];
				count++;
				break;
			}
			else if(pos1[i]<pos2[j]){
				val3[count] = val1[i];
				pos3[count]=pos1[i];
				count++;
				break;
			}
			else if(pos1[i]>pos2[j]){
				if(is_in_array(pos3, pos2[j], k1+k2)==0){
					val3[count] = val2[j];
					pos3[count]=pos2[j];
					count++;
				}
			}
			else{
				continue;
			}
		}
		if(is_in_array(pos3, pos1[i], k1+k2)==0){
					val3[count] = val1[i];
					pos3[count]=pos1[i];
					count++;
				}
	}
	
}
