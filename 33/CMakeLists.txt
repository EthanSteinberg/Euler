#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(33Prog ${HDRS} ${SRCS})
target_link_libraries(33Prog ${Boost_LIBRARIES} stdc++ gmp)
