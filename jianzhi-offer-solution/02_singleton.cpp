#include <iostream>

using namespace std;


class Singleton {
public:
    static Singleton* get() {
        if (instance == 0) {
            instance = new Singleton();
        }
        return instance;
    }
private:
    static Singleton* instance;
    Singleton() {}
};

Singleton* Singleton::instance = 0;

int main()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::get(); // Ok
    Singleton* r = Singleton::get();

    /* The addresses will be the same. */
    std::cout << s << std::endl;
    std::cout << r << std::endl;

    return EXIT_SUCCESS;
}