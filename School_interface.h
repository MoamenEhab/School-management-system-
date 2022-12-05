#include<stdio.h>
#include<stdlib.h>
#include "types.h"
#include <string.h>
typedef struct node node;

struct node{
				u8 name[20]; 
				u8 date[10];
				u8 address[30];
				u8 phone_num[20];
				u32 id;
				u32 score; 
				
				node * pointer_to_nextStudent;
		
            };


/*
Description: this function contains the main menue of the school mangment sys options 

input : void

output:void 
*/
void school_vidMainMenue(void);
/*
Description : this function used to add new student data to ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void school_vidNewStudent(node**ptr_toHeadptr);
/*
Description : this function used to delet student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void school_vidDeleteStudent(node**ptr_toHeadptr);
/*
Description : this function used to show the students data of ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidStudentsListView(node*ptr_toHeadptr);
/*
Description : this function used to edit student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct data type which carry the the fisrt member address of data list

output : void 
*/
void School_vidStudentEdit(node**ptr_toHeadptr);
/*
Description : this function used to rank the student data score 

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidRankStudentsScore(node**ptr_toHeadptr);
/*
Description : this function used to delet student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidRankStudentsAlphapitcally(node**ptr_toHeadptr);
/*
Description : this function used to edit student scrore 

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidEditStudentScore(node**ptr_toHeadptr);
/*
Description: this function contains the main menue of the school mangment sys options 

input : void

output:void 
*/
void School_vidExit(void);