// CONSTRUCCIÓN DE LA PILA
#include <iostream>
using namespace std; //espacio de trabajo estándar

// La caja
struct vox{
    int v;  //Valor normal para guardar en la caja
    vox *sgt;   //Puntero para apuntar a otra caja
};

vox *peek = NULL; //Puntero de tipo vox

void push(int x){ //meter en la pila
   vox *nvox =  new vox; // Crear una instancia y apunta a una dirección cualquiera en la memoria
   nvox->v=x,nvox->sgt=peek; // el valor x se guarda en v donde apunta el puntero | el puntero peek se guarda en sgt
   peek=nvox; // el puntero nvox se guarda en peek para poder guardar la siguiente caja
}
void pop(){ //sacar de la pila
    if(peek==NULL) // Si el puntero no apunta a nada, si esta vacia la pila
        cout<<"Nada que imprimir, Stack vacia \n";
    else
    peek=peek->sgt; //peek avanza a sgt y lo guarda en peek
}
void prt(){
     vox *aux = peek;
     if(aux==NULL)
         cout<<"Nada que imprimir, Stack vacia\n";
     else
         while(aux!=NULL){ // va iterando hasta que no quede nada
             cout<<aux->v<<" -> ";
             aux=aux->sgt; //aux avanza a sgt y lo guarda en aux
         }
}
int main(){
    int op, x;
    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija ppcion  ?: ",cin>>op; //Control de entrada
        switch (op){
            case 1:
                cout<<"Ingresa el valor a insertar en el Stack : ??  ",cin>>x; //Guarda el valor en x
                push(x);
                break;
            case 2:
                cout<<"Eliminando ..... : ";
                pop();
                break;
            case 3:
                cout<<"Imprimiendo..... : ";
                prt();
                break;
            case 4:
                cout<<"------Bye--------";
        }
    }while(op!=4);
}

