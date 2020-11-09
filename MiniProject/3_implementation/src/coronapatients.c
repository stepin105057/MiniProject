#include "coronapatients.h"
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define corona struct patient
int count=256;
struct patient
{
 int id;
 char name[100];
 char state[12];
 char gender[10];
 char age[50];
 char psaddr[200];
 char prtaddr[200];
 char phone[15];
 char mail[20];
 char severity[30];
};


//====Welcome Screen=====

void welcome()
{
 printf("\n\n\n\n\n\t\t[ [ [ WELCOME TO CORONA PATIENTS DATABASE ] ] ]\n\n\n\n\n\n\n\t");
 system("pause");
}


//----printing character ch at n times ------

void printChar(char ch,int n)
{
 while(n--)
 {
 putchar(ch);
 }
}

//-----Printing Head Line of the program -----

void printHead()
{
system("cls");
printf("\t");
printChar('=',65);
printf("\n\t");
printChar('=',16);
printf("[CORONA] [PATIENTS] [DATABASE]");
printChar('=',16);
printf("\n\t");
printChar('=',65);

}

// ==========ADDING NEW RECORD==========================

void add(FILE * fp)
{
printHead();
printf("\n\t\t\t Add Corona Patient");
char another='y';
corona c;

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{
 printf("\n\n\t\tEnter ID number: ");
 scanf("%d",&c.id);
 printf("\n\n\t\tEnter Full Name of patient: ");
 fflush(stdin);
 fgets(c.name,100,stdin); //fgets takes an extra \n character as input
 c.name[strlen(c.name)-1]='\0';


 printf("\n\n\t\tEnter state: ");
 fflush(stdin);
 fgets(c.state,10,stdin); //fgets takes an extra \n character as input
 c.state[strlen(c.state)-1]='\0';


 printf("\n\n\t\tEnter Gender: ");
 fflush(stdin);
 fgets(c.gender,10,stdin); //fgets takes an extra \n character as input
 c.gender[strlen(c.gender)-1]='\0';

 printf("\n\n\t\tEnter Age: ");
 fflush(stdin);
 fgets(c.age,50,stdin);
 c.age[strlen(c.age)-1]='\0';

 printf("\n\n\t\tEnter Present Address: ");
 fflush(stdin);
 fgets(c.psaddr,200,stdin);
 c.psaddr[strlen(c.psaddr)-1]='\0';

 printf("\n\n\t\tEnter Permanant Address: ");
 fflush(stdin);
 fgets(c.prtaddr,200,stdin);
 c.prtaddr[strlen(c.prtaddr)-1]='\0';

 printf("\n\n\t\tEnter Phone: ");
 fflush(stdin);
 fgets(c.phone,15,stdin);
 c.phone[strlen(c.phone)-1]='\0';

 printf("\n\n\t\tEnter E-mail: ");
 fflush(stdin);
 fgets(c.mail,20,stdin);
 c.mail[strlen(c.mail)-1]='\0';

 printf("\n\n\t\tEnter severity: ");
 fflush(stdin);
 fgets(c.severity,30,stdin);
 c.severity[strlen(c.severity)-1]='\0';

 fwrite(&c,sizeof(c),1,fp);
 addbed();
 printf("\n\n\t\tWant to enter another patient info (Y/N)\t");
 fflush(stdin);
 another=getchar();
}

}


//===================DELETING A RECORD FROM LIST ============
FILE * del(FILE * fp)
{
 printHead();
printf("\n\t\t\t Delete record");
corona c;
int flag=0,tempid,siz=sizeof(c);
FILE *ft;

if((ft=fopen("temp.txt","wb+"))==NULL)
{
 printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
 system("pause");
 return fp;
}

printf("\n\n\tEnter ID  of patient to Delete the Record");
printf("\n\n\t\t\tID No. : ");
scanf("%d",&tempid);

rewind(fp);


while((fread(&c,siz,1,fp))==1)
{
 if(c.id==tempid)
 { flag=1;
 printf("\n\tRecord Deleted for");
 printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",c.name,c.state,c.id);
 deletebed();
 continue;
 }

 fwrite(&c,siz,1,ft);
}


fclose(fp);
fclose(ft);

remove("coronaInfo.txt");
rename("temp.txt","coronaInfo.txt");

if((fp=fopen("coronaInfo.txt","rb+"))==NULL)
{
 printf("ERROR");
 return NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}


//===========MODIFY A RECORD ===========================

void modify(FILE * fp)
{
printHead();
printf("\n\t\t\t Modify Employee");
corona c;
int flag=0,tempid,siz=sizeof(c);


printf("\n\n\tEnter ID  of patient to Modify the Record : ");
scanf("%d",&tempid);

rewind(fp);

while((fread(&c,siz,1,fp))==1)
{
 if(c.id==tempid)
 {flag=1;
 break;
 }
}

if(flag==1)
 {
 fseek(fp,-siz,SEEK_CUR);
 printf("\n\n\t\tRecord Found");
 printf("\n\n\t\tEnter New Data for the Record");

 printf("\n\n\t\tEnter ID number: ");
 scanf("%d",&c.id);

 printf("\n\n\t\tEnter Full Name of patient: ");
 fflush(stdin);
 fgets(c.name,100,stdin); //fgets takes an extra \n character as input
 c.name[strlen(c.name)-1]='\0';


 printf("\n\n\t\tEnter state: ");
 fflush(stdin);
 fgets(c.state,10,stdin); //fgets takes an extra \n character as input
 c.state[strlen(c.state)-1]='\0';


 printf("\n\n\t\tEnter Gender: ");
 fflush(stdin);
 fgets(c.gender,10,stdin); //fgets takes an extra \n character as input
 c.gender[strlen(c.gender)-1]='\0';

 printf("\n\n\t\tEnter Age: ");
 fflush(stdin);
 fgets(c.age,50,stdin);
 c.age[strlen(c.age)-1]='\0';

 printf("\n\n\t\tEnter Present Address: ");
 fflush(stdin);
 fgets(c.psaddr,200,stdin);
 c.psaddr[strlen(c.psaddr)-1]='\0';

 printf("\n\n\t\tEnter Permanant Address: ");
 fflush(stdin);
 fgets(c.prtaddr,200,stdin);//
 c.prtaddr[strlen(c.prtaddr)-1]='\0';

 printf("\n\n\t\tEnter Phone: ");
 fflush(stdin);
 fgets(c.phone,15,stdin);
 c.phone[strlen(c.phone)-1]='\0';

 printf("\n\n\t\tEnter E-mail: ");
 fflush(stdin);
 fgets(c.mail,20,stdin);
 c.mail[strlen(c.mail)-1]='\0';

 printf("\n\n\t\tEnter Severity: ");
 fflush(stdin);
 fgets(c.severity,30,stdin);
 c.severity[strlen(c.severity)-1]='\0';


 fwrite(&c,sizeof(c),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");
system("pause");

}

//====================DISPLAY THE LIST =================
void displayList(FILE * fp)
{ printHead();
printf("\n\t\t\t List of patients");
 corona c;
 int siz=sizeof(c);
 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tGENDER : %s",c.gender);
 printf("\n\n\t\tAGE : %s",c.age);
 printf("\n\n\t\tPRESENT ADDRESS : %s",c.psaddr);
 printf("\n\n\t\tPERMANANT ADDRESS : %s",c.prtaddr);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s\n\n\t",c.mail);
 printf("\n\n\t\tSEVERITY : %s\n\n\t",c.severity);
 printChar('=',65);
 }
 printf("\n\n\n\t");
 printf("\n\n\t");
 system("pause");
}


//================SEARCH EMPLOYEE==
void searchRecord(FILE *fp)
{printHead();
printf("\n\t\t\t Search patient");
int tempid,flag=0,siz;
corona c;
char another='y';

siz=sizeof(c);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID of patient to search the record : ");
scanf("%d",&tempid);

rewind(fp);

while((fread(&c,siz,1,fp))==1)
{
 if(c.id==tempid)
 {flag=1;
 break;
 }
}

if(flag==1)
 {
 printf("\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tAGE: %s",c.age);
 printf("\n\n\t\tPRESENT ADDRESS : %s",c.psaddr);
 printf("\n\n\t\tPERMANANT ADDRESS : %s",c.prtaddr);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s",c.mail);
 printf("\n\n\t\tSEVERITY : %s",c.severity);
 printChar('=',65);

}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}

//========================LIST OF MALE EMPLOYEE==
void malepatients(FILE * fp)
{
 printHead();
 printf("\n\t\t\t List of Male patient");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 if((strcmp(c.gender,"Male")==0)||(strcmp(c.gender,"male")==0))
 {

 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printChar('-',65);
 }
 }
 printf("\n\n\n\t");
 printChar('*',65);
 printf("\n\n\t");
 system("pause");
}


//========================LIST OF FEMALE EMPLOYEE==

void femalepatients(FILE * fp)
{
 printHead();
 printf("\n\t\t\t List of Female patients");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 if((strcmp(c.gender,"Female")==0)||(strcmp(c.gender,"female")==0))
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printChar('-',65);
 }
 }
 printf("\n\n\n\t");
 printChar('*',65);
 printf("\n\n\t");
 system("pause");
}

//========================LIST OF EMPLOYEE FROM TELANGANA====


void frmtelangana(FILE * fp)
{
 printHead();
 printf("\n\t\t\t List of patients From Telangana");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 if((strcmp(c.state,"Telangan")==0)||(strcmp(c.state,"telangan")==0)||(strcmp(c.state,"TELANGAN")==0))
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s",c.mail);
 printChar('=',65);
 }
 }
 printf("\n\n\n\t");
 printf("\n\n\t");
 system("pause");
}

//========================LIST OF EMPLOYEE FROM OTHER STATES====

void frmotherstates(FILE * fp)
{
 printHead();
 printf("\n\t\t\t List of patients From Others States");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 if((strcmp(c.state,"Telangan")!=0)&&(strcmp(c.state,"telangan")!=0)&&(strcmp(c.state,"TELANGAN")!=0))
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE: %s",c.state);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s",c.mail);
 printChar('=',65);
 }
 }
 printf("\n\n\n\t");
 printf("\n\n\t");
 system("pause");
}

//==============DISPLAY BASIC INFO LIST==

void displaybasic(FILE * fp)
{
printHead();
printf("\n\t\t\t Display Basic Information");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tGENDER : %s",c.gender);
 printf("\n\n\t\tAGE : %s",c.age);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s\n\n\t",c.mail);
 printf("\n\n\t\tSEVERITY : %s\n\n\t",c.severity);
 printChar('=',65);
 }
 printf("\n\n\n\t");
 printf("\n\n\t");
 system("pause");
}

//========BASIC CONTACT INFO LIST====

void basiccontact(FILE * fp)
{ printHead();
printf("\n\t\t\t Basic Contact Information");
 corona c;
 int siz=sizeof(c);

 rewind(fp);

 while((fread(&c,siz,1,fp))==1)
 {
 printf("\n\n\t\tID : %d",c.id);
 printf("\n\n\t\tNAME : %s",c.name);
 printf("\n\n\t\tSTATE : %s",c.state);
 printf("\n\n\t\tPHONE : %s",c.phone);
 printf("\n\n\t\tE-MAIL : %s\n\n\t",c.mail);
 printChar('=',65);
 }
 printf("\n\n\n\t");
 printf("\n\n\t");
 system("pause");
}

//add beds
int addbed(){
count= count-1;
return 0;
}

//delete beds
int deletebed()
{
count=count+1;
printf("Count is %d",count);
return 0;
}

//bedavailability
int bed()
{
printf("\n\n\t\t\tNumber of beds available is/are: %d\n",count);
return 0;
}





