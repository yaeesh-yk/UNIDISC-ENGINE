
#include "UNIDISCEngine.h"
#include "UnitTester.h"
#include "ConsoleColour.h"
#include <iostream>
using namespace std;

int main() {
    cout << "\n";
    setColor(14);
    cout << "====================================================\n";
    cout << "|                                                  |\n";
    cout << "| UNIDISC ENGINE v1.0                              |\n";
    cout << "| FAST University Management System                |\n";
    cout << "| Discrete Structures Framework                    |\n";
    cout << "|                                                  |\n";
    cout << "====================================================\n\n";
    setColor(11);
    cout << "Select Mode:\n";
    cout << "1. Interactive CLI Mode\n";
    cout << "2. Run Full Demonstration\n";
    cout << "3. Run Unit Tests\n";
    setColor(10);
    cout << "Enter choice: ";
    setColor(15);
    int mode;
    cin >> mode;
    cin.ignore();
    if (mode == 1) {
        UNIDISCEngine engine;
        engine.run();
    }
    else if (mode == 2) {
        UNIDISCEngine engine;
        engine.demonstrateAllModules();
    }
    else if (mode == 3) {
        UnitTester tester;
        tester.runAllTests();
    }
    else {
        setColor(12);
        cout << "Invalid mode selected!\n";
        setColor(15);
    }
    setColor(14);
    cout << "\n====================================================\n";
    setColor(13);
    cout << " Thank you for using UNIDISC ENGINE! \n";
    setColor(14);
    cout << "=======================================================\n\n";
    setColor(15);
    return 0;
}