// DSA Project
//Police FIR record management System
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct record
{
	char name[20], gender[7], complaint[50], court[50], details[50],crime[11],date[40];
	int age,appointment,id;
	struct record *next;
};


int count=1, d=1;


struct record *start=NULL;
struct record *addrecord(struct record *start);
struct record *display(struct record *start);
struct record search(struct record *start);
int genereatefir();
void mainmenu();
void check_user(char username[10], char password[10]);
int main(){
char password[10], username[10], ch;
int i, option;
system("COLOR 8F");
//clrscr();
system("cls");
printf("\t\t==================================================================\n");
printf("\t \t==================POLICE FIR RECORD MANAGEMENT====================\n");
printf("\t \t==================....TOWN POLICE STATION.....====================\n");
printf("\t\t==================================================================\n");
printf("\t\t==================================================================\n");
printf("\t \t========================LOGIN CREDENTIALS=========================\n");
printf("\t\t==================================================================\n");
printf("\t\t\t->Enter User name: ");
scanf("%s",username);
printf("\t\t\t->Enter the password : ");

for(i=0;i<7;i++)
{
	ch = getch();
	password[i] = ch;
	ch = '*' ;
	printf("%c",ch);
}

password[i] = '\0';

check_user(username, password);

getch();
}

void check_user(char username[10], char password[10]){
    int n;
	if(strcmp(username, "police") == 0  )
	{
		if(strcmp(password, "default") == 0)
		{
			printf("\n\t\t\t----------WELCOME OFFICER-----------\n");
			mainmenu();
		}
		else
		{
			printf("\n\t\t*****Password or User ID entered is invalid*****\n");
			printf("\n->Press 1 to Try AGAIN or press 2 to exit: ");
			scanf("%d",&n);
			if(n==1)
			{
				main();
			}
			
	}}
}

int genereatefir(){
	return count++;
}

struct record *addrecord(struct record *start){
	int age,n,val, y,id;
		char name[20], gender[7], complaint[50], court[50], details[50],crime[11],date[8];
	struct record *new_node, *ptr;
	new_node=(struct record*)malloc(sizeof(struct record));

    printf("\n --------------ENTER CONVICT DETAILS-----------------\n");
    printf("->Enter Convict ID:");
    scanf("%d",&id);
    new_node->id=id;
	printf("\n->Enter Name: ");
	scanf("%s",name);
	strcpy(new_node->name,name);
	printf("->Enter Age: ");
	scanf("%d",&age);
	new_node->age=age;
	printf("\n ->Enter Gender: ");
	scanf("%s",gender);
	strcpy(new_node->gender,gender);
	printf("->Enter Crime:");
	scanf("%s",crime);
	strcpy(new_node->crime,crime);
	printf("->Enter Complaint of act: ");
	scanf("%s",complaint);
	strcpy(new_node->complaint,complaint);
	printf("->Enter Court:");
	scanf("%s",court);
	strcpy(new_node->court,court);
	printf("\n->Press 1. To insert the person in the appointment list else press 2: ");
	scanf("%d",&y);
	if(y==1)
    {
		val=genereatefir();
		new_node->appointment=val; 
    }
	else
	{
		new_node->appointment=0;
		
	}
	printf("\n \t\t\t ============= Convict Record added successfully =============\n");
	if(start==NULL)
	{
		new_node->next=NULL;
		start=new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;

		ptr->next=new_node;
		new_node->next=NULL;
	}
	return start;
}

struct record *display(struct record *start)
{
	if(start==NULL)
	{
		printf("\n \t-------------The list of Convicts is empty...Do insert it first--------------\n\n");
	}
	else
	{
		struct record *ptr;
		int i=1;
		ptr=start;
		while(ptr!=NULL)
		{
		    printf("\n\n**CONVICT %d**",i);
		    if(ptr->appointment!=0)
			{
			   printf("\n->FIR : %d",ptr->appointment);
			}
			printf("\n->ID:%d",ptr->id);
			printf("\n->Name: %s",ptr->name);
			printf("\n->Age: %d",ptr->age);
			printf("\n->Gender: %s",ptr->gender);
			printf("\n->Crime: %s",ptr->crime);
			printf("\n->Complaint of act: %s",ptr->complaint);
			printf("\n->Court: %s",ptr->court);
			ptr=ptr->next;
			i++;
		}
		return start;
	}
}
void mainmenu()
{
	int choice;
	do
	{
		printf("\n\t\t\t =========================MAIN MENU=========================\n");
		printf("\t\t\t\t \t1.Add new Record\t\n");
		printf("\t\t\t\t \t2.Display Records\t\n");
		printf("\t\t\t\t \t3.Search Records\t\t\n");
		printf("\t\t\t\t \t4.Log Out\t\t\n");
		printf("\t\t\t\t \t5.Exit\t\t\t\n");
		printf("\n\t\t\t =========================================================\n");
		printf("\n->Enter Your Option: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
					start=addrecord(start);
				break;
			case 2:
					start=display(start);
				break;
			case 3:
				search(start);
				break;
			case 4:
					main();
				break;
			case 5:
			system("cls");
            printf("\n\n\t\tTHANK YOU \n\n ");
            exit(0);
				break;
		}
	}
	while(choice!=6);
}
struct record search(struct record *start)
{
	int f,p;
    if(start==NULL)
	{
		printf("\n \t------------The list of Convicts is empty...Do insert it first---------------\n\n");
	}	
	else
	{
		struct record *ptr;
		ptr=start;
		printf("\n ->Enter FIR no. to seach:");
		scanf("%d",&f);
		while(ptr!=NULL)
		{
			if(ptr->appointment==f)
			{
			printf("\n->ID:%d",ptr->id);
			printf("\n->Name: %s",ptr->name);
			printf("\n->Age: %d",ptr->age);
			printf("\n->Gender: %s",ptr->gender);
			printf("\n->Crime: %s",ptr->crime);
			printf("\n->Complaint of act: %s",ptr->complaint);
			printf("\n->Court: %s",ptr->court);
			}
			ptr=ptr->next;
		}
	}
}

