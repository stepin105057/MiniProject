/**
* @file coronapatients.h
*
*/
#ifndef __CORONAPATIENTS_H__INCLUDED
#define __CORONAPATIENTS_H__INCLUDED
#ifndef __CORONAPATIENTS_H__
#define __CORONAPATIENTS_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>


/**
* print welcome screen
*/
void welcome();
/**
* to add records to the list
*/
void add(FILE * fp);
/**
* to delete record from the list
* This requires id of which you want to delete
*/
FILE * del(FILE * fp);
/**
* to modify a record of the list
* this requires the id of record which you want to modify
*/
void modify(FILE * fp);
/**
* display whole list of records
*/
void displayList(FILE * fp);
/**
* find a particular record
* this requires a id of record which you want to search
*/
void searchRecord(FILE *fp);
/**
* print male patients list of records
*/
void malepatients(FILE * fp);
/**
* print female patients list of records
*/
void femalepatients(FILE * fp);
/**
* print patients list of records who are from telangana
*/
void frmtelangana(FILE * fp);
/**
* print patients list of records who are from other states
*/
void frmotherstates(FILE * fp);
/**
* print basic information of patients list
*/
void displaybasic(FILE * fp);
/**
*print basic contact information of patients list
*/
void basiccontact(FILE * fp);
/**
* printing a character ch n times
*/
void printChar(char ch,int n);
/**
* print headline of the program
*/
void printHead();
/** adding beds as records add on
*/
int addbed();
/**
* deleting beds as records delete
*/
int deletebed();
/** print beds availability information
*/
int bed();
#endif
#endif


