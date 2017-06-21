#include"banking.h"


int main()
{
	time_t t1;
	time_t t2;
	t1=time(NULL);
	struct s e;
	FILE* fp;
	int i,w,v,j=0,k,x=0,nol=0;
	int l,z,p,si,r,wd,de;
	char a[100],g[100],ch;
	char another='y';


m:
    printf("WELCOME TO OUR BANK\n");
	printf("1.Login\n\n2.create an account\n");
	scanf("%d",&i);
	system("cls");

	switch(i)
{
case 1:
fp=fopen("bank.txt","r+");
	fflush(stdin);
	printf("\n enter your user id=");
	gets(a);
	printf("Enter the password <any 8 characters>:\n ");

 for(i=0;i<8;i++)
 {
  ch = getch();
  g[i] = ch;
  ch = '*' ;
  printf("%c",ch);
 }

 g[i]= '\0';
rewind(fp);
	while(fread(&e,sizeof(e),1,fp)==1)
{
	w=strcmp(a,e.username);
	v=strcmp(g,e.password);


	if(w==0&&v==0)
{p=t1-e.time;
if(p<0)
p=-p;

si=(e.amount*0.09*p)/100;

e.amount=e.amount+si;
printf("\nyour acount balance is rs %d",e.amount);
system("PAUSE");
system("cls");

fseek(fp,-sizeof(e),SEEK_CUR);
fwrite(&e,sizeof(e),1,fp);
printf("what you want to do?\n\n1.withdrawal money\n2. deposit money\n3.account information\n4.exit\n");
scanf("%d",&r);
switch(r)
{
case 1:
		fseek(fp,-sizeof(e),SEEK_CUR);
    fread(&e,sizeof(e),1,fp);
    system("cls");
    printf("enter amount you want to withdraw\n");
    scanf("%d",&wd);
    if(wd>e.amount)
        printf("insufficient amount\n");
    else
        e.amount=e.amount-wd;
        printf("your acount balance is rs %d",e.amount);
         fseek(fp,-sizeof(e),SEEK_CUR);
         fwrite(&e,sizeof(e),1,fp);
         exit(3);

         break;

case 2:

     fseek(fp,-sizeof(e),SEEK_CUR);
    fread(&e,sizeof(e),1,fp);
    system("cls");
	printf("enter amount you want to deposit\n");
    scanf("%d",&de);
    e.amount=e.amount+de;
     printf("your acount balance is rs %d",e.amount);
         fseek(fp,-sizeof(e),SEEK_CUR);
         fwrite(&e,sizeof(e),1,fp);
         exit(2);
    break;
case 3:
			system("cls");
	printf("your name is \n\t%s\n\n",e.name);
	printf("your address is \n\t%s\n\n",e.address);
	printf("your mobile no. is \n\t%s\n\n",e.mobile);
	printf("your user id is \n\t%s\n\n",e.username);
	printf("main balance is \n\t%d\n\n",e.amount);
	printf("gender \n\t%s\n\n",e.gender);
	exit(1);
	break;

case 4:
    break;


}




break;
}


}
if(fscanf(fp,"%s%s%s%s%s%s%d%d",&e.name,&e.address,&e.gender,&e.mobile,&e.username,&e.password,&e.time,&e.amount)==EOF)

{
printf("\nyour account does not exist");


}
break;







case 2:

	create_acc();
		goto m;
	}
	fclose(fp);

}


