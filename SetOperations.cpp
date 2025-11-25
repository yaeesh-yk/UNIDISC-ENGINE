#include "SetOperations.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

void SetOperations::resize() {
    capacity *= 2;
    int* newElements = new int[capacity];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

SetOperations::SetOperations() : size(0), capacity(10) {
    elements = new int[capacity];
}

SetOperations::~SetOperations() {
    delete[] elements;
}

void SetOperations::add(int val) {
    if (!contains(val)) {
        if (size >= capacity) resize();
        elements[size++] = val;
    }
}

bool SetOperations::contains(int val) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == val) return true;
    }
    return false;
}

SetOperations* SetOperations::unionWith(const SetOperations& other) {
    SetOperations* result = new SetOperations();
    for (int i = 0; i < size; i++) {
        result->add(elements[i]);
    }
    for (int i = 0; i < other.size; i++) {
        result->add(other.elements[i]);
    }
    return result;
}

SetOperations* SetOperations::intersection(const SetOperations& other) {
    SetOperations* result = new SetOperations();
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result->add(elements[i]);
        }
    }
    return result;
}

SetOperations* SetOperations::difference(const SetOperations& other) {
    SetOperations* result = new SetOperations();
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) {
            result->add(elements[i]);
        }
    }
    return result;
}

bool SetOperations::isSubset(const SetOperations& other) const {
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) return false;
    }
    return true;
}

int SetOperations::getSize() const { return size; }

void SetOperations::print() const {
    setColor(9);
    cout << "{ ";
    for (int i = 0; i < size; i++) {
        cout << elements[i] << " ";
    }
    cout << "}";
    setColor(15);
}