#include"banking.h"


void create_acc(){


		time_t t1;
	time_t t2;
	t1=time(NULL);
	struct s e;
	FILE* fp;
	int i,w,v,j=0,k,x=0,nol=0;
	int l,z,p,si,r,wd,de;
	char a[100],g[100],mf,ch;
	char another='y';
	fp=fopen("bank.txt","a+");

		while(another=='y')
		{
		printf(" enter your name:");
		fflush(stdin);
		gets(e.name);
		printf("\n enter your adderess:" );
		gets(e.address);
		printf("\ngender\nM/F:\n");
		scanf("%s",&e.gender);
		printf("\n enter your mobile number :");
		scanf("%s",&e.mobile);
		printf("\n enter your user id:");
		scanf("%s",&e.username);
	printf("Enter the password <any 8 characters>: ");

 for(i=0;i<8;i++)
 {
  ch = getch();
  e.password[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }

 e.password [i]= '\0';

 /*If you want to know what you have entered as password, you can print it*/
 printf("\nYour password is :");

 for(i=0;i<8;i++)
 {
  printf("%c",e.password[i]);
 }
getch();
		fflush(stdin);
		t2=time(NULL);
		e.time=t2;
		system("cls");

		printf("\t\t******WELCOME*****\n\n");
		printf("\t\t****your account has been created**** \n");
		printf("enter amount you want to deposit\n");
		scanf("%d",&e.amount);
		fwrite(&e,sizeof(e),1,fp);
		system("cls");
		printf("do you want to create another account y/n\n");
		fflush(stdin);
		another=getche();
		system("cls");

	}
fclose(fp);
}


