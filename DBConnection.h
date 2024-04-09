#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <string>

class DBConnection {
public:
    virtual ~DBConnection() = default;
    virtual bool open() = 0;
    virtual bool close() = 0;
    virtual std::string execQuery(const std::string& query) = 0;
};

#endif // DBCONNECTION_H

