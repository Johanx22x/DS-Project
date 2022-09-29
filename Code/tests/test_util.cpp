#include <instant.hh>
#include <util.hh>

int main() {
    Instant *list = new Instant("Aaron", 1, 2, 3);
    list = sortedInsert(list, new Instant("Johan", 4, 5, 6));

    list->show();

    return 0;
}
