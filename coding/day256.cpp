//
// Created by ruslan515 on 13.09.23.
//

#include "bits/stdc++.h"


const int dayBeer = 256;
using namespace std;

int main() {
    time_t t = time(NULL);
    tm *timePtr = localtime(&t);
    int dayOfYear = timePtr->tm_yday + 1;
    string str(75, '+');
    if (dayOfYear == dayBeer) {
        cout <<
        str <<
        "\n\n\t\t\tПоздравляю с днем программиста!\n\n\t\t\tПей пиво, ешь мясо!!!\n"
        << str;
    } else {
        cout << "Не грусти и улыбнись!";
    }

    return 0;
}