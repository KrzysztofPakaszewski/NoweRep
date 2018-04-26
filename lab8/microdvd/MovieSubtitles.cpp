//
// Created by krzysztof on 25.04.2018.
//

#include <iostream>
#include "MovieSubtitles.h"
using namespace moviesubs;

void MicroDvdSubtitles::ShiftAllSubtitlesBy(int miliseconds,int FrameRate,stringstream* input,stringstream* output){
    if(FrameRate<0)
        throw invalid_argument("Negative frame rate");
    regex pattern {R"(\{(\w+)\}\{(\w+)\})"};
    smatch matches;
    string temp;
    string in = input->str();
    vector<string> Subtitles;
    int shift= miliseconds*FrameRate/1000;
    for(int a=0;a<in.size();a++)
    {
        if(in[a] == '\n'){
            Subtitles.emplace_back(temp);
            temp="";
        }
        else
            temp+= in[a];
    }
    if(temp != "")
        Subtitles.emplace_back(temp);
    for(int a=0;a<Subtitles.size();a++)
    {
        if(regex_search(Subtitles[a],matches,pattern)){
            CheckFramesBeforeShift(matches[1],matches[2],a+1,Subtitles[a]);
            int first = stoi(matches[1]);
            int second =stoi(matches[2]);
            first+=shift;
            second+=shift;
            CheckFramesAfterShift(first,second,a+1,Subtitles[a]);
            stringstream os;
            os<<first;
            temp= "{" + os.str()+"}{";
            os.str("");
            os<< second;
            temp = temp + os.str()+"}";
            Subtitles[a].replace(Subtitles[a].find(matches[0]),matches[0].length(),temp);
            *output<<Subtitles[a] <<"\n";
        }
        else
        {
            throw InvalidSubtitleLineFormat(Subtitles[a],a+1);
        }
    }

}

void MicroDvdSubtitles::CheckFramesAfterShift(int first, int second,int Line,string input) {
    if(first>second)
        throw SubtitleEndBeforeStart(input,Line);
    if(first<0 || second<0)
        throw NegativeFrameAfterShift(input,Line);


}
void MicroDvdSubtitles::CheckFramesBeforeShift(string first, string second, int Line,string input){
    for(int a=0;a<first.size();a++)
    {
        if(int(first[a])<48 || int(first[a])>57)
            throw InvalidSubtitleLineFormat(input,Line);
    }
    for(int a=0;a<second.size();a++)
    {
        if(int(second[a])<48 || int(second[a])>57)
            throw InvalidSubtitleLineFormat(input,Line);
    }
}

NegativeFrameAfterShift::NegativeFrameAfterShift(const string & __arg,int line):invalid_argument(__arg),Line(line),arg(__arg){}

const char* NegativeFrameAfterShift::what() const throw(){
    stringstream os;
    os<< Line;
    return ("At line "+os.str()+ ": "+ arg +" Negative frame after shift").c_str();
}
int NegativeFrameAfterShift::LineAt(){
    return Line;
}

SubtitleEndBeforeStart::SubtitleEndBeforeStart(const string& __arg, int Line):invalid_argument(__arg),arg(__arg),Line(Line){}

const char* SubtitleEndBeforeStart::what() const throw(){
    stringstream os;
    os<<Line;
    return ("At line "+os.str()+": "+arg).c_str();
}

InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(const string& __arg,int Line):invalid_argument(__arg),Line(Line),arg(__arg){}

const char* InvalidSubtitleLineFormat::what() const throw(){
    stringstream os;
    os<<Line;
    return ("At line "+os.str()+": "+arg+" Invalid subtitle line format").c_str();
}

void SubRipSubtitles::ShiftAllSubtitlesBy(int miliseconds,int FrameRate,stringstream* input,stringstream* output){
    if(FrameRate<0)
        throw invalid_argument("negative frame rate");
    regex pattern {R"(((\w\w):(\w\w):(\w\w),(\w\w\w)) --> ((\w\w):(\w\w):(\w\w),(\w\w\w)))"};
    regex patternGeneral{R"(([0-9]+)\n(.+)\n)"};
    smatch matchGeneral,matches;
    string In=input->str();
    string Out=In;
    int move=0;
    int line=1;
    while(regex_search(In,matchGeneral,patternGeneral)){
        if(line != stoi(matchGeneral[1]))
            throw OutOfOrderFrames(matchGeneral[0],line);
        string ForSearch=matchGeneral[2];
        if(regex_search(ForSearch,matches,pattern)){
            for(int a=0; a<matches[1].str().size();a++)
            {
                if(matches[1].str()[a] == ':' || matches[1].str()[a] == ',')
                    continue;
                if(int(matches[1].str()[a])<48 || int(matches[1].str()[a])>57 )
                    throw InvalidSubtitleLineFormat(matchGeneral[0],line);
            }
            for(int a=0; a<matches[6].str().size();a++)
            {
                if(matches[6].str()[a] == ':'|| matches[6].str()[a] == ',')
                    continue;
                if(int(matches[6].str()[a])<48 || int(matches[6].str()[a])>57 )
                    throw InvalidSubtitleLineFormat(matchGeneral[0],line);
            }
            string temp =Add(matches,miliseconds,line,matches[0]);
            size_t position = In.find(matches[0])+move;
            Out.replace(position,matches[0].length(),temp);
            move = position+temp.length();
            In=In.c_str()+move;
        } else
            throw InvalidSubtitleLineFormat(matchGeneral[2],1);
        line++;
    }
    *output<<Out;
}
string SubRipSubtitles::Add(smatch input,int delay,int linenumber, string Line ){
    long first =stoi(input[2])*3600*1000+stoi(input[3])*60*1000+stoi(input[4])*1000+stoi(input[5]);
    long second=stoi(input[7])*3600*1000+stoi(input[8])*60*1000+stoi(input[9])*1000+stoi(input[10]);
    if(first>second)
        throw SubtitleEndBeforeStart(Line,linenumber);
    first= first+delay;
    second=second+delay;
    if(first <0 || second <0)
        throw NegativeFrameAfterShift(Line,linenumber);
    return convert(first)+" --> "+convert(second);
}
string SubRipSubtitles::convert(long number){
    int Number = number;
    int temp = number/3600000;
    string result;
    stringstream os;
    os<< temp;
    if(temp < 10)
        result = "0"+ os.str()+":";
    else
        result=os.str()+":";
    os.str("");
    Number= Number- temp*3600000;
    temp = Number/60000;
    os<<temp;
    if(temp < 10)
        result =result+ "0"+ os.str()+":";
    else
        result=result+os.str()+":";
    os.str("");
    Number=Number-temp*60000;
    temp=Number/1000;
    os<<temp;
    if(temp < 10)
        result = result+"0"+ os.str()+",";
    else
        result=result+os.str()+",";
    os.str("");
    Number=Number-temp*1000;
    os<<Number;
    if(Number < 10)
        result =result+ "00"+ os.str();
    else if (Number < 100)
        result = result+"0"+os.str();
    else
        result=result+os.str();
    os.str("");
    return result;

}
OutOfOrderFrames::OutOfOrderFrames(const string& __arg,int line):invalid_argument(__arg),arg(__arg),Line(line){}
const char* OutOfOrderFrames::what() const throw(){
    stringstream os;
    os << Line;
    return ("At line "+os.str()+ " Frames out of order").c_str();
}

MissingTimeSpecification::MissingTimeSpecification(const string& __arg,int line):invalid_argument(__arg),Line(line),arg(__arg){}
const char* MissingTimeSpecification::what() const throw(){
    stringstream os;
    os << Line;
    return ("At line "+os.str()+ " Missing time specification").c_str();
}