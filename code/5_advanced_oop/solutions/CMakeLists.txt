
add_executable(snake
  snake.h
  snake.cpp
  snake_game.h
  snake_game.cpp
)

if(UNIX)
  target_link_libraries(snake
    ncurses
  )
endif(UNIX)
