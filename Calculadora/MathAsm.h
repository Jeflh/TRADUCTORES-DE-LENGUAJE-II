#ifndef MATHASM_H
#define MATHASM_H
#define M_PI            3.14159265358979323846
#define M_PI_2          1.57079632679489661923
#include <iostream>
using namespace std;
// Clase MathAsm para funciones operacionales
class MathAsm
{
public:
    MathAsm();
    float sumNumbers(float $value, float $value1);
    float restNumbers(float $value, float $value1);
    float multNumbers(float $value, float $value1);
    float divNumbers(float $value, float $value1);
    float sinNumber(float $value);
    float cosNumber(float $value);
    float tangNumber(float $value);
    float secNumber(float $value);
    float cosecNumber(float $value);
    float cotangNumber(float $value);
    float arcTangNumber(float $value);
    float arcSinNumber(float $value);
    float arcCosNumber(float $value);
    float sqrtOfNumber(float $value);
    float exponentialFunction(float $value);
    float pow_number(float $x, float $y);
    float logaritmNatural(float $value);
    float logaritmBase2(float $value);
    float logaritmBase10(float $value);
    int factorialNumber(int $value);
    int multNumberInt(int $number, int $number1);
private:
    float arcTangNumbers(float $y, float $x);

};

#endif // MATHASM_H
