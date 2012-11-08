
add_executable(gol_with_io
  gol_with_io.cpp
)

if(UNIX)
  target_link_libraries(gol_with_io
    ncurses
  )
endif(UNIX)

add_executable(logger
  logger.cpp
)
