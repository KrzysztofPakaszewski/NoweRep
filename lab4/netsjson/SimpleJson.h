//
// Created by krzysztof on 22.03.2018.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H
#include <experimental/optional>
#include <string>
#include <map>
#include <vector>


using namespace std;



namespace nets {
    class JsonValue {
    public:
        JsonValue(int);
        JsonValue(double);
        JsonValue(string);
        JsonValue(bool);
        JsonValue(map<string,nets::JsonValue>);
        JsonValue(vector<nets::JsonValue>);

        std::experimental::optional<JsonValue> ValueByName(const std::string &name) const;
        std::string ToString() const;


        string choose() const;
        string GetInteger() const;
        string GetDouble() const;
        string GetString() const;
        string GetBool() const;
        string GetMap() const;
        string GetArray() const;


    private:
        int which;
        int integer;
        double doubleNum;
        string stringObject;
        bool boolObject;
        map<string,nets::JsonValue> mapObject;
        vector<nets::JsonValue> JsonArray;

    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
