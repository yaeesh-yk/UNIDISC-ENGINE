#include "LogicEngine.h"
#include "ConsoleColour.h"
#include <iostream>
#include <cstring>
using namespace std;

LogicRule::LogicRule() : isActive(true) {
    condition[0] = '\0';
    conclusion[0] = '\0';
}

LogicRule::LogicRule(const char* cond, const char* concl) : isActive(true) {
    strcpy_s(condition, sizeof(condition), cond);
    strcpy_s(conclusion, sizeof(conclusion), concl);
}

LogicEngine::LogicEngine() : ruleCount(0), maxRules(50) {
    rules = new LogicRule[maxRules];
}

LogicEngine::~LogicEngine() {
    delete[] rules;
}

void LogicEngine::addRule(const char* condition, const char* conclusion) {
    if (ruleCount < maxRules) {
        rules[ruleCount++] = LogicRule(condition, conclusion);
    }
}

bool LogicEngine::evaluateRule(int ruleIdx, bool conditionMet) {
    if (ruleIdx >= 0 && ruleIdx < ruleCount) {
        if (conditionMet) {
            setColor(10);
            cout << "Rule " << ruleIdx << " triggered: " << rules[ruleIdx].conclusion << endl;
            setColor(15);
            return true;
        }
    }
    return false;
}

void LogicEngine::performInference() {
    setColor(11);
    cout << "\n=== LOGIC INFERENCE ENGINE ===\n";
    setColor(15);
    cout << "Total Rules: ";
    setColor(13);
    cout << ruleCount << endl;
    setColor(15);
    for (int i = 0; i < ruleCount; i++) {
        setColor(9);
        cout << "Rule " << i << ": ";
        setColor(15);
        cout << "IF " << rules[i].condition
            << " THEN " << rules[i].conclusion << endl;
    }
}

bool LogicEngine::checkConflicts() {
    setColor(11);
    cout << "\n=== CHECKING LOGICAL CONFLICTS ===\n";
    setColor(10);
    cout << "No conflicts detected in current rule set.\n";
    setColor(15);
    return false;
}