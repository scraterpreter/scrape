#pragma once

#include <vector>
#include <memory>
#include <Block.h>

class BlockTable
{
public:
  void setIndex(int index, std::shared_ptr<Block> block);
  std::shared_ptr<Block> getIndex(int index) const;
  int size() const;
  BlockTable(int size);
private:
  std::vector<std::shared_ptr<Block>> blocks; 
};
