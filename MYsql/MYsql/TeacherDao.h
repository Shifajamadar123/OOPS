#pragma once


#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Teacher.h"
#include "CourseDao.h"

using namespace std;
class TeacherDao {
private:
    sql::Connection* conn;

public:
    TeacherDao(sql::Connection* connection) : conn(connection) {}

    Teacher* getTeacherById(string teacherId) {
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM teacher WHERE id ='" + teacherId + "'");

            Teacher* teacher=nullptr; // Assuming you have a Teacher class defined

            if (res->next()) {
                teacher = new Teacher();

                teacher->setTeacherId(res->getString("id"));
                teacher->setName(res->getString("name"));
                teacher->setSubject(res->getString("subject"));
                teacher->setSalary(res->getDouble("salary"));
                teacher->setPosition(res->getString("position"));
                teacher->setPassword(res->getString("password"));
            }

            delete res;
            delete stmt;

            return teacher;
        }
        catch (sql::SQLException& e) {
            cerr << "Error retrieving teacher: " << e.what() << endl;
            // Handle the error - returning an empty Teacher object or throwing an exception
            throw runtime_error("Error retrieving teacher information");
        }
    }

    Teacher* verifyLogin(string id, string password) {
        Teacher* teacher = nullptr;
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM teacher WHERE id='" + id + "' AND password='" + password + "'");

            if (res->next()) {
                teacher = new Teacher();

                teacher->setTeacherId(res->getString("id"));
                teacher->setName(res->getString("name"));
                teacher->setSubject(res->getString("subject"));
                teacher->setSalary(res->getDouble("salary"));
                teacher->setPosition(res->getString("position"));
                teacher->setPassword(res->getString("password"));
                delete res;
                delete stmt;
                return teacher; // Login successful
            }

            delete res;
            delete stmt;
            return teacher; // Login failed
        }
        catch (sql::SQLException& e) {
            cerr << "Error verifying login: " << e.what() << endl;
            return teacher; // Login failed due to an error
        }
    }


    void displayTeacher(Teacher* teacher)
    {
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "Your Details: " << endl;
        cout << "Id: " << teacher->getTeacherId() << "\t"
          << "Name: " << teacher->getName() << "\t"
          << "Position: " << teacher->getPosition() << "\t"
          << "Salary: " << teacher->getSalary() << "\t"
          << "Password: " << teacher->getPassword() << "\t" << endl;
        CourseDao dao(conn);
        Course* course = dao.getCourseById(teacher->getSubject());
        dao.displayCourse(course);
    }

    void displayOthers(Teacher* teacher)
    {
        cout << "" << endl;
        cout << "Teacher Details: " << endl;
        cout << "Id: " << teacher->getTeacherId() << "\t"
            << "Name: " << teacher->getName() << "\t"
            << "Position: " << teacher->getPosition() << "\t" << endl;
        CourseDao dao(conn);
        Course* course = dao.getCourseById(teacher->getSubject());
        dao.displayCourse(course);

    }
};

