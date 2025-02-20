#ifdef __APPLE2__

#include<peekpoke.h>
#include<stdlib.h>

void resetGraphics();

void resetTimer() {
  POKE(162,0);
  POKE(161,0);
}

int getTime() {
  return (PEEK(161)*256)+PEEK(162);
}

void quit() {
  // Possible to revert screen to boot normals
  resetGraphics();
  exit(0);
}

#endif /* __APPLE2__ */