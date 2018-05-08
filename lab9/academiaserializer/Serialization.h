//
// Created by pakakrzy on 08.05.18.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <experimental/optional>

using namespace std;

namespace academia{
    class Serializable;
    class Serializer{
    public:
        Serializer(ostream*);
        ~Serializer();
        virtual void IntegerField(const string& name,int value)=0;
        virtual void DoubleField(const std::string &field_name, double value)=0;
        virtual void StringField(const std::string &field_name, const std::string &value)=0;
        virtual void BooleanField(const std::string &field_name, bool value)=0;
        virtual void SerializableField(const std::string &field_name, const Serializable &value)=0;
        virtual void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const Serializable>> &value)=0;
        virtual void Header(const std::string &object_name)=0;
        virtual void Footer(const std::string &object_name)=0;

    protected:
        unique_ptr<ostream> out;
    };
    class Serializable{
    public:
        virtual void Serialize(Serializer*)const=0;
    };
    class Room : public Serializable{
    public:
        enum Type{
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM
        };
        Room(int,string,Type);
        void Serialize(Serializer*)const override;
        string ToStr(const Type)const;

    private:
        int id;
        string name;
        Type type;
    };

    class Building : public Serializable{
    public:
        Building(int ID,string Name, initializer_list<Room> Rooms);
        void Serialize(Serializer*)const override;
        int Id();

    private:
        int id;
        string name;
        vector<Room> rooms;
    };

    class JsonSerializer : public Serializer{
    public:
        JsonSerializer(ostream* out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    private:
        bool First;
    };

    class XmlSerializer : public Serializer{
    public:
        XmlSerializer(ostream* out);
        void IntegerField(const std::string &field_name, int value) override;
        void DoubleField(const std::string &field_name, double value) override;
        void StringField(const std::string &field_name, const std::string &value) override;
        void BooleanField(const std::string &field_name, bool value) override;
        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;
        void ArrayField(const std::string &field_name,
                        const vector<reference_wrapper<const academia::Serializable>> &value) override;
        void Header(const std::string &object_name) override;
        void Footer(const std::string &object_name) override;
    };

    class BuildingRepository {
    public:
        BuildingRepository(initializer_list<Building> list);
        void Add(Building temp);
        void StoreAll(Serializer*)const;
        experimental::optional<Building> operator[](int a)const;
    private:
        vector<Building> List;

    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
