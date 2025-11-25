#include "Relation.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

Relation::Relation(int n) : size(n) {
    matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}

Relation::~Relation() {
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Relation::addRelation(int from, int to) {
    if (from >= 0 && from < size && to >= 0 && to < size) {
        matrix[from][to] = 1;
    }
}

bool Relation::isReflexive() const {
    for (int i = 0; i < size; i++) {
        if (matrix[i][i] != 1) return false;
    }
    return true;
}

bool Relation::isSymmetric() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != matrix[j][i]) return false;
        }
    }
    return true;
}

bool Relation::isTransitive() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j]) {
                for (int k = 0; k < size; k++) {
                    if (matrix[j][k] && !matrix[i][k]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

bool Relation::isEquivalence() const {
    return isReflexive() && isSymmetric() && isTransitive();
}

bool Relation::isPartialOrder() const {
    return isReflexive() && !isSymmetric() && isTransitive();
}

void Relation::print() const {
    setColor(11);
    cout << "\nRelation Matrix:\n";
    setColor(9);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    setColor(15);
}

void Relation::analyzeProperties() {
    setColor(11);
    cout << "\n=== RELATION ANALYSIS ===\n";
    setColor(15);
    cout << "Reflexive: ";
    setColor(isReflexive() ? 10 : 12);
    cout << (isReflexive() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Symmetric: ";
    setColor(isSymmetric() ? 10 : 12);
    cout << (isSymmetric() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Transitive: ";
    setColor(isTransitive() ? 10 : 12);
    cout << (isTransitive() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Equivalence Relation: ";
    setColor(isEquivalence() ? 10 : 12);
    cout << (isEquivalence() ? "YES" : "NO") << endl;
    setColor(15);
    cout << "Partial Order: ";
    setColor(isPartialOrder() ? 10 : 12);
    cout << (isPartialOrder() ? "YES" : "NO") << endl;
    setColor(15);
}