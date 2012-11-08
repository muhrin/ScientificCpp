
add_executable(simple_output
  simple_output.cpp
)

add_executable(simple_input
  simple_input.cpp
)

add_executable(parse_numbers
  parse_numbers.cpp
)

## Copy over files needed by solutions
file(COPY
  caterpillar.txt
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/
)
