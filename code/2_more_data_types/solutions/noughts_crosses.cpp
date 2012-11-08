#include <iostream>

const char EMPTY = ' ';
const char NOUGHT = 'O';
const char CROSS = 'X';
const bool DIAGONAL_TOP_LEFT = false;
const bool DIAGONAL_BOTTOM_LEFT = true;

char board[3][3];

bool checkCoordinates(
  const unsigned int col,
  const unsigned int row)
{
  if(col > 2)
  {
    std::cout << "col coordinate bigger than 2!\n";
    return false;
  }
  if(row > 2)
  {
    std::cout << "row coordinate bigger than 2!\n";
    return false;
  }

  // Check that the coordinates are in a blank space
  if(board[col][row] != EMPTY)
  {
    std::cout << "That space is already taken!\n";
    return false;
  }
  return true;
}

void drawBoard()
{
  for(int row = 0; row < 3; ++row)
  {
    for(int col = 0; col < 3; ++col)
    {
      std::cout << "|" << board[col][row];
    }
    std::cout << "|\n";
  }
}

void takeTurn(const char playerType)
{
  int col, row;
  bool coordinatesValid;
  do
  {
    std::cout << "Please enter col and row between 0 and 2: ";
    std::cin >> col >> row;
    coordinatesValid = checkCoordinates(col, row);
  } while(!coordinatesValid);
  
  board[col][row] = playerType;
}

bool isWinningRow(const unsigned int row, const char playerType)
{
  for(int col = 0; col < 3; ++col)
  {
    if(board[col][row] != playerType)
      return false;
  }
  return true;
}

bool isWinningCol(const unsigned int col, const char playerType)
{
  for(int row = 0; row < 3; ++row)
  {
    if(board[col][row] != playerType)
      return false;
  }
  return true;
}

bool isWinningDiagonal(const bool diagonal, const char playerType)
{
  if(diagonal == DIAGONAL_TOP_LEFT)
  {
    for(int row = 0, col = 0; col < 3; ++row, ++col)
    {
      if(board[col][row] != playerType)
        return false;
    }
  }
  else
  {
    for(int row = 3, col = 0; col < 3; --row, ++col)
    {
      if(board[col][row] != playerType)
        return false;
    }
  }
  return true;
}

bool checkForWinner(const char & winnerType)
{
  // First check nought
  // Columns:
  for(int col = 0; col < 3; ++col)
  {
    if(isWinningCol(col, winnerType))
      return true;

  }
  // Rows:
  for(int row = 0; row < 3; ++row)
  {
    if(isWinningRow(row, winnerType))
      return true;
  }
  // Diagonals:
  if(isWinningDiagonal(DIAGONAL_TOP_LEFT, winnerType))
    return true;

  return false;
}

int main()
{
  for(int col = 0; col < 3; ++col)
  {
    for(int row = 0; row < 3; ++row)
      board[col][row] = EMPTY;
  }

  char winner = EMPTY;
  do
  {
    drawBoard();

    // Nough goes

    takeTurn(NOUGHT);
    if(checkForWinner(NOUGHT))
      winner = NOUGHT;

    // Cross goes
    if(winner == EMPTY)
    {
      drawBoard();
      takeTurn(CROSS);
      if(checkForWinner(CROSS))
        winner = CROSS;
    }
  } while(winner == EMPTY);

  std::cout << "Congratulations " << winner << " you're a winner!";

}
