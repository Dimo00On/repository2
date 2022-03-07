#include "main.h"

int sayAmount() {
    return amount;
}
std::string sayHi() {
    return hi();
}
int main() {
    for (int i = 0; i < sayAmount(); ++i) {
        std::cout << sayHi();
    }
}
