#include <cstdint>
#include <menu.hh>
#include <program.hh>
#include <string>

extern "C" {
MenuItem *dataItems[] = {
};

void DllExport setup(Program *program) {
  for (MenuItem *item : dataItems) {
    program->dataManagement->addItem(item->withContext(program));
  }
}
}
