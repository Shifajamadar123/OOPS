#pragma once


#include <iostream>
#include <string>
using namespace std;

class Teacher {
private:
    string teacher_id;
    string name;
    string subject;
    double salary;
    string position;
    string password;


public:
    // Constructor
    Teacher() {}

    Teacher(string id, const string& teacherName, string subj, double sal, const string& pos, const string& pass)
        : teacher_id(id), name(teacherName), subject(subj), salary(sal), position(pos), password(pass) {}


public:
    // Setters
    void setTeacherId(string id) {
        teacher_id = id;
    }

    void setName(string teacherName) {
        name = teacherName;
    }

    void setSubject(string teacherSubject) {
        subject = teacherSubject;
    }

    void setSalary(double teacherSalary) {
        salary = teacherSalary;
    }

    void setPosition(string teacherPosition) {
        position = teacherPosition;
    }

    void setPassword(string teacherPassword) {
        password = teacherPassword;
    }

    // Getters
    string getTeacherId() {
        return teacher_id;
    }

    string getName() {
        return name;
    }

    string getSubject() {
        return subject;
    }

    double getSalary() {
        return salary;
    }

    string getPosition() {
        return position;
    }

    string getPassword() {
        return password;
    }

};
