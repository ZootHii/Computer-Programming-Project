
// AHMET YILDIRIM - 17050111012 - TELEPHONE INSTALLATION PROGRAM

#include <stdio.h>
#include <string.h>
#include "stack_int1.h"
#define MAX 10

typedef struct{
	char name[MAX];
	char city[MAX];
	char date[MAX];
} application_t;

typedef struct{
	application_t infoapp;
	int number;
} info_t;

#include "queue_app.h"
#include "stack_info.h"


//Functions---------------------------------------------------------------------
void take_number(int &ix, queue_t *q, stack_t *s, stack_t1 *s1, stack_t1 *s2, application_t a, info_t b[MAX]);
void leave_number(queue_t *q, stack_t *s, stack_t1 *s1, stack_t1 *s2, int number, info_t b[MAX]);
void read_file(FILE *ptr, int arr[MAX]);
void put_stack1(stack_t1 *s1, int arr[MAX]);
void menu();
//------------------------------------------------------------------------------

int main(){
	
	FILE *ptr = fopen("numbers.txt","r");

	int number, choice, ix = 0, iy = 0;
	
	int numbersarr[10];
	
	application_t infos_without_numbers_a;
	info_t infos_with_numbers_b[MAX];
	
	stack_t1 just_numbers;
	initialize_s1(&just_numbers);
	
	stack_t1 installed_numbers;
	initialize_s1(&installed_numbers);
	
	queue_t infos_without_numbers;
	initialize_q(&infos_without_numbers);
	
	stack_t infos_with_numbers;
	initialize_s(&infos_with_numbers);
	
	if(ptr == NULL)
		printf("There is no number list!");
	
	else{
		
		read_file(ptr,numbersarr); // read numbers from the file to an array
		put_stack1(&just_numbers, numbersarr); // put numbers from the array to a integer stack
		
		menu();
		
		printf("\nPlease enter your choice: ");
		scanf("%d",&choice);
		
		while(choice != 5){
			if(choice == 1){
					
				take_number(ix, &infos_without_numbers, &infos_with_numbers, &just_numbers, &installed_numbers, infos_without_numbers_a, infos_with_numbers_b);
				
				printf("\nPlease enter your choice: ");
				scanf("%d",&choice);
			}
			else if(choice == 2){
				
				printf("What is your number wihtout [ 0 (543) ] : ");
				scanf("%d", &number);
				
				for(int i = 0; i < MAX; i++){
					if(numbersarr[i] == number){
						leave_number(&infos_without_numbers, &infos_with_numbers, &installed_numbers, &just_numbers, number, infos_with_numbers_b);
					}
				}
				
				printf("\nPlease enter your choice: ");
				scanf("%d",&choice);
			}
		}
	}
}
//------------------------------------------------------------------------------
void take_number(int &ix, queue_t *q, stack_t *s, stack_t1 *s1, stack_t1 *s2, application_t a, info_t b[MAX]){
	
	printf("Enter your name and surname: ");
	scanf(" %[^\n]s", &a.name);
	
	printf("Enter your city: ");
	scanf("%s", &a.city);
	
	printf("Enter the date of application: ");
	scanf("%s", &a.date);
	
	
	insert(q, a); // put datas to a queue for process
	
	if(ix == MAX+1){
		printf("\nWARNING THERE IS NO NUMBER CAN BE USED.\n");
		printf("TERMINATING THE TELEPHONE INSTALLATION PROGRAM...\n\n");
	}
	else{
		b[ix].infoapp = remove(q); // remove the datas and put it into info structure
		b[ix].number = pop1(s1); // pop the number from the integer stack(free numbers) and put it into info structure
		push1(s2, b[ix].number); // push the number from the info structure and put it into integer stack(installed numbers)
		printf("\nYour application is successfully completed!!\n");
		printf("Your number is: 0 (543) %d\n", b[ix].number);
		push(s, b[ix]); // push the datas with number into info stack by one by
	}
	ix++;
}
//------------------------------------------------------------------------------
void leave_number(queue_t *q, stack_t *s, stack_t1 *s1, stack_t1 *s2, int number, info_t b[MAX]){
	
	stack_t1 e1; // create an empty integer stack
	initialize_s1(&e1);
	
	stack_t e; // create an empty info stack
	initialize_s(&e);
	
	int i = 0;
	int temp_num;
	info_t temp_data;
	
	// DELETE NUMBER
	while (!is_empty_s1(s1)){
		temp_num = pop1(s1); //pop every numbers from the integer stack(installed numbers)	 
 		if (temp_num != number) // check if it is the same number or not with the person's number
 			push1(&e1, temp_num); // if it is not the same number push it to an empty integer stack
 		else if(temp_num == number){ 
 			printf("\nYour number and ");
			push1(s2, temp_num); // if it is the same number push it to the integer stack(free numbers)
		}
	}
 	while (!is_empty_s1(&e1))
 		push1(s1, pop1(&e1)); // pop from temporay stack and put back to integer stack(installed numbers)
 		
	// DELETE INFO
	while (!is_empty_s(s)){
		temp_data = pop(s); // pop every datas with number
 		if (temp_data.number != b[i++].number) // check if it is the same number with the person's number in the info stack
 			push(&e, temp_data);
	}
 	while (!is_empty_s(&e))
 		push(s, pop(&e));
 	printf("informations have been deleted.\n");
 	printf("Notice, this number can be reused by someone else..\n");
}
//------------------------------------------------------------------------------
void read_file(FILE *ptr, int arr[MAX]){
	int i;
	for (i = 0; i < MAX; i++){
		fscanf(ptr,"%d", &arr[i]);
	}
}
//------------------------------------------------------------------------------
void put_stack1(stack_t1 *s1, int arr[MAX]){
	int i;
	for (i = 0; i < MAX; i++){
		push1(s1, arr[i]);
	}
}
//------------------------------------------------------------------------------
void menu(){
	printf("1. I want to take a number.\n");
	printf("2. I don't want to use this number anymore.\n");
	printf("5. EXIT.\n");
}
//------------------------------------------------------------------------------
