# Set TARGET(binary file) name for convenience
set(calculator_test ${PROJECT_NAME}_calculator_test)


# Executable that runs the tests.
add_executable(
        ${calculator_test}             # Executable tests file name
        main.test.cpp
        calculator.test.cpp
        calculator.exception.test.cpp
        statement.exception.test.cpp
)


# Link the executable to needed libraries.
target_link_libraries(
        ${calculator_test}
        calculator_lib          # Library we are testing
        gtest_main              # GTest libraries
        gtest
        pthread
        # gmock_main
        # gmock
        # ${CONAN_LIBS}
)


# Add gtest to be able to run ctest.
add_test(
        NAME calculatorTest                    # Test name
        COMMAND ${calculator_test} --gtest_color=1   # Executable tests file name
)