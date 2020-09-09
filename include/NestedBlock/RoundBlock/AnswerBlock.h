#include "NestedBlock/RoundBlock/RoundBlock.h"
#include "MultiType.h"
#include <memory>
#include <string>

class Variable;

class AnswerBlock : public RoundBlock
{
public:
    MultiType getValue() const override;
    void setValue(MultiType val);
    AnswerBlock(std::shared_ptr<Variable> av);
private:
    std::shared_ptr<Variable> answerVariable;
};
