#include "DynamicArray.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

void DynamicArray::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

DynamicArray::DynamicArray() : size(0), capacity(10) {
    data = new int[capacity];
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::add(int val) {
    if (size >= capacity) resize();
    data[size++] = val;
}

int DynamicArray::get(int idx) const {
    return (idx >= 0 && idx < size) ? data[idx] : -1;
}

int DynamicArray::getSize() const { return size; }

bool DynamicArray::contains(int val) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == val) return true;
    }
    return false;
}

void DynamicArray::remove(int val) {
    for (int i = 0; i < size; i++) {
        if (data[i] == val) {
            for (int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return;
        }
    }
}

void DynamicArray::clear() { size = 0; }

void DynamicArray::print() const {
    setColor(9);
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    setColor(15);
}