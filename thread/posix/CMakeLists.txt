
SET(POSIX_THREAD_SRC PosixThreadFactory.cpp)

##
# HAVE_SCHED_GET_PRIORITY_MAX
# HAVE_SCHED_GET_PRIORITY_MIN
add_definitions(-DHAVE_SCHED_GET_PRIORITY_MAX -DHAVE_SCHED_GET_PRIORITY_MIN)


add_library(posixthread SHARED ${POSIX_THREAD_SRC})
target_link_libraries(posixthread pthread)

