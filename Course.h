#ifndef COURSE_H
#define COURSE_H

#include "DynamicArray.h"

class Course {
public:
    int id;
    char name[100];
    DynamicArray prerequisites;
    int credits;
    Course();
    Course(int cid, const char* cname, int cr = 3);
    void addPrerequisite(int prereqId);
};

#endif