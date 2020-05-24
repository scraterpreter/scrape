#include "NestedBlock/RoundBlock/Time/DaysSince2000.h"
#include "time.h"

std::string DaysSince2000::getValue() const
{
    time_t rawCurrentTime=time(nullptr);
    tm currentTimeInfo=*gmtime(&rawCurrentTime); // UTC time
    time_t currentTime=mktime(&currentTimeInfo); 

    tm year2000;
    year2000.tm_hour=0;
    year2000.tm_min=0;
    year2000.tm_sec=0;
    year2000.tm_mon=0;
    year2000.tm_mday=1;
    year2000.tm_year=100;
    year2000.tm_isdst=false;
    time_t year2000Time=mktime(&year2000);

    const double secondsInDay=86400;
    return std::to_string(difftime(currentTime,year2000Time)/secondsInDay);
}
