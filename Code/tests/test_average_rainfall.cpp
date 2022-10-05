#include <rain.hh>
#include <util.hh>
#include <iostream>

int main() {
    Rain *rain = new Rain("picha", "1", 3.9);
    rain = insert(rain, new Rain("pinga", "f", 2.0));

    rain->show();

    std::cout << rain->averageRainfall() << "\n";

    return 0;
}
