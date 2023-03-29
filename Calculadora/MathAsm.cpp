#include "MathAsm.h"
#include <iostream>
#include <string>
MathAsm::MathAsm()
{
    
}
//FUNCIÓN OPERACIÓN SUMA
float MathAsm::sumNumbers(float $value, float $value1)
{
    float $result = 0.0;
    __asm__ __volatile__(
        "FADDS %2\n"
        :"=&t"($result)
        :"0" ($value), "m" ($value1)
    );
    return $result;
}
//FUNCIÓN OPERACIÓN RESTA
float MathAsm::restNumbers(float $value, float $value1)
{
    float $result = 0.0;
    __asm__ __volatile__(
        "FSUBS %2\n"
        :"=&t"($result)
        :"0" ($value), "m" ($value1)
    );
    return $result;
}
//FUNCIÓN OPERACIÓN MULTIPLICACIÓN
float MathAsm::multNumbers(float $value, float $value1)
{
    float $result = 0.0;
    __asm__ __volatile__(
        "FMULS %2\n"
        :"=&t"($result)
        :"0" ($value), "m" ($value1)
    );
    return $result;
}
//FUNCIÓN OPERACIÓN DIVISIÓN
float MathAsm::divNumbers(float $value, float $value1)
{
    float $result = 0.0;
    __asm__ __volatile__(
        "FDIVS %2\n"
        :"=&t"($result)
        :"0" ($value), "m" ($value1)
    );
    return $result;
}
//FUNCIÓN OPERACIÓN SENO
float MathAsm::sinNumber(float $value)
{
    float $result;
    __asm__ __volatile__("fsin" : "=t" ($result) : "0" ($value));
    return $result;
}
//FUNCIÓN OPERACIÓN COSENO
float MathAsm::cosNumber(float $value)
{
    float $result;
    __asm__ __volatile__("fcos" : "=t" ($result) : "0" ($value));
    return $result;
}
//FUNCIÓN OPERACIÓN TANGENTE
float MathAsm::tangNumber(float $value)
{
    float $result;
    float $sin = sinNumber($value);
    float $cos = cosNumber($value);
    $result = divNumbers($sin, $cos);
    return $result;
}
//FUNCIÓN OPERACIÓN SECANTE
float MathAsm::secNumber(float $value)
{
    float $result;
    $value = cosNumber($value);
    $result = divNumbers(1.0, $value);
    return $result;
}
//FUNCIÓN OPERACIÓN COSECANTE
float MathAsm::cosecNumber(float $value)
{
    float $result;
    $value = sinNumber($value);
    $result = divNumbers(1.0, $value);
    return $result;
}
//FUNCIÓN OPERACIÓN COTANGENTE
float MathAsm::cotangNumber(float $value)
{
    float $result;
    $value = tangNumber($value);
    $result = divNumbers(1.0, $value);
    return $result;
}

//FUNCIÓN OPERACIÓN ARCOTANGENTE (RESULTADO)
float MathAsm::arcTangNumber(float $value)
{
    float $result;
    __asm__ __volatile__(
        "fld1\n"
        "fpatan\n"
        : "=t" ($result)
        : "0" ($value));
    return $result;
}

//FUNCIÓN OPERACIÓN RAIZ CUADRADA
float MathAsm::sqrtOfNumber(float $value)
{
    float $result;
    __asm__ __volatile__(
        "fsqrt"
        : "=t" ($result)
        : "0" ($value)
    );
    return $result;
}

//FUNCIÓN OPERACIÓN POTENCIA
float MathAsm::pow_number(float $x, float $y)
{
    float $result;
    __asm__ __volatile__(
        "fyl2x\n"
        "fld %%st(0)\n"
        "frndint\n"
        "fsub %%st,%%st(1)\n"
        "fxch\n"
        "fchs\n"
        "f2xm1\n"
        "fld1\n"
        "faddp\n"
        "fxch\n"
        "fld1\n"
        "fscale\n"
        "fstp %%st(1)\n"
        "fmulp\n"
        : "=t" ($result)
        : "0" ($x), "u" ($y)
        : "st(1)");
    return $result;
}
//FUNCIÓN OPERACIÓN LOGARITMO NATURAL
float MathAsm::logaritmNatural(float $value)
{
    float $result;
	__asm__ __volatile__(
		"fldln2\n"
		"fxch\n"
		"fyl2x\n"
		: "=t" ($result)
		: "0" ($value));
	return $result;
}
//FUNCIÓN OPERACIÓN LOGARITMO BASE 2
float MathAsm::logaritmBase2(float $value)
{
    float $result;
	__asm__ __volatile__(
		"fld1\n"
		"fld %%st(1)\n"
		"fyl2x\n"
		: "=t" ($result)
		: "0" ($value));
	return $result;
}
//FUNCIÓN OPERACIÓN LOGARITMO BASE 10
float MathAsm::logaritmBase10(float $value)
{
    float $result;
	__asm__ __volatile__(
		"fldlg2\n"
		"fld %1\n"
		"fyl2x\n"
		: "=t" ($result)
		: "m" ($value));
	return $result;
}
//FUNCIÓN OPERACIÓN FACTORIAL
int MathAsm::factorialNumber(int $value)
{
    int $result = 1;
    int $preResult = 1;
    for(int index = 2; index <= $value; index++){
        $result = multNumberInt($result, index);
    }
    return $result;
}
//FUNCIÓN OPERACIÓN MULTIPLICACIÓN FACTORIAL
int MathAsm::multNumberInt(int $number, int $number1)
{
    int $result;
	__asm__ __volatile__(
		"movl %1, %%eax;"
		"movl %2, %%ebx;"
		"imul %%ebx, %%eax;"
		"movl %%eax, %0;": "=g"($result): "g"($number), "g"($number1));
	return $result;
}
