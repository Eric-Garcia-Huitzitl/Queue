//Queue
/*ENQUEUE Inserta los elementos en la cola
DEQUEUE Remueve los elementos de la cola
REAR La operación accede al el elemento final de la cola
FRONT La operacion accede a el elemento del inicio.

El REAR no se borra solo nos regresa el elemento
El FRONT nos regresa el elemento*/
#include <iostream>
typedef int Type;

class Node{
	public:
	Node(const Type);
		Type data;
		Node *ptrSig; 
		Node *ptrAnt; 
}; 
//Contructor Node 
Node::Node(const Type _data){
	data =_data;  
	ptrAnt = NULL;
	ptrSig = NULL;
}
class Queue
{
public:
	Queue();
	void enqueue(Type);
	void dequeue();
	void front();
	void rear();
	void showQueue();
	Node *ptrFront;
	Node *ptrRear;
};
Queue::Queue(){
	ptrFront=NULL; 
	ptrRear=NULL; 
}
void Queue::rear(){
	std::cout<<"REAR: "<<ptrRear->data<<std::endl;
}
void Queue::front(){
	std::cout<<"FRONT: "<<ptrFront->data<<std::endl; 
}
void Queue::dequeue(){
	Node *auxiliar;
		auxiliar=ptrFront->ptrAnt;
			auxiliar->ptrSig=NULL; 
			delete ptrFront; 
			 ptrFront=auxiliar; 
}
void Queue::showQueue(){
	Node *iterator=ptrRear;
	while(iterator->ptrSig!=NULL){
		std::cout<<" "<<iterator->data;
		iterator=iterator->ptrSig;
	}
	std::cout << "\n\n"<<std::endl;
	}
void Queue::enqueue(Type _data){
	Node *aux;
	if (ptrRear==NULL){
		ptrRear = new Node(_data);
		ptrFront = ptrRear;
	}
	//Que pasa si ya existe un elemento
	aux = new Node(_data);
	aux->ptrSig=ptrRear; 
	ptrRear->ptrAnt=aux;
	ptrRear=aux;
}
int main(int argc, char const *argv[])
{	
	Queue uno;
	uno.enqueue(10); 
	uno.enqueue(20);
	uno.enqueue(30);
	uno.enqueue(40);
	uno.enqueue(50);
	uno.enqueue(70);
	uno.dequeue();
	uno.showQueue();
	uno.enqueue(40);
	uno.showQueue();
	return 0;
}