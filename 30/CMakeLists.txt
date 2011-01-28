#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(30Prog ${HDRS} ${SRCS})
target_link_libraries(30Prog ${Boost_LIBRARIES} stdc++ gmp)
