void main (void)
{
	static node * head=NULL;


	// school_vidNewStudent(&head);
	// school_vidNewStudent(&head);
	// School_vidStudentsListView(head);

	printf("************************************************\n");
	printf("************************************************\n");
	printf("************************************************\n");
	printf("****WELCOME TO THE SCHOOOL MANAGMENT SYSTEM*****\n");
	printf("********** CREATED BY : MOAMEN EHAB ************\n");
	while(1)
	{

		u8 selection;
		school_vidMainMenue();
		printf("please enter ur selection number : ");
		scanf("%d",&selection);

		switch(selection)
		{
			case 1:
			school_vidNewStudent(&head);
			break;
			case 2:
			school_vidDeleteStudent(&head);
			break;
			case 3:
			School_vidStudentsListView(head);
			break;
			case 4:
			School_vidStudentEdit(&head);
			break;
			case 5:
			School_vidRankStudentsScore(&head);
			break;
			case 6:
			School_vidRankStudentsAlphapitcally(&head);
			break;
			case 7 :
			School_vidEditStudentScore(&head);
			break;
			case 8:
			School_vidExit();
			break;
		}
		if(selection ==8)
		{
			break;
		}
	}
	 
}