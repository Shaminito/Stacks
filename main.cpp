// CONSTRUCCIÓN DE LA PILA
#include <iostream>
using namespace std;

// La caja
struct vox{
    char nombre;
    char apellido;
    String fecha;
    int numExpediente;
    vox *sgt;
};

vox *peek = NULL;

void push(char nombre, char apellido, String fecha, int numExpediente){
    vox *nvox =  new vox;
    nvox->nombre=nombre;
    nvox->apellido=apellido;
    nvox->fecha=fecha;
    nvox->numExpediente=numExpediente;
    peek=nvox;
}
void pop(){
    if(peek==NULL)
        cout<<"Nada que imprimir, Stack vacia \n";
    else
        peek=peek->sgt;
}
void prt(){
    vox *aux = peek;
    if(aux==NULL)
        cout<<"Nada que imprimir, Stack vacia\n";
    else
        while(aux!=NULL){
            cout<<aux->nombre;
            cout<<aux->apellido;
            cout<<aux->fecha;
            cout<<aux->numExpediente;
            aux=aux->sgt;
        }
}
int main(){
    int op;
    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija opcion  ?: ",cin>>op; //Control de entrada
        switch (op){
            case 1: //Guardar datos en la caja
                char n;
                cout<<"Nombre: ??  ",cin>>n;
                char a;
                cout<<"Apellido: ??  ",cin>>a;
                String f;
                cout<<"Fecha: ??  ",cin>>f;
                int nE;
                cout<<"numExpediente: ??  ",cin>>nE;
                push(n, a, f, nE);
                break;

            case 2: //Eliminar caja
                cout<<"Eliminando ..... : ";
                pop();
                break;

            case 3: //Imprimir datos en la caja
                cout<<"Imprimiendo..... : ";
                prt();
                break;

            case 4: // Finalizar el programa
                cout<<"------Programa finalizado--------";
        }
    }while(op!=4);
}