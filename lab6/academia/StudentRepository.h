//
// Created by pakakrzy on 10.04.18.
//

#ifndef JIMP_EXERCISES_STUDENTREPOSITORY_H
#define JIMP_EXERCISES_STUDENTREPOSITORY_H

#include <string>
#include <vector>

using namespace std;


namespace academia {
    class StudyYear{
    public:
        StudyYear();
        explicit StudyYear(int);

        explicit operator int();

        StudyYear operator++();
        StudyYear operator++(int);
        StudyYear operator--();
        StudyYear operator--(int);

    private:
        int year;
    };
    class Student{
    public:
        Student();
        Student(string,string,string,string,int);

        string Id();
        string FirstName();
        void ChangeFirstName(string);
    private:
        string id;
        string first_name;
        string last_name;
        string program;
        StudyYear year;
    };
    class StudentRepository {
    public:
        StudentRepository();
        StudentRepository(initializer_list<Student>);
        size_t StudentCount();
        Student&operator[](string);

    private:
        vector<Student> rep;
    };
}


#endif //JIMP_EXERCISES_STUDENTREPOSITORY_H
