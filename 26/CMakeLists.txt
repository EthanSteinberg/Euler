#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(26Prog ${HDRS} ${SRCS})
target_link_libraries(26Prog ${Boost_LIBRARIES} stdc++ gmp)
