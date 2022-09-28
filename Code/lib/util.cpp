#include <util.hh>
#include <cstdio>
#include <iostream>

/**
 * Reads the first char in stdin
 *
 * @returns int The first char found in the stdin buffer
 */
[[deprecated("Use std::cin instead")]]
int getInt() {
    int data = 0;
    std::cin >> data;
    return data;
}
