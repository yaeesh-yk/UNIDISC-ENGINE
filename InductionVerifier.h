#ifndef INDUCTIONVERIFIER_H
#define INDUCTIONVERIFIER_H

#include "CourseScheduler.h"
#include "DynamicArray.h"

class InductionVerifier {
private:
    CourseScheduler* scheduler;
    bool verifyBaseCase(int courseId, const DynamicArray& completed);
    bool verifyInductiveStep(int courseId, const DynamicArray& completed);
public:
    InductionVerifier(CourseScheduler* cs);
    bool verifyPrerequisiteChain(int courseId, const DynamicArray& completed);
};

#endif