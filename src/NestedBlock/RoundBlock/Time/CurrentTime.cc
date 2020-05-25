#include "NestedBlock/RoundBlock/Time/CurrentTime.h"
#include <string.h>
#include <memory>
#include <time.h>
#include <stdio.h>

CurrentTime::CurrentTime(std::shared_ptr<Constant> opt) : option(opt){}

std::string CurrentTime::getValue() const
{
    time_t rawCurrentTime=time(nullptr);
    tm currentTimeInfo=*localtime(&rawCurrentTime); // local time
    
    char timeString[50];
    char timeFormatString[10];

    if(option->getValue()=="YEAR")
    {
        strcpy(timeFormatString,"%Y");
    }
    else if(option->getValue()=="MONTH")
    {
        strcpy(timeFormatString,"%m");
    }
    else if(option->getValue()=="DATE")
    {
        strcpy(timeFormatString,"%d");
    }
    else if(option->getValue()=="DAYOFWEEK")
    {
        char tmpTimeString[50];
        strftime(tmpTimeString,sizeof(tmpTimeString),"%w",&currentTimeInfo);
        int zeroIndexedWeekday=atoi(tmpTimeString); // 0-6 with Sunday as 0, Monday as 1, etc
        sprintf(timeFormatString,"%d",zeroIndexedWeekday+1);
    }
    else if(option->getValue()=="HOUR")
    {
        strcpy(timeFormatString,"%H");
    }
    else if(option->getValue()=="MINUTE")
    {
        strcpy(timeFormatString,"%M");
    }
    else if(option->getValue()=="SECOND")
    {
        strcpy(timeFormatString,"%S");
    }
    else
    {
        strcpy(timeFormatString,"");
    }
    
    strftime(timeString,sizeof(timeString),timeFormatString,&currentTimeInfo);
    return timeString;
}
