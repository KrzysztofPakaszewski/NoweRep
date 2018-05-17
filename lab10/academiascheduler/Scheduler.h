//
// Created by krzysztof on 15.05.2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <set>
#include <numeric>
#include <map>
#include <queue>

using namespace std;

namespace academia{
    class SchedulingItem{
    public:
        SchedulingItem(int course,int teacher,int room ,int time,int year);
        int CourseId() const;
        int TeacherId() const;
        int RoomId() const;
        int TimeSlot() const;
        int Year() const;
    private:
        int course_id;
        int teacher_id;
        int room_id;
        int time_slot;
        int year;
    };
    class Schedule{
    public:
        Schedule()= default;
        Schedule(initializer_list<SchedulingItem> list);
        Schedule(vector<SchedulingItem> temp);
        Schedule OfTeacher(int teacher) const;
        Schedule OfRoom(int room) const;
        Schedule OfYear(int year) const;
        vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem& item);
        size_t Size() const;

        SchedulingItem operator[](const int slot) const;

    private:
        vector<SchedulingItem> List;
    };
    class NoViableSolutionFound: public runtime_error{
    public:
        NoViableSolutionFound(string a);
    };

    class Scheduler{
    public:
        virtual Schedule PrepareNewSchedule(const vector<int> &rooms,
                                            const std::map<int,vector<int>> &teacher_courses_assignment,
                                            const map<int, std::set<int>> &courses_of_year,
                                            int n_time_slots)=0;
    };

    class GreedyScheduler: public Scheduler{
    public:
        GreedyScheduler()= default;
        Schedule PrepareNewSchedule(const vector<int> &rooms,
                                    const std::map<int,vector<int>> &teacher_courses_assignment,
                                    const map<int, std::set<int>> &courses_of_year,
                                    int n_time_slots) override ;
    };
}


#endif //JIMP_EXERCISES_SCHEDULER_H
