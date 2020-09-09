#include "NestedBlock/RoundBlock/AnswerBlock.h"
#include "NestedBlock/RoundBlock/Variable.h"

MultiType AnswerBlock::getValue() const
{
    return answerVariable->getValue();
}

void AnswerBlock::setValue(MultiType val)
{
    answerVariable->setValue(val);
}

AnswerBlock::AnswerBlock(std::shared_ptr<Variable> av) :
    answerVariable(av) {}
