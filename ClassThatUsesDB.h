#ifndef CLASSTHATUSEDB_H
#define CLASSTHATUSEDB_H

#include "DBConnection.h"
#include <memory>

class ClassThatUsesDB {
private:
    std::unique_ptr<DBConnection> dbConn;

public:
    ClassThatUsesDB(std::unique_ptr<DBConnection> conn) : dbConn(std::move(conn)) {}

    void openConnection() { dbConn->open(); }

    void useConnection(const std::string& query) {
        if (dbConn->open()) {
            dbConn->execQuery(query);
            dbConn->close();
        }
    }

    void closeConnection() { dbConn->close(); }
};

#endif // CLASSTHATUSEDB_H

