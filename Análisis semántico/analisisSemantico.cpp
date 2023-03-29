/*
  Universidad de Guadalajara

		~=~ DESARROLLADORES ~=~
	# Juan José Salazar Villegas
	# Juan Emmanuel Fernández de Lara Hernández
	# Paola Vanessa Del Rio Gomóz
	# Mally Samira Hernández Martinez

	Versión 3.8.4
*/

#include "analisisSintactico.cpp"
 

int main(){

  analisisSintactico();

  // Abrir archivo de texto en modo lectura
  ifstream compilado;
  compilado.open("compilado.txt");

  char caracterToken;
  int posicionToken = 0;
  string tokenAlmacenado;
  string tokenAnterior = " "; 
  string tokenCondicion;
  string tokenOperador;
  bool error = false;

  while (compilado.get(caracterToken)) {
    if (caracterToken == '|') {

      if (posicionToken == 0) {
        if (tokenAlmacenado == "identificador"){
          cout << "[Error] Identificador no declarado" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "identificadorString"){
          cout << "[Error] Identificador no declarado" << endl;
        }
        else if (tokenAlmacenado == "numero"){
          cout << "[Error] Numero encontrado antes de tipo de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "cadena") {
          cout << "[Error] Cadena encontrada antes de tipo de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "else"){
          cout << "[Error] else encontrado antes de if" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "+"){
          cout << "[Error] Operador de suma encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "-"){
          cout << "[Error] Operador de resta encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "*"){
          cout << "[Error] Operador de multiplicacion encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "/"){
          cout << "[Error] Operador de division encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "%"){
          cout << "[Error] Operador de modulo encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "="){
          cout << "[Error] Operador de asignacion encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "!"){
          cout << "[Error] Operador de desigualdad encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "=="){
          cout << "[Error] Operador de igualdad encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "!="){
          cout << "[Error] Operador de diferente encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "and"){
          cout << "[Error] Operador de and encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "or"){
          cout << "[Error] Operador de or encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "<"){
          cout << "[Error] Operador de menor encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == ">"){
          cout << "[Error] Operador de mayor encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "<="){
          cout << "[Error] Operador de menor igual encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == ">="){
          cout << "[Error] Operador de mayor igual encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "("){
          cout << "[Error] Parentesis de apertura encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == ")"){ 
          cout << "[Error] Parentesis de cierre encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "{"){
          cout << "[Error] Llave de apertura encontrada antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "}"){
          cout << "[Error] Llave de cierre encontrada antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "["){
          cout << "[Error] Corchete de apertura encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == "]"){
          cout << "[Error] Corchete de cierre encontrado antes de dato" << endl;
          error = true;
        }
        else if (tokenAlmacenado == ";"){
          cout << "[Error] Punto y coma encontrado antes de dato" << endl;
          error = true;
        }
      }
      else {
        if (tokenAlmacenado == "if"){
        tokenCondicion = "if";
        tokenAnterior = "if";
        }
        else if (tokenAlmacenado == "do"){
          tokenCondicion = "do";
          tokenAnterior = "do";
        }
        else if (tokenAlmacenado == "while"){
          tokenCondicion = "while";
          tokenAnterior = "while";
        }
        else if (tokenAlmacenado == "for"){
          tokenCondicion = "for";
          tokenAnterior = "for";
        }
        else if (tokenAlmacenado == "+"){
          tokenOperador = "+";
        }
        else if (tokenAlmacenado == "-"){
          tokenOperador = "-";
        }
        else if (tokenAlmacenado == "*"){
          tokenOperador = "*";
        }
        else if (tokenAlmacenado == "/"){
          tokenOperador = "/";
        }
        else if (tokenAlmacenado == "identificador"){
          tokenAnterior = "identificador";
        }
        else if (tokenAlmacenado == "identificadorString"){
          tokenAnterior = "identificadorString";
        }
        else if (tokenAlmacenado == "numero"){
          tokenAnterior = "numero";
        }
        else if (tokenAlmacenado == "repetido"){
          error = true;
        }
        else if (tokenAlmacenado == "error"){
          error = true;
        }
      }
      
      if (tokenCondicion == "if"){
        if (tokenAlmacenado != "if"){
          if (tokenAnterior == "if"){
            if (tokenAlmacenado == "("){
              tokenAnterior = "(";
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de apertura no encontrado despues de if" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "("){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador" || tokenAlmacenado == "true" || tokenAlmacenado == "false"){

              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de parentesis de apertura" << endl;
              error = true;
              break;
            }
          }
          
          if (tokenAnterior == "numero" || tokenAnterior == "identificador" || tokenAnterior == "true" || tokenAnterior == "false"){
            if (tokenAlmacenado == ")" || tokenAlmacenado == "==" || tokenAlmacenado == "!=" || tokenAlmacenado == "<" || tokenAlmacenado == ">" || tokenAlmacenado == "<=" || tokenAlmacenado == ">=" || tokenAlmacenado == "and" || tokenAlmacenado == "or"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de cierre o operador logico no encontrado" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "==" || tokenAnterior == "!=" || tokenAnterior == "<" || tokenAnterior == ">" || tokenAnterior == "<=" || tokenAnterior == ">=" || tokenAnterior == "and" || tokenAnterior == "or"){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador" || tokenAlmacenado == "true" || tokenAlmacenado == "false"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de operador logico" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "numero" || tokenAnterior == "identificador" || tokenAnterior == "true" || tokenAnterior == "false"){
            if (tokenAlmacenado == ")"){
              tokenAnterior = ")";
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de cierre no encontrado despues de dato" << endl;
              error = true;
              break;
            }
          }
          
          if (tokenAnterior == ")"){
            if (tokenAlmacenado == "{"){
              tokenAnterior = "{";
              tokenCondicion = "";
              goto salto;
            }
            else {
              cout << "[Error] Llave de apertura no encontrada despues de parentesis de cierre" << endl;
              error = true;
              break;
            }
          }
        }
      }
      
      if (tokenCondicion == "do"){
        if (tokenAlmacenado != "do"){
          if (tokenAnterior == "do"){
            if (tokenAlmacenado == "{"){
              tokenAnterior = "{";
              tokenCondicion = "";
              goto salto;
            }
            else {
              cout << "[Error] Llave de apertura no encontrada despues de do" << endl;
              error = true;
              break;
            }
          }
        }
      }

      if (tokenCondicion == "while"){
        if (tokenAlmacenado != "while"){
          if (tokenAnterior == "while"){
            if (tokenAlmacenado == "("){
              tokenAnterior = "(";
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de apertura no encontrado despues de while" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "("){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador" || tokenAlmacenado == "true" || tokenAlmacenado == "false"){

              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de parentesis de apertura" << endl;
              error = true;
              break;
            }
          }
          
          if (tokenAnterior == "numero" || tokenAnterior == "identificador" || tokenAnterior == "true" || tokenAnterior == "false"){
            if (tokenAlmacenado == ")" || tokenAlmacenado == "==" || tokenAlmacenado == "!=" || tokenAlmacenado == "<" || tokenAlmacenado == ">" || tokenAlmacenado == "<=" || tokenAlmacenado == ">=" || tokenAlmacenado == "and" || tokenAlmacenado == "or"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de cierre o operador logico no encontrado" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "==" || tokenAnterior == "!=" || tokenAnterior == "<" || tokenAnterior == ">" || tokenAnterior == "<=" || tokenAnterior == ">=" || tokenAnterior == "and" || tokenAnterior == "or"){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador" || tokenAlmacenado == "true" || tokenAlmacenado == "false"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de operador logico" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "numero" || tokenAnterior == "identificador" || tokenAnterior == "true" || tokenAnterior == "false"){
            if (tokenAlmacenado == ")"){
              tokenAnterior = ")";
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de cierre no encontrado despues de dato" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == ")"){
            if (tokenAlmacenado == "{"){
              tokenAnterior = "{";
              tokenCondicion = "";
              goto salto;
            }
            else {
              cout << "[Error] Llave de apertura no encontrada despues de parentesis de cierre" << endl;
              error = true;
              break;
            }
          }
        } 
      }

      if (tokenCondicion == "for"){
        if (tokenAlmacenado != "for"){
          if (tokenAnterior == "for"){
            if (tokenAlmacenado == "("){
              tokenAnterior = "(";
              goto salto;
            }
            else {
              cout << "[Error] Parentesis de apertura no encontrado despues de for" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "("){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de parentesis de apertura" << endl;
              error = true;
              break;
            }
          }
          
          if (tokenAnterior == "numero" || tokenAnterior == "identificador" || tokenAnterior == "true" || tokenAnterior == "false"){
            if (tokenAlmacenado == ";" || tokenAlmacenado == "==" || tokenAlmacenado == "!=" || tokenAlmacenado == "<" || tokenAlmacenado == ">" || tokenAlmacenado == "<=" || tokenAlmacenado == ">=" || tokenAlmacenado == "and" || tokenAlmacenado == "or"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Punto y coma o operador logico no encontrado" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == "==" || tokenAnterior == "!=" || tokenAnterior == "<" || tokenAnterior == ">" || tokenAnterior == "<=" || tokenAnterior == ">=" || tokenAnterior == "and" || tokenAnterior == "or"){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador" || tokenAlmacenado == "true" || tokenAlmacenado == "false"){
              tokenAnterior = tokenAlmacenado;
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de operador logico" << endl;
              error = true;
            }
          }

          if (tokenAnterior == "numero" || tokenAnterior == "identificador"){
            if (tokenAlmacenado == ";"){
              tokenAnterior = ";";
              goto salto;
            }
            else {
              cout << "[Error] Punto y coma no encontrado despues de dato" << endl;
              error = true;
              break;
            }
          }

          if (tokenAnterior == ";"){
            if (tokenAlmacenado == "numero" || tokenAlmacenado == "identificador"){
              tokenAnterior = tokenAlmacenado;
              tokenCondicion = "";
              goto salto;
            }
            else {
              cout << "[Error] Dato no encontrado despues de punto y coma" << endl;
              error = true;
              break;
            }
          }
        }
      }

      if (tokenAlmacenado == "+" || tokenAlmacenado == "-" || tokenAlmacenado == "*" || tokenAlmacenado == "/" || tokenAlmacenado == "%"){
        
        if (tokenAnterior == "numero" || tokenAnterior == "identificador"){
          tokenAnterior = tokenAlmacenado;
          goto salto;
          
        } else if (tokenAnterior == "identificadorString"){
          cout << "[Error] Cadena detectada en operacion aritmetica" << endl;
          error = true;
          break;
        }
      }

      salto:

      // cout << "Token: " << tokenAlmacenado << endl;
      // cout << "Token anterior: " << tokenAnterior << endl;
      // cout << "Token Condicion: " << tokenCondicion << endl;
      // cout << "Token Op: " << tokenOperador << endl;
      // cout << "Posicion: " << posicionToken << endl << endl;

      tokenAlmacenado = "";
      posicionToken++;

    } else {
      tokenAlmacenado += caracterToken;
    }
  }

  if (!error){
    cout << "[Correcto] El programa no contiene errores" << endl;
  }

  compilado.close();
  cout<<endl;
  system("pause");

  return 0;
}
