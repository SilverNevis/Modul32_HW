#pragma comment(lib, "libcpmt.lib")
#pragma comment(lib, "msvcprtd.lib")

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockDBConnection.h"
#include "ClassThatUsesDB.h"

TEST(ClassThatUsesDbTest, TestOpenCloseDb) {
    auto mockDb = std::make_unique<MockDBConnection>();
    EXPECT_CALL(*mockDb, open()).WillOnce(testing::Return(true));
    EXPECT_CALL(*mockDb, close()).WillOnce(testing::Return(true));

    ClassThatUsesDB classUnderTest(std::move(mockDb));
    classUnderTest.openConnection();
    classUnderTest.closeConnection();
}

TEST(ClassThatUsesDbTest, TestUseDbWithOpenCloseAndExecQuery) {
    auto mockDb = std::make_unique<MockDBConnection>();

    EXPECT_CALL(*mockDb, open()).WillOnce(testing::Return(true));
    EXPECT_CALL(*mockDb, execQuery(testing::_)).WillOnce(testing::Return("Query Executed"));
    EXPECT_CALL(*mockDb, close()).WillOnce(testing::Return(true));

    ClassThatUsesDB classUnderTest(std::move(mockDb));
    classUnderTest.useConnection("SELECT * FROM table");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
