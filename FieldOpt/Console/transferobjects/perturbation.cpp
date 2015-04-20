#include "perturbation.h"


Perturbation::Perturbation(Case* c, int id) :
    perturbation_id(id),
    binaryLength(c->numberOfBinaryVariables()),
    integerLength(c->numberOfIntegerVariables()),
    realLength(c->numberOfRealVariables())
{
    for (int i = 0; i < binaryLength; ++i)
        binaryVariables.push_back(c->binaryVariableValue(i));

    for (int i = 0; i < integerLength; ++i)
        integerVariables.push_back(c->integerVariableValue(i));

    for (int i = 0; i < realLength; ++i)
        realVariables.push_back(c->realVariableValue(i));
}

Perturbation::Perturbation(std::vector<int> &header, std::vector<double> &binaries, std::vector<int> &integers, std::vector<double> &reals) :
    perturbation_id(header.at(0)),
    binaryLength(header.at(1)),
    integerLength(header.at(2)),
    realLength(header.at(3))
{
    binaryVariables = binaries;
    integerVariables = integers;
    realVariables = reals;
}

Case *Perturbation::getCase(Model *m)
{
    c = new Case(m);

    for (int i = 0; i < binaryLength; ++i)
        c->setBinaryVariableValue(i, binaryVariables.at(i));

    for (int i = 0; i < integerLength; ++i)
        c->setIntegerVariableValue(i, integerVariables.at(i));

    for (int i = 0; i < realLength; ++i)
        c->setRealVariableValue(i, realVariables.at(i));

    return c;
}

std::vector<int> Perturbation::getSendHeader() const
{
    std::vector<int> sendHeader { perturbation_id, binaryLength, integerLength, realLength };
    return sendHeader;
}