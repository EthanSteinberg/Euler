#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(27Prog ${HDRS} ${SRCS})
target_link_libraries(27Prog ${Boost_LIBRARIES} stdc++ gmp)
