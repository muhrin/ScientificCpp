
add_executable(ex_snake
  snake/Draw.cpp
  snake/Draw.h
  snake/Game.h
  snake/Game.cpp
  snake/GameObjects.h
  snake/GameObjects.cpp
  snake/snake.h
  snake/snake.cpp
  snake/snake_game.h
  snake/snake_game.cpp
  snake/World.h
  snake/World.cpp
  snake/WorldObject.h
)

if(UNIX)
  target_link_libraries(ex_snake
    ncurses
  )
endif(UNIX)
