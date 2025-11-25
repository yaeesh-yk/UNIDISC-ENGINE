#ifndef UNIDISCENGINE_H
#define UNIDISCENGINE_H

#include "CourseScheduler.h"
#include "Student.h"
#include "Faculty.h"
#include "LogicEngine.h"

class UNIDISCEngine {
private:
    CourseScheduler scheduler;
    Student* students;
    Faculty* faculties;
    int studentCount;
    int facultyCount;
    int maxStudents;
    int maxFaculties;
    LogicEngine logicEngine;
public:
    UNIDISCEngine();
    ~UNIDISCEngine();
    void addStudent(int id, const char* name);
    void addFaculty(int id, const char* name);
    void demonstrateAllModules();
    void displayMenu();
    void run();
};

#endif