include(AddGoogleTest)
set(TEST_FILES 
	test_template_demo.cpp
)
add_executable(template-demo-test ${TEST_FILES} ${FILES})
target_link_libraries(template-demo-test PRIVATE template_library) 
add_gtest(template-demo-test)
