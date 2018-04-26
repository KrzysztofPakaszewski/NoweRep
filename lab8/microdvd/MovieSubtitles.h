//
// Created by krzysztof on 25.04.2018.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <string>
#include <exception>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

namespace moviesubs {

    class MovieSubtitles{
    public:
        virtual void ShiftAllSubtitlesBy(int miliseconds,int FrameRate,stringstream* input,stringstream* output)=0;
    };

    class SubRipSubtitles: public MovieSubtitles{
    public:
        SubRipSubtitles()= default;
        string Add(smatch input,int delay,int linenumber, string Line );
        string convert(long);
        void ShiftAllSubtitlesBy(int miliseconds,int FrameRate,stringstream* input,stringstream* output) override ;

    };
    class MicroDvdSubtitles :public MovieSubtitles{
    public:
        MicroDvdSubtitles()= default;
        void ShiftAllSubtitlesBy(int miliseconds,int FrameRate,stringstream* input,stringstream* output) override ;
        void CheckFramesAfterShift(int first, int second, int Line,string input);
        void CheckFramesBeforeShift(string first, string second, int Line,string input);
    };
    class NegativeFrameAfterShift: public invalid_argument{
    public:
        NegativeFrameAfterShift(const string & __arg,int line);
        const char* what() const throw();
        int LineAt();
    private:
        int Line;
        string arg;
    };
    class SubtitleEndBeforeStart : public invalid_argument{
    public:
        SubtitleEndBeforeStart(const string& __arg, int Line);
        const char* what() const throw();
        int LineAt()const { return Line;}

    private:
        int Line;
        string arg;
    };
    class InvalidSubtitleLineFormat : public invalid_argument{
    public:
        InvalidSubtitleLineFormat(const string& __arg,int Line);
        const char* what() const throw();

    private:
        string arg;
        int Line;
    };
    class OutOfOrderFrames : public invalid_argument{
    public:
        OutOfOrderFrames(const string& __arg,int line);
        const char* what() const throw();

    private:
        string arg;
        int Line;
    };
    class MissingTimeSpecification :public invalid_argument{
    public:
        MissingTimeSpecification(const string& __arg,int line);
        const char* what() const throw();
    private:
        string arg;
        int Line;
    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
