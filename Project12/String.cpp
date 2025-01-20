#include <iostream>
#include "String.h"
int main() {
    String str1("Hello, World!");
    String str2 = std::move(str1);

    std::cout << "str2: " << str2.getData() << std::endl;
    std::cout << "str1: " << (str1.getData() ? str1.getData() : "null") << std::endl;

    String str3("New String!");
    str3 = std::move(str2);

    std::cout << "str3: " << str3.getData() << std::endl;
    std::cout << "str2: " << (str2.getData() ? str2.getData() : "null") << std::endl;

    return 0;
}
