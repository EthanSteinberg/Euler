#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(29Prog ${HDRS} ${SRCS})
target_link_libraries(29Prog ${Boost_LIBRARIES} stdc++ gmp)
