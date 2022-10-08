/**
 * Here is implemented all the methods form the Program header file
 *
 * @author Johan Rodriguez, Aaron Gonzalez
 * @version 1.0
 *
 * last modification: 07/10/2022
 */

#include <instant.hh>
#include <proxy.hh>
#include <region.hh>
#include <person.hh>
#include <program.hh>
#include <util.hh>

// Charge the data inside the constructor of the program
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

  Place *monteverdePlace = new Place("Monteverde", 2314, 89214.532, monteverde);
  this->places = insert(this->places, monteverdePlace);
  monteverde->places = new Proxy(monteverdePlace);

  Region *sanCarlos = this->regions->search("A-1");
  if (sanCarlos == nullptr) {
    printf("FATAL ERROR!!\n");
  }

  Place *ciudadQuesada = new Place("Ciudad Quesada", 32183, 3124.2, sanCarlos);
  this->places = insert(this->places, ciudadQuesada);
  sanCarlos->places->append(new Proxy(ciudadQuesada));

  Place *laTigra = new Place("La Tigra", 9804, 54323.523, sanCarlos);
  this->places = insert(this->places, laTigra);
  sanCarlos->places->append(new Proxy(laTigra));

  Place *platanar = new Place("Platanar", 3214, 4123.53, sanCarlos);
  this->places = insert(this->places, platanar);
  sanCarlos->places->append(new Proxy(platanar));

  Place *fortuna = new Place("La Fortuna", 54321, 8912.31, sanCarlos);
  this->places = insert(this->places, fortuna);
  sanCarlos->places->append(new Proxy(fortuna));

  Rain *rainOne = new Rain("Thunder", "R-2", 8.3);
  this->rains = insert(this->rains, rainOne);

  Rain *rainTwo = new Rain("Cloudy", "R-3", 5.12);
  this->rains = insert(this->rains, rainTwo);

  Rain *rainThree= new Rain("Sunny", "R-4", 3.70);
  this->rains = insert(this->rains, rainThree);

  Rain *rainFour = new Rain("Dry", "R-5", 0.12);
  this->rains = insert(this->rains, rainFour);

  Rain *rainFive = new Rain("Strong rain", "R-6", 9.31);
  this->rains = insert(this->rains, rainFive);

  Rain *rainSix = new Rain("Only sun day", "R-7", 3.31);
  this->rains = insert(this->rains, rainSix);

  Rain *rainSeven = new Rain("Extremely rainy", "R-8", 9.99);
  this->rains = insert(this->rains, rainSeven);

  Rain *rainEight = new Rain("Cloudy and sunny", "R-9", 3.54);
  this->rains = insert(this->rains, rainEight);

  Rain *rainNine = new Rain("Ultra sunny", "R-10", 0.54);
  this->rains = insert(this->rains, rainNine);

  Rain *rainTen = new Rain("Ultra dry", "R-11", 0);
  this->rains = insert(this->rains, rainTen);

  Rain *rainEleven = new Rain("Rainy and cloudy", "R-12", 5.4);
  this->rains = insert(this->rains, rainEleven);

  Rain *rainTwelve = new Rain("Cloudy and shiny", "R-13", 3.5);
  this->rains = insert(this->rains, rainTwelve);

  Rain *rainThirteen = new Rain("Ultra cloudy", "R-14", 4.83);
  this->rains = insert(this->rains, rainThirteen);

  Climate *climateOne = new Climate("2", 4.1, 28.1, 22.1, 0.1, 83.12, 'S', true, 1661247440, 1661247440, 1661249940, rainOne, santaElena, johan);
  this->climates->append(climateOne);
  santaElena->climate = new Proxy(climateOne);
  johan->climates = new Proxy(climateOne);

  Climate *climateTwo = new Climate("3", 8.2, 31.1, 25.2, 2.5, 23.41, 'W', false, 1665147440, 1665147440, 1665147823, rainTwo, santaCecilia, johan);
  this->climates->append(climateTwo);
  santaCecilia->climate = new Proxy(climateTwo);
  johan->climates->append(new Proxy(climateTwo));

  Climate *climateThree = new Climate("4", 1.2, 29.2, 18.5, 8.3, 74.31, 'E', false, 1664347440, 1664347440, 1661247440, rainThree, guapiles, maria);
  this->climates->append(climateThree);
  guapiles->climate = new Proxy(climateThree);
  maria->climates = new Proxy(climateThree);

  Climate *climateFour = new Climate("5", 5.3, 29.2, 23.1, 5.2, 41.21, 'S', false, 1661947440, 1661947440, 1665231440, rainFour, sanRamonPlace, gabriel);
  this->climates->append(climateFour);
  sanRamonPlace->climate = new Proxy(climateFour);
  gabriel->climates = new Proxy(climateFour);

  Climate *climateFive = new Climate("6", 9.1, 29.4, 27.7, 5.1, 84.92, 'N', true, 1612347440, 1612347440, 1665148440, rainFive, sanRamonPlace, alonso);
  this->climates->append(climateFive);
  sanRamonPlace->climate->append(new Proxy(climateFive));
  alonso->climates = new Proxy(climateFive);

  Climate *climateSix = new Climate("7", 2.3, 30, 19.7, 31.2, 13.21, 'W', false, 1641342954, 1641306954, 1641342954, rainSix, ciudadQuesada, alonso);
  this->climates->append(climateSix);
  ciudadQuesada->climate = new Proxy(climateSix);
  alonso->climates->append(new Proxy(climateSix));

  Climate *climateSeven = new Climate("8", 9.8, 22.1, 19.7, 31.2, 13.21, 'E', true, 1642339614, 1642339614, 1642382814, rainSeven, ciudadQuesada, johan);
  this->climates->append(climateSeven);
  ciudadQuesada->climate->append(new Proxy(climateSeven));
  johan->climates->append(new Proxy(climateSeven));

  Climate *climateEight = new Climate("9", 5.5, 28.2, 22.5, 12.2, 44.31, 'S', true, 1644416814, 1644416814, 1644463614, rainEight, ciudadQuesada, maria);
  this->climates->append(climateEight);
  ciudadQuesada->climate->append(new Proxy(climateEight));
  maria->climates->append(new Proxy(climateEight));

  Climate *climateNine = new Climate("10", 1.2, 35.2, 28.5, 4.2, 9.1, 'W', false, 1648824234, 1648824234, 1648857318, rainNine, ciudadQuesada, gabriel);
  this->climates->append(climateNine);
  ciudadQuesada->climate->append(new Proxy(climateNine));
  gabriel->climates->append(new Proxy(climateNine));

  Climate *climateTen = new Climate("11", 0.4, 37.6, 30.1, 2.3, 4.1, 'N', false, 1652273754, 1652273754, 1652321274, rainTen, ciudadQuesada, gabriel);
  this->climates->append(climateTen);
  ciudadQuesada->climate->append(new Proxy(climateTen));
  gabriel->climates->append(new Proxy(climateTen));

  Climate *climateEleven = new Climate("12", 6.4, 28.2, 20.5, 12.7, 31.2, 'N', true, 1660827954, 1660827954, 1660867554, rainEleven, ciudadQuesada, johan);
  this->climates->append(climateEleven);
  ciudadQuesada->climate->append(new Proxy(climateEleven));
  johan->climates->append(new Proxy(climateEleven));

  Climate *climateTwelve= new Climate("13", 4.9, 30.6, 22.2, 10.3, 21.1, 'E', true, 1652321274, 1652321274, 1652481274, rainTwelve, ciudadQuesada, alonso);
  this->climates->append(climateTwelve);
  ciudadQuesada->climate->append(new Proxy(climateTwelve));
  alonso->climates->append(new Proxy(climateTwelve));

  Climate *climateThirteen = new Climate("14", 8.2, 29.7, 25.8, 15.9, 27.5, 'N', true, 1671967200, 1671967200, 1672022820, rainThirteen, ciudadQuesada, maria);
  this->climates->append(climateThirteen);
  ciudadQuesada->climate->append(new Proxy(climateThirteen));
  maria->climates->append(new Proxy(climateThirteen));

  this->instants = sortedInsert(this->instants, new Instant("Early cloudy sun", 1518924331, 1518924331, 1518944582));
  this->instants = sortedInsert(this->instants, new Instant("Early rainy sun", 1511224332, 1511224332, 1518129992));
  this->instants = sortedInsert(this->instants, new Instant("Shiny sun", 1518319932, 1518929932, 1518124332));
  this->instants = sortedInsert(this->instants, new Instant("Rainy day without sun", 1518325532, 1518325532, 1518906532));
  this->instants = sortedInsert(this->instants, new Instant("Late sunrise", 1321924332, 1321924332, 1321954332));

  this->instants = sortedInsert(this->instants, new Instant("August 14, relax sunday", 1660479558, 1660479558, 1660525698));
  this->instants = sortedInsert(this->instants, new Instant("New year, 2022", 1641041718, 1641041718, 1641084918));
  this->instants = sortedInsert(this->instants, new Instant("July 09, Vacations", 1657368618, 1657368618, 1657415418));
  this->instants = sortedInsert(this->instants, new Instant("April 13", 1649848698, 1649848698, 1649898318));
  this->instants = sortedInsert(this->instants, new Instant("A beatiful day to send the project :)", 1665232945, 1665232945, 1665274338));
}

/**
 * Run the program using the Menu::prompt method
 */
int Program::run() {
  this->menu->display();

  while (this->menu->prompt() == CommandCodes::CONTINUE);

  return 0;
}
