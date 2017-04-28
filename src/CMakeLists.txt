add_library(toto
	SHARED
	Dvector.cpp main.cpp)

install (TARGETS toto
	DESTINATION lib)

file (
     GLOB
     headers
     *.hpp
)

install(FILES ${headers}
	DESTINATION include/${CMAKE_PROJECT_NAME}) 