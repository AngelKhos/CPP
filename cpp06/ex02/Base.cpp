#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    switch (std::rand() % 3) {
    case 0:
        return new A();
    case 1:
        return new B();
    default:
        return new C();
    }
}

void identify(Base *p) {
    A *a = dynamic_cast<A *>(p);
    if (a != NULL) {
        std::cout << "  Pointer cast: class of type A!" << std::endl;
    }
    B *b = dynamic_cast<B *>(p);
    if (b != NULL) {
        std::cout << "  Pointer cast: class of type B!" << std::endl;
    }
    C *c = dynamic_cast<C *>(p);
    if (c != NULL) {
        std::cout << "  Pointer cast: class of type C!" << std::endl;
    }
}

void identify(Base &p) {
    try {
        const A _ = dynamic_cast<A &>(p);
        std::cout << "Reference cast: class of type A!" << std::endl;
    } catch (std::exception &) {
    }
    try {
        const B _ = dynamic_cast<B &>(p);
        std::cout << "Reference cast: class of type B!" << std::endl;
    } catch (std::exception &) {
    }
    try {
        const C _ = dynamic_cast<C &>(p);
        std::cout << "Reference cast: class of type C!" << std::endl;
    } catch (std::exception &) {
    }
}