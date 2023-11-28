#pragma once


#include <iostream>
#include <string>
#include <vector>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "Student.h"
#include "TeacherDao.h"
#include "MarksDao.h"

using namespace std;

class StudentDao {
private:
    sql::Connection* conn;

public:
    StudentDao(sql::Connection* connection) : conn(connection) {}

    Student* verifyLogin(string id,string password) {
        Student* student = nullptr;
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM student WHERE id='" + id + "' AND password='" + password + "'");

            if (res->next()) {
                student = new Student();
                student->setId(res->getString("id"));
                student->setName(res->getString("name"));
                student->setMiddlename(res->getString("middlename"));
                student->setLastname(res->getString("lastname"));
                student->setRollNo(res->getInt("rollno"));
                student->setDOB(res->getString("dob"));
                student->setContact(res->getString("contact"));
                student->setAddress(res->getString("address"));
                student->setCourseId(res->getString("courseid"));
                student->setTeacherId(res->getString("teacherid"));
                student->setPassword(res->getString("password"));
                delete res;
                delete stmt;
                return student; // Login successful
            }

            delete res;
            delete stmt;
            return student; // Login failed
        }
        catch (sql::SQLException& e) {
            cerr << "Error verifying login: " << e.what() << endl;
            return student; // Login failed due to an error
        }
    }

    vector<Student*> getStudentsFromCourse(string courseId) {
        vector<Student*> students;
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM student WHERE courseid='" + courseId + "'");

            while (res->next()) {
                Student* student = new Student();
                student->setId(res->getString("id"));
                student->setName(res->getString("name"));
                student->setMiddlename(res->getString("middlename"));
                student->setLastname(res->getString("lastname"));
                student->setRollNo(res->getInt("rollno"));
                student->setDOB(res->getString("dob"));
                student->setContact(res->getString("contact"));
                student->setAddress(res->getString("address"));
                student->setCourseId(res->getString("courseid"));
                student->setTeacherId(res->getString("teacherid"));
                student->setPassword(res->getString("password"));
                students.push_back(student);
            }

            delete res;
            delete stmt;
        }
        catch (sql::SQLException& e) {
            cerr << "Error retrieving students: " << e.what() << endl;
        }
        return students;
    }


    void displayStudent(Student* student)
    {
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "Your Details: " << endl;
        cout << "id: " << student->getId() << "\t"
          << "Name: " << student->getName() << "\t"
          << "Middle Name: " << student->getMiddlename() << "\t"
          << "Last Name: " << student->getLastname() << "\t"
          << "Roll.No: " << student->getRollNo() << "\t"
          << "DOB: " << student->getDOB() << "\t"
          << "Contact: " << student->getContact() << "\t"
          << "Address: " << student->getAddress() << "\t"
          << "Password: " << student->getPassword() << endl;

        TeacherDao dao(conn);
        Teacher* teacher = dao.getTeacherById(student->getTeacherId());
        dao.displayOthers(teacher);
        MarksDao dao1(conn);
        Marks* marks = dao1.getMarksById(student->getId());
        dao1.displayMarks(marks);
    }

    void displayOthers(Student* student)
    {
        cout << "id: " << student->getId() << "\t"
            << "Name: " << student->getName() << "\t"
            << "Middle Name: " << student->getMiddlename() << "\t"
            << "Last Name: " << student->getLastname() << "\t"
            << "Roll.No: " << student->getRollNo() << "\t"
            << "DOB: " << student->getDOB() << "\t"
            << "Contact: " << student->getContact() << "\t"
            << "Address: " << student->getAddress() << "\t"
            << endl;

        TeacherDao dao(conn);
        Teacher* teacher = dao.getTeacherById(student->getTeacherId());
        dao.displayOthers(teacher);
    }
};


