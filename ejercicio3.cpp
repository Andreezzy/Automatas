#include <iostream>
using namespace std;
class Automata{
	private:
		char* cadena;
	public:
		Automata(char* cad){
			cadena = cad;
		}
		bool lexico();
		bool sintactico();
		bool ejecutar();
};
bool Automata::lexico(){
	int c = 0;
	bool error = false;
	while(cadena[c] != '\0'){
		if ((cadena[c] < '0' or cadena[c] > '9') and (cadena[c] != '+' and cadena[c] != '-' and cadena[c] != '*' and cadena[c] != '/')){
			cout<<"Error Lexico: No se reconoce el simbolo "<<cadena[c]<<" en la posicion "<<c<<endl;
			error = true;
		}
		c++;
	}
	if (error == false){
		cout<<"[OK] Analisis Lexico"<<endl;
	}
	return !error;
}
bool Automata::sintactico(){
	int c = 0;
	int estado = 0;
	char simbolo;
	bool error = false;
	while(cadena[c] != '\0'){
		simbolo = cadena[c];
		if (estado == 0){
			if (simbolo >= '0' and simbolo <= '9'){
				estado = 1;
			}else{
				error = true;
				break;
			}
		}else if (estado == 1){
			if (simbolo == '+' or simbolo == '-' or simbolo == '*' or simbolo == '/'){
				estado = 2;
			}else{
				error = true;
				break;
			}
		}else if(estado == 2){
			if (simbolo >= '0' and simbolo <= '9'){
				estado = 3;
			}else{
				error = true;
				break;
			}
		}else if(estado == 3){
			if (simbolo == '+' or simbolo == '-' or simbolo == '*' or simbolo == '/'){
				estado = 2;
			}else{
				error = true;
				break;
			}
		}
		c++;
	}
	if (estado == 3 and error == false){
		cout<<"[OK] Analisis sintactico"<<endl;
	}else{
		error = true;
	}
	if (error == true){
		cout<<"Error Sintactico: Posicion "<<c<<" entrada "<<simbolo;
	}
	return !error;
}
bool Automata::ejecutar(){
	if (lexico() == true){
		if (sintactico() == true){
			cout<<endl<<"CADENA: "<<cadena<<" -> ";
			cout<<"RECONOCIDA"<<endl;
		}
	}else{
		cout<<endl<<"CADENA: "<<cadena<<" -> ";
		cout<<"NO RECONOCIDA..."<<endl;
	}
}

int main(){
	Automata obj("2+4");
	obj.ejecutar();
	return 0;
}
