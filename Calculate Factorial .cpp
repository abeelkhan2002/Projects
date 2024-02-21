//Factorial Assignment
//11/29/2023
//Abeel Khan
//Make a class that uses a template parameter that shows the data type to process the calculation

#include <chrono>
#include <limits>
#include <locale>

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
using namespace chrono;

template <class TypeMultiply>
bool isSafeMultiply(TypeMultiply mult01, TypeMultiply mult02, TypeMultiply& multResult) {
    // Add code to check if mult01 or mult02 = 0
    if (mult01 == 0 || mult02 == 0) {
        multResult = 0;
        return true;
    }

    // Calculate the multResult from mult01 and mult02
    multResult = mult01 * mult02;

    // Check if mult01 is equal to the multResult divided by mult02
    return mult01 == multResult / mult02;
}

template <class TypeMultiply>
void calculateTimeFactorialLoopFunc(void) {
    auto timeStart = steady_clock::now();

    TypeMultiply multiplier = 1, factorialResult = 1;
    while (isSafeMultiply(multiplier, factorialResult, factorialResult)) {
        cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
        ++multiplier;
    }

    auto timeElapsed = duration_cast<nanoseconds>(steady_clock::now() - timeStart);

    cout << endl;
    cout << "Unsigned overflow at : " << setw(3) << multiplier << endl;
    cout << "Time Elapsed (nano)  : " << setw(14) << timeElapsed.count() << endl;
}

template <class TypeMultiply>
void factorialRecursiveFunc(TypeMultiply& multiplier, TypeMultiply factorialResult) {
    if (isSafeMultiply(multiplier, factorialResult, factorialResult)) {
        cout << setw(3) << multiplier << setw(27) << factorialResult << endl;
        factorialRecursiveFunc(++multiplier, factorialResult);
    }
}

template <class TypeMultiply>
void calculateTimeFactorialRecursiveFunc() {
    auto timeStart = steady_clock::now();

    TypeMultiply mult01 = 1;
    factorialRecursiveFunc<TypeMultiply>(mult01, 1);

    auto timeElapsed = duration_cast<nanoseconds>(steady_clock::now() - timeStart);

    cout << endl;
    cout << "Unsigned overflow at : " << setw(3) << mult01 << endl;
    cout << "Time Elapsed (nano)  : " << setw(14) << timeElapsed.count() << endl;
}

template <typename TYPESIZE>
class FactorialCalculationClass {
private:
    unsigned typeSizeBits;

public:
    // Constructor
    FactorialCalculationClass(unsigned typeSize) : typeSizeBits(typeSize) {}

    void executeFactorialForType() {
        cout << typeSizeBits << " bit unsigned Factorial Loop" << endl;
        cout << "------------------------------" << endl;
        calculateTimeFactorialLoopFunc<TYPESIZE>();
        cout << endl << endl;

        cout << typeSizeBits << " bit unsigned Factorial Recursion" << endl;
        cout << "-----------------------------------" << endl;
        calculateTimeFactorialRecursiveFunc<TYPESIZE>();
        cout << endl << endl;
    }
};

int main() {
    // condition cout set to local digit separation comas (USA)
    cout.imbue(locale(""));

    // Create objects for uint16_t, uint32_t, and uint64_t
    FactorialCalculationClass<uint16_t> factorialCalculateUint16Obj(16);
    FactorialCalculationClass<uint32_t> factorialCalculateUint32Obj(32);
    FactorialCalculationClass<uint64_t> factorialCalculateUint64Obj(64);

    // Execute factorial calculations for each type
    factorialCalculateUint16Obj.executeFactorialForType();
    factorialCalculateUint32Obj.executeFactorialForType();
    factorialCalculateUint64Obj.executeFactorialForType();

    // Pause the screen
    cout << "Press the enter key once or twice to end..." << endl;
    cin.ignore();
    cin.get();

    return 0;
}
