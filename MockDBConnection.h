#ifndef MOCKDBCONNECTION_H
#define MOCKDBCONNECTION_H

#include "DBConnection.h"
#include <gmock/gmock.h>

class MockDBConnection : public DBConnection {
public:
    MOCK_METHOD(bool, open, (), (override));
    MOCK_METHOD(bool, close, (), (override));
    MOCK_METHOD(std::string, execQuery, (const std::string& query), (override));
};

#endif // MOCKDBCONNECTION_H

