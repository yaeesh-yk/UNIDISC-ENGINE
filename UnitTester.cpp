#include "UnitTester.h"
#include "SetOperations.h"
#include "Relation.h"
#include "FunctionMapper.h"
#include "StudentGroupManager.h"
#include "DynamicArray.h"
#include "ConsoleColour.h"
#include <iostream>
#include <string>
using namespace std;

void UnitTester::runAllTests() {
    cout << "\n";
    setColor(14);
    cout << "=====================================================\n";
    cout << "| UNIT TESTING MODULE |\n";
    cout << "=====================================================\n";
    setColor(15);
    int passed = 0, total = 0;

    // Test 1: Set Operations
    setColor(11);
    cout << "\nTest 1: Set Operations\n";
    setColor(15);
    total++;
    SetOperations s1, s2;
    s1.add(1); s1.add(2); s1.add(3);
    s2.add(2); s2.add(3); s2.add(4);
    SetOperations* inter = s1.intersection(s2);
    if (inter->getSize() == 2) {
        setColor(10);
        cout << " PASSED: Intersection size correct\n";
        setColor(15);
        passed++;
    }
    else {
        setColor(12);
        cout << " FAILED: Intersection size incorrect\n";
        setColor(15);
    }
    delete inter;

    // Test 2: Relations
    setColor(11);
    cout << "\nTest 2: Relation Properties\n";
    setColor(15);
    total++;
    Relation testRel(3);
    testRel.addRelation(0, 0);
    testRel.addRelation(1, 1);
    testRel.addRelation(2, 2);
    if (testRel.isReflexive()) {
        setColor(10);
        cout << " PASSED: Reflexive relation detected\n";
        setColor(15);
        passed++;
    }
    else {
        setColor(12);
        cout << " FAILED: Reflexive relation not detected\n";
        setColor(15);
    }

    // Test 3: Functions
    setColor(11);
    cout << "\nTest 3: Function Injectivity\n";
    setColor(15);
    total++;
    FunctionMapper testFunc(3, 3);
    testFunc.setMapping(0, 0);
    testFunc.setMapping(1, 1);
    testFunc.setMapping(2, 2);
    if (testFunc.isInjective()) {
        setColor(10);
        cout << " PASSED: Injective function detected\n";
        setColor(15);
        passed++;
    }
    else {
        setColor(12);
        cout << " FAILED: Injective function not detected\n";
        setColor(15);
    }

    // Test 4: Student Groups
    setColor(11);
    cout << "\nTest 4: Combination Calculation\n";
    setColor(15);
    total++;
    StudentGroupManager sgm;
    int result = sgm.calculateCombinations(5, 3);
    if (result == 10) {
        setColor(10);
        cout << " PASSED: C(5,3) = 10\n";
        setColor(15);
        passed++;
    }
    else {
        setColor(12);
        cout << " FAILED: C(5,3) calculation incorrect\n";
        setColor(15);
    }

    // Test 5: Dynamic Array
    setColor(11);
    cout << "\nTest 5: Dynamic Array Operations\n";
    setColor(15);
    total++;
    DynamicArray arr;
    arr.add(10); arr.add(20); arr.add(30);
    if (arr.contains(20) && arr.getSize() == 3) {
        setColor(10);
        cout << " PASSED: Array operations correct\n";
        setColor(15);
        passed++;
    }
    else {
        setColor(12);
        cout << " FAILED: Array operations incorrect\n";
        setColor(15);
    }

    setColor(14);
    cout << "\n" << string(50, '=') << endl;
    setColor(15);
    cout << "TOTAL TESTS: ";
    setColor(13);
    cout << total << endl;
    setColor(15);
    cout << "PASSED: ";
    setColor(10);
    cout << passed << endl;
    setColor(15);
    cout << "FAILED: ";
    setColor(12);
    cout << (total - passed) << endl;
    setColor(15);
    cout << "SUCCESS RATE: ";
    setColor(13);
    cout << (passed * 100 / total) << "%\n";
    setColor(14);
    cout << string(50, '=') << endl;
    setColor(15);
}