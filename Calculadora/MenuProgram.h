#ifndef MENUPROGRAM_H
#define MENUPROGRAM_H
#include "MathAsm.h"
// Clase MenuProgram para funciones operacionales
class MenuProgram
{
    public:
        MenuProgram();
        void menu();
    private:
        void selectOperationBasics();
        void selectTrigonometircFunction();
        void enterDataPow();
        void enterDataRoots();
        void selectLogaritm();
        void enterDataFactorial();
};

#endif // MENUPROGRAM_H
