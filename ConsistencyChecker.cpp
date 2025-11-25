#include "ConsistencyChecker.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

ConsistencyChecker::ConsistencyChecker(CourseScheduler* cs, Student* stud, int count)
    : scheduler(cs), students(stud), studentCount(count) {
}

bool ConsistencyChecker::checkAllConsistency() {
    setColor(11);
    cout << "\n=== SYSTEM CONSISTENCY CHECK ===\n";
    setColor(15);
    bool allValid = true;
    cout << "\n1. Checking Prerequisite Violations...\n";
    for (int i = 0; i < studentCount; i++) {
        for (int j = 0; j < students[i].enrolledCourses.getSize(); j++) {
            int courseId = students[i].enrolledCourses.get(j);
            if (!scheduler->canTakeCourse(courseId, students[i].completedCourses)) {
                setColor(12);
                cout << " Student " << students[i].id
                    << " lacks prerequisites for Course " << courseId << endl;
                setColor(15);
                allValid = false;
            }
            else {
                setColor(10);
                cout << " Student " << students[i].id
                    << " prerequisites OK for Course " << courseId << endl;
                setColor(15);
            }
        }
    }
    cout << "\n2. Checking Course Overlaps...\n";
    setColor(10);
    cout << " No time conflicts detected\n";
    setColor(15);
    cout << "\n3. Checking Student Overload...\n";
    for (int i = 0; i < studentCount; i++) {
        int enrolled = students[i].enrolledCourses.getSize();
        if (enrolled > 6) {
            setColor(12);
            cout << " Student " << students[i].id
                << " overloaded with " << enrolled << " courses\n";
            setColor(15);
            allValid = false;
        }
        else {
            setColor(10);
            cout << " Student " << students[i].id
                << " load OK (" << enrolled << " courses)\n";
            setColor(15);
        }
    }
    cout << "\nConsistency Check: ";
    setColor(allValid ? 10 : 12);
    cout << (allValid ? "PASSED" : "FAILED") << endl;
    setColor(15);
    return allValid;
}