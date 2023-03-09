
#include "Questions.h"



int Q1_for(){
	int sum=0, i;//Initializing the variables to be used inside this function
	// calculate your sum below..this has to use for loop
	for(i=30;i<1001;i++){//this for loop runs while the variable i is less than 1001, starting at 30 and incrementing by 1 each time
		if(i%4==0){//checks is i is divisible by 4 and adds i to the sum
			sum+=i;
		}
	}
	// here, we return the calculated sum:
	return sum;
}
int Q1_while(){
	int sum=0, i = 30;
	// calculate your sum below..this has to use while loop
	while(i<1001){//This while loop runs while i is less than 1001 and increases i by 1 each time
		if(i%4==0){//checks is i is divisible by 4 and adds i to the sum
			sum+=i;
		}
		i++;
	}
	// here, we return the calculated sum:
	return sum;
}
int Q1_do(){
	int sum=0;
	int i =30;
	// calculate your sum below..this has to use do-while loop
	do{//this do while loop runs while i is less than 1001 and i increases by 1 each time
		if(i%4==0){//checks is i is divisible by 4 and adds i to the sum
			sum+=i;
		}
		i++;
	}
	while(i<1001);

	// here, we return the calcualted sum:
	return sum;
}
//===============================================================================================
int Q2(int Q2_input){
	
	// this is the flag that is holding whether the input number is 5-digit or not
	int IsFiveDigit=0;
	
	// Do your coding below to check

	//count variable to used in while loop to count the n umber of digits
	int count=0;

	//while loop will be used while Q2_input is not equal to 0, and with each iteration it will
	//be divided by 10 using integer division to remove the last digit, while also increamenting the count variable
	while(Q2_input!=0){
		Q2_input = Q2_input/10;
		count++;
	}

	if(count==5){
		IsFiveDigit=1;
	}

//	if(Q2_input>9999 && Q2_input<100000){//checks if the input is positive and has 5 digits
//		IsFiveDigit=1;
//	}
//	else{
//		if(Q2_input<-9999 && Q2_input>-100000){//checks if the input is negative and has 5 digits
//			IsFiveDigit=1;
//		}
//	}
	//finally, we must return IsFiveDigit, which must be 1 is the number is five digits and 0 otherwise
	return IsFiveDigit;
}
//===============================================================================================
int Q3(float Q3_input){
	
	/* Question 3: 
	Write a program that takes a student's Q3_input as an input, which is a floating point value,
	and returns:
	4 if the Q3_input is in the range 90-100,
	3 if it is in the range 80-89, 
	2 if it is in the range 70-79,
	1 if it is in the range 60-69 and
	0 if the Q3_input is between 0 and 59.
	If the Q3_input is not in the range 0-100, the program shouldreturn -1
*/	
	// this is the varaible that holds the out value to return
	float GPA=0;
	
	
	// Do your coding below to calculate the GPA variable value
	if(Q3_input>=90 && Q3_input<=100){//Checks is the average is between 90 and 100
		GPA = 4;
	}
	else if(Q3_input>=80 && Q3_input<90){//Checks is the average is between 80 and 89
		GPA = 3;
	}
	else if(Q3_input>=70 && Q3_input<80){//Checks is the average is between 70 and 79
		GPA = 2;
	}
	else if(Q3_input>=60 && Q3_input<70){//Checks is the average is between 60 and 69
		GPA = 1;
	}
	else if(Q3_input>=0 && Q3_input<60){//Checks is the average is between 0 and 59
		GPA = 0;
	}
	else{//sets GPA to -1 if the input number is not between 0-100
		GPA = -1;
	}
	// finally, we return the GPA
	return GPA;	
}
//===============================================================================================
double Q4(int Q4_input){
	
	// this is the varaible that holds the pi value to return
	double pi=0;
	
	//counter variable to be incremented in the below loop and variable to be used in series calculations
	double i = 1;
	double count = 0;
	
	// Do your coding below to calculate the pi value
	//the while loop will iterate while the count variable is less then the given number of terms
	//the count starts at 0 this is why it is less than instead of less than and equal
	while(count<Q4_input){
		//Finding pi using infinite series
		pi = pi+(4/i)*pow(-1, count);

		//increament variables
		i+=2;
		count++;
	}

	// finally, we return the pi value
	return pi;	
}
//===============================================================================================
int Q5(){
	
	// this is the varaible that holds and the total number of triples to return at the end of the function
	int totNumTribles=0;

	//Variables to represent sides of triangle
	double side1, side2, hypo;
	
	/* Do your coding below
		Use a triple-nested for loop that simply tries all possibilities
		and update the total number of triples if needed
	*/

	//Triple nested for loop to increment side1, side2, and hypo
	for(hypo=1;hypo<=400;hypo++){
		for(side2=1;side2<=400;side2++){
			for(side1=1;side1<=400;side1++){
				//checks to make sure the hypo is the largest side and that side2 is the second largest or equal to side1
				if(side1<=side2){
					//checks to see if the numbers form a pythagorean triple
					if((hypo*hypo)==(side1*side1+side2*side2)){
						totNumTribles++;
					}
				}
			}
		}
	}

	//finally you should return the total number of triples.
	return totNumTribles;
}
//===============================================================================================
int Q6(int Q6_input, int perfect[]){
	
	
	
		//counts is teh variable that should hold the total number of found perfect numbers
		//you should update it within your code and return it at the end
	    int counts=0;

	    //variable used in for loop to test if a number is perfect
	    //variable used in for loop to find factors
	    //variable used to determine if number is perfect
	    int perf, factor, sum=0, index=0;


		/*
		*
		*perfect is an array that you need to add into it any perfect number you find
		*which means at the end of this function, the perfect[] array should hold all the found perfect numbers in the range
		*you do not need to return perfect because as stated in lectures arrays are already passed by reference. so, modifying them will 
		*autmoatically reflect in the main calling function.
		*/
	    //This double nested for loop checks ever number between 2 and the input, finding its factors in the second loop and then
	    //determining if their sum is equal to the number itself
	    for(perf=2;perf<=Q6_input;perf++){
	    	//resets the variable sum for every new number being tested
	    	sum = 0;
	    	for(factor=1;factor<perf;factor++){
	    		//checks to see if "factor" is a factor of the number "perf"
	    		if(perf%factor==0){
	    			sum+=factor;
	    		}
	    	}
	    	//if the sum of factors is equal to the number it adds it to the array perfect, increments "counts" by 1, and increments "index" by 1
	    	if(perf==sum){
	    		perfect[index]=perf;
	    		counts++;
	    		index++;
	    	}
	    }
		
	   //returns variable counts
	   return counts;
}
//===============================================================================================
int Q7a(int Q7_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//in this part you can assume the knowledge of the number of digits: seven-digit positive integer
	
	//variable to be used in for loop
	int i, temp=0, count, scale;
	
	//For loop is used to determine the digits in the input number
	for(i=7;i>0;i--){
		//determines the last digit in the current version of the input
		temp = Q7_input%10;
		//Reset Variables to be used in while loop
		count = 0;
		scale = 1;
		//while loop is used to recreate 10^(i-1) in order to scale the digit so it is placed in the proper place
		while(count<i-1){
			scale=scale*10;
			count++;
		}
		//adds the last digit to the begining of reversedInt by multiplying by 10 to the power of the place in the new number minus 1
		reversedInt = reversedInt+temp*scale;
		//Use integer division to get rid of the last number in Q7_input
		Q7_input = Q7_input/10;
	}
	
	//return the reversed integer
	return reversedInt;

}
int Q7b(int Q7b_input){
	
	//this is the variable that holds the reversed int.
	int reversedInt=0;
	
	// Do your coding logic here
	//Hint: Use the division and remainder operators to separate the number into its individual digits.
	//this part should be generalized for any number of allowed digits
	
	//variable to be used in for loop and while loop
	int i, temp1=Q7b_input, temp2, count=0, count2, scale;

	//while loop is used to determine the number of digits
	while(temp1!=0){
		temp1=temp1/10;
		count++;
	}

	//For loop is used to determine the digits in the input number
	for(i=count;i>0;i--){
		temp2 = Q7b_input%10;//determines the last digit in the current version of the input
		//Reset Variables to be used in while loop
		count2 = 0;
		scale = 1;
		//while loop is used to recreate 10^(i-1) in order to scale the digit so it is placed in the proper place
		while(count2<i-1){
			scale=scale*10;
			count2++;
		}
		reversedInt = reversedInt+temp2*scale;//adds the last digit to the begining of reversedInt by multiplying by 10 to the power of the place in the new number minus 1
		Q7b_input = Q7b_input/10;//Use integer division to get rid of the last number in Q7_input
		}
	
	
	return reversedInt;

	
	
	
}
