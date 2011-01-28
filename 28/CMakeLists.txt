#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(28Prog ${HDRS} ${SRCS})
target_link_libraries(28Prog ${Boost_LIBRARIES} stdc++ gmp)
