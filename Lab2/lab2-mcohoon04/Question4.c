#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Questions.h"

int is_uppercase(char letter){
	//flag variable to be returned
	int flag=0;
	//checks if the char is in the uppercase ASCII range
	if(letter<=90 && letter>=65){
		//set flag to TRUE or 1
		flag = 1;
	}
	return flag;
}

int is_lowercase(char letter){
	//flag variable to be returned
	int flag=0;
	//checks if the char is in the uppercase ASCII range
	if(letter<=122 && letter>=97){
		//set flag to TRUE or 1
		flag = 1;
	}
	return flag;
}
void letter_freq(const char word[], int freq[]){

	//variable index is used to represent the index in the string/char array
	int index;
	//for loop is used to iterate through the given string
	for(index=0;word[index]!='\0';index++){
		//checks if the character is an uppercase letter
		if(is_uppercase(word[index])){
			//if condition is true then add one to the correct index in freq
			//index is determined by subtracting the ASCII value of 'A' from the character
		    freq[word[index]-'A']++;
		}
		//checks if character is lower case letter
		else if(is_lowercase(word[index])){
			//if condition is true then add one to the correct index in freq
			//index is determined by subtracting the ASCII value of 'a' from the character
		    freq[word[index]-'a']++;
		}
		//if the character is not a letter just continue looping through
		else{
			continue;
		}
	}
}

