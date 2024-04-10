#include <iostream>

 using namespace std;
 const char *nombre_archivo = "archivo.dat";
 struct Estudiante {
 	int codigo;
 	char nombres[50];
 	char apellidos [50];
 	int telefono;
 };
 
  void Crear();
 main(){
 	
 	
 	
 	
 	//archivos binarios
 	  Crear();
 	system("pause");
 }
 void Crear(){
 		
		 FILE* archivo = fopen(nombre_archivo,"a+b");
 		char res;
 		Estudiante estudiante;
 		do{	
 		    fflush(stdin);
 		    cout<<"ingrese Codigo:";
 		    cin>>estudiante.codigo;
 		    cin.ignore();
 		    
		    cout<<"Ingrese Nombres:";
 		    cin.getline(estudiante.nombres,50);
 		     
			  cout<<"Ingrese Apellidos:";
 		    cin.getline(estudiante.apellidos,50);
 		   
 		 cout<<"ingrese Telefono:";
 		    cin>>estudiante.telefono;
 		    
 		
 		   fwrite(&estudiante,sizeof(Estudiante),1,archivo);
			cout<<"desea ingresar otro estudiante(s/n):";
 		   cin>>res;
		 }while(res=='s' || res=='S');
 		
 		
		 fclose(archivo);
 
 }