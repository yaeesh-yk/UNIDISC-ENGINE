#include "StudentGroupManager.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

int StudentGroupManager::factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int StudentGroupManager::nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void StudentGroupManager::generateCombinationsHelper(int* arr, int n, int r, int idx, int* data, int i) {
    if (idx == r) {
        setColor(9);
        cout << "Group: ";
        for (int j = 0; j < r; j++) {
            cout << data[j] << " ";
        }
        cout << endl;
        setColor(15);
        return;
    }
    if (i >= n) return;
    data[idx] = arr[i];
    generateCombinationsHelper(arr, n, r, idx + 1, data, i + 1);
    generateCombinationsHelper(arr, n, r, idx, data, i + 1);
}

int StudentGroupManager::calculateCombinations(int students, int groupSize) {
    return nCr(students, groupSize);
}

void StudentGroupManager::generateGroups(int* studentIds, int numStudents, int groupSize) {
    setColor(11);
    cout << "\n=== GENERATING STUDENT GROUPS (Size: " << groupSize << ") ===\n";
    setColor(15);
    cout << "Total possible groups: ";
    setColor(13);
    cout << calculateCombinations(numStudents, groupSize) << endl;
    setColor(15);
    int* data = new int[groupSize];
    generateCombinationsHelper(studentIds, numStudents, groupSize, 0, data, 0);
    delete[] data;
}