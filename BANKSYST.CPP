#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

struct customers{
		  char AccountNo[11];
		  long long float AB;   //AB:- account balance....
		  char Name[20];

		  };
typedef struct customers CUSTOMERS;

int main()
{
 FILE *fp,*ft;
 char another,choise;
 CUSTOMERS c;
 char custName[40];
 long int recsize;
 long long float amount;
 char AN[10];
 clrscr();
 fp=fopen("CUST.DAT","rb+");
 if(fp==NULL)
{
fp=fopen("CUST.DAT","wb+");

if(fp==NULL)
{
puts("cannot open file");
exit(1);
}
}
recsize=sizeof(c);
while(1)
{clrscr();
gotoxy(30,10);
printf("1.Add Details of customers");
gotoxy(30,11);
printf("2.Details of customer with balance below 100");
gotoxy(30,12);
printf("3.Modify Details of customer");
gotoxy(30,13);
printf("4.Deposit");
gotoxy(30,14);
printf("5.Withdrawl");
gotoxy(30,15);
printf("6.Balance Inquiry");
gotoxy(30,16);
printf("0.exit");
gotoxy(30,17);
printf("Your Choise ");
fflush(stdin);
choise=getche();
switch(choise)
{
case '1': clrscr();
fseek(fp,0,SEEK_END);
another='y';
while(another=='y')
{
printf("\nEnter AccountNo  ");
fflush(stdin);
gets(c.AccountNo);
printf("\nEnter Account Balance=   ");
fflush(stdin);
scanf("%llf",&c.AB);
printf("\nEnter Name  ");
fflush(stdin);
gets(c.Name);

fwrite(&c,recsize,1,fp);
printf("\nAdd another record(y/n)");
fflush(stdin);
another=getche();
}
break;


case'2':clrscr();
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(c.AB<100)
{printf("\nAccount Number= ");
puts(c.AccountNo);
printf("Account Balance= %llf\n",c.AB);
printf("Name= ");
puts(c.Name);
}
}
getch();
break;

case'3': clrscr();
another='y';
while(another=='y')
{
printf("\nenter the name of customer to modify ");
gets(custName);
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(strcmp(c.Name,custName)==0)
{clrscr();
printf("\nEnter AccountNo  ");
gets(c.AccountNo);
printf("\nEnter Account Balance  ");
fflush(stdin);
scanf("%llf",&c.AB);
printf("\nEnter Name  ");
fflush(stdin);
gets(c.Name);
fseek(fp,-recsize,SEEK_CUR);
fwrite(&c,recsize,1,fp);
break;
}
}
printf("\Modify another record(y/n) ");
fflush(stdin);
another=getche();

} break;

case '4': clrscr();
printf("Enter account number ");
fflush(stdin);
gets(AN);
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(strcmp(c.AccountNo,AN)==0)
{
printf("Enter amount to deposit ");
fflush(stdin);
scanf("%llf",&amount);
c.AccountNo[0]=AN[0];
c.AB=c.AB+amount;
c.Name[0]=c.Name[0];
fseek(fp,-recsize,SEEK_CUR);
fwrite(&c,recsize,1,fp);
}
}break;


case '5': clrscr();
printf("Enter account number ");
fflush(stdin);
gets(AN);
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(strcmp(c.AccountNo,AN)==0)
{
printf("Enter amount to withdrawl ");
fflush(stdin);
scanf("%llf",&amount);
if(amount>c.AB)
{printf("Insufficient Balance!");
delay(2000);}
else
{c.AccountNo[0]=AN[0];
c.AB=c.AB-amount;
c.Name[0]=c.Name[0];
fseek(fp,-recsize,SEEK_CUR);
fwrite(&c,recsize,1,fp);}
}
}break;

case'6':clrscr();
printf("Enter account number ");
fflush(stdin);
gets(AN);
rewind(fp);
while(fread(&c,recsize,1,fp)==1)
{
if(strcmp(c.AccountNo,AN)==0)
{
printf("Account Balance= %llf\n",c.AB);
printf("Name= ");
puts(c.Name);
}
}
getch();
break;



case '0':exit(0);
}
}
}




