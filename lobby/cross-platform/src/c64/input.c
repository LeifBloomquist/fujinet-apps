#ifdef __C64__

/**
 * Cross platform Input functions
 */

#include <peekpoke.h>

unsigned char readJoystick() {
  return 127-PEEK(0xDC00); // joystick 2
}

#endif /* __C64__ */