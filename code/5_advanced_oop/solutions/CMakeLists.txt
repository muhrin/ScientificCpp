
add_executable(logger
  logger.cpp
)

add_executable(snake
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
  target_link_libraries(snake
    ncurses
  )
endif(UNIX)
