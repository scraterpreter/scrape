#include "NestedBlock/RoundBlock/Time/CurrentTime.h"
#include <string.h>
#include <time.h>
#include <stdio.h>

CurrentTime::CurrentTime(std::string opt) : option(opt){}

std::string CurrentTime::getValue() const
{
    time_t rawCurrentTime=time(nullptr);
    tm currentTimeInfo=*localtime(&rawCurrentTime); // local time
    
    char timeString[50];
    char timeFormatString[10];

    if(option=="YEAR")
    {
        strcpy(timeFormatString,"%Y");
    }
    else if(option=="MONTH")
    {
        strcpy(timeFormatString,"%m");
    }
    else if(option=="DATE")
    {
        strcpy(timeFormatString,"%d");
    }
    else if(option=="DAYOFWEEK")
    {
        char tmpTimeString[50];
        strftime(tmpTimeString,sizeof(tmpTimeString),"%w",&currentTimeInfo);
        int zeroIndexedWeekday=atoi(tmpTimeString); // 0-6 with Sunday as 0, Monday as 1, etc
        sprintf(timeFormatString,"%d",zeroIndexedWeekday+1);
    }
    else if(option=="HOUR")
    {
        strcpy(timeFormatString,"%H");
    }
    else if(option=="MINUTE")
    {
        strcpy(timeFormatString,"%M");
    }
    else if(option=="SECOND")
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
