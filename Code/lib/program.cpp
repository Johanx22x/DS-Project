#include <program.hh>

Program::Program() {
  this->regions->places = new Proxy(places);
  this->people->climates = new Proxy(climates);
  this->places->climate = new Proxy(climates);
}

int Program::run() {
  this->menu->display();

  while (this->menu->prompt() == CommandCodes::CONTINUE);

  // TODO: return whatever prompt() returns
  return 0;
}
