#pragma once

#include <string>
#include <vector>
#include "NestedBlock/RoundBlock/RoundBlock.h"

struct ListFindResult;

class List : public RoundBlock
{
public:
    MultiType getValue() const override;
    //std::vector<std::string> getVector() const;
    MultiType getIndex(int index) const;
    //void setVector(std::vector<std::string> v);
    void add(MultiType v);
    void remove(int index);
    void clear();
    void insert(int index, MultiType v);
    void replace(int index, MultiType v);
    int length() const;
    ListFindResult find(MultiType v);

    List(std::vector<std::string> v);
    List();
private:
    std::vector<MultiType> val;
};

struct ListFindResult
{
    bool itemFound;
    int index;
};
