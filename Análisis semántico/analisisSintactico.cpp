#include "analisisLexico.cpp"
#include <fstream>

int analisisSintactico() {

  // Crear y abrir un archivo de texto en modo escritura
  ofstream archivo;
  archivo.open("compilado.txt");

  bool error = false;
  bool repetido = false;
  
  i = 0;

  printf("\nIngrese el codigo (# para finalizar): ");

  do {
    ch = getchar();
    input[i++] = ch;
  } while (ch != '#');

  i = 0;
  cout<<endl;
  do {

    analisisLexico();
    // Disponible 47 - 49
    switch(res) {
      // case -1:
      //   cout << "[Error] Caracter no valido: " << token << endl;
      //   archivo << "error|";
      //   break;

      case 0:
        cout << "[Error] El identificador no puede ser una palabra reservada: " << token << endl;
        archivo << "error|";
        error = true;
        break;

      case 1:
        // cout << "[Identificador] " << token << endl;
        archivo << "identificador|";
        break;
      
      case 51:
        // cout << "[Identificador] " << token << endl;
        archivo << "identificadorString|";
        break;

      case 2:
        cout << "[Error] Identificador declarado mas de una vez: " << token << endl;
        archivo << "repetido|";
        error = true;
        break;

      case 50:
        cout << "[Error] Identificador no declarado: " << token << endl;
        archivo << "noDeclarado|";
        error = true;
        break;

      case 3: 
        // cout << "[Numero] " << num << endl;
        archivo << "numero|";
        break;

      case 4:
        // cout << "[OperadorSuma] " << token << endl;
        archivo << "+|";
        break;

      case 5:
        // cout << "[OperadorResta] " << token << endl;
        archivo << "-|";
        break;

      case 6:
        // cout << "[OperadorMulti] " << token << endl;
        archivo << "*|";
        break;

      case 7:
        // cout << "[OperadorDiv] " << token << endl;
        archivo << "/|";
        break;

      case 8:
        // cout << "[OperadorMod] " << token << endl;
        archivo << "%|";
        break;

      case 9:
        // cout << "[OperadorMayorQue] " << token << endl;
        archivo << ">|";
        break;

      case 10:
        // cout << "[OperadorMayorIgual] " << token << endl;
        archivo << ">=|";
        break;

      case 11:
        // cout << "[OperadorMenorQue] " << token << endl;
        archivo << "<|";
        break;

      case 12:
        // cout << "[OperadorMenorIgual] " << token << endl;
        archivo << "<=";
        break;

      case 13:
        // cout << "[OperadorAsignacion] " << token << endl;
        archivo << "=|";
        break;

      case 14:
        // cout << "[OperadorIgualdad] " << token << endl;
        archivo << "==|";
        break;

      case 15:
        // cout << "[OperadorNegacion] " << token << endl;
        archivo << "!|";
        break;

      case 16:
        // cout << "[OperadorDiferente] " << token << endl;
        archivo << "!=|";
        break;

      case 17:
        cout << "[Error] Operador no reconocido " << token << endl;
        archivo << "error|";
        error = true;
        break;

      case 18:
        // cout << "[OperadorY] " << token << endl;
        archivo << "and|";
        break;

      case 19:
        cout << "[Error] Operador no reconocido " << token << endl;
        error = true;
        break;

      case 20:
        // cout << "[OperadorO] " << token << endl;
        archivo << "or|";
        break;

      case 21:
        // cout << "[Delimitador] " << token << endl;
        archivo << ";|";
        break;

      case 22:
        // cout << "[Delimitador] " << token << endl;
        archivo << "(|";
        break;

      case 23:
        // cout << "[Delimitador] " << token << endl;
        archivo << ")|";
        break;

      case 24:
        // cout << "[Delimitador] " << token << endl;
        archivo << "{|";
        break;

      case 25:
        // cout << "[Delimitador] " << token << endl;
        archivo << "}|";
        break;

      case 26:
        // cout << "[Delimitador] " << token << endl;
        archivo << "[|";
        break;

      case 27:
        // cout << "[Delimitador] " << token << endl;
        archivo << "]|";
        break;

      case 28:
        // cout << "[Cadena] " << token << endl;
        archivo << "cadena|";
        break;

      // Palabras reservadas
      case 30:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "if|";
        break;

      case 31:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "else|";
        break;

      case 32:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "while|";
        break;

      case 33:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "do|";
        break;

      case 34:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "for|";
        break;

      case 35:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "break|";
        break;

      case 36:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "continue|";
        break;

      case 37:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "int|";
        break;

      case 38:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "double|";
        break;

      case 39:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "float|";
        break;

      case 40:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "return|";
        break;

      case 41:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "char|";
        break;

      case 42:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "string|";
        break;

      case 43:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "unsigned|";
        break;

      case 44:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "void|";
        break;

      case 45:
        // cout << "[Palabra reservada] " << token << endl;
        archivo << "print|";
        break;
    }
  } while ( res != 99);

  archivo.close();

	return (0);
}

