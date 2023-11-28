#pragma once
#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Course.h"

using namespace std;
class CourseDao {
private:
    sql::Connection* conn;

public:
    CourseDao(sql::Connection* connection) : conn(connection) {}

    Course* getCourseById(string courseId) {
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM course WHERE coursesid = '" + courseId+"'");

            Course* course = nullptr; // Assuming you have a Teacher class defined

            if (res->next()) {
                course = new Course();

                course->setCourseId(res->getString("coursesid"));
                course->setName(res->getString("name"));
                course->setDescription(res->getString("description"));
                course->setDuration(res->getString("duration"));
            }

            delete res;
            delete stmt;

            return course;
        }
        catch (sql::SQLException& e) {
            cerr << "Error retrieving course: " << e.what() << endl;
            // Handle the error - returning an empty Teacher object or throwing an exception
            throw runtime_error("Error retrieving course information");
        }
    }

    void displayCourse(Course * course)
    {
        cout << "" << endl;
        cout << "Course Details: " << endl;
        cout << "Course-id: " << course->getCourseId() << "\t"
         << "Course Name: " << course->getName() << "\t"
         << "Description: " << course->getDescription() << "\t"
         << "Duration of the course: " << course->getDuration() << "\t" << endl;
        

    }
};

