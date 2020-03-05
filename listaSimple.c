#include<stdlib.h>
#include<stdio.h>

struct Lista{
 int dato;
 struct Lista *siguiente;
};


struct Lista *crear (int dato){
 struct Lista *nuevo =NULL;
 nuevo=(struct Lista *)malloc(sizeof(struct Lista));
 if(nuevo==NULL)
 { return NULL;}
 nuevo->dato = dato;
 nuevo ->siguiente =NULL;
return nuevo;
}

struct Lista *insertar(struct Lista*lista , int dato){
struct Lista *nueva=crear(dato);
nueva->siguiente = lista;
return nueva;
}


void mostrar (struct Lista *lista){
while(lista!=NULL)
{
 printf(" %d ",lista->dato);
 lista=lista->siguiente;
 }
printf("\n");
}

struct Lista *invertir(struct Lista *lista){
   struct Lista *nueva=NULL;
   
   while(lista!=NULL)
   {
   
      nueva=insertar(nueva,lista->dato);
     lista=lista->siguiente;
    
   }
  mostrar(nueva);
    
    return nueva;
}

int main(void){
 struct Lista *miLista=crear(20);
 
 if(miLista==NULL)
 {
 printf("No se pudo crear la Lista");
 return NULL;
 }
miLista=insertar(miLista,12);
miLista=insertar(miLista,27);

mostrar(miLista);

invertir(miLista);

return 0;
}
