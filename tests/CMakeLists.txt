include(AddGoogleTest)
## Added these
include_directories("${PROJECT_SOURCE_DIR})/include")
set(FILES ../src/library.c ../include/template_demo/library.h)
##

set(TEST_FILES test_template_demo.cpp)
add_executable(template-demo-test ${TEST_FILES} ${FILES})
add_gtest(template-demo-test)