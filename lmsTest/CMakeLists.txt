cmake_minimum_required( VERSION 2.8 )

project( alice )

set( CMAKE_CXX_COMPILER "g++" )
set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x" )

############### dependencies ######################
# Eigen
#include_directories( "/usr/include/eigen3" )
include_directories( "./eigen3" )
############### dependencies ######################

add_executable( alice alice.C )

# copy files
set(cv_Scripts
	)
foreach(_script ${cv_Scripts})
	configure_file(
		${PROJECT_SOURCE_DIR}/${_script}
		${PROJECT_BINARY_DIR}/${_script}
		COPYONLY
		)
endforeach()
