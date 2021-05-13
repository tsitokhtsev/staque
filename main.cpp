#include <iostream>

#include "staque.h"

using namespace std;

int main() {
    /* S1 initialization */
    cout << "--------------------------------------------------\n"
         << "Staque S1\n";
    Staque S1;

    /* Adding numbers to S1 */
    cout << "--------------------------------------------------\n"
         << "> Adding numbers to S1\n\n";
    S1.push(5);
    S1.push(4);
    S1.push(2);
    S1.push(8);
    S1.push(11);

    /* Removing 2 even and 1 odd numbers from S1 */
    cout << "--------------------------------------------------\n"
         << "> Removing 2 even and 1 odd number from S1\n\n";
    S1.pop_even(2);
    S1.pop_odd();

    /* S2 initialization using copy constructor*/
    cout << "--------------------------------------------------\n"
         << "Staque S2\n"
         << "--------------------------------------------------\n";
    Staque S2(S1);

    /* Removing more odd numbers than there is in S2 */
    cout << "--------------------------------------------------\n"
         << "> Removing more odd numbers than there is in S2\n\n";
    S2.pop_odd(2);

    /* Assigning S2 to itself */
    cout << "--------------------------------------------------\n"
         << "> Assigning S2 to itself\n\n";
    S2 = S2;

    /* S3 initialization using '=' operator*/
    cout << "--------------------------------------------------\n"
         << "Staque S3\n"
         << "--------------------------------------------------\n";
    Staque S3 = S1;
    S3.push(3);
    S3.push(20);
    S3.push(9);

    /* Removing all numbers in S3 */
    cout << "--------------------------------------------------\n"
         << "> Removing all numbers in S3\n\n";
    S3.pop_end(5);

    /* Removing numbers from empty S3 */
    cout << "--------------------------------------------------\n"
         << "> Removing numbers from empty S3\n\n";
    S3.pop_even();
    cout << "--------------------------------------------------\n";
}