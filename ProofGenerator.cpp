#include "ProofGenerator.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

void ProofGenerator::generatePrerequisiteProof(int courseId, const DynamicArray& completed, CourseScheduler* scheduler) {
    setColor(11);
    cout << "\n=== FORMAL PROOF: PREREQUISITE VERIFICATION ===\n";
    setColor(15);
    cout << "Theorem: Student can take Course ";
    setColor(13);
    cout << courseId << endl;
    setColor(15);
    cout << "Given: Completed courses = ";
    completed.print();
    cout << endl;
    Course* course = scheduler->getCourse(courseId);
    if (!course) {
        setColor(12);
        cout << "Proof: INVALID - Course not found\n";
        setColor(15);
        return;
    }
    setColor(11);
    cout << "\nProof by Mathematical Induction:\n";
    setColor(15);
    cout << "Step 1: Base Case - Verify direct prerequisites\n";
    bool allSatisfied = true;
    for (int i = 0; i < course->prerequisites.getSize(); i++) {
        int prereq = course->prerequisites.get(i);
        if (completed.contains(prereq)) {
            setColor(10);
            cout << " Prerequisite " << prereq << " satisfied\n";
        }
        else {
            setColor(12);
            cout << " Prerequisite " << prereq << " NOT satisfied\n";
            allSatisfied = false;
        }
    }
    setColor(15);
    if (!allSatisfied) {
        setColor(12);
        cout << "\nProof: FAILED\n";
        setColor(15);
        return;
    }
    setColor(11);
    cout << "\nStep 2: Inductive Hypothesis - All prerequisites satisfied\n";
    cout << "Step 3: Conclusion - Student may enroll in Course " << courseId << "\n";
    setColor(10);
    cout << "\nProof: COMPLETE \n";
    setColor(15);
}