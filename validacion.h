#include <iostream>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
//Primero se comprueba la existencia del archivo
bool existeArch(string arch){
  bool existe;
  ifstream archivo(arch);
  if(!archivo.is_open()){
    existe = false;
  }else{
    existe = true;
  }
  archivo.close();
  return existe;
}

//Comprobamos datos dentro del archivo
bool categoriaExiste(string cat){
  bool existe;
  if(cat == "1" || cat == "2" || cat == "3"){
    existe = true;
  }else{
    existe = false;
  }
  return existe;
}
//Comprobar que el nombre del empleado no contengan num o caracteres esp
bool nombreCorrecto(string nom){
  bool correcto = true;
  for(int i = 0; i < nom.length(); i++){
    if(!isalpha(nom[i])){
      correcto = false;
    }
  }
  return correcto;
}
//Comprobar la nomina del empleado
bool nominaCorrecta(string nom){
  bool correcto = true;
  if(nom[0] != '#'){
    correcto = false;
  }else{
    for(int i = 1; i < nom.length(); i++){
      if(!isdigit(nom[i])){
        correcto = false;
      }
    }
  }
  return correcto;
}

//Comprobar si un dato numerico de interes es decimal
bool esDecimal(string num){
  bool correcto = true;
  for(int i = 0; i < num.length(); i++){
    if(!isdigit(num[i]) && num[i]!='.'){
      correcto = false;
    }
  }
  return correcto;
}

//Comprobar si un dato numerico de interes es entero
bool esEntero(string num){
  bool correcto = true;
  for(int i = 0; i < num.length(); i++){
    if(!isdigit(num[i])){
      correcto = false;
    }
  }
  return correcto;
}

bool estaVacio(){
  
}

//Almacenado de las lineas erroreneas en archivo lineasdedatoserrorneos.
void reporteErrores(vector<int> errores){
  if(!errores.empty()){
    cout<<endl<<"Se encontraron los siguientes errores:"<<endl;
    for(int i = 0; i < errores.size(); i++){
      cout << "Error en los datos en la linea " << errores[i] << endl;
    }
  }else{
    cout<<endl<<"No se encontraron errores"<<endl;
  }
}
