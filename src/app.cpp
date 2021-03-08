#include "libtcod.hpp"
#include <iostream>

using namespace std;

class Player {
  public:
    std::string name;
    int xPos;
    int yPos;

    Player() {
      name = "Arthur";
      xPos = 40;
      yPos = 25;
    }
};

void initControls(Player& player) {
  TCOD_key_t key;
  TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS,&key,NULL);

  switch(key.vk) {
    case TCODK_UP : player.yPos--; break;
    case TCODK_DOWN : player.yPos++; break;
    case TCODK_LEFT : player.xPos--; break;
    case TCODK_RIGHT : player.xPos++; break;
    case TCODK_ESCAPE : exit(0); break;
    default:break;
  }
}

void renderPlayer(Player& player) {
  TCODConsole::root -> putChar(player.xPos, player.yPos, '@');
}

void initGraphics(Player& player) {
  TCODConsole::root -> clear();
  renderPlayer(player);
  TCODConsole::flush();
}

int main() {
  TCODConsole::initRoot(80, 50, "Wilder 0.01a", false);

  Player player;

  while (!TCODConsole::isWindowClosed()) {
    initControls(player);
    initGraphics(player);
  }

  return 0;
}
