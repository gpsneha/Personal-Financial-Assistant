#include<stdio.h>
#include<string.h> 
#include<conio.h> 
#include<math.h>
#include<time.h>
#include<ctype.h>
#include <windows.h>
#include<dos.h>
//======================================================================================================================
int login_page();
int addIncome ();
void about();
void main_menu();
int addexpense(int totalBudget);
void user_remainder();
//=======================================================================================================================
int login_status,option,totalBudget;
int Total_Balance=0;
char a[10];
static int total;
//=========================================================================================================================
struct login_details
{
	char username[15]; 
   	char password[15]; 
};
//=========================================================================================================================
struct user_details
{
	int user_id;
	char user_name[30];
	char city[20];
	char mob_no[11];
	char email[50];
};
struct user_details temp_c;
FILE *UserFile;
//=========================================================================================================================
struct income
{
 	int totalIncome;
	int salary;
	int business;
	int others;
	int Income_source;
	int revenue;
	int iday,imonth,iyear;
	char date[15];
};
struct income temp_i;
//=========================================================================================================================
struct expense
{
	int monthly;
	int Total_Expense;
	char category[30];
	int amount;
	char date[15];
	int iday,imonth,iyear;
};
struct expense temp_e;
FILE *ft;
//=========================================================================================================================
struct remainder2
{
	int rday;
	int rmonth;
	int ryear;
	int total_days;	
};
struct remainder2 temp_r;
//FILE *ptr_r;
//===========================================================================================================================
int t(void)
{
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	printf("      Date: %d-%d-%d \t",now->tm_mday,now->tm_mon,now->tm_year);
	printf("      Time: %d:%d:%d\n",now->tm_hour, now->tm_min,now->tm_sec);
	return 0;
}
//=============================================================================================================================
void ventry(char t[],int code)
{
  int i=0;
	if(code==0)
	{
		while((t[i]=getch())!='\r' && i<30)
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==1)
	{
		while((t[i]=getch())!='\r' && i<10 )
		if((t[i]>=48 && t[i]<=57) || t[i]==46 ||  t[i]=='-')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}
	else if(code==2)
	{
		while((t[i]=getch())!='\r' && i<30 )
		if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) ||(t[i]>=48 && t[i]<=57) || t[i]==32 || t[i]==8 ||t[i]=='@'||t[i]=='.')
		{
			printf("%c",t[i]);
			i++;
		}
		else if(t[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;              //Length counter is decremented.

		}
	}

	t[i]='\0';
}
//====================================MAIN PART============================================
int main() 
{ 
  	char name[15];
	char pass[15];
	int count=0,i;

	system("cls");
	login_page();
	main_menu();
	return 0;
} 
//=====================================MAIN MENU============================================
void main_menu()
{
  char ch;

	do
	{
		system("cls");
		printf("Income Info\n");
		printf("Expenses Info\n");
		printf("About\n");
		printf("Exit\n");
		printf("\n");
		printf("\n");
		time_t t;   // not a primitive datatype
        time(&t);
		printf("\n");
		printf("\n");
		printf("                   %s",ctime(&t));
		printf("\n");
		printf("\n");
		printf("            Welcome To Personal Financial Assitance \n          ");
		printf("Press First Character for further Menu \n ");
		ch=toupper(getche());
		printf("\n");
		switch(ch)
		{
			case 'I':totalBudget=addIncome();
     			 break;
			case 'E':totalBudget=addexpense(totalBudget);
				 break;
			case 'A':about();
				 break; 	
			case 'X':
			printf("Do you want to exit now? Y/N :\n");

			ch=(getche());
			ch=toupper(ch);
			if(ch=='Y')
			{
				system("cls");
				printf(" Please wait.....");
				exit(0);
			}
			else
			{
				main_menu();
			}

			default:
			printf("Plese Enter right character ONLY (I,E,A,X).\n");
			getch();
		}
	}while(ch!='X');
}
//===================================LOGIN PAGE====================================================
int login_page() 
{ 
    struct login_details user;
 	char name[15];
	char pass[15];
	int count=0,i;
start:
	printf(" LOGIN \n");
	printf("Enter user name :");
	strcpy(gets(name),name);
	printf("Enter password  :");
	i=0;
	do
	{
		pass[i] = getch();
		if(pass[i] == 13 )
		{
			break;
			
		}
		else if(pass[i]==8 && i>0)
		{
			printf("%c%c%c",8,32,8);
			i--;
		}
		else
		{
			printf("*");
			i++;
		}
	}while(pass[i]!=13);
	pass[i] = '\0';

	if(strcmp(name,"sree") || strcmp(pass,"1234"))
	{
	 printf("Please Enter vailid Username & Passward!!!!!\n");
	 count++;
	 printf("%d chance left!!!!\n",3-count);
	 getch();
	 if(count==3)
	 exit(0);
	 else
	 goto start;
	}
	else
	{
	  return 1;
	}	
}
//===================================INCOME DETAILS=================================================
int addIncome ()
{
	char resp[20],psw[4]="OK",ch;
	time_t t;   // not a primitive datatype
    time(&t);
	FILE *ft;
	ft=fopen("Myincome.txt","a"); //it will append the data to the file
	fprintf(ft,"%s\n", ctime(&t));
	if(ft==NULL)
	{
		printf("\n\t Can not open file!!\n ");
		exit(0);
	}
	system("cls");
	printf(" ****INSERT INCOME DETAILS****\n");
	printf("SALARY\n");
	printf("BUSINESS\n");
	printf("OTHERS\n");
	printf("Main Menu\n");
	while(1)
	{
	printf("Press First Character for further Operations  \n");
	ch=toupper(getche());    	
	switch(ch)
    	{
    		case 'S':
				   printf("Enter monthly Salary: $");
    			   scanf("%d",&temp_i.salary);
				   printf("\n");
				   printf("OK\t");
				   printf("Cancel\n");
	               printf("Press First charecter for the operation :\n ");
				   ch=getch();
	               printf("press OK to confirm the income\n");
    			   if(ch=='o' || ch=='O')
				  {
					fprintf(ft,"%d ",temp_i.salary);
					system("cls");
					printf("Income Added Successfully!!!!!\n");
					printf("More entries  [y/n] ");
					ch=getche();
				  }
    		   	   break;
    		case 'B':system("cls");
				   printf("Enter business profit: $");
    			   scanf("%d",&temp_i.business);
				   printf("\n");
				   printf("OK\t");
				   printf("Cancel\n");
	               printf("Press First charecter for the operation :\n ");
				   ch=getch();
	               printf("press OK to confirm the income\n");
    			   if(ch=='o' || ch=='O')
				  {
					fprintf(ft,"%d ",temp_i.business);
					system("cls");
					printf("Income Added Successfully!!!!!\n");
					printf("More entries  [y/n] ");
					ch=getche();
				  }
    		       break;
    		case 'O':system("cls");
			       printf("Enter other source of income if any: $");
    			   scanf("%d",&temp_i.others);
				   printf("\n");
				   printf("OK\t");
				   printf("Cancel\n");
	               printf("Press First charecter for the operation :\n ");
				   ch=getch();
	               printf("press OK to confirm the income\n");
    			   if(ch=='o' || ch=='O')
				  {
					fprintf(ft,"%d ",temp_i.others);
					system("cls");
					printf("Income Added Successfully!!!!!\n");
					printf("More entries  [y/n] ");
					ch=getche();
				  }
    		   	   break;
    		case 'U':system("cls");
			       goto update;
    			   break;
    		case 'M':main_menu();
    				break;
		}
	}
update:
	temp_i.totalIncome = temp_i.totalIncome + temp_i.salary + temp_i.business + temp_i.others;
	system("cls");
	printf("\n");
	printf("Save\t");
	printf("Cancel\n");
	printf("Press First charecter for the operation to save total income :\n ");
	ch=getch();
    if(ch=='s' || ch=='S')
		{	
		    printf ("your total income is: $%d" ,temp_i.totalIncome);
			fprintf(ft, "                       %d\n",temp_i.totalIncome);
			fprintf(ft,"===============================================================================\n");
			system("cls");
			printf("Income Added Successfully!!!!!\n");
			printf("More entries  [y/n] ");
			ch=getche();
		}
	   
	totalBudget=temp_i.totalIncome;
	fclose(ft);
    return totalBudget; 
}
//============================================ABOUT================================================
void about()
{  
   int c;
   system("cls");
   do
   {
	printf("*****PERSONAL FINANCE ASSISTANCE*****\n");
	printf("     VERSION 1.0\n");
	printf("     DEVELOPED BY\n");
	printf("            NAME:SNEHA.G.P\n");
	printf("            USN: 1NH19CS172\n");
	printf("            SEM:III\n");
	printf("            SEC:C\n");
	printf("<<<<-Press 1 for main menu->>>>");
	c = (getche());
	switch (c)      //This 'SWITCH' structure will ask the user for input from [1] to [7] and will display error on Invalid Entry.
		{
			case '1': main_menu();
				puts("<<--ENTER FROM 1 PLEASE-->>");	//This message will only print on INVALID ENTRY and Will ask again for input.
				getch();
		}

   }while(c != '1');
		
}
//=====================================EXPENSE DETAILS========================================================
int addexpense(int totalBudget)
{
	char ch;
	time_t t;   // not a primitive datatype
    time(&t);
	ft=fopen("Myexpense.txt","a"); //it will append the data to the file
	if(ft==NULL)
	{
		printf("\n\t Can not open file!!\n ");
		exit(0);
	}
	system("cls");
	printf(" ****INSERT EXPENSE DETAILS****\n");
	printf("ADD EXPENSE\n");
	printf("UPDATE EXPENSE\n");
	printf("REMAINDER\n");
	printf("MAIN MENU\n");
	while(1)
	{
		printf("\nPress First Character for further Menu \n ");
		ch=toupper(getche());
		
	switch(ch)
    	{
    		case 'A':
    				printf("\nEnter your expense amount:$");
    				ventry(a,1);
					temp_e.amount= atoi(a);
					temp_e.Total_Expense=temp_e.Total_Expense+temp_e.amount;
					Total_Balance=totalBudget-temp_e.Total_Expense;
				    totalBudget=Total_Balance;
					if (temp_e.Total_Expense >= totalBudget)
				   {
				 		printf ("\nThe expenses was rejected because the budget exceeded.%d\n",totalBudget);
				 		exit(0);
				   }
			       else
				   {
				        printf("\nThe expenses was accepted, your remaining budget is: $%d\n",Total_Balance);	
				   }
				    printf("\n");
    				printf("Enter the category of expensed amount:");
    				ventry(temp_e.category,0);
					printf("\n");
				   	printf("OK\t");
				   	printf("Cancel\n");
	               	printf("Press First charecter for the operation :\n ");
				   	ch=getch();
	               	printf("press OK to confirm the income\n");
    			   	if(ch=='o' || ch=='O')
				  	{
						fprintf(ft,"%s  %d\n",temp_e.category,temp_e.amount);
						system("cls");
						printf("Expense Added Successfully!!!!!\n");
						printf("More entries  [y/n] ");
						ch=getche();
				  	}
				   break;  
			case 'R':
					user_remainder();
					break;   		
			case 'U':
					goto expense_update;
					break;	
			  
    		case 'M':main_menu();
    				break;
		}
	}
expense_update:
			printf("\n");
			system("cls");
			printf("\t");
			printf("Save\t");
			printf("Cancel\n");
			printf("Press First charecter for the operation :\n ");
			ch=getch();
			printf("press OK to confirm the  Total Expense\n");
    		if(ch=='s' || ch=='S')
			{
				fprintf(ft,"%s\n", ctime(&t));
				fprintf(ft,"===============================================================================\n");
				fprintf(ft, "                   %d\n",temp_e.Total_Expense);
				fprintf(ft,"===============================================================================\n");
				system("cls");
				printf("Total Expenses Added Successfully!!!!!\n");
				printf("More entries  [y/n] ");
				ch=getche();
			}	
			fclose(ft);
			//user_remainder();
		return totalBudget;	
}
//=============================================================================================================================
//=========================================================================================================================================
void user_remainder()
{
	char ch;
	int dd,mm,yyyy;
	int Mdays=30,count=0;
	time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
	ft=fopen("Myexpense.txt","r");
	if(ft==NULL)
	{
		printf("\n\t Can not open File! ");
	}
	while((fread(&temp_e,sizeof(temp_e),1,ft))==1)
	{
			temp_e.iday=now->tm_mday;
			temp_e.imonth=now->tm_mon;
			temp_e.iyear=now->tm_year;
			count=Mdays-temp_e.iday;
				if(count >=5 && count <=10)
				{
					printf("Still you need to manage another 1 0 days with this balance amount \n");
				} 
				else if (count >=15 && count <=20)
				{
					printf("Still you need to manage another 20 days with this balance amount\n");					
				}		
	}
	fclose(ft);
	ch=getche();
} 