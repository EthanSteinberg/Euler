#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(23Prog ${HDRS} ${SRCS})
target_link_libraries(23Prog ${Boost_LIBRARIES} stdc++ gmp)
