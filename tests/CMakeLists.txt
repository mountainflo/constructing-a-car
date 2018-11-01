# define all tests here
set(TESTS construct-car-test.cpp)

add_executable(${TEST_NAME} catch.h main.cpp ${TESTS})

# add all used libraries
target_link_libraries(${TEST_NAME} ${EXEC_NAME})
