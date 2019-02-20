#ifndef LISTA_H_
#define LISTA_H_

#include "NODO.h"
#include <iostream>

using namespace std;

template <class T>
class LISTA;
template<class T> istream& operator>> (istream& os, LISTA<T>& lx);
template<class T> ostream& operator<< (ostream& os, const LISTA<T>& lx);


template <class T>
class LISTA
{
private:
	NODO<T> *prim, *ult;
	int ch;
	void QuickSort(int izq, int der);
	static void mayoRecursivo(NODO<T>* aux,T *e, int *n);//usada para una asignacion en un lab
	
/**protected:*/
public:
	void eliminarPtr(NODO<T>* ptr);		//recibe un apuntador al elemento que desea eliminar
	NODO<T>* estaPtr(const T& e) const;
	NODO<T>* consultarPtr(int pos) const;
	NODO<T>* first()const {return prim;}
	NODO<T>* last()const {return ult;}
	void insertarPtr(NODO<T>* ptr, const T& e);	//recibe un apuntador al elemento que esta en la posicion donde se va a inserta
	
public:

	///constructores_Destructor
	LISTA<T>();
	LISTA<T>(const LISTA<T>& l);
	~LISTA<T>();
	
	///consultores
	bool EsVacia() const;
	int longitud() const {return ch;};
	T consultar(int pos) const;
	int esta(const T& e) const;
	
	//modificadores
	void insertar(const T& e, int pos);
	void eliminar(int pos);
	void vaciarL();

	///editadas
	LISTA<T> copy()const{LISTA<T> aux; aux=*this;return (aux);}
	void modifElem(int pos, const T& e);
	void insertar(const T& e);//si solo se le pasa el elemento como parametro, entonces asume que es un insertar ordenado
	void invertirL();
	void invertirSubL(const T& a, const T& b);
	void invertSubLint(int a, int b);
	int esSubL(const LISTA<T> &x)const;
	int ocurrencia(const LISTA &x) const;//indica cuantas veces aparece una subLista
	void imprimir() const ;
	void eliminarSL(const LISTA<T> &x);
	LISTA<T> generarSL(const T& a, const T& b);
	LISTA<T> generarSLint(int x, int y);
	int estaOrdenada() const;
	T menorElem() const;
	int menorPos() const;
	T mayorElem() const;
	int mayorPos() const;
	LISTA<T> intersecion(const LISTA<T> &l2);
	void mezclarL(const LISTA<T> &l1, const LISTA<T> &l2);//retorna una lista con los elementos de ambas listas ordenados
	void swap(int i1, int i2)const;
	
		///*Ordenamiento
		void ordenar();
		

	///sobreCargas
	bool operator==(const LISTA<T>& l2) const;
	bool operator!=(const LISTA<T>& l2) const;
	LISTA<T> operator+(const LISTA<T>& l2) const;
	LISTA<T> operator-(const LISTA<T>& l2) const;
	void operator=(const LISTA<T>& l2);
	friend istream& operator>> <>(istream& is, LISTA<T>& lx);
	friend ostream& operator<< <>(ostream& os, const LISTA<T>& lx);


	
	///para las clases
	void mayorElem(T *mayor,int *n);
	void mezclarL2(const LISTA<T> &l1, const LISTA<T> &l2);

	
	
};

//(cpp) desarrollo
	template<class T>
	istream& operator>> (istream& is, LISTA<T>& lx)
	{
		int n;
		T e;
		
		is>> n;
		for (int i = 1; i <= n; i++)
		{	
			is>> e;
			lx.insertar(e, i);
		}
		return is;
	}


	template <class T>
	ostream& operator<< (ostream& os, const LISTA<T>& lx)
	{
		NODO<T>* aux;
		if (lx.ch> 0)
		{
			aux= lx.prim;
			while (aux->ObtSig()!=NULL)
			{
				os<<aux->ObtElem()<<"\n-\n";
				aux= aux->ObtSig();

			}
			os<<aux->ObtElem();

		}
		return os;
	}

///construtores
	template<class T>
	LISTA<T>::LISTA()
	{
		///- cout<<"contructor_basico(lista)/";
		ch= 0;
		prim= NULL;
		ult= NULL;
		
	}

	template<class T>
	LISTA<T>::LISTA(const LISTA<T>& l2)
	{
		///- cout<<"sobrecarga(= ... <<lista>>)/";
		//cout<<"constructor copia\n";

		NODO<T> *aux;

		this->vaciarL();
		aux= l2.prim;

		while(aux!= NULL)
		{
			this->insertar(aux->ObtElem(), this->ch+1);
			aux= aux->ObtSig();
		}

	}
	


/////////////////////////////////////////////
///consultoras	
	template<class T>
	bool LISTA<T>::EsVacia() const
	{
		return (ch== 0);
	}
	
	
	template<class T>
	T LISTA<T>::consultar(int pos) const
	{
		///- cout<<"consultar(lista)/";
		T r;
		int i;
		NODO<T>* aux;
		
		if ((pos>0)&&(pos<= this->ch))
		{
			aux= prim;
			for (i = 1; i < pos; i++)//recorre todos los nodos(confirmado)
			{
				aux= aux->ObtSig();
			}
			r= aux->ObtElem();
		}
		
		///- cout<<"return(R).. <<fconsultar(Lista)>>/";
		return (r);
	}


	template<class T>
	int LISTA<T>::esta(const T& e) const
	{	
		int i;
		NODO<T>* aux;
		bool encontrado;
		
		aux= prim;
		i=1;
		encontrado= 0;
		while ((!encontrado) && (aux!= NULL))
		{
			if (aux->ObtElem()== e)
				encontrado= 1;
			
			else
			{
				aux= aux->ObtSig();
				i++;
			}		
		}

		if (encontrado== 0)
			i= -1;//un valor negativo que indica que no esta el elemento
			
		return (i);
	}
	


/////////////////////////////////////////////
///modificadoras

	template<class T>
	void LISTA<T>::modifElem(int pos, const T& e)
	{
		NODO<T> *aux;
		aux=this->consultarPtr(pos);
		aux->ModifElem(e);
	}

	
	template<class T>
	void LISTA<T>::insertar(const T& e, int pos)
	{
		///- cout<<"insertar(lista)/";
		NODO<T> *nvo, *ant;
		int i;
		
		nvo= new NODO<T>;//crea o reserva la memoria para el nodo nvo
		nvo->ModifElem(e);//le asigna el elemento al nvo nodo

		
		if ((pos <= ch+1) && (pos>=1))//veriica que la posicion este en el rango de la cantidad de elementos actuales
		{
			if(ch== 0)//si es el unico elemento
			{
				nvo->ModifSig(ult);//coloca el nvo nodo apuntando al primer elemento
				nvo->ModifAnt(prim);//y como no tiene un nodo anterior, se le coloca apuntando a NULL
				prim= nvo;//luego, coloca al apuntador prim a apuntar al nvo nodo
				ult= nvo;
			}
					
			else if (pos== 1)//si es la primera posicion
			{
				nvo->ModifSig(prim);//coloca el nvo nodo apuntando al primer elemento
				nvo->ModifAnt(NULL);//y como no tiene un nodo anterior, se le coloca apuntando a NULL
				prim->ModifAnt(nvo);
				prim= nvo;//luego, coloca al apuntador prim a apuntar al nvo nodo
			}

			else if(pos== ch+1)//si es la ultima posicion
			{
				nvo->ModifSig(NULL);//como no tiene un nodo proximo, se le coloca apuntando a NULL
				nvo->ModifAnt(ult);//coloca el nvo nodo apuntando al que era el ultimo elemento
				ult->ModifSig(nvo);//luego, coloca al apuntador de elq era el ultimo elemento a apuntar al nvo nodo
				ult=nvo; 

			}
			
			else// sino, si es una posicion intermedia
			{
				if (pos<=((ch/ 2)+ (ch% 2) ))//si la posicion esta en la primera mitad
				{
					//cout<<"\n--------primera mitad\n";
					ant= prim;
					for (i = 1; i < pos-1; i++)//frena el recorrido en el anterior a la poscion deseada
					{
						ant= ant->ObtSig();
					}
					
					ant->ObtSig()->ModifAnt(nvo);
					nvo->ModifSig(ant->ObtSig());//ahora nvo apunta al siguien del anterior
					nvo->ModifAnt(ant);//ahora, coloca al nvo nodo a apuntar a su anterior (ant)
					ant->ModifSig(nvo);
					//cout<<"enlace SUCCES FULL\n";
				}

				else//si pos esta en la segunda mitad
				{
					//cout<<"\n--------segunda mitad\n";
					ant= ult;
					for (i = ch; i > pos; i--)//frena el recorrido en el anterior a la poscion deseada
					{//cout<<i<<","<<ant->ObtElem()<<"\n";
						ant= ant->ObtAnt();
					}//cout<<i<<","<<ant->ObtElem()<<"\n";
				
					
					nvo->ModifSig(ant);
					nvo->ModifAnt(ant->ObtAnt());
					ant->ObtAnt()->ModifSig(nvo);
					ant->ModifAnt(nvo);
					//cout<<"enlace SUCCES FULL\n";
				}
			}

			//succes_full
			ch++;//aunmenta la cantidad de elementos
		}
		
		///- cout<<"Finsertar(Lista)/";
	}
	
	
	template <class T>
	void LISTA<T>:: eliminar(int pos)
	{
		NODO<T> *aux, *enl;
		int i;
		
		if((ch> 0)&&((pos<=ch) && (pos>=1)))//si esta dentro del rango y existe almenos un elemento
		{
			if(ch==1)//si queda un solo elemento
			{
				delete (prim);
				prim= NULL;
				ult= NULL;

			}
			
			else if (pos== 1)//si es el primer elemento
			{
				enl= prim->ObtSig();
				delete (prim);
				prim= enl;
				prim->ModifAnt(NULL);
				
			}

			else if(pos== ch)//si es el ultimo elemento
			{
				enl= ult->ObtAnt();
				delete (ult);
				ult= enl;
				ult->ModifSig(NULL);
				
			}
			
			else// si es una posicion intermedia
			{
				if (pos<=(ch/ 2))//si la posicion esta en la primera mitad
				{
					enl= prim;
					for (i = 1; i < pos-1; i++)//termina en < (pos-1) xq ya el apuntador aux esta en el primer nodo antes de entrar al ciclo
					{
						enl= enl->ObtSig();
					}
					
					aux= enl->ObtSig();
					enl->ModifSig(aux->ObtSig());
					aux->ObtSig()->ModifAnt(enl);
					delete(aux);
				}

				else//si la pos pertence a la segunda mitad
				{
					enl= ult;
					for (i = ch; i > pos+1; i--)//termina en pos-1 xq ya el apuntador aux esta en el primer nodo antes de entrar al ciclo
					{
						enl= enl->ObtAnt();
					}
					
					aux= enl->ObtAnt();
					enl->ModifAnt(aux->ObtAnt());
					aux->ObtAnt()->ModifSig(enl);
					delete(aux);
				}
			}
			ch--;
		}
	}


	template <class T>
	void LISTA<T>:: vaciarL()
	{
		int i, n;
		NODO<T> *aux, *sig;
		
		aux= prim;
		n= ch;
		if(aux!=NULL)
		{
			for (i = 0; i < n; i++)
			{
				sig= aux->ObtSig();
				delete (aux);
				ch--;
				aux= sig;
			}

			prim= NULL;
			ult= NULL;
		}
		ch=0;
	}



/////////////////////////////////////////////	
///destructor
	template <class T>
	LISTA<T>:: ~LISTA()
	{
		
		///- cout<<"destructor_lista/";
		int i, n;
		NODO<T> *aux, *sig;
		
		aux= prim;
		n= ch;
		if(aux!=NULL)
		{
			for (i = 0; i < n; i++)
			{
				sig= aux->ObtSig();
				//cout<<"deleteAux/"<<endl;
				///liberar nodo
				aux->ModifSig(NULL);
				aux->ModifAnt(NULL);
				delete (aux);
				//cout<<"deleteAux--SucessFull/"<<endl;
				ch--;
				aux= sig;
			}
			prim= NULL;
			ult= NULL;
		}
		///- cout<<"FdestructorLista/";
	//	cout <<"\n\n\n\tLista destruida, ahora posee "<< ch<< " elementos\n\n";
	}


/////////////////////////////////////////////
///Editadas

	template<class T>
	void LISTA<T>::insertar(const T& e)//insertOrdenado
	{
		//cout << "\ninsertar ordenado:\n";
		NODO<T> *nvo, *aux;
		int pos;
		
		nvo= new NODO<T>;//crea o reserva la memoria para el nodo nvo
		//cout<<"modificar elemento\n";
		nvo->ModifElem(e);//le asigna el elemento al nvo nodo
		//cout<<"elemento modificado\n";
		
			if(ch== 0)//si es el unico elemento
			{
				//cout << "no hay elementos\n";
				nvo->ModifSig(NULL);//coloca el nvo nodo apuntando al primer elemento
				nvo->ModifAnt(NULL);//y como no tiene un nodo anterior, se le coloca apuntando a NULL
				prim= nvo;//luego, coloca al apuntador prim a apuntar al nvo nodo
				ult= nvo;
			}
			
			else// sino, si es una posicion intermedia
			{
				//cout << "si hay elemento\n";

				aux= prim;//coloca al aux a apuntar a la primera posicion
				pos= 1;//indica que el aux esta en la primera posicion
				while ((aux!= NULL) && (e> (aux->ObtElem() )) )
				{
					aux= aux->ObtSig();
					pos++;
				}
//cout<<"posicion:"<< pos<<"\n";
				if (pos== 1)//si es en la primera posicion
				{
				//	cout << "va a ingrsar en la primera pos\n";
					prim= nvo;
					nvo->ModifSig(aux);
					aux->ModifAnt(nvo);
				}

				else if(pos== ch+1)//si es la ultima posicion
				{
			//		cout << "va a ingrsar en la ultima pos\n";
					aux= ult;// lo pone en la ultima posicion hasta ahora(antes estaba en null)

					ult= nvo;
					nvo->ModifAnt(aux);
					aux->ModifSig(nvo);
				}
				
				else//si es una posicion intermedia
				{
			//		cout << "va a ingrsar en la pos intermedia\n";
					nvo->ModifSig(aux);
					nvo->ModifAnt(aux->ObtAnt());
					aux->ObtAnt()->ModifSig(nvo);
					aux->ModifAnt(nvo);
				}


			}

			ch++;//aumenta la cantidad de elementos

	}


	template<class T>
	void LISTA<T>:: invertirL()
	{
		NODO<T> *ant, *act, *sig;
		
		ant= NULL;
		act= prim;
		while(act!=NULL)
		{
			sig= act->ObtSig();
			act->ModifSig(ant);
			act->ModifAnt(sig);
			ant= act;
			act= sig;
		}
		ult= prim;
		prim= ant;
	}
	

	template<class T>
	void LISTA<T>:: invertirSubL(const T& a, const T& b)
	{
		NODO<T> *ant, *act, *sig, *aux, *aux2;
		bool band;
		int na, nb;

		aux= prim;
		band= false;

		na= this->esta(a);
		nb= this->esta(b);

		if ( (ch>1) &&(nb>na)&& ((na>0)&&(na<ch)) && ((nb>1)&&(nb<=ch)) )
		{
		
			while (aux->ObtElem()!= a)
					aux=aux->ObtSig();
			
			act= aux;
			aux2= aux;
			ant= aux->ObtAnt();
			aux= ant;
			while(!band)
			{
				if(act->ObtElem()== b)
					band=true;
				
				sig= act->ObtSig();
				act->ModifSig(ant);
				act->ModifAnt(sig);
				ant= act;
				act= sig;
			}
			
			//aux->ObtSig()->ModifSig(act);
			//act->ModifAnt(aux->ObtSig());
			aux2->ModifSig(act);
			if(act!=NULL)
				act->ModifAnt(aux2);
			else
				ult= aux2;

			ant->ModifAnt(aux);
			if(aux!=NULL)
				aux->ModifSig(ant);
			else
				prim= ant;
		}
		
		
		
	}


	template<class T>
	void LISTA<T>:: invertSubLint(int a, int b)
	{
		NODO<T> *ant, *act, *sig, *aux, *aux2, *bptr;
		bool band;
		int i;

		
		aux= prim;
		band= false;
		


		if ( (ch>1) &&(b>a)&& ((a>0)&&(a<ch)) && ((b>1)&&(b<=ch)) )
		{
			aux	=this->consultarPtr(a);
			if (aux!=NULL)
			{
				band= true;
			}
			
			
			act= aux;
			aux2= aux;
			ant= aux->ObtAnt();
			aux= ant;


			bptr= this->consultarPtr(b);
			//cout<<endl<<"::::::::::break"<<endl;
			i=1;
			while(band)
			{
				if(act==bptr)
				{
					band=false;
			//		cout<<endl<<"::::::::::TRUE"<<endl;
				}
			//	cout<<endl<<"::::::::::"<<i<<"{ "<<endl;
				sig= act->ObtSig();
				act->ModifSig(ant);
				act->ModifAnt(sig);
				ant= act;
				act= sig;
			//	cout<<endl<<"::::::::::"<<i<<" }"<<endl;
				i++;
			}
			

			aux2->ModifSig(act);
			if(act!=NULL)
				act->ModifAnt(aux2);
			else
				ult= aux2;

			
			ant->ModifAnt(aux);
			if(aux!=NULL)
				aux->ModifSig(ant);
			else
				prim= ant;
		}
		
		




	}


	template<class T>
	void LISTA<T>::imprimir() const 
	{
		NODO<T>* aux;
		int i;
		
		if (this->ch> 0)
		{
			i=0;
			aux= prim;
			//cout << "\nlista de ("<<this->longitud()<<") elementos:" << endl;
			while (aux->ObtSig()!=NULL)
			{
				cout<<i<<": {"<<aux->ObtElem()<<"}"<<"\n-\n";
				//cout << "\tposicion " << i<< ":\t"<< this->consultar(i)<< endl;
				aux= aux->ObtSig();
				i++;
			}//cout << "fin de lista, long= "<< this->longitud()<<"\n\n";
			cout<<i<<": {"<<aux->ObtElem()<<"}"<<endl;
		}
		//cout<<endl;
	}
	
	template<class T>
	int LISTA<T>::esSubL(const LISTA &x) const
	{
		NODO<T> *aux, *ptr, *pivot;
		bool esSL, band;
		int pos;
		
		pivot= prim;
		esSL= false;
		pos= 0;
//cout<<endl;

		if((x.ch== 0)||((this->ch)< (x.ch)))//si la lista x, es mas grande que la lista principal
		{
			pos=-1;//automaticamente NO es sublista
		//	cout<<"::::::::pos= -1"<<endl;
		}
		else//sino
		{
			while ((!esSL)&& (pivot!=NULL))
			{
				ptr= x.prim;//pone al ptr en el primer elemento de la lista x
			//	cout<<"::::::::ptr:"<<ptr->ObtElem()<<endl;
				band= false;//asigna falso para indica que aun no ha encontrado el primer elemento de la lista x en la lista principal
				while ((!band) && (pivot!=NULL))
				{
					pos++;
					if(pivot->ObtElem()== ptr->ObtElem())
					{
						band= true;
				//		cout<<"::::::::aux:"<<aux->ObtElem()<<endl;
					}
					else
						pivot=pivot->ObtSig();
				}


				if(band)//si encontro el primer elemento de la lista x en la lista base
				{
					esSL= true;
					
					//si la lista x aun cabe en la lista base
				//	cout<<"::::::::dimension restante"<<((this->ch)-pos)- (x.ch)<<endl;
					if (((this->ch+1)-pos)>= (x.ch))
					{
						aux= pivot;
						//mientras, no sea el final de ninguna de las dos lista
						//y los elementos que se esten comparando sean iguales
					//	cout<<"::::::::while{"<<endl;
						while( (aux!=NULL)&&(ptr!=NULL) && (esSL))
						{
					//		cout<<"::::::::ptr:"<<ptr->ObtElem()<<endl;
					//		cout<<"::::::::aux:"<<aux->ObtElem()<<endl;
							if(aux->ObtElem()== ptr->ObtElem())//si los elementos son iguales
							{
								aux=aux->ObtSig();//compara el sig
								ptr=ptr->ObtSig();//compara el sig
							}
							
							else
							{
								esSL= false;//le dice que no es SubLista
				//				cout<<"::::::::false"<<endl;
							}

						}
				//		cout<<"::::::::}Fwhile"<<aux->ObtElem()<<endl;
					}
					else
					{
						esSL= false;//entonces, no es sublista
				//		cout<<"::::::::false"<<endl;
					}

				}
				else//si no encontro el primer elemento de la lista x en la lista base
				{
					esSL= false;//entonces, no es sublista
				//	cout<<"::::::::false"<<endl;
				}

				if (pivot !=NULL)
					pivot= pivot->ObtSig(); 
			}
			
				
		}
			
		
		if (!esSL)
		{
			pos=-1;
		//	cout<<"::::::::pos= -1"<<endl;
		}

		return pos;//retorna la posicion donde empieza la subLista

	}
	


	template<class T>
	int LISTA<T>::ocurrencia(const LISTA &x) const
	{
		NODO<T> *aux, *ptr, *pivot;
		bool esSL, band;
		int pos, nveces=0;
		
		pivot= prim;
		
		pos= 0;

		if((x.ch== 0)||((this->ch)< (x.ch)))//si la lista x, es mas grande que la lista principal
			pos=-1;//automaticamente NO es sublista
			
		else//sino
		{
			while (pivot!=NULL)
			{
				esSL= false;
				ptr= x.prim;//pone al ptr en el primer elemento de la lista x
				band= false;//asigna falso para indica que aun no ha encontrado el primer elemento de la lista x en la lista principal
				while ((!band) && (pivot!=NULL))
				{
					pos++;
					if(pivot->ObtElem()== ptr->ObtElem())
						band= true;
					else
						pivot=pivot->ObtSig();
				}

				if(band)//si encontro el primer elemento de la lista x en la lista base
				{
					esSL= true;
					//si la lista x aun cabe en la lista base
					if (((this->ch+1)-pos)>= (x.ch))
					{
						aux= pivot;
						//mientras, no sea el final de ninguna de las dos lista
						//y los elementos que se esten comparando sean iguales
						while( (aux!=NULL)&&(ptr!=NULL) && (esSL))
						{
							if(aux->ObtElem()== ptr->ObtElem())//si los elementos son iguales
							{
								aux=aux->ObtSig();//compara el sig
								ptr=ptr->ObtSig();//compara el sig
							}
							else
								esSL= false;//le dice que no es SubLista
						}
					}
					else
						esSL= false;//entonces, no es sublista
				}
				
				///avanza el pivot a la siguiente posicion para seguir buscando mas subListas
				if (pivot !=NULL)
					pivot= pivot->ObtSig(); 
				
				///si encontro alguna SubLista, suma 1
				if (esSL)
					nveces++;
			}
		}
		
		return nveces;//retorna la posicion donde empieza la subLista

	}

	
	template<class T>
	void LISTA<T>::eliminarSL(const LISTA &x)
	{
		int i, n, sl;
		NODO<T>* aux;

		
		sl= this->esSubL(x);
		if (sl>0)
		{
			aux= this->consultarPtr(sl);
			n= x.longitud();
			for(i=1; i<= n; i++)
				this->eliminarPtr(aux);
		}

	}


	template<class T>
	LISTA<T> LISTA<T>:: generarSL(const T& a, const T& b)
	{
		NODO<T>* aux;
		int i, x, y;
		LISTA<T> nvo;
		

		x= this->esta(a);//busca los elementos
		y= this->esta(b);

		if ((x>0) && (y>0)&& (x<=y))//verifica que amos elementos estan en la lista y que el 'a' esta primero que el 'b'
		{
		
			aux= this->prim;
			for (i = 1; i < x; i++)//recorre los nodos hasta el elemento 'a'
				aux= aux->ObtSig();
			
			for (i = 1; i <=((y-x)+1) ; i++)
			{
				nvo.insertar(aux->ObtElem(), i);
				aux= aux->ObtSig();
				//nvo->ModifElem(this->consultar(i))
			}

		}
		return (nvo);
	}

	template<class T>
	LISTA<T> LISTA<T>:: generarSLint(int x, int y)
	{
		NODO<T>* aux;
		int i;
		LISTA<T> nvo;

		if ((x<=ch)&&(x>0) && (y>0)&&(y<=ch)&& (x<=y))//verifica que amos elementos estan en la lista y que el 'a' esta primero que el 'b'
		{
		
			aux= this->prim;
			for (i = 1; i < x; i++)//recorre los nodos hasta el elemento 'a'
				aux= aux->ObtSig();
			
			for (i = 1; i <=((y-x)+1) ; i++)
			{
				nvo.insertar(aux->ObtElem(), i);
				aux= aux->ObtSig();
			}

		}
		return (nvo);
	}

	


	template<class T>
	int LISTA<T>:: estaOrdenada() const
	{	//1- si esta ordenada de forma ascendente, 2- si esta ordenada
		// de forma descendente, 0- si esta desordenada

	
		NODO<T>* ant, aux;
		int orden, op;

		orden= 1;//asume que esta ordenada ascendentemente
		ant= prim;
		aux= ant->ObtSig();
		while ((orden==1)&& (aux!=NULL))
		{
			if( ant->ObtElem()<= aux->ObtElem())
			{
				ant= aux;
				aux= aux->ObtSig();
			}

			else
				orden= 2;//asume que esta ordenada descendentemente
		}

		ant= prim;
		aux= ant->ObtSig();
		while ((orden==2)&& (aux!=NULL))
		{
			if( ant->ObtElem()>= aux->ObtElem())
			{
				ant= aux;
				aux= aux->ObtSig();
			}

			else
				orden= -1;//no esta ordenada
		}

		return (orden);

	}


	template<class T>
	T LISTA<T>::mayorElem() const
	{	
		NODO<T>* aux;
		T mayor;

		if (ch>0)
		{
			aux= prim->ObtSig();
			mayor= prim->ObtElem();
			while (aux!= NULL)
			{
				if (aux->ObtElem()> mayor)
					mayor=aux->ObtElem();
				
				aux= aux->ObtSig();
			}
		}

		return (mayor);
	}


	template<class T>
	T LISTA<T>:: menorElem() const
	{	
		NODO<T>* aux;
		T menor;
		if (ch>0)
		{
			aux= prim->ObtSig();
			menor= prim->ObtElem();
			while (aux!= NULL)
			{
				if (aux->ObtElem()< menor)
					menor=aux->ObtElem();
				
				aux= aux->ObtSig();
			}
		}
		return (menor);
	}



	template<class T>
	int LISTA<T>:: menorPos() const
	{
		int  pos=-1, i;
		NODO<T>* aux;
		T menor;
		
		if (ch>0)
		{
			aux= prim->ObtSig();
			menor= prim->ObtElem();
			pos=1;
			i=2;
			while (aux!= NULL)
			{
				
				if (aux->ObtElem()< menor)
				{
					menor=aux->ObtElem();
					pos=i;
				}
				aux= aux->ObtSig();
				i++;
			}
		}
		return pos;
	}

	template<class T>
	int LISTA<T>:: mayorPos() const
	{
		int  pos=-1, i;
		NODO<T>* aux;
		T mayor;
		
		if (ch>0)
		{
			aux= prim->ObtSig();
			mayor= prim->ObtElem();
			pos=1;
			i=2;
			while (aux!= NULL)
			{
				
				if (aux->ObtElem()> mayor)
				{
					mayor=aux->ObtElem();
					pos=i;
				}
				aux= aux->ObtSig();
				i++;
			}
		}
		return pos;
	}

	template<class T>
	LISTA<T> LISTA<T>:: intersecion(const LISTA &l2)
	{
		NODO<T>* aux2;
		int i;
		LISTA<T> lr;

		aux2= l2->prim;
		i=1;

		while(aux2!= NULL)
		{
			if ((this->esta(aux2->ObtElem())> 0) && (lr->esta(aux2->ObtElem())< 0))
			{
				lr->insertar(aux2->ObtElem(), i);
				
				i++;
			}
			aux2= aux2->ObtSig();
		}

		return (lr);

	}


	template<class T>
	void LISTA<T>:: mezclarL(const LISTA &l1, const LISTA &l2)
	{
		NODO<T> *aux, *aux2;


		this->vaciarL();
		aux2= l2.prim;
		aux=l1.prim;

		while(aux!= NULL)
		{
			this->insertar(aux->ObtElem());
			aux= aux->ObtSig();
		}

		while(aux2!= NULL)
		{
			//if(lr->esta(aux2->ObtElem())< 0){
			this->insertar(aux2->ObtElem());
			aux2= aux2->ObtSig();
			//}
		}

	
		
	}




	template<class T>
	void LISTA<T>:: swap(int a, int b)const
	{
		int i;
		NODO<T> *aux1, *aux2, *auxS, *auxA;

		if ((a!=b)&&(a>0)&&(a<=ch)&&(b>0)&&(b<=ch))
		{
			aux2= this->prim;
			if (a>b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			for (i = 1; i < b; i++)//recorre todos los nodos(confirmado)
			{
				if (i==a)
					aux1=aux2;

				aux2= aux2->ObtSig();
			}

			///nodo1
			if (aux1->ObtAnt()!=NULL)
				aux1->ObtAnt()->ModifSig(aux2);
			if (aux1->ObtSig()!=NULL)
				aux1->ObtSig()->ModifAnt(aux2);
			auxS= aux1->ObtSig();
			auxA= aux1->ObtAnt();	
			aux1->ModifSig(aux2->ObtSig());
			aux1->ModifAnt(aux2->ObtAnt());
			
			///nodo2
			if (aux2->ObtAnt()!=NULL)
				aux2->ObtAnt()->ModifSig(aux1);
			if (aux2->ObtSig()!=NULL)
				aux2->ObtSig()->ModifAnt(aux1);
			aux2->ModifSig(auxS);
			aux2->ModifAnt(auxA);
			
			
		}

	}


	

/////////////////////////////////////////////
///SobreCargas
	template<class T>
	bool LISTA<T>::operator==(const LISTA<T>& l2) const
	{
		NODO<T> *aux1, *aux2;
		bool igual;
		
		aux1= this->prim;
		aux2= l2.prim;
		igual= true;
		
		if (this->ch!= l2.ch)
			igual= false;
		 
		else
		{
			while( (aux1!=NULL)&&(aux2!=NULL) && (igual))//mientras no se acaben los elementos de ambas listas
			{
				if(aux1->ObtElem()== aux2->ObtElem())//si los elementos son iguales
				{
					aux1=aux1->ObtSig();//compara el sig
					aux2=aux2->ObtSig();//compara el sig
				}
				
				else
					igual= false;//le dice que no son iguales
			}
		}

		return igual;
	}


	template<class T>
	bool LISTA<T>::operator!=(const LISTA<T>& l2) const
	{
		NODO<T> *aux1, *aux2;
		bool igual;
		
		aux1= this->prim;
		aux2= l2.prim;
		igual= true;
		
		if (this->ch!= l2.ch)
			igual= false;
		 
		else
		{
			while( (aux1!=NULL)&&(aux2!=NULL) && (igual))//mientras no se acaben los elementos de ambas listas
			{
				if(aux1->ObtElem()== aux2->ObtElem())//si los elementos son iguales
				{
					aux1=aux1->ObtSig();//compara el sig
					aux2=aux2->ObtSig();//compara el sig
				}
				
				else
					igual= false;//le dice que no son iguales
			}
		}

		return (!igual);
	}


	template<class T>
	LISTA<T> LISTA<T>::operator+(const LISTA<T>& l2) const
	{
		NODO<T> *aux, *aux2;
		LISTA<T> lr;

		aux2= l2.prim;
		aux=this->prim;
		while(aux!= NULL)
		{
			lr.insertar(aux->ObtElem(), lr.ch+1);
			aux= aux->ObtSig();
		}
		while(aux2!= NULL)
		{
			lr.insertar(aux2->ObtElem(), lr.ch+1);
			aux2= aux2->ObtSig();
		}

		return lr;
	}


	template<class T>
	LISTA<T> LISTA<T>::operator-(const LISTA<T>& l2) const
	{
		/** retona una lista con todos los elementos de la lista original, menos, los elementos
		 *	de l2 que esten en esa lista original*/
		NODO<T> *w, *v;
		LISTA<T> lr;

		lr= *this;
		v= lr.prim;
		w= l2.prim;

		while (w != NULL)//mientras el primer pivot no llegue al final
		{

			if (v==NULL)//si el segundo pivot llega al final, entonces...
			{
				w= w->ObtSig();//el primer pivot se mueve al siguiente
				if (w!=NULL)//y si aun el primer pivot no ha llegado al final, entocnes
					v=lr.prim;//reseteo el segundo pivot
			}
			///evaluo
			if (((v!=NULL) && (w!=NULL))&&(w->ObtElem()== v->ObtElem()))//si encontro el elemnto de l2 en lr
				lr.eliminarPtr(v);//se elimina
			
			///fin de la evaluacion
			if (v!=NULL)//si el segundo pivot no ha llegado al final, entonces
				v= v->ObtSig();//se mueve el segundo pivot a la sig posicion
		}
		return lr;
	}


	template<class T>
	void LISTA<T>::operator=(const LISTA<T>& l2)
	{
		///- cout<<"sobrecarga(= ... <<lista>>)/";
		NODO<T> *aux;
		//cout<<endl<<"sobrecargaAsignacion('=')/";

		//cout<<"vaciarListaMadre()/";
		this->vaciarL();
		//cout<<"ListaMAdraVacia/";
		aux= l2.prim;
		//cout<<"LlenarListaMadre/";
		while(aux!= NULL)
		{
			this->insertar(aux->ObtElem(), this->ch+1);
			aux= aux->ObtSig();
		}
		//cout<<"ListaMadreLLena/";
		//cout<<"--SucessFull"<<endl;
		///- cout<<"FsobreCarga/";
	}


//////////////////////////////////////////////
///privados
	template<class T>
	void LISTA<T>::insertarPtr(NODO<T> *ptr, const T& e)//el ptr debe quedar alante del elemento que se va a insertar
	{
		///cout<<"estoy escribiendo desde el insertar ptr, 'inicio'"<<endl;
		NODO<T> *nvo, *ant;
		
		nvo= new NODO<T>;//crea o reserva la memoria para el nodo nvo
		nvo->ModifElem(e);//le asigna el elemento al nvo nodo

		///cout<<"estoy escribiendo desde el insertar ptr, 'antesala a los casos'"<<endl;
 /*caso1*/	if(this->prim== NULL)//si es el unico elemento
			{
				nvo->ModifSig(NULL);//coloca el nvo nodo apuntando a NULL
				nvo->ModifAnt(NULL);//y como no tiene un nodo anterior, se le coloca apuntando a NULL
				prim= nvo;//luego, coloca al apuntador prim a apuntar al nvo nodo
				ult= nvo;
			}
					
 /*caso2*/	else if(ptr== NULL)//si es la ultima posicion
			{
				///cout<<"estoy escribiendo desde el insertar ptr, 'caso3'"<<endl;
				nvo->ModifSig(NULL);//como no tiene un nodo proximo, se le coloca apuntando a NULL
				nvo->ModifAnt(ult);//coloca el nvo nodo apuntando al que era el ultimo elemento
				ult->ModifSig(nvo);//luego, coloca al apuntador de elq era el ultimo elemento a apuntar al nvo nodo
				ult=nvo; 
			}

 /*caso3*/	else if (ptr->ObtAnt()==NULL)//si es la primera posicion
			{
				nvo->ModifSig(ptr);//coloca el nvo nodo apuntando al primer elemento
				nvo->ModifAnt(NULL);//y como no tiene un nodo anterior, se le coloca apuntando a NULL
				ptr->ModifAnt(nvo);
				prim= nvo;//luego, coloca al apuntador prim a apuntar al nvo nodo
			}
			
 /*caso4*/	else// sino, si es una posicion intermedia
			{
					ant= ptr->ObtAnt();
					ptr->ModifAnt(nvo);
					nvo->ModifSig(ptr);//ahora nvo apunta al siguien del anterior
					nvo->ModifAnt(ant);//ahora, coloca al nvo nodo a apuntar a su anterior (ant)
					ant->ModifSig(nvo);
			}

			//succes_full
			ch++;//aunmenta la cantidad de elementos		
	}


	template <class T>
	void LISTA<T>:: eliminarPtr(NODO<T>* ptr)
	{
		NODO<T> *enl;
		
		if (ptr!=NULL)
		{
			//se elimina
				if((ptr->ObtSig()==NULL) && (ptr->ObtAnt()==NULL))//si queda un solo elemento
				{
					delete (ptr);
					prim= NULL;
					ult= NULL;
				}
				
				else if (ptr->ObtAnt()==NULL)//si es el primer elemento
				{
					enl= ptr->ObtSig();
					delete (ptr);
					prim= enl;
					prim->ModifAnt(NULL);	
				}

				else if(ptr->ObtSig()==NULL)//si es el ultimo elemento
				{
					enl= ptr->ObtAnt();
					delete (ptr);
					ult= enl;
					ult->ModifSig(NULL);
				}

				else//si es un elemento intermedio
				{
					enl=ptr->ObtAnt();

					enl->ModifSig(ptr->ObtSig());
					ptr->ObtSig()->ModifAnt(enl);
					delete(ptr);
				}
				ch--;
		}
	}



	template <class T>
	NODO<T>* LISTA<T>:: estaPtr(const T& e) const
	{
		NODO<T>* aux;
		
		aux= prim;
		while ((aux!= NULL) && (aux->ObtElem()!= e))
			aux= aux->ObtSig();

		return (aux);
	}



	template<class T>
	NODO<T>* LISTA<T>::consultarPtr(int pos) const
	{
		int i;
		NODO<T>* aux=NULL;

		if ((pos>0)&&(pos<= this->ch))
		{
			aux= prim;
			for (i = 1; i < pos; i++)//recorre todos los nodos(confirmado)
				aux= aux->ObtSig();
		}
		return (aux);
	}



/////////////////////////////////////////////
///asignaciones para lab
	template<class T>
	void LISTA<T>:: mayorElem(T *mayor,int *n)
	{
		NODO<T>* aux;
		
		aux= prim;
		
		mayoRecursivo(aux , mayor, n);
		
		
	}


	template<class T>
	void LISTA<T>:: mayoRecursivo(NODO<T>* aux,T *e, int *n)
	{
		if (aux->ObtSig()== NULL)
		{
			(*e)= aux->ObtElem();
			(*n)= 1;
		}
		else
		{
			mayoRecursivo(aux->ObtSig(), e, n);
			if ((aux->ObtElem())>(*e))
			{
				*e=aux->ObtElem();
				(*n)= 1;
			}
			else if (aux->ObtElem()==(*e))
			{
				(*n)++;
			}
			
			
		}

	}
	


	template<class T>
	void LISTA<T>:: mezclarL2(const LISTA &l1, const LISTA &l2)
	{
		NODO<T> *aux, *aux2;

///		*esto es con listas ordenadas. la primera en orden ascendente,
///		la segunda en orden descendente
		this->vaciarL();
		aux=l1.prim;
		aux2= l2.ult;

		/*l1->imprimir();
		l2->imprimir();*/
		
		while( ((aux!= NULL) || (aux2!= NULL)) )
		{
			if (aux== NULL)//si se acabaron los elementos de la primera lista
			{
				this->insertar(aux2->ObtElem(), this->longitud()+1);
				aux2= aux2->ObtAnt();
			}
			else if (aux2== NULL)//si se acabaron los elementos de la segunda lista
			{
				this->insertar(aux->ObtElem(), this->longitud()+1);
				aux= aux->ObtSig();
			}
			else//si aun quedan elementos en ambas listas
			{
				if (aux->ObtElem()<= aux2->ObtElem())//si el elemento de la lista1 es menor o igual al de la lista2
				{
					this->insertar(aux->ObtElem(), this->longitud()+1);//inserta el elemento de la lista1
					aux= aux->ObtSig();//y avanza el pivot de la lista 1 al siguiente
				}
				else//si el elemento de la lista 2 es menor que el de la lista1
				{
					this->insertar(aux2->ObtElem(), this->longitud()+1);//inserta el elemento de la lista 2
					aux2= aux2->ObtAnt();//y avanza el pivoy de la lista2 al anterior
				}
			}
		}
	}



	template<class T>
	void LISTA<T>:: ordenar()
	{
		this->QuickSort(1, this->longitud());
	}


	template<class T>
	void LISTA<T>:: QuickSort(int izq, int der)//izq debe recibir la primera posicion, der la ultima
	{
		NODO<T> *ei, *ej, *eaux;
		int i,j,aux,pivote;
		i=izq;
		j=der;
		aux=(izq+der)/2;
		pivote= this->consultar(aux);

		eaux= new NODO<T>;//crea o reserva la memoria para el nodo nvo

		ei= this->consultarPtr(i);
		ej= this->consultarPtr(j);
			do{
				while(ei->ObtElem() < pivote)
				{
					if (ei != NULL)
					{
						i++;
						ei= ei->ObtSig();
					}
				}	
					while(ej->ObtElem() > pivote)
					{
						if (ej != NULL)
						{
							j--;
							ej= ej->ObtAnt();
						}
					}
						if(i <= j)
						{
							eaux->ModifElem(ei->ObtElem());
							ei->ModifElem(ej->ObtElem());
							ej->ModifElem(eaux->ObtElem());
							i++;
							j--;
						}
			}while(i <= j);
			
			if(izq < j)
				this->QuickSort(izq,j);
			if(i < der)
				this->QuickSort(i,der);
	}///Fproc***
	


#endif /*LISTA_H_*/
			
