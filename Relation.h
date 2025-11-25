#ifndef RELATION_H
#define RELATION_H

class Relation {
private:
    int** matrix;
    int size;
public:
    Relation(int n);
    ~Relation();
    void addRelation(int from, int to);
    bool isReflexive() const;
    bool isSymmetric() const;
    bool isTransitive() const;
    bool isEquivalence() const;
    bool isPartialOrder() const;
    void print() const;
    void analyzeProperties();
};

#endif