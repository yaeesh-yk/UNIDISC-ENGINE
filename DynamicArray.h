#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;
    void resize();
public:
    DynamicArray();
    ~DynamicArray();
    void add(int val);
    int get(int idx) const;
    int getSize() const;
    bool contains(int val) const;
    void remove(int val);
    void clear();
    void print() const;
};

#endif