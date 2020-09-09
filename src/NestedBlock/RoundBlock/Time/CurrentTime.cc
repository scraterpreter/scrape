#include "NestedBlock/RoundBlock/Time/CurrentTime.h"
#include <string.h>
#include <memory>
#include <time.h>
#include <stdio.h>

CurrentTime::CurrentTime(std::shared_ptr<Constant> opt) : option(opt){}

MultiType CurrentTime::getValue() const
{
    time_t rawCurrentTime=time(nullptr);
    tm currentTimeInfo=*localtime(&rawCurrentTime); // local time
    
    char timeString[50];
    char timeFormatString[10];

    if(option->getString()=="YEAR")
    {
        strcpy(timeFormatString,"%Y");
    }
    else if(option->getString()=="MONTH")
    {
        strcpy(timeFormatString,"%m");
    }
    else if(option->getString()=="DATE")
    {
        strcpy(timeFormatString,"%d");
    }
    else if(option->getString()=="DAYOFWEEK")
    {
        char tmpTimeString[50];
        strftime(tmpTimeString,sizeof(tmpTimeString),"%w",&currentTimeInfo);
        int zeroIndexedWeekday=atoi(tmpTimeString); // 0-6 with Sunday as 0, Monday as 1, etc
        sprintf(timeFormatString,"%d",zeroIndexedWeekday+1);
    }
    else if(option->getString()=="HOUR")
    {
        strcpy(timeFormatString,"%H");
    }
    else if(option->getString()=="MINUTE")
    {
        strcpy(timeFormatString,"%M");
    }
    else if(option->getString()=="SECOND")
    {
        strcpy(timeFormatString,"%S");
    }
    else
    {
        strcpy(timeFormatString,"");
    }
    
    strftime(timeString,sizeof(timeString),timeFormatString,&currentTimeInfo);
    return std::string(timeString);
}
