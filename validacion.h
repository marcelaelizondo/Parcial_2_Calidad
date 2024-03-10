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

//Comprobar si el archivo no esta vacio
bool vacio(ifstream arch){
  bool vacio = false;
  if(arch.peek()==ifstream::traits_type::eof()){
    vacio=true;
  }
  return vacio;
}

//Comprobamos datos dentro del archivo
//Esta funcion se encarga de comprobar si la categoria de contrato existe, recibe un string
bool categoriaExiste(string cat){
  bool existe;
  if(cat == "1" || cat == "2" || cat == "3"){
    existe = true;
  }else{
    existe = false;
  }
  return existe;
}
//Comprobar que el nombre del empleado no contengan num o caracteres esp, recibe un string
bool nombreCorrecto(string nom){
  bool correcto = true;
  for(int i = 0; i < nom.length(); i++){
    if(!isalpha(nom[i])){
      correcto = false;
    }
  }
  return correcto;
}
//Comprobar que la nomina del empleado sea escrita de manera adecuada, recibe un string
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

//Comprobar si un dato numerico de interes es decimal, sirve para la tarifa, sueldo, y precios entre otros archivos que puedan llegar a ser doubles o floats. lo dejo a su criterio
bool esDecimal(string num){
  bool correcto = true;
  for(int i = 0; i < num.length(); i++){
    if(!isdigit(num[i]) && num[i]!='.'){
      correcto = false;
    }
  }
  return correcto;
}

//Lo mismo que para la funcion  esDecimal, solo que para datos tipo int, long y long long, lo dejo a su criterio.
bool esEntero(string num){
  bool correcto = true;
  for(int i = 0; i < num.length(); i++){
    if(!isdigit(num[i])){
      correcto = false;
    }
  }
  return correcto;
}

//Validacion completa. Si el string Datos se encuentra vacio entonces los datos no eran Validos
//Recibe un string (Los datos)
//Recibe un contador (Identificador de linea)
//Le hace referencia a un vector llamado datos
bool datosValidos(string linea, int contador, vector<string> &Datos){
    string linea;
    stringstream ss(linea);
    string categoria, nombre, nomina;
    getline(ss, categoria, ' ');
    getline(ss, nombre, ' ');
    getline(ss, nomina, ' ');
    if(categoriaExiste(categoria) && nombreCorrecto(nombre) && nominaCorrecta(nomina)){//Primera validacion de datos: Tipo de contrato, nombre del empleado y numero de nomina
      switch(categoria[0]){
        //Empleado Categoria 1
        case '1':{
          string tarifa, horas;
          getline(ss, tarifa, ' ');
          getline(ss, horas);
          if(esDecimal(tarifa) && esEntero(horas)){ //Segunda validacion de datos para empleados categoria 1: Tarifa y horas trabajadas
            //Empieza el proceso de calculo de sueldo
            Datos.push_back(categoria);
            Datos.push_back(nombre);
            Datos.push_back(nomina);
            Datos.push_back(tarifa);
            Datos.push_back(horas);
            return true;
          }else{
            cout<<"Existe un error en la linea "<<contador<<". Favor de corregir."<<endl;
            return false;
          }
          break;
        }
        //Empleado Categoria 2
        case '2':{
          string sueldoBase, prestaciones, deducciones;
          getline(ss, sueldoBase, ' ');
          getline(ss, prestaciones, ' ');
          getline(ss, deducciones);
          if(esDecimal(sueldoBase) && esDecimal(prestaciones) && esDecimal(deducciones)){
            /*Segunda validacion de datos para empleados con un contrato tipo 2:
              Sueldo Base, Prestaciones y Deducciones*/
            //Termina Validacion de Datos
            Datos.push_back(categoria);
            Datos.push_back(nombre);
            Datos.push_back(nomina);
            Datos.push_back(sueldoBase);
            Datos.push_back(prestaciones);
            Datos.push_back(deducciones);
            return true;
          }else{
            cout<<"Existe un error en la linea "<<contador<<". Favor de corregir."<<endl;
            return false;
          }
          break;
        }
        //Empleado Categoria 3
        case '3':{
          string porcentaje, numVentas;
          getline(ss, porcentaje, ' ');
          getline(ss, numVentas, ' ');
          if(esDecimal(porcentaje) && esEntero(numVentas)){
            Datos.push_back(categoria);
            Datos.push_back(nombre);
            Datos.push_back(nomina);
            Datos.push_back(porcentaje);
            Datos.push_back(numVentas);
            int numV = stoi(numVentas);
            string precioUni;
            vector<float> preciosUni; //Vector para el precio de cada venta
            bool precioValido = true;
            //Validacion de cada precio.
            for(int i = 0; i < numV && precioValido; i++){
              getline(ss, precioUni, ' ');
              precioValido = esDecimal(precioUni);
              if(precioValido){
                Datos.push_back(precioUni);
              }else{
                precioValido=false;
              }
            }
            if(precioValido){
              //Empieza el proceso de calculo de sueldo
              return true;
            }
          }else{
              cout<<"Existe un error en la linea "<<contador<<". Favor de corregir."<<endl;
              return false;
          }
          break;
        }
      }
    }else{
      cout<<"Existe un error en la linea "<<contador<<". Favor de corregir."<<endl;
      return false;
    }
}
