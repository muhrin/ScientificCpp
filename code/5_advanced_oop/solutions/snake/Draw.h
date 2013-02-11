

#ifndef DRAW_H
#define DRAW_H

class Vector;

// Drawing and keyboard functions
void initDraw();
void cleanUpDraw();
void drawChars(const unsigned int x, const unsigned int y, const char * const toDraw);
void drawChars(const Vector & pos, const char * const toDraw);
void clearScreen();
void refreshScreen();
int getKey();

// KEY DEFINITIONS
extern const int SKEY_UP;
extern const int SKEY_DOWN;
extern const int SKEY_LEFT;
extern const int SKEY_RIGHT;

#endif
