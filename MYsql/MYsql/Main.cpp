#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "ConnectionProvider.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "StudentDao.h"

using namespace std;
const string server = "tcp://127.0.0.1:3306";
const string user = "root";
const string password = "shifa@MYSQL11";
const string database = "schoolmanagement";

int main() {
    ConnectionProvider con;
    sql::Connection* connection = con.connectToDatabase(server, user, password, database);
    if (connection!= NULL)
    {
        cout <<"----------------------------------------------------------------------------------------"<< endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        cout << "Loggin In As:" << endl;
        cout << "1-->Student" << endl;
        cout << "2-->Faculty" << endl;
        cout << "" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------------------------------------------------------------" << endl;
        cout << "" << endl;
        cout << "Enter Choice" << endl;
        int ch = 0;
        cin >> ch ;
        string Id, password;
        switch (ch)
        {
        case 1: {
            cout << "" << endl;
            cout << "Enter Id and Password" << endl;
            cin >> Id;
            cin >> password;
            StudentDao dao(connection);
            Student* student = dao.verifyLogin(Id, password);
            if (student != nullptr)
            {
                dao.displayStudent(student);
            }
            else
            {
                cout << "Login Failed!! Wrong Credentials!!" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "" << endl;
            cout << "Enter Id and Password" << endl;
            cin >> Id;
            cin >> password;
            TeacherDao dao(connection);
            Teacher* teacher = dao.verifyLogin(Id, password);
            if (teacher != nullptr)
            {
                dao.displayTeacher(teacher);
                cout << "----------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------------------------------------------------------" << endl;
                cout << "" << endl;
                cout << "1-->View Your Course Students" << endl;
                cout << "2-->Edit Marks" << endl;
                cout << "" << endl;
                cout << "----------------------------------------------------------------------------------------" << endl;
                cout << "----------------------------------------------------------------------------------------" << endl;
                cout << "" << endl;
                cout << "Enter Choice" << endl;
                int ch = 0;
                cin >> ch;
                switch (ch) {
                case 1: {
                    StudentDao dao1(connection);
                    cout << "" << endl;
                    cout << "" << endl;
                    cout << "Your students" << endl;
                    cout << "" << endl;
                    cout << "----------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------------------------------------------------------" << endl;

                    vector<Student*> list = dao1.getStudentsFromCourse(teacher->getSubject());
                    for (int i = 0; i < list.size(); i++)
                    {
                        dao1.displayOthers(list[i]);
                    }

                    cout << "----------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------------------------------------------------------" << endl;

                    break;
                }
                case 2: {
                    cout << "----------------------------------------------------------------------------------------" << endl;
                    cout << "----------------------------------------------------------------------------------------" << endl;
                    cout << "Enter student id to edit: " << endl;
                    string id;
                    int flag = -1;
                    cin >> id;
                    StudentDao dao1(connection);
                    vector<Student*> list = dao1.getStudentsFromCourse(teacher->getSubject());
                    for (int i = 0; i < list.size(); i++)
                    {
                        if (list[i]->getId() == id)
                        {
                            flag = 0;
                        }
                    }
                    if (flag == 0)
                    {
                        cout << "Enter isa1,isa2,esa and project marks: " << endl;
                        int isa1, isa2, esa, project;
                        cin >> isa1;
                        cin >> isa2;
                        cin >> esa;
                        cin >> project;
                        MarksDao dao1(connection);
                        dao1.editMarks(isa1, isa2, esa, project, id);
                        cout << "Marks updated!! " << endl;
                        cout << "----------------------------------------------------------------------------------------" << endl;
                        cout << "----------------------------------------------------------------------------------------" << endl;

                    }
                    else
                    {

                        cout << "The id does not belong to your course student." << endl;
                    }

                    break;
                }
                default: cout << "Wrong Choice" << endl;
                }
            }
            else
            {
                cout << "Login Failed!! Wrong Credentials!!" << endl;
            }
            break;
        }
        default:cout << "Wrong Choice" << endl;
        }
        con.closeConnection();
    }
    else
    {
        cout << "OOPS :( Could Not Connect To Database" << endl;
    }

    return 0;
}