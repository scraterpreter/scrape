#pragma once

#include <vector>
#include <StackedBlock/StackedBlock.h>

class StackOfBlocks
{
public:
  void execAll();
private:
  std::vector<StackedBlocks> blocks;
}
