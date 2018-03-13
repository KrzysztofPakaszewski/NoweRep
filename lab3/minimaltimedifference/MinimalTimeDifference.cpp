//
// Created by pakakrzy on 13.03.18.
//

#include "MinimalTimeDifference.h"


unsigned int minimaltimedifference::ToMinutes(string time_HH_MM)
{
    string Hour;
    string Minutes;
    bool Flag = false;
    for(int a = 0; a< time_HH_MM.size();a++)
    {
        if(time_HH_MM[a] == ':'){
            Flag = true;
            continue;
        }
        if(!Flag)
        {
            Hour+=time_HH_MM[a];
        }
        else
            Minutes+=time_HH_MM[a];
    }
    int hour = atoi(Hour.c_str());
    int minutes = atoi(Minutes.c_str());
    return hour*60+minutes;
}


unsigned int minimaltimedifference::MinimalTimeDifference(vector<string> times)
{
    vector<int> TimeMinute;
    for(int a = 0;a<times.size(); a++)
    {
        TimeMinute.push_back(minimaltimedifference::ToMinutes(times[a]));
        int j= TimeMinute.size()-1;
        while(j>0  && TimeMinute[j] < TimeMinute[j-1])
        {
            int temp = TimeMinute[j-1];
            TimeMinute[j-1] = TimeMinute[j];
            TimeMinute[j] = temp;
            j--;
        }
    }
    int minimal;
    if(TimeMinute.size()>1)
        minimal = 24*60 - TimeMinute[TimeMinute.size()-1]+TimeMinute[0];
    else
        return 0;
    for(int a = 1; a< TimeMinute.size(); a++)
    {
        if(TimeMinute[a]-TimeMinute[a-1] < minimal)
        {
            minimal = TimeMinute[a]-TimeMinute[a-1];
        }
    }
    return minimal;
}