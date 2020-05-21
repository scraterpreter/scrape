#include <vector>
#include "BlockTable.h"
#include "Block.h"

void BlockTable::setIndex(int index, Block* block)
{
    blocks[index] = block;
}

Block* BlockTable::getIndex(int index) const
{
    return blocks[index];
}

int BlockTable::size() const
{
    return blocks.size();
}

BlockTable::BlockTable(int size): blocks{size, nullptr} {}
