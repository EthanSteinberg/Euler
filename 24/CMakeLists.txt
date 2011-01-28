#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(24Prog ${HDRS} ${SRCS})
target_link_libraries(24Prog ${Boost_LIBRARIES} stdc++ gmp)
