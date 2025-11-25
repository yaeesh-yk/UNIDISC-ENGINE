#ifndef PROOFGENERATOR_H
#define PROOFGENERATOR_H

#include "CourseScheduler.h"
#include "DynamicArray.h"

class ProofGenerator {
public:
    void generatePrerequisiteProof(int courseId, const DynamicArray& completed, CourseScheduler* scheduler);
};

#endif