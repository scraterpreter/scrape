#pragma once

#include <vector>
#include <StackedBlock/StackedBlock.h>

class StackOfBlocks
{
public:
  void execAll() const;
  StackOfBlocks(const std::vector<StackedBlock*>& b);
private:
  const std::vector<StackedBlock*>& blocks; 
    // vector of StackedBlock pointers
};
