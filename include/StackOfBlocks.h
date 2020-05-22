#pragma once

#include <vector>
#include <memory>
#include <StackedBlock/StackedBlock.h>

class StackOfBlocks
{
public:
  void execAll() const;
  StackOfBlocks(const std::vector<std::shared_ptr<StackedBlock>>& b);
private:
  std::vector<std::shared_ptr<StackedBlock>> blocks; 
    // vector of StackedBlock pointers
};
