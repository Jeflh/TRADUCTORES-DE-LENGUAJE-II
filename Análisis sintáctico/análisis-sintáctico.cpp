#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

//EJEMPLO PARA DEMOSTRACI�n:
// int var = 10; while (var > 0){ printf(var); var-- }%

char input[300];
char token[20];
char ch;
int p;
int fg;
int num;

// Matriz de caracteres bidimensionales, almacenando palabras clave
char PalReserv[8][8]={"if", "while", "return", "else", "printf", "int", "float", "void"};

// Declaraci�n del m�todo de an�lisis l�xico
void scaner();
int main(){
	FILE* fichero;
    fichero = fopen("compilador.txt", "wt");
    p=0;
    cout<<"***************** ANALISIS SINTACTICO *****************"<<endl;
    cout<<"Escriba el codigo | Termina el codigo con '%': ";
    // Lectura ciclica de caracteres
    do {
        ch=getchar();
        input[p++] = ch;
    } while( ch!='%' );
    cout<<endl<<"Elementos encontrados: "<<endl;
    p=0;
    do {
      scaner();
        switch( fg ){
          case 8:
						printf("ID:0   ");
						fputs("ID|", fichero);
						break;
          
					case -1:
						printf("input error\n");
            fputs("error|", fichero);
						break;
            
					default:

					if (fg == 9){
						printf("Entero:1	");
						fputs("entero|", fichero);
					}
					else if (fg == 6 || fg == 7 || fg == 8){
						printf("Tipo:4	");
						fputs("tipo|", fichero);
					}
					else if (fg == 35 || fg == 10){
						printf("OpSuma:5   ");
						fputs("opSuma|", fichero);
					}
					else if (fg == 11 || fg == 12){
						printf("OpMul:6   ");
						fputs("opMul|", fichero);
					}
					else if (fg == 17 || fg == 16 || fg == 38 || fg == 39){
						printf("OpRelac:7   ");
						fputs("opRelac|", fichero);
					}
					else if (fg == 40){
						printf("OpOr:8   ");
						fputs("opOr|", fichero);
					}
					else if (fg == 42){
						printf("OpAnd:9   ");
						fputs("opAnd|", fichero);
					}
					else if (fg == 31){
						printf("OpNot:10   ");
						fputs("opNot|", fichero);
					}
					else if (fg == 30 || fg == 32){
						printf("OpIgualdad:11   ");
						fputs("opIgualdad|", fichero);
					}
					else if (fg == 19){
						printf(";:12   ");
						fputs(";|", fichero);
					}
					else if (fg == 44){
						printf(",:13   ");
						fputs(",|", fichero);
					}
					else if (fg == 20){
						printf("(:14   ");
						fputs("(|", fichero);
					}
					else if (fg == 21){
						printf("):15   ");
						fputs(")|", fichero);
					}
					else if (fg == 45){
						printf("{:16   ");
						fputs("{|", fichero);
					}
					else if (fg == 46){
						printf("}:17   ");
						fputs("}|", fichero);
					}
					else if (fg == 33){
						printf("=:18   ");
						fputs("=|", fichero);
					}
					else if (fg == 1){
						printf("if:19   ");
						fputs("if|", fichero);
					}
					else if (fg == 2){
						printf("while:20   ");
						fputs("while|", fichero);
					}
					else if (fg == 3){
						printf("return:21   ");
						fputs("return|", fichero);
					}
					else if (fg == 4){
						printf("else:22   ");
						fputs("else|", fichero);
					}
					else if (fg == 5){
						printf("printf:23   ");
						fputs("printf|", fichero);
					}
					else if (fg == 47){
						printf("$:24   ");
						fputs("$|", fichero);
					}
					else if (fg == 34){
						printf(".:24   ");
						fputs(".|", fichero);
					}
				}
    } while( fg != 99 );
    //cerrar fichero
    fclose(fichero);
	cout<<endl<<"Tokens Agregados con Exito."<<endl<<endl;


	fopen("compilador.txt", "r");
	char caracterToken;
	string tokenAlmacenado;
	int limiteLectura=0;
	int tokenPosicion=0;
	string tokenAnterior;
	string tokenCondicion;

	while(limiteLectura<300) {
		caracterToken = fgetc(fichero);
		if (caracterToken == '|') //encontro el delimitador
		{
			//Procede a comprobar la sintaxis
			cout<<"Token encontrado: "<<tokenAlmacenado<<endl;

			//cout<<"POS: "<<tokenPosicion<<endl<<endl;
			if(tokenPosicion == 0) //Mientras que dentro del primer token
			{
				if(tokenAlmacenado == "if" || (tokenAlmacenado == "while" )|| (tokenAlmacenado == "int") || (tokenAlmacenado == "float")|| (tokenAlmacenado == "void")|| (tokenAlmacenado == "printf"))
				{
					//cout<<"En Orden, token almacenado: "<<tokenAlmacenado<<endl;
					if (tokenAlmacenado =="if"){
						tokenCondicion = "if";
						tokenAnterior = "if";

					}
				}
				else{
					if(tokenAlmacenado == "ID"){ //Exista un identificador
					  cout<<"[Error] ID no declarado"<<endl;
						break;
					}
					else if(tokenAlmacenado == "entero"){ //El primer token es entero
						cout<<"[Syntax Error] entero encontrado antes que tipo de dato"<<endl;
						break;
					}
					else if(tokenAlmacenado == "else"){ //El primer token es entero
						cout<<"[Syntax Error] else encontrado antes que if"<<endl;
						break;
					}
					else{
						//cout<<"[Error] Tipo de dato no declarado"<<endl;
					}
				}
			}
//int b=0; if b==0%
			if(tokenCondicion == "if"){//si el usuario esta tecleando un if
				if (tokenAlmacenado == "if"){

				}
				else{
					if(tokenAnterior == "if"){
						if(tokenAlmacenado == "(")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<"[Error] Expected '(' before"<<endl;
								break;
						}
					}
					if (tokenAnterior == "("){
						if(tokenAlmacenado == "ID")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;


						}
						else{
							cout<<"[Syntax Error] ID no valido"<<endl;
							break;
						}
					}
					if (tokenAnterior == "ID"){
						if(tokenAlmacenado == "opIgualdad" && (tokenAlmacenado == ")"))
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
							cout<<"[Syntax Error] ID no valido"<<endl;

						}
						else{
							cout<<"[Syntax Error] operador de igualdad no valido en if"<<endl;
							break;
						}
					}
					if(tokenAnterior == "opIgualdad"){
						if(tokenAlmacenado == "ID" || (tokenAlmacenado == "entero")){
							tokenAnterior=tokenAlmacenado;
							goto seCumple;

						}
						else{
								cout<<"[Syntax Error] operador no valido en if before ')'"<<endl;
								break;
						}
					}

					if ((tokenAnterior == "ID") || (tokenAnterior == "entero")){
						if(tokenAlmacenado == ")")
						{
							tokenAnterior=tokenAlmacenado;
							goto seCumple;

						}
						else{
							cout<<"[Syntax Error] Expected ')'"<<endl;
							break;
						}
					}
					if(tokenAnterior == ")"){
						if(tokenAlmacenado == "{")
						{
							cout<<endl<<"Codigo sin errores analizado exitosamente";
							tokenAnterior=tokenAlmacenado;
							goto seCumple;
						}
						else{
								cout<<"[Syntaxis Error] Expected '{' before ')'"<<endl;
								break;
						}
					}

				}//Fin else if tokenPosicion >0

			}//entra solo si la bandera de condicion es if

		seCumple:
		tokenAlmacenado="";
		tokenPosicion++;
		} //Fin de encontrar token
		else{//Sigue buscando delimitador.. token
			//printf("%c",var);
			tokenAlmacenado+=caracterToken;
			limiteLectura=limiteLectura+1;
		}


	}
	fclose(fichero);
	
	cout<<endl<<"Fin de compilador";


    return 0;
}

//Analizador l�xico
void scaner(){
	int m=0;        // token [] sub�ndice
	int n;
    // Filtrar espacios
    ch=input[p++];
    while(ch==' ') ch=input[p++];

    // Flujo de procesamiento de palabras reservadas (ID)
    if(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' )){
            while(( ch<='z' && ch>='a' )||( ch<='Z' && ch>='A' )||( ch<='9' && ch>='0' ))
            {
                 token[m++] = ch;
                 ch = input[p++];
            }
            p--;
            token[m++] = '\0';
            fg = 8;

            for( n=0; n<9; n++ )
            {
                if(strcmp(token, PalReserv[n])==0)// strcmp () compara dos cadenas y devuelve 0 si son iguales
                    {
                        fg = n+1;
                        break;
                    }
            }
    }

    // Flujo de procesamiento digital
    else if(( ch<='9' && ch>='0' ))
    {
        num=0;
        while(( ch<='9' && ch>='0' ))
        {
            num = num*10+ch-'0';
            ch = input[p++];
        }
        p--;
        fg = 9;
    }

    // Flujo de procesamiento del delimitador del operador
    else
        switch(ch)
        {
		    case '>':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar >=
                {
                    fg=17;
                    token[m++]=ch;
                }
                else               // Generar >
                {
                    fg=16;
                    p--;
                }
                token[m++] = '\0';
                break;
            }
            case '<':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar <=
                {
                    fg=38;
                    token[m++]=ch;
                }
                else               // Generar <
                {
                    fg=39;
                    p--;
                }
                token[m++] = '\0';
                break;
            }
            case '|':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='|')        // Generar ||
                {
                    fg=40;
                    token[m++]=ch;
                }
                else               // Generar |
                {
                    fg=41;
                    p--;
                }
                token[m++] = '\0';
                break;
            }
            case '&':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='&')        // Generar &&
                {
                    fg=42;
                    token[m++]=ch;
                }
                else               // Generar &
                {
                    fg=43;
                    p--;
                }
                token[m++] = '\0';
                break;
            }

            case '+': fg=35; token[0]=ch; token[1]='\0'; break;
            case '-': fg=10; token[0]=ch; token[1]='\0'; break;
            case '*': fg=11; token[0]=ch; token[1]='\0'; break;
            case '/': fg=12; token[0]=ch; token[1]='\0'; break;
            //case '=': fg=18; token[0]=ch; token[1]='\0'; break;
            case '=':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar ==
                {
                    fg=32;
                    token[m++]=ch;
                }
                else               // Generar =
                {
                    fg=33;
                    p--;
                }
                token[m++] = '\0';
                break;
            }
            case ';': fg=19; token[0]=ch; token[1]='\0'; break;
            case '(': fg=20; token[0]=ch; token[1]='\0'; break;
            case ')': fg=21; token[0]=ch; token[1]='\0'; break;
            case '{': fg=45; token[0]=ch; token[1]='\0'; break;
            case '}': fg=46; token[0]=ch; token[1]='\0'; break;
            case '$': fg=47; token[0]=ch; token[1]='\0'; break;

            case '%': fg=99; token[0]=ch; token[1]='\0'; break;
            // cambios
			//case '!': fg=22; token[0]=ch; token[1]='\0'; break;
			case '!':
            {
                token[m++]=ch;
                ch=input[p++];
                if(ch=='=')        // Generar !=
                {
                    fg=30;
                    token[m++]=ch;
                }
                else               // Generar !
                {
                    fg=31;
                    p--;
                }
                token[m++] = '\0';
                break;
            }
            case '.': fg=34; token[0]=ch; token[1]='\0'; break;
            case ',': fg=44; token[0]=ch; token[1]='\0'; break;
            default: fg=-1;
        }

}
