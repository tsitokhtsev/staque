#include <iostream>

#include "staque.h"

using namespace std;

int main() {
    /* S1 initialization */
    cout << "------------------------------\n"
         << "Staque S1\n"
         << "------------------------------\n";
    Staque S1;

    /* Adding numbers to S1 */
    S1.push(5);
    S1.push(4);
    S1.push(2);
    S1.push(8);
    S1.push(11);

    S1.pop_front(2);  // Removing 2 even numbers
    S1.pop_end();     // Removing 1 odd number

    /* S2 initialization */
    cout << "------------------------------\n"
         << "Staque S2\n"
         << "------------------------------\n";
    Staque S2;
}