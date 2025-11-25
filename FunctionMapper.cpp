#include "FunctionMapper.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

FunctionMapper::FunctionMapper(int dSize, int cSize) : domainSize(dSize), codomainSize(cSize) {
    domain = new int[domainSize];
    codomain = new int[codomainSize];
    mapping = new int[domainSize];
    for (int i = 0; i < domainSize; i++) {
        domain[i] = i;
        mapping[i] = -1;
    }
    for (int i = 0; i < codomainSize; i++) {
        codomain[i] = i;
    }
}

FunctionMapper::~FunctionMapper() {
    delete[] domain;
    delete[] codomain;
    delete[] mapping;
}

void FunctionMapper::setMapping(int from, int to) {
    if (from >= 0 && from < domainSize && to >= 0 && to < codomainSize) {
        mapping[from] = to;
    }
}

bool FunctionMapper::isInjective() const {
    for (int i = 0; i < domainSize; i++) {
        if (mapping[i] == -1) continue;
        for (int j = i + 1; j < domainSize; j++) {
            if (mapping[i] == mapping[j] && mapping[j] != -1) {
                return false;
            }
        }
    }
    return true;
}

bool FunctionMapper::isSurjective() const {
    for (int i = 0; i < codomainSize; i++) {
        bool found = false;
        for (int j = 0; j < domainSize; j++) {
            if (mapping[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

bool FunctionMapper::isBijective() const {
    return isInjective() && isSurjective();
}

void FunctionMapper::analyzeFunction() {
    setColor(11);
    cout << "\n=== FUNCTION ANALYSIS ===\n";
    setColor(15);
    cout << "Domain Size: ";
    setColor(13);
    cout << domainSize << endl;
    setColor(15);
    cout << "Codomain Size: ";
    setColor(13);
    cout << codomainSize << endl;
    setColor(15);
    cout << "Injective (One-to-One): ";
    setColor(isInjective() ? 10 : 12);
    cout << (isInjective() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Surjective (Onto): ";
    setColor(isSurjective() ? 10 : 12);
    cout << (isSurjective() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Bijective: ";
    setColor(isBijective() ? 10 : 12);
    cout << (isBijective() ? "YES" : "NO") << endl;
    setColor(15);
}

void FunctionMapper::printMapping() {
    setColor(11);
    cout << "\nFunction Mapping:\n";
    setColor(9);
    for (int i = 0; i < domainSize; i++) {
        if (mapping[i] != -1) {
            cout << i << " -> " << mapping[i] << endl;
        }
    }
    setColor(15);
}