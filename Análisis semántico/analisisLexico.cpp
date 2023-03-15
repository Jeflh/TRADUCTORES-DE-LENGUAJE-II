#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector <string> identificadores = {" "};
const char* reservadas[16] = { "if", "else", "while", "do", "for", "break", "continue", "int", "double", "float", "return", "char", "string", "unsigned", "void", "print"};
const char* tipoDatos[7] = { "int", "double", "float", "char", "string", "unsigned", "void"};

char input[255], token[32], tokenReservado[32], ch;
int i = 0, res = -1, num;


void analisisLexico() {

  int j = 0;
  bool find = false;
  bool declarado = false;
  
  // limpiar el token
  for (int i = 0; i < 32; i++) {
    token[i] = '\0';
  }

  ch = input[i++];

  while(ch == ' ' || ch == '\n') {
    ch = input[i++];
  }

  // Identificadores
  if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A' )) {
    while ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A' ) || (ch <= '9' && ch >= '0')) {
      token[j++] = ch;
      ch = input[i++];
    }

    // Verificar si es una palabra reservada
    for (int i = 0; i < 16; i++) {
      if (strcmp(reservadas[i], token) == 0) {
        strcpy(tokenReservado, token);
        res = 30 + i;
        find = true;
        break; 
      }
    }

    // Verificar si es un identificador repetido
    if (!find) {
      int k = 0; 

      while(k < identificadores.size()){  
        if (identificadores[k] == token) {
          for (int i = 0; i < 7; i++) {
            if (strcmp(tipoDatos[i], tokenReservado) == 0) { 
              res = 2; // Identificador repetido
              break;
            }
          }
          res = 1; // Identificador valido
          break;
        }
        else {
          for (int i = 0; i < 7; i++) {
            if (strcmp(tipoDatos[i], tokenReservado) == 0) { 
              if (identificadores[k] == " ") {
                identificadores[k] = token;
              }
              declarado = true;
              res = 1; // Identificador valido
              identificadores.push_back(token); // Agregar a la lista
              break;
            }else {
              res = 50; // Identificador no declarado
            }
          }
          break;
        }        
        k++;
      }
    } 
  }

  // Numeros
  else if (ch <= '9' && ch >= '0') {
    
    num = 0;

    while (ch <= '9' && ch >= '0') {
      num = num * 10 + (ch - '0');
      ch = input[i++];
    }
    i--;

    res = 3; // Numero entero valido
  }

  // Operadores
  else {
    switch (ch) {
      case '+':
        res = 4; // Operador aritmetico
        token[0] = ch;
        token[1] = '\n';
        break;

      case '-':
        res = 5; // Operador aritmetico
        token[0] = ch;
        token[1] = '\n';
        break;

      case '*':
        res = 6; // Operador aritmetico
        token[0] = ch;
        token[1] = '\n';
        break;

      case '/':
        res = 7; // Operador aritmetico
        token[0] = ch;
        token[1] = '\n';
        break;

      case '%':
        res = 8; // Operador aritmetico
        token[0] = ch;
        token[1] = '\n';
        break;

      case '>':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '=') {
          res = 10; // Operador relacional
          token[j++] = ch;
        }
        else {
          res = 9; // Operador relacional
          i--;
        }
        break;

      case '<':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '=') {
          res = 12; // Operador relacional
          token[j++] = ch;
        }
        else {
          res = 11; // Operador relacional
          i--;
        }
        break;

      case '=':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '=') {
          res = 14; // Operador relacional
          token[j++] = ch;
        }
        else {
          res = 13; // Operador relacional
          i--;
        }
        break;

      case '!':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '=') {
          res = 16; // Operador relacional
          token[j++] = ch;
        }
        else {
          res = 15; // Operador relacional
          i--;
        }
        break;

      case '&':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '&') {
          res = 18; // Operador logico
          token[j++] = ch;
        }
        else {
          res = 17; // Operador logico
          i--;
        }
        break;

      case '|':
        token[j++] = ch;
        ch = input[i++];
        if (ch == '|') {
          res = 20; // Operador logico
          token[j++] = ch;
        }
        else {
          res = 19; // Operador logico
          i--;
        }
        break;

      case ';':
        res = 21; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case '(':
        res = 22; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case ')':
        res = 23; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case '{':
        res = 24; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case '}':
        res = 25; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case '[':
        res = 26; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;

      case ']':
        res = 27; // Delimitador
        token[0] = ch;
        token[1] = '\n';
        break;
      
      case '"':
        ch = input[i++];
        if ((ch <= 'z' && ch >= 'a') || (ch <= 'Z' && ch >= 'A' )) {
          while (ch != '"') {
            token[j++] = ch;
            ch = input[i++];
          }
        }
        res = 28; // Delimitador
        break;

      case '#':
        res = 99; // Fin de cadena
        token[0] = ch;
        token[1] = '\n';
        break;

      default:
        res = -1; // Error
    }
  }
}