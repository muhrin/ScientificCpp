
add_executable(snake
  Game.h
  Game.cpp
  snake.h
  snake.cpp
  snake_game.h
  snake_game.cpp
  World.h
  World.cpp
  WorldObject.h
)

if(UNIX)
  target_link_libraries(snake
    ncurses
  )
endif(UNIX)
