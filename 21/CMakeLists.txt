#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(21Prog ${HDRS} ${SRCS})
target_link_libraries(21Prog ${Boost_LIBRARIES} stdc++)
