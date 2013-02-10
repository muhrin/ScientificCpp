
add_executable(vector2
  vector2.cpp
)

add_executable(planets
  planets.cpp
)

add_executable(bouncy_balls
  bouncy_balls.cpp
)

## Copy over files needed by solutions
file(COPY
  bouncy_balls.plt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/
)