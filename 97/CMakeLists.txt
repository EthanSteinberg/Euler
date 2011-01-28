#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(97Prog ${HDRS} ${SRCS})
target_link_libraries(97Prog ${Boost_LIBRARIES} stdc++ gmp)
