#include <iostream>

 using namespace std;
 const char *nombre_archivo = "archivo.dat";
 struct Estudiante {
 	int codigo;
 	char nombres[50];
 	char apellidos [50];
 	int telefono;
 };
 void Leer();
  void Crear();
 main(){
 	
 	
 	
 	
 	//archivos binarios
 	  Leer();
 	 Crear();
 	system("pause");
 }
 void Leer(){
 		system("cls");
 		 FILE* archivo = fopen(nombre_archivo,"rb");
 		 if(!archivo){
 		  archivo = fopen(nombre_archivo,"w+b");
 		 	
 		 	 }
 		 	 Estudiante estudiante;
 		 	 int id=0; // indice o pocision del registro (fila)dentro del archivo
 		 	 fread(&estudiante,sizeof(Estudiante),1,archivo);
 		 	 cout<<"__________________________________________________"<<endl;
 		 	 cout<<"ID"<<"|"<<"Codigo"<<"|"<<"  Nombres   "<<"|"<<"  Apellidos  "<<"|"<<"  Telefono  "<<endl;
 		 	 do{
 		 	    cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
                 fread(&estudiante,sizeof(Estudiante),1,archivo);
 	             
				    id+=1;
			   }while(feof(archivo)==0);
			   fclose(archivo);
 	
 	
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
			cout<<" ingresar otro estudiante(s/n):";
 		   cin>>res;
		 }while(res=='s' || res=='S');
 		
		 fclose(archivo);
		 Leer();
 
 }