#ifndef FUNCTIONMAPPER_H
#define FUNCTIONMAPPER_H

class FunctionMapper {
private:
    int* domain;
    int* codomain;
    int* mapping;
    int domainSize;
    int codomainSize;
public:
    FunctionMapper(int dSize, int cSize);
    ~FunctionMapper();
    void setMapping(int from, int to);
    bool isInjective() const;
    bool isSurjective() const;
    bool isBijective() const;
    void analyzeFunction();
    void printMapping();
};

#endif