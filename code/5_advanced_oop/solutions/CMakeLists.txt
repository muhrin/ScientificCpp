
add_executable(snake
  snake.h
  snake.cpp
)

if(UNIX)
  target_link_libraries(snake
    ncurses
  )
endif(UNIX)