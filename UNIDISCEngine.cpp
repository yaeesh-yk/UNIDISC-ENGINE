#include "UNIDISCEngine.h"
#include "StudentGroupManager.h"
#include "InductionVerifier.h"
#include "SetOperations.h"
#include "Relation.h"
#include "FunctionMapper.h"
#include "ProofGenerator.h"
#include "ConsistencyChecker.h"
#include "Benchmarker.h"
#include "ConsoleColour.h"
#include <iostream>
#include <cstring>
using namespace std;

UNIDISCEngine::UNIDISCEngine() : studentCount(0), facultyCount(0), maxStudents(100), maxFaculties(50) {
    students = new Student[maxStudents];
    faculties = new Faculty[maxFaculties];
}

UNIDISCEngine::~UNIDISCEngine() {
    delete[] students;
    delete[] faculties;
}

void UNIDISCEngine::addStudent(int id, const char* name) {
    if (studentCount < maxStudents) {
        students[studentCount++] = Student(id, name);
    }
}

void UNIDISCEngine::addFaculty(int id, const char* name) {
    if (facultyCount < maxFaculties) {
        faculties[facultyCount++] = Faculty(id, name);
    }
}

void UNIDISCEngine::demonstrateAllModules() {
    cout << "\n";
    setColor(14);
    cout << "=====================================================\n";
    cout << "| UNIDISC ENGINE - FAST UNIVERSITY |\n";
    cout << "| Discrete Structures Computational Framework |\n";
    cout << "=====================================================\n";
    setColor(15);

    // Module 1: Course Scheduling
    scheduler.addCourse(101, "Intro to CS", 3);
    scheduler.addCourse(102, "Data Structures", 3);
    scheduler.addCourse(103, "Algorithms", 3);
    scheduler.addCourse(201, "Database Systems", 3);
    scheduler.addPrerequisite(102, 101);
    scheduler.addPrerequisite(103, 102);
    scheduler.addPrerequisite(201, 102);
    scheduler.generateValidSequences();

    // Module 2: Student Groups
    StudentGroupManager groupMgr;
    int studentIds[] = { 1, 2, 3, 4, 5 };
    groupMgr.generateGroups(studentIds, 5, 3);

    // Module 3: Induction Verification
    addStudent(1, "Alice");
    addStudent(2, "Bob");
    students[0].completeCourse(101);
    students[0].completeCourse(102);
    InductionVerifier inductionVerifier(&scheduler);
    inductionVerifier.verifyPrerequisiteChain(103, students[0].completedCourses);

    // Module 4: Logic Engine
    logicEngine.addRule("Professor X teaches CS101", "Lab must be Lab A");
    logicEngine.addRule("Student enrolled in CS102", "Must have completed CS101");
    logicEngine.addRule("Course has 30+ students", "Require additional section");
    logicEngine.performInference();
    logicEngine.checkConflicts();

    // Module 5: Set Operations
    setColor(11);
    cout << "\n=== SET OPERATIONS DEMONSTRATION ===\n";
    setColor(15);
    SetOperations cs101Students, math101Students;
    cs101Students.add(1); cs101Students.add(2); cs101Students.add(3); cs101Students.add(4);
    math101Students.add(3); math101Students.add(4); math101Students.add(5); math101Students.add(6);
    cout << "CS101 Students: "; cs101Students.print(); cout << endl;
    cout << "MATH101 Students: "; math101Students.print(); cout << endl;
    SetOperations* bothCourses = cs101Students.intersection(math101Students);
    cout << "Students in BOTH courses: "; bothCourses->print(); cout << endl;
    SetOperations* allStudents = cs101Students.unionWith(math101Students);
    cout << "All students (Union): "; allStudents->print(); cout << endl;
    SetOperations* onlyCS = cs101Students.difference(math101Students);
    cout << "Only CS101: "; onlyCS->print(); cout << endl;
    delete bothCourses;
    delete allStudents;
    delete onlyCS;

    // Module 6: Relations
    setColor(11);
    cout << "\n=== RELATIONS MODULE ===\n";
    setColor(15);
    Relation coursePrereqRelation(4);
    coursePrereqRelation.addRelation(0, 0);
    coursePrereqRelation.addRelation(1, 1);
    coursePrereqRelation.addRelation(2, 2);
    coursePrereqRelation.addRelation(3, 3);
    coursePrereqRelation.addRelation(0, 1);
    coursePrereqRelation.addRelation(1, 2);
    coursePrereqRelation.addRelation(0, 2);
    coursePrereqRelation.print();
    coursePrereqRelation.analyzeProperties();

    // Module 7: Functions
    setColor(11);
    cout << "\n=== FUNCTIONS MODULE ===\n";
    setColor(15);
    FunctionMapper courseToFaculty(5, 3);
    courseToFaculty.setMapping(0, 0);
    courseToFaculty.setMapping(1, 1);
    courseToFaculty.setMapping(2, 2);
    courseToFaculty.setMapping(3, 0);
    courseToFaculty.setMapping(4, 1);
    courseToFaculty.printMapping();
    courseToFaculty.analyzeFunction();

    // Module 8: Automated Proof
    ProofGenerator proofGen;
    proofGen.generatePrerequisiteProof(103, students[0].completedCourses, &scheduler);

    // Module 9: Consistency Checker
    students[0].enrollCourse(103);
    students[1].enrollCourse(102);
    ConsistencyChecker checker(&scheduler, students, studentCount);
    checker.checkAllConsistency();

    // Module 10: Benchmarking
    Benchmarker benchmark;
    benchmark.runPerformanceTests();

    cout << "\n";
    setColor(14);
    cout << "=====================================================\n";
    cout << "| ALL MODULES EXECUTED SUCCESSFULLY |\n";
    cout << "=====================================================\n";
    setColor(15);
    cout << "\nenter any key to quit...";
}

void UNIDISCEngine::displayMenu() {
    setColor(14);
    cout << "\n=============================================\n";
    cout << "| UNIDISC ENGINE - MAIN MENU |\n";
    cout << "==============================================\n";
    setColor(15);
    cout << "1. Add Course\n";
    cout << "2. Add Prerequisite\n";
    cout << "3. Add Student\n";
    cout << "4. Add Faculty\n";
    cout << "5. Generate Course Sequences\n";
    cout << "6. Generate Student Groups\n";
    cout << "7. Verify Prerequisites (Induction)\n";
    cout << "8. Add Logic Rule\n";
    cout << "9. Perform Inference\n";
    cout << "10. Set Operations Demo\n";
    cout << "11. Relation Analysis\n";
    cout << "12. Function Analysis\n";
    cout << "13. Generate Proof\n";
    cout << "14. Check Consistency\n";
    cout << "15. Run Benchmarks\n";
    cout << "16. Run Full Demo\n";
    setColor(12);
    cout << "0. Exit\n";
    setColor(10);
    cout << "Enter choice: ";
    setColor(15);
}

void UNIDISCEngine::run() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            int id, credits;
            char name[100];
            setColor(10);
            cout << "Enter Course ID: ";
            setColor(15);
            cin >> id;
            setColor(10);
            cout << "Enter Course Name: ";
            setColor(15);
            cin.ignore();
            cin.getline(name, 100);
            setColor(10);
            cout << "Enter Credits: ";
            setColor(15);
            cin >> credits;
            scheduler.addCourse(id, name, credits);
            setColor(10);
            cout << "Course added successfully!\n";
            setColor(15);
            break;
        }
        case 2: {
            int courseId, prereqId;
            setColor(10);
            cout << "Enter Course ID: ";
            setColor(15);
            cin >> courseId;
            setColor(10);
            cout << "Enter Prerequisite ID: ";
            setColor(15);
            cin >> prereqId;
            scheduler.addPrerequisite(courseId, prereqId);
            setColor(10);
            cout << "Prerequisite added successfully!\n";
            setColor(15);
            break;
        }
        case 3: {
            int id;
            char name[100];
            setColor(10);
            cout << "Enter Student ID: ";
            setColor(15);
            cin >> id;
            setColor(10);
            cout << "Enter Student Name: ";
            setColor(15);
            cin.ignore();
            cin.getline(name, 100);
            addStudent(id, name);
            setColor(10);
            cout << "Student added successfully!\n";
            setColor(15);
            break;
        }
        case 4: {
            int id;
            char name[100];
            setColor(10);
            cout << "Enter Faculty ID: ";
            setColor(15);
            cin >> id;
            setColor(10);
            cout << "Enter Faculty Name: ";
            setColor(15);
            cin.ignore();
            cin.getline(name, 100);
            addFaculty(id, name);
            setColor(10);
            cout << "Faculty added successfully!\n";
            setColor(15);
            break;
        }
        case 5: {
            scheduler.generateValidSequences();
            break;
        }
        case 6: {
            int numStudents, groupSize;
            setColor(10);
            cout << "Enter number of students: ";
            setColor(15);
            cin >> numStudents;
            int* ids = new int[numStudents];
            setColor(10);
            cout << "Enter student IDs:\n";
            setColor(15);
            for (int i = 0; i < numStudents; i++) {
                cin >> ids[i];
            }
            setColor(10);
            cout << "Enter group size: ";
            setColor(15);
            cin >> groupSize;
            StudentGroupManager mgr;
            mgr.generateGroups(ids, numStudents, groupSize);
            delete[] ids;
            break;
        }
        case 7: {
            int studentId, courseId;
            setColor(10);
            cout << "Enter Student ID: ";
            setColor(15);
            cin >> studentId;
            setColor(10);
            cout << "Enter Course ID to verify: ";
            setColor(15);
            cin >> courseId;
            Student* student = nullptr;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].id == studentId) {
                    student = &students[i];
                    break;
                }
            }
            if (student) {
                InductionVerifier verifier(&scheduler);
                verifier.verifyPrerequisiteChain(courseId, student->completedCourses);
            }
            else {
                setColor(12);
                cout << "Student not found!\n";
                setColor(15);
            }
            break;
        }
        case 8: {
            char condition[200], conclusion[200];
            setColor(10);
            cout << "Enter condition: ";
            setColor(15);
            cin.getline(condition, 200);
            setColor(10);
            cout << "Enter conclusion: ";
            setColor(15);
            cin.getline(conclusion, 200);
            logicEngine.addRule(condition, conclusion);
            setColor(10);
            cout << "Logic rule added successfully!\n";
            setColor(15);
            break;
        }
        case 9: {
            logicEngine.performInference();
            logicEngine.checkConflicts();
            break;
        }
        case 10: {
            SetOperations set1, set2;
            int n1, n2, val;
            setColor(10);
            cout << "Enter number of elements in Set 1: ";
            setColor(15);
            cin >> n1;
            setColor(10);
            cout << "Enter elements: ";
            setColor(15);
            for (int i = 0; i < n1; i++) {
                cin >> val;
                set1.add(val);
            }
            setColor(10);
            cout << "Enter number of elements in Set 2: ";
            setColor(15);
            cin >> n2;
            setColor(10);
            cout << "Enter elements: ";
            setColor(15);
            for (int i = 0; i < n2; i++) {
                cin >> val;
                set2.add(val);
            }
            cout << "\nSet 1: "; set1.print(); cout << endl;
            cout << "Set 2: "; set2.print(); cout << endl;
            SetOperations* u = set1.unionWith(set2);
            cout << "Union: "; u->print(); cout << endl;
            SetOperations* i = set1.intersection(set2);
            cout << "Intersection: "; i->print(); cout << endl;
            SetOperations* d = set1.difference(set2);
            cout << "Difference (Set1 - Set2): "; d->print(); cout << endl;
            delete u; delete i; delete d;
            break;
        }
        case 11: {
            int n;
            setColor(10);
            cout << "Enter size of relation: ";
            setColor(15);
            cin >> n;
            Relation rel(n);
            int numPairs;
            setColor(10);
            cout << "Enter number of ordered pairs: ";
            setColor(15);
            cin >> numPairs;
            setColor(10);
            cout << "Enter pairs (from to):\n";
            setColor(15);
            for (int i = 0; i < numPairs; i++) {
                int from, to;
                cin >> from >> to;
                rel.addRelation(from, to);
            }
            rel.print();
            rel.analyzeProperties();
            break;
        }
        case 12: {
            int domainSize, codomainSize;
            setColor(10);
            cout << "Enter domain size: ";
            setColor(15);
            cin >> domainSize;
            setColor(10);
            cout << "Enter codomain size: ";
            setColor(15);
            cin >> codomainSize;
            FunctionMapper func(domainSize, codomainSize);
            int numMappings;
            setColor(10);
            cout << "Enter number of mappings: ";
            setColor(15);
            cin >> numMappings;
            setColor(10);
            cout << "Enter mappings (from to):\n";
            setColor(15);
            for (int i = 0; i < numMappings; i++) {
                int from, to;
                cin >> from >> to;
                func.setMapping(from, to);
            }
            func.printMapping();
            func.analyzeFunction();
            break;
        }
        case 13: {
            int studentId, courseId;
            setColor(10);
            cout << "Enter Student ID: ";
            setColor(15);
            cin >> studentId;
            setColor(10);
            cout << "Enter Course ID: ";
            setColor(15);
            cin >> courseId;
            Student* student = nullptr;
            for (int i = 0; i < studentCount; i++) {
                if (students[i].id == studentId) {
                    student = &students[i];
                    break;
                }
            }
            if (student) {
                ProofGenerator pg;
                pg.generatePrerequisiteProof(courseId, student->completedCourses, &scheduler);
            }
            else {
                setColor(12);
                cout << "Student not found!\n";
                setColor(15);
            }
            break;
        }
        case 14: {
            ConsistencyChecker checker(&scheduler, students, studentCount);
            checker.checkAllConsistency();
            break;
        }
        case 15: {
            Benchmarker bench;
            bench.runPerformanceTests();
            break;
        }
        case 16: {
            demonstrateAllModules();
            break;
        }
        case 0: {
            setColor(13);
            cout << "\nExiting UNIDISC Engine. Goodbye!\n";
            setColor(15);
            break;
        }
        default: {
            setColor(12);
            cout << "Invalid choice! Please try again.\n";
            setColor(15);
        }
        }
    } while (choice != 0);
}