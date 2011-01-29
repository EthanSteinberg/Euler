#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
      board.cpp
)


add_executable(96Prog ${HDRS} ${SRCS})
target_link_libraries(96Prog ${Boost_LIBRARIES} stdc++ gmp)
