// Copyright [2022] <https://github.com/damianWu>
#include <gtest/gtest.h>

// Retrieves standard std::cin configuration
class Environment : public ::testing::Environment {
 public:
    ~Environment() override = default;

    // Override this to define how to set up the environment.
    void SetUp() override { orig = std::cin.rdbuf(); }

    // Override this to define how to tear down the environment.
    void TearDown() override { std::cin.rdbuf(orig); }

 private:
    std::streambuf* orig = nullptr;
};

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new Environment);
    return RUN_ALL_TESTS();
}
