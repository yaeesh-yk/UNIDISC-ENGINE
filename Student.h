#ifndef STUDENT_H
#define STUDENT_H

#include "DynamicArray.h"

class Student {
public:
    int id;
    char name[100];
    DynamicArray enrolledCourses;
    DynamicArray completedCourses;
    Student();
    Student(int sid, const char* sname);
    void enrollCourse(int courseId);
    void completeCourse(int courseId);
};

#endif