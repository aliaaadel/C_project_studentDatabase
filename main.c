#include <stdio.h>
#include <stdlib.h>
#include "C_project.h"
#include <stdbool.h>
#include <stdint.h>

int main()
{
    unit8 id1 =22;
    unit8 year1=3;
    unit8 subject1[]={16,221,101};
    unit8 grades1[]={60,50,70};

    unit8 id2 =130;
    unit8 year2=2;
    unit8 subject2[]={331,121,441};
    unit8 grades2[]={80,40,90};


    unit8 id3=0;
    unit8 year3;
    unit8* subject3;
    unit8* grades3;

    SDB_isFull();
    SDB_AddEntry(id1,year1,subject1,grades1);
    SDB_AddEntry(id2,year2,subject2,grades2);

    SDB_GetUsedSize();
    SDB_IsIdExist(id1);
    SDB_DeleteEntry(id2);
    SDB_GetUsedSize();
    SDB_ReadEntry(id1,&year3,subject3,grades3);
    printf("id=%d\t year=%d\n",id1,year3);
    unit8 count ;
    unit8* list=NULL;
    SDB_GetIdList(&count,list);
    printf("count= %d ",count);


    return 0;
}
