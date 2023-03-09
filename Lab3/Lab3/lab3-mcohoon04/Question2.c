#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	//open file
	FILE *input_file = fopen(filename, "r");

	fscanf(input_file,"%d",sizePtr);
	//allocate memory for the class list
	class_list = malloc((*sizePtr)*sizeof(student *));

	for(int i=0;i<*sizePtr;i++){
		class_list[i] = malloc(sizeof(student));
		fscanf(input_file, "%d", &class_list[i]->student_id);
		fscanf(input_file, "%s", class_list[i]->first_name);
		fscanf(input_file, "%s", class_list[i]->last_name);
		class_list[i]->project1_grade=0;
		class_list[i]->project2_grade=0;
		class_list[i]->final_grade=0;

	}

	fclose(input_file);
	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	//for loop to iterate through array of pointers to student structures
	for(int i = 0;i<size;i++){
		//check if student id of current element is equal to one looking for
		if(list[i]->student_id == idNo){
			//return the index if condition is true
			return i;
		}
	}
	//return -1 if condition is never true
	return -1;
}

void input_grades(char *filename, student **list, int size)
{
	//open file
	FILE *input_file = fopen(filename, "r");
	int id,index;
	for(int i=0;i<size;i++){
		fscanf(input_file, "%d", &id);
		index=find(id,list,size);
		if(index!=-1){
		fscanf(input_file, "%d", &list[index]->project1_grade);
		fscanf(input_file, "%d", &list[index]->project2_grade);
		}
	}

	fclose(input_file);
}

void compute_final_course_grades(student **list, int size)
{
	//for loop to iterate through the class list
	for(int i=0;i<size;i++){
		//sets the final grade of student at index i equal to the average of project1&2 grades
		list[i]->final_grade = (list[i]->project1_grade+list[i]->project2_grade)/2.0;
	}

}

void output_final_course_grades(char *filename, student **list, int size)
{

	FILE *input_file = fopen(filename, "w");

	fprintf(input_file,"%d\n", size);

	for(int i=0;i<size;i++){
		fprintf(input_file,"%d %f\n", list[i]->student_id,list[i]->final_grade);
	}

	fclose(input_file);
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	int index = find(idNo,list,*sizePtr);
	if(index==-1){
		printf("This student is not in the class list\n");
	}
	else{
		free(list[index]);
		for(int i=index;i<(*sizePtr-1);i++){
			list[i]=list[i+1];
		}
		*sizePtr-=1;
	}
}

void destroy_list(student **list, int *sizePtr)
{
	for(int i=0;i<*sizePtr;i++){
		free(list[i]);
	}
	free(list);
	list = NULL;
	*sizePtr=0;
}
