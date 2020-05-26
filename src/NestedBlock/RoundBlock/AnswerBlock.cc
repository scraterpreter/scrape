#include "NestedBlock/RoundBlock/AnswerBlock.h"
#include "NestedBlock/RoundBlock/Variable.h"

std::string AnswerBlock::getValue() const
{
    return answerVariable->getValue();
}

void AnswerBlock::setValue(std::string val)
{
    answerVariable->setValue(val);
}

AnswerBlock::AnswerBlock(std::shared_ptr<Variable> av) :
    answerVariable(av) {}
