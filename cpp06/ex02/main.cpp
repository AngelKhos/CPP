#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>

int main(){
    std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++) {
        Base *thing = generate();
        identify(thing);
        identify(*thing);
        delete thing;
    }
}