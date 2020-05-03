

#include <fstream>

  #include <iostream>

  #include <string>

  #include <cstdlib>

  #include<ctime> 

  #include <stdio.h>

  #include <vector>

  using namespace std;


  struct Productos{

    string codigo;

    int minimo;

    int actual;

    string proveedor;

    float precio;

  };


  std::vector<Productos> producto;


  void agregar_producto(){

    Productos x;

    cout << "Ingrese código de producto"<< "\n";

    cin >> x.codigo;

    cout << "Ingrese el minimo del producto"<< "\n";

    cin >> x.minimo;

    cout << "Ingrese cantidad actual del producto"<< "\n";

    cin >> x.actual;

    cout << "Ingrese el proveedor del producto"<< "\n";

    cin >> x.proveedor;

    cout << "Ingrese precio del producto"<< "\n";

    cin >> x.precio;


      ofstream miarchivo("stock.txt", std::ios_base::app);

      miarchivo << x.codigo << "\t" << x.minimo << "\t" << x.actual << "\t" << x.proveedor << "\t" << x.precio << endl;


      miarchivo.close();

  }


  void mostrar_informacion(){

    

  cout << "Los siguientes productos necesitan mas stock" << endl;

  cout << "---------------------------------------------" << endl;

  cout << "COD"<< "\t" << "MIN" << "\t" << "EXI" << "\t" << "PROVEEDOR" << "\t" << "PRE" << endl;

  cout << "---------------------------------------------" << endl; 


  for (int i=0; i< producto.size(); i++){

    if (producto[i].minimo>=producto[i].actual){

        cout << producto[i].codigo << "\t" << producto[i] .minimo << "\t" << producto[i].actual << "\t" <<   producto[i].proveedor << "\t" << producto[i].precio <<  "\t" << endl;

    }

  }

    string empty;

      cin >> empty;

      return;

  }


  void leer_archivo(){

  

      ifstream miarchivo;


      producto.clear();


      Productos prod;


      miarchivo.open("stock.txt",ios::in);

      


      while(miarchivo >> prod.codigo >> prod.minimo >> prod.actual >> prod.proveedor >> prod.precio)

      {


          producto.push_back(prod);

      }


      miarchivo.close();

      mostrar_informacion();

      return;

  }


  int main() {

    char tecla;

    string empty;

    bool bandera=false;

    

    do

      {

          system("clear");

          cin.clear();

          cout << "Productos" << endl;

          cout << "-----------" << endl << endl;

          cout << "\t1 .- Agregar Producto" <<endl;

          cout << "\t2 .- Leer archivo y mostrar minimos" <<endl;

          cout << "\t3 .- Salir" << endl << endl;

          cout << "Elije una opcion: ";

  

          cin >> tecla;

  

      switch(tecla)

          {

        case '1':

          system("clear");

          agregar_producto();

          break;

  

        case '2':

          system("clear");

          leer_archivo();

          break;

        

        case '3':

          bandera=true;

          

          break;

  

        default:

          system("clear");

          cout << "Opcion no valida.\a\n";

          getchar();

          getline(cin, empty);

          break;

      }

      }while(bandera!=true);

    

    return 0;

  }
