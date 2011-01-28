#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(22Prog ${HDRS} ${SRCS})
target_link_libraries(22Prog ${Boost_LIBRARIES} stdc++)
