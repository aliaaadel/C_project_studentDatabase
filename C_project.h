#ifndef C_PROJECT_H_INCLUDED
#define C_PROJECT_H_INCLUDED
#include <stdbool.h>
#include <stdint.h>
typedef unsigned int unit8;
typedef struct course {

    unit8 ID;
    unit8 grade;

} course;
typedef struct st {

    unit8 ID;
    unit8 year;
    struct course subjects[3];

} st;
bool SDB_isFull(void);
unit8 SDB_GetUsedSize(void);
bool SDB_AddEntry(unit8 id , unit8 year, unit8* subject, unit8* grades);
void SDB_DeleteEntry(unit8 id);
bool SDB_ReadEntry(unit8 id, unit8* year , unit8* subjects ,unit8* grade);
void SDB_GetIdList(unit8* , unit8* );
bool SDB_IsIdExist(unit8 id);

#endif // C_PROJECT_H_INCLUDED
