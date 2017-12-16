
SET(STD_THREAD_SRC StdThreadFactory.cpp)

set(CMAKE_CXX_FLAGS "-O0 -std=c++11")

add_library(stdthread SHARED ${STD_THREAD_SRC})

## Notice. the std::thread depends on pthread.
target_link_libraries(stdthread pthread)

