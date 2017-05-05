configure_file(CMakeLists.txt in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
		${CMAKE_BINARY_DIR}/googletest-build)
add_subdirectory(test)
enable_testing()
add_executable(test_prng test_prng.cxx)
target_link_libraries(test_prng gtest gmock_main)
add_test(NAME prng_test
	 COMMAND test_prng)