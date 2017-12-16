
SET(BOOST_THREAD_SRC BoostThreadFactory.cpp)

add_library(boostthread SHARED ${BOOST_THREAD_SRC})
#target_link_libraries(boostthread /usr/local/lib/libboost_thread.so /usr/local/lib/libboost_system.so)
target_link_libraries(boostthread /usr/local/lib/libboost_thread.so /usr/local/lib/libboost_system.so)

