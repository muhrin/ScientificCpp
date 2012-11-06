
add_executable(fractal_forest
  fractal_forest.cpp
)

add_executable(lottery_odds
  lottery_odds.cpp
)

add_executable(fibonacci
  fibonacci.cpp
)

add_executable(pi
  pi.cpp
)

## Copy over files needed by solutions
file(COPY
  fractal_forest.plt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/
)
