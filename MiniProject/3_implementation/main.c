#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include "coronapatients.h"

#define corona struct patient

int main()

{
 FILE * fp;

int option;


if((fp=fopen("coronaInfo.txt","rb+"))==NULL)
{
 if((fp=fopen("coronaInfo.txt","wb+"))==NULL)
 {
 printf("can't open file");
 return 0;
 }
}
char username[10],password[10];
printHead();
welcome();
printHead();
printf("\n\t\t\t\t Login Screen");
printf("\n\t\t\t Enter Your Credential");
printf("\n\n\n\t\tUsername: ");
scanf("%s", username);
printf("\n\t\tPassword: ");
int i;
i=0;
	do
	{
	password[i] = getch();
	if(password[i] == 13 )
	{
	break;
	}
	else if(password[i]==8 && i>0)
	{
	printf("%c%c%c",8,32,8);
	i--;
	}
	else
	{
	printf("*");
	i++;
	}
	}while(password[i]!=13);
	password[i] = '\0';

if(((strcasecmp(username,"admin"))==0)&&((strcasecmp(password,"pass")==0)))
{
 while(1)
{

 printHead();
 printf("\n\t\t\t\tMain Menu");
 printf("\n\n\n");


 printf("\n\n\t\t\t1. Add Info");
 printf("\n\n\t\t\t2. Delete record");
 printf("\n\n\t\t\t3. Modify Info");
 printf("\n\n\t\t\t4. Display corona patient's List");
 printf("\n\n\t\t\t5. Search Record");
 printf("\n\n\t\t\t6. Display Basic Info");
 printf("\n\n\t\t\t7. Display Basic Contact Info");
 printf("\n\n\t\t\t8. List of Male patients");
 printf("\n\n\t\t\t9. List of Female patients");
 printf("\n\n\t\t\t10. List of patient's From Telangana");
 printf("\n\n\t\t\t11. List of patient's From Others state's");
 printf("\n\n\t\t\t0. EXIT");
bed();
 printf("\n\n\t\tEnter Your Option :--> ");
 scanf("%d",&option);


 switch(option)
 {
 case 0: return 1;
 break;
 case 1: add(fp);
 break;
 case 2: fp=del(fp);
 break;
 case 3: modify(fp);
 break;
 case 4: displayList(fp);
 break;
 case 5: searchRecord(fp);
 break;
 case 6: displaybasic(fp);
 break;
 case 7: basiccontact(fp);
 break;
 case 8: malepatients(fp);
 break;
 case 9: femalepatients(fp);
 break;
 case 10: frmtelangana(fp);
 break;
 case 11: frmotherstates(fp);
 break;
 default: printf("\n\t\tYou Pressed wrong key");
 printf("\n\t\tProgram terminated");
 getch();
 exit(0);

 }
}
}
else {
 printf("\n\t\tLogin Failed");

}
return 1;

}



