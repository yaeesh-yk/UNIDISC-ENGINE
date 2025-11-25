#ifndef FACULTY_H
#define FACULTY_H

#include "DynamicArray.h"

class Faculty {
public:
    int id;
    char name[100];
    DynamicArray assignedCourses;
    Faculty();
    Faculty(int fid, const char* fname);
    void assignCourse(int courseId);
};

#endif