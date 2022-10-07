#include <program.hh>
#include <util.hh>

Program::Program() {
  this->regions->places = new Proxy(places);
  this->people->climates = new Proxy(climates);
  this->places->climate = new Proxy(climates);

  this->people = sortedInsert(this->people, new Person("Maria Herrera", "2012", 24, "Ciudad Quesada", 1615329182));
  this->people = sortedInsert(this->people, new Person("Alonso Porras", "2005", 28, "Aguas Zarcas", 1660182194));
  this->people = sortedInsert(this->people, new Person("Johan Rodriguez", "2022141892", 18, "Santa Rosa", 1531721412));
  this->people = sortedInsert(this->people, new Person("Elena Quesada", "2018", 22, "San Ramon", 1662873645));
}

int Program::run() {
  this->menu->display();

  while (this->menu->prompt() == CommandCodes::CONTINUE);

  // TODO: return whatever prompt() returns
  return 0;
}
