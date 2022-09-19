#include <region.hh>
#include <string>

Region::Region(std::string name, std::string id, std::string location) {
    this->name = name;
    this->id = id;
    this->location = location;
}
