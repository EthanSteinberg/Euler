#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(25Prog ${HDRS} ${SRCS})
target_link_libraries(25Prog ${Boost_LIBRARIES} stdc++ gmp)
