#include "Course.h"
#include <cstring>

Course::Course() : id(0), credits(3) {
    name[0] = '\0';
}

Course::Course(int cid, const char* cname, int cr) : id(cid), credits(cr) {
    strcpy_s(name, sizeof(name), cname);
}

void Course::addPrerequisite(int prereqId) {
    prerequisites.add(prereqId);
}