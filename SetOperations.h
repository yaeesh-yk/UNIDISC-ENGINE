#ifndef SETOPERATIONS_H
#define SETOPERATIONS_H

class SetOperations {
private:
    int* elements;
    int size;
    int capacity;
    void resize();
public:
    SetOperations();
    ~SetOperations();
    void add(int val);
    bool contains(int val) const;
    SetOperations* unionWith(const SetOperations& other);
    SetOperations* intersection(const SetOperations& other);
    SetOperations* difference(const SetOperations& other);
    bool isSubset(const SetOperations& other) const;
    int getSize() const;
    void print() const;
};

#endif