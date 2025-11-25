#ifndef CONSISTENCYCHECKER_H
#define CONSISTENCYCHECKER_H

#include "CourseScheduler.h"
#include "Student.h"

class ConsistencyChecker {
private:
    CourseScheduler* scheduler;
    Student* students;
    int studentCount;
public:
    ConsistencyChecker(CourseScheduler* cs, Student* stud, int count);
    bool checkAllConsistency();
};

#endif