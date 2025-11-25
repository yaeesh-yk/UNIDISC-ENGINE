#include "Student.h"
#include <cstring>

Student::Student() : id(0) {
    name[0] = '\0';
}

Student::Student(int sid, const char* sname) : id(sid) {
    strcpy_s(name, sizeof(name), sname);
}

void Student::enrollCourse(int courseId) {
    enrolledCourses.add(courseId);
}

void Student::completeCourse(int courseId) {
    completedCourses.add(courseId);
    enrolledCourses.remove(courseId);
}