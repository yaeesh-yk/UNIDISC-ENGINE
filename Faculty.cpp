#include "Faculty.h"
#include <cstring>

Faculty::Faculty() : id(0) {
    name[0] = '\0';
}

Faculty::Faculty(int fid, const char* fname) : id(fid) {
    strcpy_s(name, sizeof(name), fname);
}

void Faculty::assignCourse(int courseId) {
    assignedCourses.add(courseId);
}