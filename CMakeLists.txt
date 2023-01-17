#project name and minimum cmake version
cmake_minimum_required(VERSION 3.2.1)
project(timelapse-creator)

#c++ version
add_compile_options(-std=c++17)

#find Boost Library
find_package(Boost REQUIRED program_options)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS}) 
endif()

#find OpenCV library
find_package(OpenCV REQUIRED)

#add the path of includes to includes search path
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/include")

#build the source code
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} "${SOURCES}")
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${OpenCV_LIBS})
