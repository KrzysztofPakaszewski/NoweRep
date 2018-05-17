//
// Created by krzysztof on 15.05.2018.
//

#include "Scheduler.h"
using namespace academia;

SchedulingItem::SchedulingItem(int course,int teacher,int room ,int time,int year):course_id(course),teacher_id(teacher),room_id(room) ,
time_slot(time),year(year){}

Schedule::Schedule(vector<SchedulingItem> temp){
    copy(temp.begin(),temp.end(),back_inserter(List));
}

int SchedulingItem::CourseId()const{ return course_id;}
int SchedulingItem::TeacherId()const{ return teacher_id;}
int SchedulingItem::RoomId()const{ return room_id;}
int SchedulingItem::TimeSlot()const{ return time_slot;}
int SchedulingItem::Year()const{ return year;}

SchedulingItem Schedule::operator[](const int slot) const{
    if(slot< List.size() && slot >= 0)
        return List[slot];
    else
        throw invalid_argument("Invalid reference to object");
}

Schedule::Schedule(initializer_list<SchedulingItem> list){
    copy(list.begin(),list.end(),back_inserter(List));
}

Schedule Schedule::OfTeacher(int teacher) const{
    vector<SchedulingItem> res;
    copy_if(List.begin(),List.end(),back_inserter(res),[teacher](SchedulingItem a){return a.TeacherId()==teacher;});
    return Schedule(res);
}
Schedule Schedule::OfRoom(int room) const{
    vector<SchedulingItem> res;
    copy_if(List.begin(),List.end(),back_inserter(res),[room](SchedulingItem a){return a.RoomId()==room;});
    return Schedule(res);
}
Schedule Schedule::OfYear(int year) const{
    vector<SchedulingItem> res;
    copy_if(List.begin(),List.end(),back_inserter(res),[year](SchedulingItem a){return a.Year()==year;});
    return Schedule(res);
}
vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const{
    vector<int> first;
    vector<int> second(n_time_slots);
    vector<int> result;
    transform(List.begin(),List.end(),back_inserter(first),[](SchedulingItem a){ return a.TimeSlot();});
    unique(first.begin(),first.end());
    iota(second.begin(),second.end(),1);
    set_difference(second.begin(),second.end(),first.begin(),first.end(),back_inserter(result));
    return result;

}
void Schedule::InsertScheduleItem(const SchedulingItem& item){
    List.emplace_back(item);
}
size_t Schedule::Size() const{
    return List.size();
}
NoViableSolutionFound::NoViableSolutionFound(string a):runtime_error(a){}

Schedule GreedyScheduler::PrepareNewSchedule(const vector<int> &rooms,
                                             const std::map<int,vector<int>> &teacher_courses_assignment,
                                             const map<int, std::set<int>> &courses_of_year,
                                             int n_time_slots) {
    Schedule schedule;
    queue<pair<int,int>> Queue; // first = Teacher ID,    second = course id
    for( auto it=teacher_courses_assignment.begin(); it != teacher_courses_assignment.end();it++)
    {
        for_each(it->second.begin(),it->second.end(),[&Queue,it](int a){Queue.push({it->first,a});});
    }
    bool First =true;
    int Save;
    int RoomIter =0;
    int TimeIter =1;
    while( !Queue.empty()){
        if( RoomIter == rooms.size())
        {
            throw NoViableSolutionFound("No viable solution found");
        }
        if(TimeIter>n_time_slots)
        {
            RoomIter++;
            TimeIter=1;
            continue;
        }
        pair<int,int> Current = Queue.front(); // first=Teacher ID      second= Course ID
        Queue.pop();
        auto Course = courses_of_year.begin();
        for(;Course!=courses_of_year.end();Course++)
        {
            if(find(Course->second.begin(),Course->second.end(),Current.second)!=Course->second.end())
            {
                break;
            }
        }
        if(Course == courses_of_year.end())
            throw invalid_argument("No course found");

        if(RoomIter>0)
        {
            if(schedule.OfRoom(rooms[RoomIter-1])[TimeIter-1].TeacherId()==Current.first
                    || (schedule.OfRoom(rooms[RoomIter-1])[TimeIter-1].Year()== Course->first
                                      //&& schedule.OfRoom(rooms[RoomIter-1])[TimeIter-1].CourseId() != Current.second
                                      ))
            {
                if(First)
                {
                    Save =Queue.size();
                    First= false;
                }
                if(Save == 0){
                    TimeIter++;
                    First = true;
                    Queue.push(Current);
                    continue;
                }
                Queue.push(Current);
                Save--;
                continue;
            }
        }
        schedule.InsertScheduleItem(SchedulingItem{Current.second,Current.first,rooms[RoomIter],TimeIter,Course->first});
        TimeIter++;
        First=true;
    }
    return schedule;
}