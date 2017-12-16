
## USE_STD_THREAD
## USE_BOOST_THREAD
## HAVE_PTHREAD_H
add_definitions(-DUSE_BOOST_THREAD)

add_subdirectory(posix)

add_subdirectory(std)

add_subdirectory(boost)

set(TEST_THREAD Main.cpp TOutput.cpp)
add_executable(main ${TEST_THREAD})
## posixthread
## stdthread
## boostthread
target_link_libraries(main boostthread)

