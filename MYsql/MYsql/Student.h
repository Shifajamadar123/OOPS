#pragma once

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string id;
    string name;
    string middlename;
    string lastname;
    int rollNo;
    string dob;
    string contact;
    string address;
    string courseId;
    string teacherId;
    string password;

public:
    // Constructors
    Student() :  rollNo(0) {}
    Student(string studentId, string studentName,string studentMiddlename,string studentLastname, int studentRollNo, string studentDob, string studentContact, string studentAddress, string studentCourseId, string studentTeacherId,string studentPassword)
        : id(studentId), name(studentName),middlename(studentMiddlename), lastname(studentLastname), rollNo(studentRollNo), dob(studentDob),
        contact(studentContact), address(studentAddress), courseId(studentCourseId),
        teacherId(studentTeacherId), password(studentPassword) {}

    // Setters
    void setId(string studentId) {
        id = studentId;
    }

    void setName(std::string studentName) {
        name = studentName;
    }

    void setMiddlename(std::string studentMiddlename) {
        middlename = studentMiddlename;
    }

    void setLastname(std::string studentLastname) {
        lastname = studentLastname;
    }

    void setRollNo(int studentRollNo) {
        rollNo = studentRollNo;
    }

    void setDOB(std::string studentDob) {
        dob = studentDob;
    }

    void setContact(std::string studentContact) {
        contact = studentContact;
    }

    void setAddress(std::string studentAddress) {
        address = studentAddress;
    }

    void setCourseId(string studentCourseId) {
        courseId = studentCourseId;
    }

    void setTeacherId(string studentTeacherId) {
        teacherId = studentTeacherId;
    }

    void setPassword(string studentPassword)
    {
        password = studentPassword;
    }


    // Getters
    string getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getMiddlename() {
        return middlename;
    }

    string getLastname() {
        return lastname;
    }

    int getRollNo() {
        return rollNo;
    }

    string getDOB() {
        return dob;
    }

    string getContact() {
        return contact;
    }

    string getAddress() {
        return address;
    }

    string getCourseId() {
        return courseId;
    }

    string getTeacherId() {
        return teacherId;
    }

    string getPassword() {
        return password;
    }


    // Display Student Information
    void displayInfo() {
        cout << "ID: " << id << "\nName: " << name << "\nRoll No: " << rollNo
            << "\nDOB: " << dob << "\nContact: " << contact << "\nAddress: " << address
            << "\nCourse ID: " << courseId << "\nTeacher ID: " << teacherId << endl;
    }
};
