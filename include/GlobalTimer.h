#include <time.h>
#include "Block.h"

class GlobalTimer : public Block
{
public:
    GlobalTimer();
    void reset();
    double timeElapsedInSeconds() const;
private:
    clock_t time;
};
