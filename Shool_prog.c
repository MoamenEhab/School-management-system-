#include<stdio.h>
#include<stdlib.h>
#include "types.h"
#include <string.h>
/*
Description: this function contains the main menue of the school mangment sys options 

input : void

output:void 
*/
void school_vidMainMenue(void)
{

	printf("=================================================\n");
	printf("Here is our school mangment options :\n");
	printf("(1) add new student\n");
	printf("(2) delet student\n");
	printf("(3) view students data list\n"); 
	printf("(4) edit student data \n");
	printf("(5) rank students score\n");
	printf("(6) rank students alphapitcally\n");
	printf("(7) edit student score\n");
	printf("(8) exit program\n");
	printf("=================================================\n");
	
}
/*
Description : this function used to add new student data to ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void school_vidNewStudent(node**ptr_toHeadptr)
{
	//increasing counter of nodes by one
	counter++;
	//create new student node
	node * new_student=(node*)malloc(sizeof(node));
	u32 copy_phone;
	//get its data from the user 
	u8 name[20]; 
	u8 date[10];
	u8 address[30];
	u8 phone_num[20];
	u8 id;
	u8 score; 
	printf("\nplease enter student name : ");
	scanf(" %[^\n]%*c",&name);
	strcpy(new_student->name,name);

	printf("\nplease enter student date : ");
	scanf(" %[^\n]%*c",&date);
	strcpy(new_student->date,date);

	printf("\nplease enter student address : ");
	scanf(" %[^\n]%*c",&address);
	strcpy(new_student->address,address);

	printf("\nplease enter student phone number : ");
	scanf(" %[^\n]%*c",&phone_num);
	strcpy(new_student->phone_num,phone_num);

	printf("\nplease enter student ID : ");
	scanf("%d",&id);
	new_student->id=id;

	printf("\nplease enter student score : ");
	scanf("%d",&score);
	new_student->score=score;
	
	
	//make the new student pointer  points to what the head points to 
	new_student-> pointer_to_nextStudent = *ptr_toHeadptr;
	//make the head pointer points to the head node 
	*ptr_toHeadptr=new_student;
}

/*
Description : this function used to show the students data of ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidStudentsListView(node*ptr_toHeadptr)
{
	//create varible refer to student num 
	u8 num=1;
	//create pointer and make it point to head 
	node * temporary_pointer ;
	
	temporary_pointer = ptr_toHeadptr;
	if(temporary_pointer == NULL){printf("sorry ur list is empty . you didn't have any student in ur school\n");}
	while(temporary_pointer != NULL)
	{
	 printf("Data of student number %d \n",num);
	 printf("=================================");
	printf("\nstudent name : %s\n",temporary_pointer->name);
	printf("\nstudent date : %s\n",temporary_pointer->date);
	printf("\nstudent ID : %d\n",temporary_pointer->id);
	printf("\nstudent address : %s\n",temporary_pointer->address);
	printf("\nstudent phone number : %d\n",temporary_pointer->phone_num);
	//printf("\nstudent phone number : %u\n",temporary_pointer->h);
	printf("\nstudent score : %d\n",temporary_pointer->score);
	printf("=================================\n");
	num++;
	//make the temporary pointer point to the next students node 
	temporary_pointer=temporary_pointer->pointer_to_nextStudent;

	}
	
}
/*
Description : this function used to edit student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct data type which carry the the fisrt member address of data list

output : void 
*/
void School_vidEditStudentsScore(node**ptr_toHeadptr)
{
	//create varible refer to student num 
	u8 num=1;
	//create pointer and make it point to head 
	node * temporary_pointer ;
	
	temporary_pointer = *ptr_toHeadptr;
	
	while (temporary_pointer != NULL)
	{
		printf("\n%d - student ID : %d \n",num,temporary_pointer->id);
		printf("=================================\n");
		printf("please enter student new score : ");
		scanf("%d",&(temporary_pointer->score));
		temporary_pointer=temporary_pointer->pointer_to_nextStudent;
		num++;
	}
	
}
/*
Description : this function used to edit student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct data type which carry the the fisrt member address of data list

output : void 
*/
void School_vidStudentEdit(node**ptr_toHeadptr)
{
	u8 name[20]; 
	u8 date[10];
	u8 address[30];
	u8 phone_num[20];
	u8 id;
	u8 score; 
	
	
	u8 ID;
	printf("please enter the ID of the student u want to edit its data :");
	scanf("%d",&ID);
	//create pointer and make it point to head 
	node * temporary_pointer ;
	
	temporary_pointer = *ptr_toHeadptr;
	if(temporary_pointer==NULL){printf("sorry , your data base is empty !");}
	while(temporary_pointer != NULL)
	{
		if(temporary_pointer->id == ID)
		{
		printf("u r updating Data of student ID %d \n",temporary_pointer->id);
		printf("=================================");
		printf("\nplease enter student name : ");
		scanf(" %[^\n]%*c",&name);
		strcpy(temporary_pointer->name,name);
		printf("\nplease enter student date : ");
		scanf(" %[^\n]%*c",&date);
		strcpy(temporary_pointer->date,date);

		printf("\nplease enter student address : ");
		scanf(" %[^\n]%*c",&address);
		strcpy(temporary_pointer->address,address);

		printf("\nplease enter student phone number : ");
		scanf(" %[^\n]%*c",&phone_num);
		strcpy(temporary_pointer->phone_num,phone_num);

		printf("\nplease enter student ID : ");
		scanf("%d",&id);
		temporary_pointer->id=id;

		printf("\nplease enter student score : ");
		scanf("%d",&score);
		temporary_pointer->score=score;
		printf("=================================\n");
		printf("Thank u for updating data.");
		break;
		}
		else
		{
			temporary_pointer=temporary_pointer->pointer_to_nextStudent;
			if(temporary_pointer==NULL){printf("sorry , the id u entered doesn't match any student id pls try again");}
		}
		
	}		
}
/*
Description : this function used to delet student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void school_vidDeleteStudent(node**ptr_toHeadptr)
{
	//create current and pervious node 
	node * current_node;
	node * pervious_node;
	u8 ID ;
	printf("please enter the ID of the student u want to delet its data :");
	scanf("%d",&ID);
	current_node=*ptr_toHeadptr;
	pervious_node=*ptr_toHeadptr;
	//check if the list is empty
	if(current_node==NULL)
	{
	printf("sorry , there is no data in ur data base to delet ! \n");
	return;
	}
	//check if the node u want to delet is the first node  (the node that head point to)
	if(current_node->id ==ID)
	{	*ptr_toHeadptr=current_node->pointer_to_nextStudent;
		free(current_node);
		printf("data deleted successfully. thank you :) \n");
		//decreasing counter of nodes by one
	    counter--;
		return;
	}
	//check if the list is empty and if not . start search for the node u want to delet 
	if(current_node != NULL)
	{
		while( current_node->id != ID  )
		{
			pervious_node=current_node;
			current_node=current_node->pointer_to_nextStudent;	
			//if u reach the end of the list and not find the node 
			if(current_node == NULL)
			{
				printf("Oops ! ID u entered not exist in ur data base \n");
				return;
			}
		}
		
	}
	
	//connect the last to the next 
	pervious_node->pointer_to_nextStudent = current_node->pointer_to_nextStudent;	
	free(current_node);
	printf("data deleted successfully. thank you :) \n");
	//decreasing counter of nodes by one
	counter--;
}
/*
Description : this function used to rank the student data score 

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/

void School_vidRankStudentsScore(node**ptr_toHeadptr)
{
	
	//check if there in no node in the list
	if(counter == 0){printf("there is no data to sort"); return;}
	//check if there is only one node in the list
	else if(counter == 1){printf("there is only one node in ur linked list"); return;}
	//if there are more then one node sort them
	else if(counter > 1)
	{
		for(node*current=*ptr_toHeadptr ; current->pointer_to_nextStudent!=NULL ;current=current->pointer_to_nextStudent )
		{
			for(node*Next=current->pointer_to_nextStudent  ; Next!=NULL  ;  Next=Next->pointer_to_nextStudent  )
			{		

				if(current->score > Next->score)
				{

				u32  temp_name; 
				u32  temp_date;
				u32  temp_address;
				u32 temp_phone_num;
				u16 temp_id;
				u8  temp_score; 
				//swapping name
				for(int i;i<20;i++)
				{
				temp_name=current->name[i];
				current->name[i]=Next->name[i];
				Next->name[i]=temp_name;					
				}
				//swapping date
				for(int i;i<10;i++)
				{
				temp_date=current->date[i];
				current->date[i]=Next->date[i];
				Next->date[i]=temp_date;					
				}
				//swapping address
				for(u8 i;i<30;i++)
				{
				temp_address=current->address[i];
				current->address[i]=Next->address[i];
				Next->address[i]=temp_address;					
				}
				//swapping phone_num
				for(u8 i;i<20;i++)
				{
				temp_phone_num=current->phone_num[i];
				current->phone_num[i]=Next->phone_num[i];
				Next->phone_num[i]=temp_phone_num;					
				}	
				//swaping score
				temp_score=current->score;
				current->score=Next->score;
				Next->score=temp_score;
				//swaping id
				temp_id=current->id;
				current->id=Next->id;
				Next->id=temp_id;
				}
			}
		}
	}
	
}
/*
Description : this function used to delet student data from ur data base system

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidRankStudentsAlphapitcally(node**ptr_toHeadptr)
{
	
	
	//check if there in no node in the list
	if(counter == 0){printf("there is no data to sort"); return;}
	//check if there is only one node in the list
	else if(counter == 1){printf("there is only one node in ur linked list"); return;}
	//if there are more then one node sort them
	else if(counter > 1)
	{
		for(node*current=*ptr_toHeadptr ; current->pointer_to_nextStudent!=NULL ;current=current->pointer_to_nextStudent )
		{
			for(node*Next=current->pointer_to_nextStudent  ; Next!=NULL  ;  Next=Next->pointer_to_nextStudent  )
			{		

				if(current->name[0] > Next->name[0])
				{

				u8  temp_name; 
				u8  temp_date;
				u8  temp_address;
				u8 temp_phone_num;
				u8 temp_id;
				u8  temp_score; 
				//swapping name
				for(u8 i;i<20;i++)
				{
				temp_name=current->name[i];
				current->name[i]=Next->name[i];
				Next->name[i]=temp_name;					
				}
				//swapping date
				for(u8 i;i<10;i++)
				{
				temp_date=current->date[i];
				current->date[i]=Next->date[i];
				Next->date[i]=temp_date;					
				}
				//swapping address
				for(u8 i;i<30;i++)
				{
				temp_address=current->address[i];
				current->address[i]=Next->address[i];
				Next->address[i]=temp_address;					
				}
				//swapping phone_num
				for(u8 i;i<20;i++)
				{
				temp_phone_num=current->phone_num[i];
				current->phone_num[i]=Next->phone_num[i];
				Next->phone_num[i]=temp_phone_num;					
				}	
				//swaping score
				temp_score=current->score;
				current->score=Next->score;
				Next->score=temp_score;
				//swaping id
				temp_id=current->id;
				current->id=Next->id;
				Next->id=temp_id;
				}
			}
		}
	}
	
}
/*
Description : this function used to edit student scrore 

input : (node**ptr_toHeadptr)----> this is pointer to struct pointer to carry the address of the head pinter (which point to the first member in ur data)

output : void 
*/
void School_vidEditStudentScore(node**ptr_toHeadptr)
{
	u8 score; 
	
	
	u8 ID;
	printf("please enter the ID of the student u want to edit its data :");
	scanf("%d",&ID);
	//create pointer and make it point to head 
	node * temporary_pointer ;
	
	temporary_pointer = *ptr_toHeadptr;
	if(temporary_pointer==NULL){printf("sorry , your data base is empty !");}
	while(temporary_pointer != NULL)
	{
		if(temporary_pointer->id == ID)
		{
		printf("u r updating score of student ID %d \n",temporary_pointer->id);
		printf("=================================");
		printf("\nplease enter student score : ");
		scanf("%d",&score);
		temporary_pointer->score=score;
		printf("=================================\n");
		printf("Thank u for updating student score.");
		break;
		}
		else
		{
			temporary_pointer=temporary_pointer->pointer_to_nextStudent;
			if(temporary_pointer==NULL){printf("sorry , the id u entered doesn't match any student id pls try again");}
		}
		
	}		
}
/*
Description: this function contains the main menue of the school mangment sys options 

input : void

output:void 
*/
void School_vidExit(void)
{
	printf("The program closed. good bye :)");
}
