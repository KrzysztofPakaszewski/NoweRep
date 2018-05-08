//
// Created by pakakrzy on 08.05.18.
//

#include "Serialization.h"
using namespace academia;


Room::Room(int a, string b, academia::Room::Type c) :id(a),name(b),type(c){}
Serializer::Serializer(ostream* a){
    out =move(unique_ptr<ostream>(a));
}
Serializer::~Serializer(){
    out.release();
}
string Room::ToStr(const Type)const{
    switch(type)
    {
        case Type::COMPUTER_LAB:
            return "COMPUTER_LAB";
        case Type::LECTURE_HALL:
            return "LECTURE_HALL";
        case Type::CLASSROOM:
            return "CLASSROOM";
    }
}
void Room::Serialize(Serializer* temp)const{
    temp->Header("room");
    temp->IntegerField("id",id);
    temp->StringField("name",name);
    temp->StringField("type",ToStr(type));
    temp->Footer("room");
}

Building::Building(int ID,string Name, initializer_list<Room> Rooms):id(ID),name(Name){
    for(auto p :Rooms){
        rooms.emplace_back(p);
    }
}

void Building::Serialize(Serializer* temp)const{
    temp->Header("building");
    temp->IntegerField("id",id);
    temp->StringField("name",name);
    vector<reference_wrapper<const Serializable>> Rooms;
    for(auto p=rooms.begin(); p!=rooms.end();p++)
        Rooms.emplace_back(*p);
    temp->ArrayField("rooms",Rooms);
    temp->Footer("building");
}
JsonSerializer::JsonSerializer(ostream* out):Serializer(out),First(true){}

void JsonSerializer::IntegerField(const std::string &field_name, int value){
    stringstream os;
    os<< value;
    if(!First)
        *out << ", ";
    *out<< "\""<< field_name << "\": "<<os.str();
    First = false;
}
void JsonSerializer::DoubleField(const std::string &field_name, double value){
    stringstream os;
    os<< value;
    if(!First)
        *out << ", ";
    *out<< "\""<< field_name << "\": "<<os.str();
    First = false;
}
void JsonSerializer::StringField(const std::string &field_name, const std::string &value){
    if(!First)
        *out << ", ";
    *out<< "\""<< field_name << "\": \""<<value<<"\"";
    First = false;
}
void JsonSerializer::BooleanField(const std::string &field_name, bool value) {
    if(!First)
        *out << ", ";
    *out << "\""<<field_name<<"\": ";
    First = false;
    if(value)
        *out << "TRUE";
    else
        *out << "FALSE";
}
void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    if(!First)
        *out << ", ";
    *out << "\""<<field_name<<"\": ";
    First = true;
    value.Serialize(this);
}
void JsonSerializer::ArrayField(const std::string &field_name,
                const vector<reference_wrapper<const academia::Serializable>> &value) {
    if(!First)
        *out << ", ";
    *out<< "\""<< field_name << "\": [";
    bool temp=false;
    for(const Serializable& p: value){
        if(temp)
            *out << ", ";
        First = true;
        p.Serialize(this);
        temp=true;
    }
    *out <<"]";

}
void JsonSerializer::Header(const std::string &object_name) {
    *out<<"{";
}
void JsonSerializer::Footer(const std::string &object_name) {
    *out << "}";
}

XmlSerializer::XmlSerializer(ostream* out):Serializer(out){}

void XmlSerializer::IntegerField(const std::string &field_name, int value){
    stringstream os;
    os<< value;
    *out<< "<"<<field_name<<">"<<os.str() << "<\\"<<field_name<<">";
}
void XmlSerializer::DoubleField(const std::string &field_name, double value){
    stringstream os;
    os<< value;
    *out<< "<"<<field_name<<">"<<os.str() << "<\\"<<field_name<<">";
}
void XmlSerializer::StringField(const std::string &field_name, const std::string &value){
    *out<< "<"<<field_name<<">"<<value << "<\\"<<field_name<<">";
}
void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
    *out<< "<"<<field_name<<">";
    if(value)
        *out << "TRUE";
    else
        *out << "FALSE";
    *out << "<\\"<<field_name<<">";
}
void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
    value.Serialize(this);
}
void XmlSerializer::ArrayField(const std::string &field_name,
                                const vector<reference_wrapper<const academia::Serializable>> &value) {
    *out<< "<"<<field_name<<">";
    for(const Serializable& p: value){
        p.Serialize(this);
    }
    *out<< "<\\"<<field_name<<">";

}
void XmlSerializer::Header(const std::string &object_name) {
    *out<<"<"<<object_name<<">";
}
void XmlSerializer::Footer(const std::string &object_name) {
    *out<<"<\\"<<object_name<<">";
}

BuildingRepository::BuildingRepository(initializer_list<Building> list){
    for(auto p=list.begin();p!=list.end();p++)
        List.emplace_back(*p);
}
void BuildingRepository::Add(Building temp){
    List.emplace_back(temp);
}
void BuildingRepository::StoreAll(Serializer* temp)const{
    temp->Header("building_repository");
    vector<reference_wrapper<const Serializable>> Buildings;
    for(auto p=List.begin(); p!=List.end();p++)
        Buildings.emplace_back(*p);
    temp->ArrayField("buildings",Buildings);
    temp->Footer("building_repository");
}
int Building::Id(){
    return id;
}

experimental::optional<Building> BuildingRepository::operator[](int a)const{
    for(auto p: List){
        if(p.Id() == a)
            return experimental::optional<Building>{p};
    }
    return {};
}