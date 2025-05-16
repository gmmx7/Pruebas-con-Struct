/*
	Opción de programa usando *struct*
*/
#include <iostream>
using namespace std;

//Clase Alumno
class Alumno{
	private:
	string boleta;
	string nombre;
	string genero;
	float promedio;
	short semestre;
	string carrera;
	public:
	//Se define constructor, getters y setters
	Alumno();
	Alumno(string,string,string,float,short,string);
	//Getters
	string getBoleta();
	string getNombre();
	string getGenero();
	float getPromedio();
	short getSemestre();
	string getCarrera();
	//Setters
	void setBoleta(string);
	void setNombre(string);
	void setGenero(string);
	void setPromedio(float);
	void setSemestre(short);
	void setCarrera(string);
	//Funciones
	
};

//Inicialización del constructor, getters y setters
Alumno::Alumno(){
	boleta = "";
    nombre = "";
    genero = "";
    promedio = 0.0;
    semestre = 0;
    carrera = "";
}

Alumno::Alumno(string boleta,string nombre,string genero,float promedio,short semestre,string carrera){
	this->boleta = boleta;
	this->nombre = nombre;
	this->genero = genero;
	this->promedio = promedio;
	this->semestre = semestre;
	this->carrera = carrera;
}

string Alumno::getBoleta(){
	return boleta;
}
string Alumno::getNombre(){
	return nombre;
}
string Alumno::getGenero(){
	return genero;
}
float Alumno::getPromedio(){
	return promedio;
}
short Alumno::getSemestre(){
	return semestre;
}
string Alumno::getCarrera(){
	return carrera;
}
void Alumno::setBoleta(string boleta){
	this->boleta = boleta; 
}
void Alumno::setNombre(string nombre){
	this->nombre = nombre;
}
void Alumno::setGenero(string genero){
	this->genero= genero;
}
void Alumno::setPromedio(float promedio){
	this->promedio = promedio;
}
void Alumno::setSemestre(short semestre){
	this->semestre = semestre;
}
void Alumno::setCarrera(string carrera){
	this->carrera = carrera;
}

class Materia{
	private:
	string claveMateria;
	string nombreMateria;
	public:
	//constructor, getters
	Materia(string, string);
	string getClaveMateria();
	string getNombreMateria();
};

Materia::Materia(string claveMateria, string nombreMateria){
	this->claveMateria = claveMateria;
	this->nombreMateria = nombreMateria;
}

string Materia::getClaveMateria(){
	return claveMateria;
}
string Materia::getNombreMateria(){
	return nombreMateria;
}
 
struct AlumnoMateria {
    string rel_boleta;     // clave de alumno
    string rel_claveMateria;  // clave de materia
};

int main(){
	Alumno alumnos[10];
	AlumnoMateria relaciones[60];
	int opc, contador = 0;
	bool boletaEncontrada = false;
	string boleta;
				
	//Se crea el listado de materias para asociarlas con el alumno
	Materia m1("117","Calculo vectorial");
	Materia m2("054","Matematicas discretas");
	Materia m3("087","Electricidad y magnetismo");
	Materia m4("115","Programacion Orientada a objetos");
	Materia m5("114","Algebra lineal");
	Materia m6("103","Humanidades II");
	
	Materia materias[6] = {m1,m2,m3,m4,m5,m6};
	int totalRelaciones = 0;
	
	cout << "--------Sistema de registro de alumnos--------" << endl;
	cout << "Se tiene como limite un registro de 10 alumnos";
	cout << endl;
	
	do{
		cout << " \n------------Menu------------" << endl;
		cout << "1.Registro de alumno" << endl;
		cout << "2.Buscar alumno por boleta" << endl;
		cout << "3.Salir" << endl;
		cout << "Opcion: ";
		cin >> opc;
		cin.ignore();
		switch(opc){
			case 1:
				cout << "\nNOTA: al ingresar alumno se deben registrar las materias" << endl;
				cout << "-> Presione ENTER para continuar" << endl;
				if (contador < 10) {
					Alumno nuevo;
					string boleta, nombre, genero, carrera;
					float promedio;
					short semestre;
				
					cin.ignore(); // Limpia buffer por si queda un salto de línea pendiente
					cout << "---------Alumno nuevo ["<< contador + 1 <<"]----------" << endl;
					cout << "Boleta: ";
					getline(cin, boleta); //Obtener toda la cadena del string
					nuevo.setBoleta(boleta);
					
					cout << "Nombre: ";
					getline(cin, nombre); 
					nuevo.setNombre(nombre);
					
					cout << "Genero: ";
					getline(cin, genero);
					nuevo.setGenero(genero);
					
					cout << "Promedio: ";
					cin >> promedio;
					nuevo.setPromedio(promedio);
					
					cout << "Semestre: ";
					cin >> semestre;
					nuevo.setSemestre(semestre);
					
					cin.ignore();
					cout << "Carrera: ";
					getline(cin, carrera);
					nuevo.setCarrera(carrera);
					
					alumnos[contador] = nuevo;
					contador++;
					
					cout << "\n------Materias disponibles a cursar------\n";
					//Materias a cursar dependiendo de la clave
					for(int i=0;i<6;i++){
						cout << materias[i].getClaveMateria() << " - " << materias[i].getNombreMateria() << endl;
					}
					int numMaterias;
					cout << "\nMaterias a ingresar: ";
					cin >> numMaterias;
					cin.ignore();
					
					for(int i=0;i<numMaterias;i++){
						string clave;
						bool claveValida = false;
						do{
							cout << "\nClave de la materia: ";
							getline(cin, clave);
							
							for(int j=0;j<6;j++){
								if(clave == materias[j].getClaveMateria()){
									claveValida = true;
									if(totalRelaciones < 60){
										relaciones[totalRelaciones].rel_boleta = boleta;
										relaciones[totalRelaciones].rel_claveMateria = clave;
										totalRelaciones++;
										cout << materias[j].getNombreMateria() << ": Asignada a " << nuevo.getNombre() << endl;
									}else{
										cout << "No se permiten mas relaciones." << endl;
									}
								}
							}
							
							if(!claveValida){
								cout << "Clave de materia no existente, ingrese de nuevo" << endl;
							}
						}while(!claveValida);
					}
					cout << "\nAlumno registrado con exito.\n";						
				}else{
					cout << "\nEstructura de 10 alumnos llena.\n";		
				}
				break;
			case 2:
				//Buscar Relación entre alumno y materia
				cout << "-----Busqueda de alumno por materia-----" << endl;
				cout << "Boleta a buscar: ";
				getline(cin,boleta);
				
				cout << "\nBuscando..." << endl;
				cout << "Datos del alumno:" << endl;
				for(int i=0;i<contador;i++){
					if(boleta == alumnos[i].getBoleta()){
						boletaEncontrada = true;
						cout << "Nombre: " << alumnos[i].getNombre() << endl;
						cout << "Genero: " << alumnos[i].getGenero() << endl;
						cout << "Promedio: " << alumnos[i].getPromedio() << endl;
						cout << "Carrera: " << alumnos[i].getCarrera() << endl;
						cout << "Semestre: " << alumnos[i].getSemestre() << endl;
					}
				}
				
				cout << "Materias que el alumno esta cursando:" << endl;
				cout << "----------------------------------------------------" << endl;
				for(int i=0;i<totalRelaciones;i++){
					if(boleta == relaciones[i].rel_boleta){
						string claveMateria = relaciones[i].rel_claveMateria;
						for(int j=0;j<6;j++){
							if(claveMateria == materias[j].getClaveMateria()){
								cout << materias[j].getClaveMateria() << " - " << materias[j].getNombreMateria() << endl;
							}
						}
					}
				}
				cout << "----------------------------------------------------" << endl;
				
				break;
			default: cout << "Fin del programa" ;
		}
	}while(opc != 3);
	return 0;
}
