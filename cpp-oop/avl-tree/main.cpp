#include <iostream>
#include "Student.h"

int main() {
    Address school("Herzog", 10, "Tel Aviv");
    Address home("Bavli", 12, "Tel Aviv");

    Student s1("Moshe", school, home);
    home.setStreet("Toledano");
    home.setCity("Holon");
    Student s2("Gogo", school, home);
    s1.show();
    s2.show();

    school.setStreet("Yerushalmi");

    cout << "\nAfter changing school address:\n";
    s1.show();
    s2.show();

    cout << "After changing city of s1:\n";
    s1.getHomeAddress().setCity("Jerusalem");
    s1.show();
    cout << "------------------\n";



    return 0;
}
