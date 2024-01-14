#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int ticket_no=0;
char name[30];
int age;
long int mobile_no;
long int aadhar_no;
char address[50];
void counter();


struct ticket
{
	int ticket_no;
	char name[30];
	int age;
	long int mobile_no;
	long int aadhar_no;
	char address[50];
	struct ticket*next;

};
typedef struct ticket node;
node *start = NULL;

int menu()
{
	printf("\n\n                                      ");
	printf("\n\n         ***************************************** TICKET OPERATIONS *****************************************\n\n");
	int ch;
	printf("\n                                                   1.Create a Ticket \n");
	printf("\n                                                   2.Delete a Ticket \n");
	printf("\n                                                   3.Check/Search a ticket \n");
	printf("\n                                                   4.Update Ticket Details \n");
	printf("\n                                                   5.Total Ticket \n");
	printf("\n                                                   6.Exit \n");
	printf("\n\n         *****************************************************************************************\n\n");
	printf("\n\n                                                 Enter your choice: \n                                                                      ");

	scanf("%d",&ch);

	return ch;
}

node* getnode()
{
	node *newnode;
	newnode=(node*)malloc(sizeof(node));
	ticket_no++;
	newnode->ticket_no=ticket_no;
	printf("\n\n         *****************************************************************************************\n\n");
	printf("\n\n                                                    Enter Name : \n                                                                      ");
	scanf("%s", &newnode-> name);
	printf("\n\n                                                    Enter Age : \n                                                                      ");
	scanf("%d", &newnode-> age); 
	printf("\n\n                                                    Enter Mobile No. : \n                                                                      ");
	scanf("%ld", &newnode-> mobile_no);
	printf("\n\n                                                    Enter Aadhar No. : \n                                                                      ");
	scanf("%ld", &newnode-> aadhar_no);
	printf("\n\n                                                    Enter Address : \n                                                                      ");
	scanf("%s", &newnode-> address);
	newnode->next=NULL;
		printf("\n\n         *****************************************************************************************\n\n");
				printf("\n\n                                                   Ticket No : %d ",ticket_no);
				printf("\n\n                                                   Name : %s ",newnode->name);
				printf("\n\n                                                   Age : %d ",newnode->age);
				printf("\n\n                                                   Mobile No : %ld n",newnode->mobile_no);
				printf("\n\n                                                   Aadhar No : %ld ",newnode->aadhar_no);
				printf("\n\n                                                   Address : %s ",newnode->address);
				printf("\n\n         *****************************************************************************************\n\n");
	return newnode;
}

int countnode(node *ptr)
{
	int count=0;
	while(ptr != NULL)
	{
		count++;
		ptr = ptr -> next;
	}
	return (count);
}

void create_ticket(int n)
{
	int i;
	node *newnode;
	node*temp;
	for(i = 0; i < n; i++)
	{
		newnode = getnode();
		if(start == NULL)
		{
			start = newnode;
		}
		else
		{
			temp = start;
			while(temp -> next != NULL)
			{
				temp = temp->next;
			}
			temp -> next = newnode;
		}
	}
}
void update_ticket(int n)
{
	int i;
	node *newnode;
	node*temp;
	if(start == NULL)
	{
		printf("\n\n                                                   Ticket List is Empty........");
	}
	else
	{
		temp = start;
		while(temp)
		{
			if(temp->ticket_no==n)
			{
				temp->ticket_no=ticket_no;
				printf("\n\n         *****************************************************************************************\n\n");
				printf("\n\n                                                    Enter Name : \n                                                                      ");
				scanf("%s", &temp-> name);
				printf("\n\n                                                    Enter Age : \n                                                                      ");
				scanf("%d", &temp-> age); 
				printf("\n\n                                                    Enter Mobile No. : \n                                                                      ");
				scanf("%ld", &temp-> mobile_no);
				printf("\n\n                                                    Enter Aadhar No. : \n                                                                      ");
				scanf("%ld", &temp-> aadhar_no);
				printf("\n\n                                                    Enter Address : \n                                                                      ");
				scanf("%s", &temp-> address);
				return;
			}
			temp = temp->next;
		}
	}
}

void delete_ticket()
{
	int ctr = 1, pos, nodectr;
	node *temp, *temp1;
	if(start == NULL) 
	{
		printf("\n\n         *****************************************************************************************\n\n");
		printf("\n\n                                                    Empty Ticket List..");
		printf("\n\n         *****************************************************************************************\n\n");
		return ;
	} 
	else
	{
		printf("\n\n         *****************************************************************************************\n\n");
		printf("\n\n                                                    Enter Ticket Number to delete: \n                                                                      "); 
		scanf("%d", &pos);
		nodectr = countnode(start); 
		if(pos> 0)
		{
			temp = temp1 = start; 
			while(temp->ticket_no!=pos) 
			{
				temp1 = temp; 
				temp = temp -> next;
				ctr ++; 
			}
			temp1 -> next = temp -> next;
			free(temp);
			printf("\n\n                                                    Ticket deleted..");
			printf("\n\n         *****************************************************************************************\n\n"); 
		} 
		else
		{
			printf("\n\n                                                    Invalid Ticket Number....");
			printf("\n\n         *****************************************************************************************\n\n");
		}
	}
	counter();
}
 
void search_ticket()
{
	int ctr = 1, pos, nodectr,a=0;
	node *temp, *temp1;
	if(start == NULL) 
	{ 
		printf("\n\n                                                    Ticket List is empty..");
		printf("\n\n         *****************************************************************************************\n\n");
		return ;
	} 
	else
	{ 
		printf("\n\n                                                    Enter Ticket Number to search : \n                                                                      "); 
		scanf("%d", &pos);
		printf("\n\n         *****************************************************************************************\n\n");
		temp = temp1 = start; 
		while(temp) 
		{
			temp1 = temp; 
			if(temp->ticket_no==pos)
			{
				printf("\n\n                                                    Ticket found........ ");
				printf("\n\n         *****************************************************************************************\n\n");
				printf("\n\n                                                   Ticket No : %d ",temp->ticket_no);
				printf("\n\n                                                   Name : %s ",temp->name);
				printf("\n\n                                                   Age : %d ",temp->age);
				printf("\n\n                                                   Mobile No : %ld ",temp->mobile_no);
				printf("\n\n                                                   Aadhar No : %ld ",temp->aadhar_no);
				printf("\n\n                                                   Address : %s ",temp->address);
				printf("\n\n         *****************************************************************************************\n\n");
				return;
			}
			temp = temp -> next;
			ctr ++;
		}
		printf("\n\n                                                   Ticket Number not found ...."); 
		printf("\n\n         *****************************************************************************************\n\n"); 
	}
	counter();
}
 
void counter()
{
	int ch, n;
	while(1)
	{
		ch = menu();
		switch(ch)
		{
		case 1:
			printf("\n\n                                                    Number of member you want to create ticket : \n                                                                      ");
			scanf("%d", &n);
			printf("\n\n         *****************************************************************************************\n\n");
			create_ticket(n);
			printf("\n\n                                                    List created..");
			printf("\n\n         *****************************************************************************************\n\n");
			break;
			case 2: delete_ticket();
			break;
			case 3: search_ticket();
			break;
			case 4: printf("\n\n                                                   Enter ticket number for update details : \n                                                                      ");
			scanf("%d", &n);
			printf("\n\n         *****************************************************************************************\n\n");
			update_ticket(n);
			printf("\n\n                                                    Ticket updated..");
			printf("\n\n         *****************************************************************************************\n\n");
			break;
			case 5: printf("\n\n                                                    No of Ticktes : %d ", countnode(start));
			printf("\n\n         *****************************************************************************************\n\n");
			break;
			case 6: exit(0);
		}
	}
	getch();
}

int main()
{
	int ch;
	while(1)
	{
	printf("\n\n                                                   - W E L C O M E -           ");
	scanf("%c");
	printf("\n\n         ******************************************* TICKET COUNTER ****************************************\n\n");
	printf("\n\n                                                  1. Counter No. 1 \n\n                                                  2. Counter No. 2 \n\n                                                  3. Counter No. 3 \n\n                                                  4. EXIT \n\n");
	printf("\n\n         *****************************************************************************************\n\n");
	printf("\n                                                Choose a counter : \n                                                                      ");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: counter();
		break;
		case 2:counter();
		break;
		case 3: counter();
		break;
		case 4: return 0;
		default : printf("\n                                                   Your choice is wrong...............");
		printf("\n\n         *****************************************************************************************\n\n");
	}

printf("\n\n         *****************************************************************************************\n\n");}
return 0;

}
