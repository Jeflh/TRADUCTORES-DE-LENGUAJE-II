#include "MenuProgram.h"
#include <iostream>
#include <string>
#include<stdio.h>

MenuProgram::MenuProgram()
{
    
}
//MENU PRINCIPAL
void MenuProgram::menu()
{
    char option;
    do
    {
        system("cls");
        system ("color 3");
        cout << endl << "     ==== [CALCULADORA PROGRAMACION MIXTA] ==== "<<endl;
        cout << "    	  	 (Ensamblador y C++) "<<endl;
        cout << endl << " 	===========[MENU PRINCIPAL]======="<<endl;
        cout << " 	 [1] Operaciones basicas          "<<endl;
		cout << " 	 [2] Operaciones trigonometricas  "<<endl; 
        cout << " 	 [3] Logaritmos                   "<<endl; 
		cout << " 	 [4] Raices                       "<<endl; 
        cout << " 	 [5] Factorial                    "<<endl;
		cout << " 	 [6] Potencias                    "<<endl;
		cout << " 	 [0] Salir                        "<<endl;
		cout << " 	=================================="<<endl;
		cout << "  	[Ingrese una Opcion]: ";
		

        cin >> option;
        switch (option)
        {
        case '1':
            selectOperationBasics();
            break;
        case '2':
            selectTrigonometircFunction();
            break;
        case '3':
            selectLogaritm();
            break;
        case '4':
            enterDataRoots();
            break;
        case '5':
            enterDataFactorial();
            break;
        case '6':
            enterDataPow();
            break;
        default:
            break;
        }
    }
    while(option != '0');
}
//MENU OPERACIONES BASICAS
void MenuProgram::selectOperationBasics()
{
    char option;
    MathAsm math;
    float number1, number2;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << " ===[ OPERACIONES BASICAS ]==="<<endl;
        cout << " [1] Suma"<<endl;
		cout << " [2] Resta"<<endl;
        cout << " [3] Multplicacion"<<endl;
		cout << " [4] Division"<<endl;
		cout << " [0] Salir"<<endl;
		cout << endl << " [Ingrese una Opcion]: ";
    	
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ SUMA ]==="<<endl;
            cout << "Ingresa el primer numero: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa el segundo numero: ";
            cin >> number2;
            cin.ignore();
            cout << "El resultado de la suma es: "  << math.sumNumbers(number1, number2) << endl;
            system("pause");
            break;
        case '2':
            system("cls");
            cout << endl << " ===[ RESTA ]==="<<endl;
            cout << "Ingresa el primer numero: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa el segundo numero: ";
            cin >> number2;
            cin.ignore();
            cout << "El resultado de la resta es: "  << math.restNumbers(number1, number2) << endl;
            system("pause");
            break;
        case '3':
            system("cls");
            cout << endl << " ===[ MULTIPLICACION ]==="<<endl;
            cout << "Ingresa el primer numero: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa el segundo numero: ";
            cin >> number2;
            cin.ignore();
            cout << "El resultado de la multiplicacion es: "  << math.multNumbers(number1, number2) << endl;
            system("pause");
            break;
        case '4':
            system("cls");
            cout << endl << " ===[ DIVISION ]==="<<endl;
            cout << "Ingresa el primer numero: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa el segundo numero: ";
            cin >> number2;
            cin.ignore();
            cout << "El resultado de la division es: "  << math.divNumbers(number1, number2) << endl;
            system("pause");
            break;
        case '0':
            break;
        default:
            break;
        }
    }
    while(option != '0');
}

//MENU OPERACIONES TRIGONOMETRICAS
void MenuProgram::selectTrigonometircFunction()
{
    char option;
    MathAsm math;
    float number1;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << " ===[ OPERACIONES TRIGONOMETRICAS ]==="<<endl;
        cout << " [1] Seno x"<<endl;
		cout << " [2] Coseno x"<<endl;
        cout << " [3] Tangente x"<<endl;
		cout << " [4] Secante x"<<endl;
		cout << " [5] CoSecante x"<<endl;
		cout << " [6] CoTangente x"<<endl;
		cout << " [0] Salir"<<endl;
		cout << endl << " [Ingrese una Opcion]: ";
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ SENO X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cout << "Sin x: "  << math.sinNumber(number1)<< endl;
            system("pause");
            break;
        case '2':
            system("cls");
            cout << endl << " ===[ COSENO X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "Cos x: "  << math.cosNumber(number1) << endl;
            system("pause");
            break;
        case '3':
            system("cls");
            cout << endl << " ===[ TANGENTE X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "Tan x: "  << math.tangNumber(number1) << endl;
            system("pause");
            break;
        case '4':
            system("cls");
            cout << endl << " ===[ SECANTE X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "Sec x: "  << math.secNumber(number1) << endl;
            system("pause");
            break;
        case '5':
            system("cls");
            cout << endl << " ===[ CO-SECANTE X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "CoSec x: "  << math.cosecNumber(number1) << endl;
            system("pause");
            break;
        case '6':
            system("cls");
            cout << endl << " ===[ CO-TANGENTE X ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "CoTan x: "  << math.cotangNumber(number1) << endl;
            system("pause");
            break;
        default:
            break;
        }
    }
    while(option != '0');
}


//MENU POTENCIAS
void MenuProgram::enterDataPow()
{
    char option;
    MathAsm math;
    float number1;
    float number2;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << "  ===[ POTENCIAS ]==="<<endl;
        cout << " [1] Potencia cuadratica"<<endl; 
		cout << " [2] Potencia a la n"<<endl; 
		cout << " [0] Salir"<<endl; 
		cout << endl << " [Ingrese una Opcion]: ";
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ POTENCIA CUADRATICA ]==="<<endl;
            cout << "Ingresa el numero: ";
            cin >> number1;
            cin.ignore();
            cout << "El valor cuadratico del numero es: "  << math.pow_number(number1, 2.0)<< endl;
            system("pause");
            break;
        case '2':
            system("cls");
            cout << endl << " ===[ POTENCIA A LA N ]==="<<endl;
            cout << "Ingresa el numero a calcular su potencia: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa la potencia: ";
            cin >> number2;
            cin.ignore();
            cout << "El valor a la potencia de n, del numero es: "  << math.pow_number(number1, number2)<< endl;
            system("pause");
            break;
        case '0':
            break;
        default:
            break;
        }
    }
    while(option != '0');	
}
//MENU RAICES
void MenuProgram::enterDataRoots()
{
    char option;
    MathAsm math;
    float number1;
    float number2;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << " ===[ RAICES ]==="<<endl;
        cout << " [1] Raiz cuadratica"<<endl;
		cout << " [2] Raiz a la n"<<endl; 
		cout << " [0] Salir "<<endl; 
		cout << endl << " [Ingrese una Opcion]: ";
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ RAIZ CUADRADA ]==="<<endl;
            cout << "Ingresa el numero: ";
            cin >> number1;
            cin.ignore();
            cout << "La raiz cuadrada del numero es: "  << math.sqrtOfNumber(number1)<< endl;
            system("pause");
            break;
        case '2':
            system("cls");
            cout << endl << " ===[ RAIZ A LA N ]==="<<endl;
            cout << "Ingresa el numero a calcular su raiz: ";
            cin >> number1;
            cin.ignore();
            cout << "Ingresa el valor de n: ";
            cin >> number2;
            cin.ignore();
            cout << "El valor a la potencia de n, del numero es: "  << math.pow_number(number1, (1.0 / number2))<< endl;
            system("pause");
            break;
        case '0':
            break;
        default:
            break;
        }
    }
    while(option != '0');
}
//MENU LOGARITMOS
void MenuProgram::selectLogaritm()
{
    char option;
    MathAsm math;
    float number1;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << " ===[ LOGARITMOS ]==="<<endl;
        cout << " [1] Logaritmo Natural"<<endl; 
		cout << " [2] Logaritmo base 2"<<endl; 
		cout << " [3] Logaritmo base 10"<<endl; 
		cout << " [0] Salir "<<endl; 
		cout << endl << " [Ingrese una Opcion]: ";
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ LOGARITMO NATURAL ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "El logaritmo natural de x es: "  << math.logaritmNatural(number1)<< endl;
            system("pause");
            break;
        case '2':
        	cout << endl << " ===[ LOGARITMO BASE 2 ]==="<<endl;
            system("cls");
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "El logaritmo base 2 de x es: "  << math.logaritmBase2(number1)<< endl;
            system("pause");
            break;
        case '3':
            system("cls");
            cout << endl << " ===[ LOGARITMO BASE 10 ]==="<<endl;
            cout << "Ingresa el valor de x: ";
            cin >> number1;
            cin.ignore();
            cout << "El logaritmo base 10 de x es: "  << math.logaritmBase10(number1)<< endl;
            system("pause");
            break;
        case '0':
            break;
        default:
            break;
        }
    }
    while(option != '0');
}
//MENU FACTORIAL
void MenuProgram::enterDataFactorial()
{
    char option;
    MathAsm math;
    int number1, result;
    do
    {
        system("cls");
        system ("color 2");
        cout << endl << " ===[ FACTORIAL ]=== "<<endl;
        cout << " [1] Ingresar el valor del factorial"<<endl;
		cout << " [0] Salir "<<endl; 
		cout << endl << " [Ingrese una Opcion]: ";
        cin >> option;
        switch (option)
        {
        case '1':
            system("cls");
            cout << endl << " ===[ FACTORIAL ]==="<<endl;
            cout << "Ingresa el numero: ";
            cin >> number1;
            cin.ignore();
            result = math.factorialNumber(number1);
            cout << "El factorial del numero es: " << result <<  endl;
            system("pause");
            break;
        case '0':
            break;
        default:
            break;
        }
    }
    while(option != '0');
}


