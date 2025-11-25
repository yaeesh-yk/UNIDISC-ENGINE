#include "InductionVerifier.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

bool InductionVerifier::verifyBaseCase(int courseId, const DynamicArray& completed) {
    Course* course = scheduler->getCourse(courseId);
    if (!course) return false;
    if (course->prerequisites.getSize() == 0) return true;
    for (int i = 0; i < course->prerequisites.getSize(); i++) {
        if (!completed.contains(course->prerequisites.get(i))) {
            return false;
        }
    }
    return true;
}

bool InductionVerifier::verifyInductiveStep(int courseId, const DynamicArray& completed) {
    Course* course = scheduler->getCourse(courseId);
    if (!course) return false;
    for (int i = 0; i < course->prerequisites.getSize(); i++) {
        int prereqId = course->prerequisites.get(i);
        if (!completed.contains(prereqId)) {
            return false;
        }
        if (!verifyInductiveStep(prereqId, completed)) {
            return false;
        }
    }
    return true;
}

InductionVerifier::InductionVerifier(CourseScheduler* cs) : scheduler(cs) {}

bool InductionVerifier::verifyPrerequisiteChain(int courseId, const DynamicArray& completed) {
    setColor(11);
    cout << "\n=== INDUCTION VERIFICATION FOR COURSE " << courseId << " ===\n";
    setColor(15);
    cout << "Base Case: ";
    if (!verifyBaseCase(courseId, completed)) {
        setColor(12);
        cout << "FAILED - Missing direct prerequisites\n";
        setColor(15);
        return false;
    }
    setColor(10);
    cout << "PASSED\n";
    setColor(15);
    cout << "Inductive Step (Strong Induction): ";
    if (!verifyInductiveStep(courseId, completed)) {
        setColor(12);
        cout << "FAILED - Missing indirect prerequisites\n";
        setColor(15);
        return false;
    }
    setColor(10);
    cout << "PASSED\n";
    cout << "Verification: SUCCESS\n";
    setColor(15);
    return true;
}