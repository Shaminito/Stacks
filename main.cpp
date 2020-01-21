#include <iostream>
using namespace std;
struct vox{
	float v;
	string s;
    vox *sgt;
};
vox *peek = NULL;
void push(float x, string y){
   vox *nvox =  new vox;
   nvox->v=x,nvox->sgt=peek;
	nvox->s=y;
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
             cout<<aux->v<<" -> ";
	          cout<<aux->s<<" -> ";
             aux=aux->sgt;
         }
}
int main(){
    int op;
    float x;
    string y;
    do{
        cout<<"\n(1) Push    (2) Pop    (3) Print   (4) Salir \n ";
        cout<<"\n Elija ppcion  ?: ",cin>>op;
        switch (op){
            case 1:
                cout<<"Ingresa el valor float a insertar en el Stack : ??  ",cin>>x;
		          cout<<"Ingresa el valor string  a insertar en el Stack : ??  ",cin>>y;
                push(x,y);
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
