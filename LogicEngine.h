#ifndef LOGICENGINE_H
#define LOGICENGINE_H

class LogicRule {
public:
    char condition[200];
    char conclusion[200];
    bool isActive;
    LogicRule();
    LogicRule(const char* cond, const char* concl);
};

class LogicEngine {
private:
    LogicRule* rules;
    int ruleCount;
    int maxRules;
public:
    LogicEngine();
    ~LogicEngine();
    void addRule(const char* condition, const char* conclusion);
    bool evaluateRule(int ruleIdx, bool conditionMet);
    void performInference();
    bool checkConflicts();
};

#endif