#pragma once

#include <iostream>
#include <string>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "Marks.h"

using namespace std;

class MarksDao
{
private:
    sql::Connection* conn;

public:
    MarksDao(sql::Connection* connection) : conn(connection) {}

    Marks* getMarksById(string studentId)
    {
        try {
            sql::Statement* stmt = conn->createStatement();
            sql::ResultSet* res = stmt->executeQuery("SELECT * FROM marks WHERE studentid = '" + studentId + "'");

            Marks* marks = nullptr; // Assuming you have a Teacher class defined

            if (res->next()) {
                marks = new Marks();

                marks->setStudentId(res->getString("studentid"));
                marks->setIsa1(res->getDouble("isa1"));
                marks->setIsa2(res->getDouble("isa2"));
                marks->setEsa(res->getDouble("esa"));
                marks->setProject(res->getDouble("project"));
            }

            delete res;
            delete stmt;

            return marks;
        }
        catch (sql::SQLException& e) {
            cerr << "Error retrieving marks: " << e.what() << endl;
            // Handle the error - returning an empty Teacher object or throwing an exception
            throw runtime_error("Error retrieving marks information");
        }
    }

    void editMarks(double newIsa1, double newIsa2, double newEsa, double newProject, const std::string& studentId) {
        try {
            sql::PreparedStatement* pstmt = conn->prepareStatement(
                "UPDATE marks SET isa1 = ?, isa2 = ?, esa = ?, project = ? WHERE studentid = ?"
            );

            pstmt->setDouble(1, newIsa1);
            pstmt->setDouble(2, newIsa2);
            pstmt->setDouble(3, newEsa);
            pstmt->setDouble(4, newProject);
            pstmt->setString(5, studentId);

            pstmt->executeUpdate();

            delete pstmt;
        }
        catch (sql::SQLException& e) {
            cerr << "Error editing marks: " << e.what() << endl;
            throw runtime_error("Error editing marks");
        }
    }


    void displayMarks(Marks* marksObj)
    {

        cout << "" << endl;
        cout << "Marks: " << endl;
        cout << "Student ID: " << marksObj->getStudentId() << "\t" <<
         "ISA1: " << marksObj->getIsa1() << "\t"
         << "ISA2: " << marksObj->getIsa2() << "\t"
         << "ESA: " << marksObj->getEsa() << "\t"
         << "Project: " << marksObj->getProject() << endl;

        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
    }
};

