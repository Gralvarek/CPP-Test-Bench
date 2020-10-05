// Debug_Maren.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define DEBUG_MODE 1

#if DEBUG_MODE == 1
#define DEBUG_WARN(x) std::cout << x << std::endl;
#else
#define DEBUG_WARN(x)
#endif



int main()
{
    std::cout << "This is normal text." << std::endl;
    DEBUG_WARN("This is debug text.");

    std::cout << 10 << std::endl;
    DEBUG_WARN(15);

    std::cout << 23.4f << std::endl;
    DEBUG_WARN(56.7f);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
