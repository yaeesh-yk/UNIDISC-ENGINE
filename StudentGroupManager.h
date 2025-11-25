#ifndef STUDENTGROUPMANAGER_H
#define STUDENTGROUPMANAGER_H

class StudentGroupManager {
private:
    int factorial(int n);
    int nCr(int n, int r);
    void generateCombinationsHelper(int* arr, int n, int r, int idx, int* data, int i);
public:
    int calculateCombinations(int students, int groupSize);
    void generateGroups(int* studentIds, int numStudents, int groupSize);
};

#endif