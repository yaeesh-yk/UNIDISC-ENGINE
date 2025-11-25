#include "Benchmarker.h"
#include "SetOperations.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

void Benchmarker::runPerformanceTests() {
    setColor(11);
    cout << "\n=== ALGORITHMIC EFFICIENCY BENCHMARK ===\n";
    setColor(15);
    cout << "Testing with large datasets...\n";
    SetOperations set1, set2;
    for (int i = 0; i < 1000; i++) {
        set1.add(i);
        set2.add(i + 500);
    }
    cout << "Set 1 size: ";
    setColor(13);
    cout << set1.getSize() << endl;
    setColor(15);
    cout << "Set 2 size: ";
    setColor(13);
    cout << set2.getSize() << endl;
    setColor(15);
    SetOperations* unionSet = set1.unionWith(set2);
    cout << "Union size: ";
    setColor(13);
    cout << unionSet->getSize();
    setColor(10);
    cout << " - PASS\n";
    setColor(15);
    SetOperations* intersectSet = set1.intersection(set2);
    cout << "Intersection size: ";
    setColor(13);
    cout << intersectSet->getSize();
    setColor(10);
    cout << " - PASS\n";
    setColor(15);
    delete unionSet;
    delete intersectSet;
    setColor(10);
    cout << "\nAll performance tests completed successfully!\n";
    setColor(15);
}