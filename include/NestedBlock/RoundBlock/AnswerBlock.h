#include "NestedBlock/RoundBlock/RoundBlock.h"
#include <memory>
#include <string>

class Variable;

class AnswerBlock : public RoundBlock
{
public:
    std::string getValue() const override;
    void setValue(std::string val);
    AnswerBlock(std::shared_ptr<Variable> av);
private:
    std::shared_ptr<Variable> answerVariable;
};
