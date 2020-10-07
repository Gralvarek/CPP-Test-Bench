
set(HEADER_LIST "${Test_CMake_SOURCE_DIR}/include/Test_CMake/Print.hpp")

add_library(print_library STATIC Print.cpp ${HEADER_LIST})

target_include_directories(print_library PUBLIC ../include)
set_target_properties(print_library PROPERTIES LINKER_LANGUAGE CXX)

source_group(
	TREE "${Test_CMake_SOURCE_DIR}/include"
	PREFIX "Header Files"
	FILES ${HEADER_LIST}
)