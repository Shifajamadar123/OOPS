#pragma once


#include <iostream>
#include <string>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
using namespace std;

class ConnectionProvider {
private:
    sql::Driver* driver;
    sql::Connection* connection;

public:
    ConnectionProvider() : driver(nullptr), connection(nullptr) {}

    ~ConnectionProvider() {
        closeConnection();
    }

    sql::Connection* connectToDatabase(const string& server, const string& user, const string& password, const string& database) {
        try {
            driver = get_driver_instance();
            connection = driver->connect(server, user, password);
            connection->setSchema(database);
            cout << "Connected to MySQL" << endl;
            return connection;
        }
        catch (sql::SQLException& e) {
            cerr << "Error connecting to MySQL: " << e.what() << endl;
            return connection;
        }
    }

    void closeConnection() {
        if (connection != nullptr) {
            delete connection;
            connection = nullptr;
            cout << "Connection closed" << endl;
        }
    }
};

