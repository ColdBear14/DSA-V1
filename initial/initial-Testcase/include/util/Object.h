/* 
 * File:   Object.h
 * Author: NTM
 *
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <iomanip>
#include <math.h>
#include <random>
#include <sstream>
using namespace std;

class Object {
private:
    string content;
    friend ostream& operator<<(ostream& os, const Object& object);

public:
    static int num_of_object;

    static void reset() {
        num_of_object = 0;
    }

    Object(string content = "") : content(content) {
        ++num_of_object;
    }

    Object(const Object& object) : content(object.content) {
        ++num_of_object;
    }

    Object& operator=(const Object& object) {
        content = object.content;
        return *this;
    }

    ~Object() {
        --num_of_object;
    }
    
    void setContent(string content) {
        this->content = content;
    }

    string getContent() const {
        return this->content;
    }
    
    bool operator==(Object rhs){
        return content == rhs.content;
    }
    
    static bool objectEQ(Object& lhs, Object& rhs){
        return lhs == rhs;
    }

    static bool objectEQ(Object*& lhs, Object*& rhs){
        return  *lhs == *rhs;
    }
    
    static string object2str(Object& object){
        stringstream os;
        os  << object.content;
        return os.str();
    }

    static string object2str(Object*& object){
        return object2str(*object);
    }
};

int Object::num_of_object = 0;

ostream &operator<<( ostream &os, const Object& object){
    os << object.content;
    return os;
}

#endif /* OBJECT_H */

