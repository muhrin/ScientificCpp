

add_executable(lottery
  lottery.cpp
)

add_executable(game_of_life
  game_of_life.cpp
)

target_link_libraries(game_of_life
  ncurses
)
