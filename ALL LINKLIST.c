//ANKIT PODDAR
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int c=0; //counter
struct node {   //creating main data
	int data;
	struct node *link;
}*start=NULL; //creating a default node with store 1st element address
//inserting and creating node 
void insert()
{
	system("cls");
	int a;
	struct node *temp; //creating new node 
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\nENTER DATA : ");
	scanf("%d",&(temp->data));
	printf("\nENTER POSITION : ");
	scanf("%d",&a);
	if(a>c) //if position is given out of boundary
	{
		printf("\nYOU HAVE ENTER POSITION OUT OF BOUNDARY SO ELEMENT WILL BE ADDED AT LAST ");
		a=c+1;
	}
	temp->link=NULL; 
	if(start==NULL) //if there is no node present it will creat new one
	{
		start=temp;
	}
	else
	{
		struct node *p;  //creating a temp node 
		p=start;
		int i=2;
		while(i<a)  // finding last node
		{
			p=p->link;
			i++;
		}
		if(a==1) //if we need to add an element at 1st
		{
			temp->link=p;
			start=temp;
		}
		else
		{
		temp->link=p->link;
		p->link=temp;} //linking node with last node
	}
}
//deleteing element
void del()
{
	system("cls");
	struct node *p;  //creating a temp node 
	p=start;
	struct node *t;  //creating a temp node 
	t=start;
	int a;
	printf("\nENTER POSITION FROM WHICH YOU WANT TO REMOVE DATA: ");
	scanf("%d",&a);
	if(a>c)
	{
		printf("\nNO DATA FOUND AT THAT POSITION !");
	}
	else{
	
		int i=2;
		while(i<a)  // finding last 2nd node 
		{
			p=p->link;
			i++;
		}
		int j=1;
		while(j<a)  // finding last node
		{
			t=t->link;
			j++;
		}
		p->link=t->link; //linking two nodes
		struct node *q; //creating a node for storing data for a while
		q=t; //transfering t to q
		printf("\n%d IS SUCCUSFULLY REMOVED ",q->data);
		free(q); //making deleted row free
	}
		
}
//displaying data
void display()
{
	system("cls");
	struct node *temp; //creating new node 
	temp=start;
	printf("\n NODES DATA ARE AS FOLLOWS : ");
	while(temp!=NULL) //running will last node with contain null
	{
		printf("\n%d",temp->data);
		temp=temp->link;
	}
}
//main funtion
void main()
{
	int ch=0;
	do{		
			printf("\n\nENTER 1 FOR CREATE NODE  ");
			printf("\nENTER 2 FOR INSERTING ELEMENT ");
			printf("\nENTER 3 FOR DELETING ELEMENT ");
			printf("\nENTER 4 FOR DISPLAY  ");
			printf("\nENTER 5 FOR COUNT ELEMENT ");
			printf("\nENTER 0 FOR QUIT :  ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					{
					insert();
					c++;
					break;}
				case 2: 
					{
					insert();
					c++;
					break;}
				case 3:
					{
						if(c==0)
						printf("\nNO DATA FOUND !");
						else {
						del();
						c--;}
					break;}
				case 4:
					{
						if(c==0)
						printf("\nNO DATA FOUND !");
						else
						display();
					break;}
				case 5:
					{
					printf("\n NO OF ELEMENT : %d",c);
					break;}
				case 0:
					{
					printf("\n THANK YOU ");
					break;}
				default :
					printf("\n INVALID INPUT !!! ");
			}
	}while(ch!=0);
}//end of main funtion
