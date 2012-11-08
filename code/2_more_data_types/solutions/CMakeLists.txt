

add_executable(lottery
  lottery.cpp
)

add_executable(game_of_life
  game_of_life.cpp
)

if(UNIX)
  target_link_libraries(game_of_life
    ncurses
  )
endif(UNIX)

add_executable(noughts_crosses
  noughts_crosses
)