#include "StringArray.h"
#include <cstring>

void StringArray::resize() {
    capacity *= 2;
    char** newData = new char* [capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

StringArray::StringArray() : size(0), capacity(10) {
    data = new char* [capacity];
}

StringArray::~StringArray() {
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void StringArray::add(const char* str) {
    if (size >= capacity) resize();
    data[size] = new char[strlen(str) + 1];
    strcpy_s(data[size], strlen(str) + 1, str);
    size++;
}

const char* StringArray::get(int idx) const {
    return (idx >= 0 && idx < size) ? data[idx] : nullptr;
}

int StringArray::getSize() const { return size; }

bool StringArray::contains(const char* str) const {
    for (int i = 0; i < size; i++) {
        if (strcmp(data[i], str) == 0) return true;
    }
    return false;
}