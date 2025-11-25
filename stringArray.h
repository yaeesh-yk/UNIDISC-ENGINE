#ifndef STRINGARRAY_H
#define STRINGARRAY_H

class StringArray {
private:
    char** data;
    int size;
    int capacity;
    void resize();
public:
    StringArray();
    ~StringArray();
    void add(const char* str);
    const char* get(int idx) const;
    int getSize() const;
    bool contains(const char* str) const;
};

#endif