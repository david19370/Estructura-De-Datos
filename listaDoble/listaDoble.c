#include<stdlib.h>
#include<stdio.h>

struct Lista{
 int dato;
 struct Lista *siguiente;
 struct Lista *anterior;
};


struct Lista *crear (int dato){
 struct Lista *nuevo =NULL;
 nuevo=(struct Lista *)malloc(sizeof(struct Lista));
 if(nuevo==NULL)
 { return NULL;}
 nuevo->dato = dato;
 nuevo ->siguiente =NULL;
 nuevo->anterior=NULL;
return nuevo;
}

struct Lista *insertar(struct Lista*lista , int dato){
struct Lista *nueva=crear(dato);
if(nueva!=NULL)
{
	nueva->siguiente = lista;
nueva->anterior=NULL;
	
if(lista==NULL)
{	lista->anterior=nueva;  }

lista=nueva;

}

return nueva;
}


void mostrar (struct Lista *lista){
	struct Lista *aux=lista;
while(aux!=NULL)
{
 printf(" %d ",aux->dato);
 aux=aux->siguiente;
 }
printf("\n");
}

struct Lista *invertir(struct Lista *lista){
   struct Lista *nueva=lista;
   
   while(lista!=NULL)
   {
   	nueva=insertar(nueva,lista->dato);
   	lista=lista->siguiente;
    
   }
  mostrar(nueva);
    
    return nueva;
}

struct Lista *insertarFinal(struct Lista *lista, int dato){
	struct Lista *nuevo=NULL;
	struct Lista *aux=lista;
	
	nuevo=crear(dato);
	if(nuevo!=NULL)
	{          
	while( aux->siguiente!=NULL) 
         {          aux=aux->siguiente; }
         nuevo->anterior=aux;
         aux->siguiente=nuevo;
         

		}
	return nuevo;
}

int main(void){
 struct Lista *miLista=crear(15);
 
miLista=insertar(miLista,12);

miLista=insertar(miLista,27);

insertarFinal(miLista,50);

mostrar(miLista);
invertir(miLista);
return 0;
}
