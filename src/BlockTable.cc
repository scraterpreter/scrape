#include <vector>
#include "BlockTable.h"
#include "Block.h"
#include <memory>

void BlockTable::setIndex(int index, std::shared_ptr<Block> block)
{
    blocks[index] = block;
}

std::shared_ptr<Block> BlockTable::getIndex(int index) const
{
    return blocks[index];
}

int BlockTable::size() const
{
    return blocks.size();
}

BlockTable::BlockTable(int size): blocks{size, nullptr} {}
