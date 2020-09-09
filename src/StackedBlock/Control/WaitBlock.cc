#include <memory>
#include <thread>
#include <chrono>
#include <string>
#include "StackedBlock/Control/WaitBlock.h"
#include "StackOfBlocks.h"
#include "NestedBlock/NestedBlock.h"

WaitBlock::WaitBlock(const std::shared_ptr<NestedBlock> d)
    : duration(d){}

void WaitBlock::exec() const
{
    std::this_thread::sleep_for(std::chrono::milliseconds((int)(duration->getDouble())*1000));
}
