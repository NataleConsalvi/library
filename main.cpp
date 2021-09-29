#include <iostream>
#include "natslibrary.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;


int main() {

    Date today = Date(29, 9, 2021);

    cout << "Today is " << today.as_string() << endl;

    Date* birthday_dad  = new Date(today);
    birthday_dad->set_day(10);
    birthday_dad->set_month(4);
    birthday_dad->set_year(1967);

    std::cout << birthday_dad->as_string() << std::endl;

    Identity dad = Identity("Giovanni", "Consalvi", birthday_dad);

    cout << dad.as_string() << endl;
}
