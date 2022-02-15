#include <stdio.h>
#include <stdlib.h>
#include "C_project.h"
#include <stdbool.h>
#include <stdint.h>

st SDB[10];// array of structure for database

static unit8 entry_num =0; // static int for numbers of entry

bool SDB_isFull(void)
{
    if (entry_num==9){ // check if the array is full
        printf("Database is full\n");
        return true;
    }
    else{
        printf("Database isn't full\n");
        return false;
    }
}

unit8 SDB_GetUsedSize(void)
{

    printf("number of entries = %d\n", entry_num);
    return entry_num;

}

bool SDB_AddEntry(unit8 id , unit8 Year, unit8* subject, unit8* grades)
{
    unit8 j=0;
    int flag=0;
    printf("Add new entry\n");
    st student; // initialize struct to hold valuew
    student.ID=id;
    student.year= Year;
    puts("student info added");
    for(unit8 j =0 ; j<3 ; j++){
        printf("course %d added\n",j+1);
        student.subjects[j].ID= *subject;
        subject++;
        if (*grades >= 0 && *grades<=100) // grade out of range assign it to 0
        {
            student.subjects[j].grade= *grades;
        }
        else{
            puts("Wrong grade value");
            student.subjects[j].grade= 0;
        }
        grades++;
        flag++;
    }

   if (flag == 3){
        SDB[entry_num] = student;
        entry_num++;
        puts("successful entry");
        return true;

    }
    else
    {
        puts("unsuccessful entry");
        return false;
    }
}
void SDB_DeleteEntry(unit8 id)
{

    for (unit8 i =0 ; i<= entry_num;i++){
        if (SDB[i].ID == id){ // to delete an entry get the index of struct
            for(unit8 j= i ;j<= entry_num-1;j++ )// then shift it
            {
                SDB[j]=SDB[j+1];
            }
            puts("Entry deleted");
            entry_num --;
            break;
        }
        else{
            continue;
        }


    }

}

bool SDB_ReadEntry(unit8 id, unit8* Year , unit8* subject ,unit8* grades)
{
    bool flag= false;
    unit8 tmp_grade[3];// array to store subject grade
    unit8 tmp_subject[3];// store subject ids
    for (unit8 i =0 ; i<= entry_num;i++){
        if (SDB[i].ID == id){ // loop throught the array of struct to find id
            flag= true;
            puts("ID found");
            unit8 tmp= SDB[i].year;
            *Year = tmp;
            for (unit8 j=0 ;j<3 ; j++){ // loop through subject values and assign it to arrays
                tmp_subject[j]= SDB[i].subjects[j].ID;
                tmp_grade[j]= SDB[i].subjects[j].grade;
            }
            subject=tmp_subject;
            grades= tmp_grade;
            break;
        }
        else{
            continue;
        }
    }
    return flag;

}
void SDB_GetIdList(unit8* count, unit8* list)
{
    *count=1;
    puts("getting id list");
    unit8 Ids[entry_num];  // make an array == size of entries
    for (unit8 i =0 ; i<= entry_num;i++){
         Ids[i]= SDB[i].ID;
    }
    list = Ids; // assign array to pointer
    *count = sizeof(Ids)/sizeof(Ids[0]);
}
bool SDB_IsIdExist(unit8 id)
{
    bool flag = false;
    for (unit8 i =0 ; i<= entry_num;i++){
        if (SDB[i].ID ==id){ // loop through struct if id is found return true
            flag= true;
            puts("this ID exists");
            break;
        }
        else{
            continue;
        }
    }
    return flag;
}
