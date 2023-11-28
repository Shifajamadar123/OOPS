#pragma once
#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string course_id;
    string name;
    string description;
    string duration; // Representing duration as a string

public:
    Course(){}
    // Setters
    void setCourseId(string id) {
        course_id = id;
    }

    void setName(string courseName) {
        name = courseName;
    }

    void setDescription(string courseDescription) {
        description = courseDescription;
    }

    void setDuration(string courseDuration) {
        duration = courseDuration;
    }

    // Getters
    string getCourseId() {
        return course_id;
    }

    string getName() {
        return name;
    }

    string getDescription() {
        return description;
    }

    string getDuration() {
        return duration;
    }
};
