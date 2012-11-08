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
// TODO: Need to check if the proposed row and column are valid i.e.:
// 1) Are both within bounds 0->3
// 2) Don't fall on a space that has a piece on it already
// If either of the conditions above is not met, print an error
// message and return false.

// If everything is okay at the end then return true.
  return true;
}

void drawBoard()
{
// TODO: Loop over the board array and draw the board.
// Because it's an array of chars you can print these directly
// using the std::cout
// You may want to draw a board between the O/Xs using | and -
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
// TODO: Check if 'row' is a winning row, i.e. all columns contain
// the playerType passed into the function.
// Return true if it is a winner, false otherwise
  return false;
}

bool isWinningCol(const unsigned int col, const char playerType)
{
// TODO: Check if 'col' is a winning column, i.e. all rows contain
// the playerType passed into the function.
// Return true if it is a winner, false otherwise
  return false;
}

bool isWinningDiagonal(const bool diagonal, const char playerType)
{
// TODO: There are two types of diagonal diagonal == DIAGONAL_TOP_LEFT and
// diagonal == DIAGONAL_BOTTOM_LEFT defining where they start.
// Check if the specified diagonal is a winning diagonal for the playerType
// Passed into the function.
// Return true if it is a winner, false otherwise
  return false;
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

// TODO: Print to the screen that it's noughts go

    // Nough goes

    takeTurn(NOUGHT);
    if(checkForWinner(NOUGHT))
      winner = NOUGHT;

// TODO: Print to the screen that it's crosses go

    // Cross goes
    if(winner == EMPTY)
    {
      drawBoard();
      takeTurn(CROSS);
      if(checkForWinner(CROSS))
        winner = CROSS;
    }
  } while(winner == EMPTY);

// TODO: Print a message congratulating the player that one naming them
// using the 'winner' character.
// TODO: Ammend the functions above to also find out which row, column
// or diagonal was the winning one

}
