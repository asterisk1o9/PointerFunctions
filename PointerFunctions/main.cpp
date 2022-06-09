//
//  main.cpp
//  PointerFunctions
//
//  Created by Marvin Augustin on 4/13/22.
//

#include <vector>
#include <iostream>
#include <stdexcept>
using namespace std;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(int argc, const char * argv[]) {
    std::vector<int (*)(int, int)> vf;

    vf.push_back(add);
    vf.push_back(subtract);
    vf.push_back(multiply);
    vf.push_back(divide);
    
    int a, b;
    cout << "Enter a value for a and b on the same line or seperate line\n";
    std::cin >> a >> b;
    for (const auto &e : vf) {
    std::cout << e(a, b) << std::endl;
 }

     return 0;
   }

   int add(int a, int b) {
     std::cout << "Called add(" << a << ", " << b << ")" << std::endl;
     return a + b;
   }

   int subtract(int a, int b) {
     std::cout << "Called subtract(" << a << ", " << b << ")" << std::endl;
     return a - b;
   }

   int multiply(int a, int b) {
     std::cout << "Called multiply(" << a << ", " << b << ")" << std::endl;
     return a * b;
   }

   int divide(int a, int b) {
     std::cout << "Called divide(" << a << ", " << b << ")" << std::endl;
     try {
       if (b == 0)
         throw std::runtime_error("Divide by 0.");
       return a / b;
     } catch (std::runtime_error err) {
       std::cerr << err.what() << std::endl;
       return 0;
     }
   }
