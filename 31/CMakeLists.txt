#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(31Prog ${HDRS} ${SRCS})
target_link_libraries(31Prog ${Boost_LIBRARIES} stdc++ gmp)
