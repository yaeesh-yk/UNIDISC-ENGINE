#ifndef COURSESCHEDULER_H
#define COURSESCHEDULER_H

#include "Course.h"
#include "DynamicArray.h"

class CourseScheduler {
private:
    Course* courses;
    int courseCount;
    int maxCourses;
    bool hasPrerequisites(int courseId, const DynamicArray& completed);
    void generateSequencesHelper(DynamicArray& completed, DynamicArray& remaining, int depth);
public:
    CourseScheduler();
    ~CourseScheduler();
    void addCourse(int id, const char* name, int credits = 3);
    void addPrerequisite(int courseId, int prereqId);
    void generateValidSequences();
    bool canTakeCourse(int courseId, const DynamicArray& completedCourses);
    Course* getCourse(int id);
    int getCourseCount() const;
};

#endif