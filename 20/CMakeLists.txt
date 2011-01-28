#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(20Prog ${HDRS} ${SRCS})
target_link_libraries(20Prog ${Boost_LIBRARIES} stdc++)
