#ifndef COMPASSSEARCHOPTIMIZER_H
#define COMPASSSEARCHOPTIMIZER_H

#include "gssalgorithm.h"
#include "optimizer.h"

class CompassSearchOptimizer : public Optimizer, public GSSAlgorithm
{
private:
    QVector<Case*> perturb(Case *c);
    bool isBetter(Case *c);
public:
    CompassSearchOptimizer(){}

    void initialize(Case* baseCase, OptimizerSettings* settings);
    QVector<Case*> getNewCases();
    void compareCases(QVector<Case*> cases);
    bool isFinished();

    void reduceStepLength();
};

#endif // COMPASSSEARCHOPTIMIZER_H
