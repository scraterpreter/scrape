#pragma once

#include <string>
#include <vector>
#include "NestedBlock/RoundBlock/RoundBlock.h"

class List : public RoundBlock
{
public:
    std::string getValue() const override;
    std::vector<std::string> getVector() const;
    std::string getIndex(int index) const;
    void setVector(std::vector<std::string> v);
    void add(std::string v);
    void remove(int index);
    void clear();
    void insert(int index, std::string v);
    void replace(int index, std::string v);
    int length();
    List(std::vector<std::string> v);
    List();
private:
    std::vector<std::string> val;
};
