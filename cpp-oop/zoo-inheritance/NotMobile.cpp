#include "NotMobile.h"

NotMobile::NotMobile():Animal("NotMobile") {}

NotMobile::NotMobile( string type ):Animal(type) {}

NotMobile::~NotMobile() {}

void NotMobile::inner_view() const {
    cout << "Beautiful & colorful views!" << endl;
}
