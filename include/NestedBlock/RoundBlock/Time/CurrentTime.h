#include <string>
#include "NestedBlock/RoundBlock/RoundBlock.h"

class CurrentTime : public RoundBlock
{
public:
    CurrentTime(std::string opt);
    std::string getValue() const override;
private:
    std::string option;
};
