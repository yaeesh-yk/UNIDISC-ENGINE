#include "CourseScheduler.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

bool CourseScheduler::hasPrerequisites(int courseId, const DynamicArray& completed) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {
            for (int j = 0; j < courses[i].prerequisites.getSize(); j++) {
                if (!completed.contains(courses[i].prerequisites.get(j))) {
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

void CourseScheduler::generateSequencesHelper(DynamicArray& completed, DynamicArray& remaining, int depth) {
    if (remaining.getSize() == 0) {
        setColor(10);
        cout << "Valid Sequence: ";
        completed.print();
        cout << endl;
        setColor(15);
        return;
    }
    if (depth > 20) return;
    for (int i = 0; i < remaining.getSize(); i++) {
        int courseId = remaining.get(i);
        if (hasPrerequisites(courseId, completed)) {
            completed.add(courseId);
            DynamicArray newRemaining;
            for (int j = 0; j < remaining.getSize(); j++) {
                if (j != i) newRemaining.add(remaining.get(j));
            }
            generateSequencesHelper(completed, newRemaining, depth + 1);
            completed.remove(courseId);
        }
    }
}

CourseScheduler::CourseScheduler() : courseCount(0), maxCourses(50) {
    courses = new Course[maxCourses];
}

CourseScheduler::~CourseScheduler() {
    delete[] courses;
}

void CourseScheduler::addCourse(int id, const char* name, int credits) {
    if (courseCount < maxCourses) {
        courses[courseCount++] = Course(id, name, credits);
    }
}

void CourseScheduler::addPrerequisite(int courseId, int prereqId) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == courseId) {
            courses[i].addPrerequisite(prereqId);
            return;
        }
    }
}

void CourseScheduler::generateValidSequences() {
    DynamicArray completed;
    DynamicArray remaining;
    for (int i = 0; i < courseCount; i++) {
        remaining.add(courses[i].id);
    }
    setColor(11);
    cout << "\n=== GENERATING VALID COURSE SEQUENCES ===\n";
    setColor(15);
    generateSequencesHelper(completed, remaining, 0);
}

bool CourseScheduler::canTakeCourse(int courseId, const DynamicArray& completedCourses) {
    return hasPrerequisites(courseId, completedCourses);
}

Course* CourseScheduler::getCourse(int id) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == id) return &courses[i];
    }
    return nullptr;
}

int CourseScheduler::getCourseCount() const { return courseCount; }