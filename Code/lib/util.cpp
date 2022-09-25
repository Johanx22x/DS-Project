#include <util.hh>
#include <cstdio>

/**
 * Reads the first char in stdin
 *
 * @returns int The first char found in the stdin buffer
 */
int getInt() {
    // TODO: Find a better way to implement this function
    int ret = getchar();
    while (getchar() != '\n');
    return ret - 0x30;
}
