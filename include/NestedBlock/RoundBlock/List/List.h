#pragma once

#include <string>
#include <vector>
#include <memory>
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
    int length() const;
    List(std::shared_ptr<std::vector<std::string>> v);
    List();
private:
    std::shared_ptr<std::vector<std::string>> val;
};
