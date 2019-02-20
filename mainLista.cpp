#include <iostream>
//#include "NODO.h"
#include "LISTA.h"

using namespace std;


void cargarListas(LISTA<int> *lx);
void consultas(LISTA<int> *lx);
void verificar(LISTA<int> *lx);
void invertir(LISTA<int> *lx);
void invertir2(LISTA<int> *lx);
void sublista (LISTA<int> *lx, LISTA<int> *lr);

int main()
{
	LISTA<int> l1, l2, l3, l4, l5, l6, l7, lr;

	cin>>l1;
	cin>>l2;
	cin>>l3;
	cin>>l4;
	cin>>l5;
	cin>>l6;
	cin>>l7;

	cout<<"listas";
	cout<<endl<<"l1: "<<l1.longitud()<<endl;
	cout<<l1;
	cout<<endl<<"l2: "<<l2.longitud()<<endl;
	cout<<l2;
	cout<<endl<<"l3: "<<l3.longitud()<<endl;
	cout<<l3;
	cout<<endl<<"l4: "<<l4.longitud()<<endl;
	cout<<l4;
	cout<<endl<<"l5: "<<l5.longitud()<<endl;
	cout<<l5;
	cout<<endl<<"l6: "<<l6.longitud()<<endl;
	cout<<l6;
	cout<<endl<<"l7: "<<l7.longitud()<<endl;
	cout<<l7;
	cout<<endl<<"lr: "<<lr.longitud()<<endl;
	cout<<lr;

	cout<<"consultas"<<endl;
	cout<<"l1:"<<endl;
	consultas(&l1);
	cout<<"l2:"<<endl;
	consultas(&l2);
	cout<<"l3:"<<endl;
	consultas(&l3);
	cout<<"l4:"<<endl;
	consultas(&l4);
	cout<<"l5:"<<endl;
	consultas(&l5);
	cout<<"l6:"<<endl;
	consultas(&l6);
	cout<<"l7:"<<endl;
	consultas(&l7);


	cout<<"esta?"<<endl;
	cout<<"l1:"<<endl;
	verificar(&l1);
	cout<<"l2:"<<endl;
	verificar(&l2);
	cout<<"l3:"<<endl;
	verificar(&l3);
	cout<<"l4:"<<endl;
	verificar(&l4);
	cout<<"l5:"<<endl;
	verificar(&l5);
	cout<<"l6:"<<endl;
	verificar(&l6);
	cout<<"l7:"<<endl;
	verificar(&l7);
	cout<<"lr:"<<endl;
	verificar(&lr);


	cout<<"invertir Listas"<<endl;
	cout<<"l1:"<<endl;
	cout<<l1<<endl;
	l1.invertirL();
	cout<<l1<<endl;
	l1.invertirL();
	cout<<l1<<endl;
	cout<<"l2:"<<endl;
	cout<<l2<<endl;
	l2.invertirL();
	cout<<l2<<endl;
	l2.invertirL();
	cout<<l2<<endl;
	cout<<"l3:"<<endl;
	cout<<l3;cout<<endl;
	l3.invertirL();
	cout<<l3;cout<<endl;
	l3.invertirL();
	cout<<l3;cout<<endl;
	cout<<"l4:"<<endl;
	cout<<l4;cout<<endl;
	l4.invertirL();
	cout<<l4;cout<<endl;
	l4.invertirL();
	cout<<l4;cout<<endl;
	cout<<"l5:"<<endl;
	cout<<l5;cout<<endl;
	l5.invertirL();
	cout<<l5;cout<<endl;
	l5.invertirL();
	cout<<l5;cout<<endl;
	cout<<"l6:"<<endl;
	cout<<l6;cout<<endl;
	l6.invertirL();
	cout<<l6;;cout<<endl;
	l6.invertirL();
	cout<<l6;;cout<<endl;
	cout<<"l7:"<<endl;
	cout<<l7;cout<<endl;
	l7.invertirL();
	cout<<l7;cout<<endl;
	l7.invertirL();
	cout<<l7;cout<<endl;


	cout<<"invertir SUBListas(con elementos)";
	cout<<endl<<"l1:"<<endl;
	lr= l1;
	invertir(&l1);
	l1= lr;
	cout<<endl<<"l2:"<<endl;
	lr= l2;
	invertir(&l2);
	l2= lr;
	cout<<endl<<"l3:"<<endl;
	lr= l3;
	invertir(&l3);
	l3= lr;
	cout<<endl<<"l4:"<<endl;
	lr= l4;
	invertir(&l4);
	l4= lr;
	cout<<endl<<"l5:"<<endl;
	lr= l5;
	invertir(&l5);
	l5= lr;
	cout<<endl<<"l6:"<<endl;
	lr= l6;
	invertir(&l6);
	l6= lr;
	cout<<endl<<"l7:"<<endl;
	lr= l7;
	invertir(&l7);
	l7= lr;

	lr.vaciarL();


	cout<<endl<<"invertir SUBListas(con enteros/posiciones)"<<endl;
	cout<<"l1:"<<endl;
	lr= l1;
	invertir2(&l1);
	l1= lr;
	cout<<endl<<"l2:"<<endl;
	lr= l2;
	invertir2(&l2);
	l2= lr;
	cout<<endl<<"l3:"<<endl;
	lr= l3;
	invertir2(&l3);
	l3= lr;
	cout<<endl<<"l4:"<<endl;
	lr= l4;
	invertir2(&l4);
	l4= lr;
	cout<<endl<<"l5:"<<endl;
	lr= l5;
	invertir2(&l5);
	l5= lr;
	cout<<endl<<"l6:"<<endl;
	lr= l6;
	invertir2(&l6);
	l6= lr;
	cout<<endl<<"l7:"<<endl;
	lr= l7;
	invertir2(&l7);
	l7= lr;

	lr.vaciarL();


	cout<<endl<<"es sublista?"<<endl;
	cout<<"l1:"<<endl;
	sublista(&l1,&lr);
	cout<<"l2:"<<endl;
	sublista(&l2,&lr);
	cout<<"l3:"<<endl;
	sublista(&l3,&lr);
	cout<<"l4:"<<endl;
	sublista(&l4,&lr);
	cout<<"l5:"<<endl;
	sublista(&l5,&lr);
	cout<<"l6:"<<endl;
	sublista(&l6,&lr);
	cout<<"l7:"<<endl;
	sublista(&l7,&lr);

	/*cout<<endl<<endl<<"-----ORDENAR-----"<<endl;
	cout<<endl<<endl<<"l1:"<<endl;
	l1.imprimir();
	l1.ordenar();
	l1.imprimir();*/

	

}




	void cargarListas(LISTA<int> *l1)
	{
		int e, pos;
		//cout<<"lista 1::"<<endl;
		do
		{
			//cout <<endl<<"ingrese la posicion en la que desea insertar:  (un valor negativo para salir)"<<endl;
			cin >> pos;
			
			if (pos>0)
			{
			//	cout<<endl<<"ingrese el elemento que desea insertar: "<<endl;
				cin >> e;
				
				l1->insertar(e, pos);
			//	l1.imprimir();
			}
			//l1->imprimir();
		} while (pos>0);

		//~ l1.imprimir();
		//~ l2.imprimir();
	}



	void consultas(LISTA<int> *lx)
	{
		int pos;
		do
		{
			cin >> pos;
			if (pos!=-1)
			{
				cout<<pos<<"->";
				if ((pos>lx->longitud())||(pos<1))
					cout<<"no"<<endl;
				else
					cout<<lx->consultar(pos)<<endl;
				
			}
		} while (pos!=-1);
	}



	void verificar(LISTA<int> *lx)
	{
		int e;
		do
		{
			cin >> e;
			if (e!=-1)
				cout<<e<<"->"<<lx->esta(e)<<endl;
		} while (e!=-1);

	}



	void invertir(LISTA<int> *lx)
	{
		
		int a, b;
		cout<<*lx;
		cin>> a;
		cin>> b;
		cout<<endl<<a<<"-"<< b<<endl;
		lx->invertirSubL(a, b);
		cout<<*lx;
		cin>> a;
		cin>> b;
		cout<<endl<<a<<"-"<< b<<endl;
		lx->invertirSubL(a, b);
		cout<<*lx;
	}


	void invertir2(LISTA<int> *lx)
	{
	
		int a, b;
		cout<<*lx;
		cin>> a;
		cin>> b;
		cout<<endl<<a<<"-"<< b<<endl;
		lx->invertSubLint(a, b);
		cout<<*lx;
		cin>> a;
		cin>> b;
		cout<<endl<<a<<"-"<< b<<endl;
		lx->invertSubLint(a, b);
		cout<<*lx;
		
	}



	void sublista (LISTA<int> *lx, LISTA<int> *lr)
	{
		int x;

		lr->vaciarL();
		cin>>*lr;
		cout<<"lx: ";
		cout<<*lx;cout<<endl;
		cout<<"lR: ";
		cout<<*lr;cout<<endl;
		x= lx->esSubL(*lr);
		//cout<<"((((((("<<x<<"))))))"<<endl;
		if (x>0)
			cout<<"SI"<<endl;
		else
			cout<<"NO"<<endl;
		
		lr->vaciarL();
		cin>>*lr;
		cout<<"lx: ";
		cout<<*lx;cout<<endl;
		cout<<"lR: ";
		cout<<*lr;cout<<endl;
		x= lx->esSubL(*lr);
		//cout<<"((((((("<<x<<"))))))"<<endl;
		if (x>0)
			cout<<"SI"<<endl;
		else
			cout<<"NO"<<endl;
			
}


