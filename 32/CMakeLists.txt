#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(32Prog ${HDRS} ${SRCS})
target_link_libraries(32Prog ${Boost_LIBRARIES} stdc++ gmp)
