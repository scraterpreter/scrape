#pragma once

#include <vector>
#include <Block.h>

class BlockTable
{
public:
  void setIndex(int index, Block* block);
  Block* getIndex(int index) const;
  int size() const;
  BlockTable(int size);
private:
  std::vector<Block*> blocks; 
};
