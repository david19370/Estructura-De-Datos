#include <stdio.h>
#include <stdlib.h>

struct Circular{
    int dato;
    struct Circular *siguiente;
    struct Circular *anterior;
};

struct Circular *raiz=NULL;

struct Circular *crear (int dato){

 struct Circular *nuevo =NULL;

 nuevo=(struct Circular *)malloc(sizeof(struct Circular));


 nuevo->dato=dato;
 nuevo->siguiente=NULL;
return nuevo;
}

struct Circular *insertar(struct Circular *lista,int dato){

      struct Circular *nuevo=NULL;
      nuevo=crear(dato);

      nuevo->dato=dato;

      if(raiz==NULL)
      {
          nuevo->siguiente=nuevo;
          nuevo->anterior=nuevo;
          raiz=nuevo;
      }
else{
    struct Circular *ultimo=raiz->anterior;
    nuevo->siguiente=raiz;
    nuevo->anterior=ultimo;
    raiz->anterior=nuevo;
    ultimo->siguiente=nuevo;
    raiz=nuevo;
}

return nuevo;
};

void mostrar(struct Circular *lista){


    if(lista!=NULL)
    {
        struct Circular *actual=raiz;
        do{
            printf(" %d ",actual->dato);
            actual=actual->siguiente;
        }
        while(actual!=raiz);
    }
    else{
        printf("no hay nada we");
    }
}

int main()
{
    struct circular *miLista;
    miLista=crear(15);
    if(miLista==NULL)
    {return NULL;}
    insertar(&miLista,50);
     insertar(&miLista,20);
       mostrar(miLista);
    return 0;
}
