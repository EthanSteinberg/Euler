#CMakeLists file for server

set(HDRS 
      )
 
set(SRCS
      main.cpp
)


add_executable(19Prog ${HDRS} ${SRCS})
target_link_libraries(19Prog ${Boost_LIBRARIES} stdc++)
