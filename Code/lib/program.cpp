#include "instant.hh"
#include "proxy.hh"
#include <region.hh>
#include <person.hh>
#include <program.hh>
#include <util.hh>

Program::Program() {
  this->regions->places = new Proxy(places);
  this->people->climates = new Proxy(climates);
  this->places->climate = new Proxy(climates);

  Person *maria = new Person("Maria Herrera", "2012", 24, "Ciudad Quesada", 1615329182);
  this->people = sortedInsert(this->people, maria);

  Person *alonso = new Person("Alonso Porras", "2005", 28, "Aguas Zarcas", 1660182194);
  this->people = sortedInsert(this->people, alonso);

  Person *johan = new Person("Johan Rodriguez", "2022141892", 18, "Santa Rosa", 1531721412);
  this->people = sortedInsert(this->people, johan);

  Person *gabriel = new Person("Gabriel Alfaro", "2018", 22, "San Ramon", 1662873645);
  this->people = sortedInsert(this->people, gabriel);

  Region *sanRamon = new Region("San Ramon", "A-2", "Alajuela, Costa Rica");
  this->regions = insert(this->regions, sanRamon);

  Region *laCruz = new Region("La Cruz", "G-1", "Guanacaste, Costa Rica");
  this->regions = insert(this->regions, laCruz);

  Region *cartago = new Region("Cartago", "C-1", "Cartago, Costa Rica");
  this->regions = insert(this->regions, cartago);

  Region *monteverde = new Region("Monteverde", "P-1", "Puntarenas, Costa Rica");
  this->regions = insert(this->regions, monteverde);

  Region *pococi = new Region("Pococi", "L-1", "Limon, Costa Rica");
  this->regions = insert(this->regions, pococi);

  Place *santaCecilia = new Place("Santa Cecilia", 1231, 23132.1, laCruz);
  this->places = insert(this->places, santaCecilia);
  laCruz->places = new Proxy(santaCecilia);

  Place *sanRamonPlace = new Place("San Ramon", 15802, 3782.1, sanRamon);
  this->places = insert(this->places, sanRamonPlace);
  sanRamon->places = new Proxy(sanRamonPlace);

  Place *guapiles = new Place("Guapiles", 541332, 321874.312, pococi);
  this->places = insert(this->places, guapiles);
  pococi->places = new Proxy(guapiles);

  Place *cartagoPlace = new Place("Cartago", 903124, 32184.122, cartago);
  this->places = insert(this->places, cartagoPlace);
  cartago->places = new Proxy(cartagoPlace);

  Place *santaElena = new Place("Santa Elena", 6327, 7412.31, monteverde);
  this->places = insert(this->places, santaElena);
  monteverde->places = new Proxy(santaElena);

  Region *sanCarlos = this->regions->search("5");
  if (sanCarlos == nullptr) {
    printf("FATAL ERROR!!\n");
  }
  Place *ciudadQuesada = new Place("Ciudad Quesada", 32183, 3124.2, sanCarlos);
  this->places = insert(this->places, ciudadQuesada);
  sanCarlos->places->append(new Proxy(ciudadQuesada));

  Rain *rainOne = new Rain("Thunder", "R-2", 21.3);
  this->rains = insert(this->rains, rainOne);

  Rain *rainTwo = new Rain("Cloudy", "R-3", 54.12);
  this->rains = insert(this->rains, rainTwo);

  Rain *rainThree= new Rain("Sunny", "R-4", 31.43);
  this->rains = insert(this->rains, rainThree);

  Rain *rainFour = new Rain("Dry", "R-5", 90.12);
  this->rains = insert(this->rains, rainFour);

  Rain *rainFive = new Rain("Strong rain", "R-6", 72.31);
  this->rains = insert(this->rains, rainFive);

  Climate *climateOne = new Climate("2", 4.1, 8.1, 2.1, 0.1, 83.12, 'S', true, 1665147440, 1665147440, 1665147823, rainOne, santaElena, johan);
  this->climates->append(climateOne);
  santaElena->climate = new Proxy(climateOne);
  johan->climates = new Proxy(climateOne);

  Climate *climateTwo = new Climate("3", 8.2, 3.1, 5.2, 2.5, 23.41, 'W', false, 1665147440, 1665147440, 1665147823, rainTwo, santaCecilia, johan);
  this->climates->append(climateTwo);
  santaCecilia->climate = new Proxy(climateTwo);
  johan->climates->append(new Proxy(climateTwo));

  Climate *climateThree = new Climate("4", 1.2, 8.2, 8.5, 8.3, 74.31, 'E', false, 1665147440, 1665147440, 1665147823, rainThree, guapiles, maria);
  this->climates->append(climateThree);
  guapiles->climate = new Proxy(climateThree);
  maria->climates = new Proxy(climateThree);

  Climate *climateFour = new Climate("5", 5.3, 9.2, 3.1, 5.2, 41.21, 'S', false, 1665147440, 1665147440, 1665147823, rainFour, sanRamonPlace, gabriel);
  this->climates->append(climateFour);
  sanRamonPlace->climate = new Proxy(climateFour);
  gabriel->climates = new Proxy(climateFour);

  Climate *climateFive = new Climate("6", 9.1, 9.4, 7.7, 5.1, 84.92, 'N', true, 1665147440, 1665147440, 1665147823, rainFive, sanRamonPlace, alonso);
  this->climates->append(climateFive);
  sanRamonPlace->climate->append(new Proxy(climateFive));
  alonso->climates = new Proxy(climateFive);

  this->instants = sortedInsert(this->instants, new Instant("Early cloudy sun", 1518924332, 1518924332, 1518944332));
  this->instants = sortedInsert(this->instants, new Instant("Early rainy sun", 1511224332, 1511224332, 1518123332));
  this->instants = sortedInsert(this->instants, new Instant("Shiny sun", 1518314332, 1518924332, 1518123332));
  this->instants = sortedInsert(this->instants, new Instant("Rainy day without sun", 1518321332, 1518321332, 1518900332));
  this->instants = sortedInsert(this->instants, new Instant("Late sunrise", 1321924332, 1321924332, 1321954332));
}

int Program::run() {
  this->menu->display();

  while (this->menu->prompt() == CommandCodes::CONTINUE);

  // TODO: return whatever prompt() returns
  return 0;
}
