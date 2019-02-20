#ifndef NODO_H_
#define NODO_H_

#include <iostream>


template <class T>
class NODO
{
private:
	T info;
	NODO<T> *prox;
	NODO<T> *ant;
public:
	//constructores
	NODO<T>():prox(NULL), ant(NULL){};
	///NODO<T>(const T &e);
	NODO<T>(const NODO<T> &n): info(n.info), prox(n.prox), ant(n.ant){};
	NODO<T>(const T &e, NODO<T> *sig, NODO<T> *atras ): info(e), prox(sig), ant(atras){};

	//consultores
	T ObtElem() const {return info;};
	T* getPtr() {return &info;}
	NODO<T>* ObtSig(){return prox;};
	NODO<T>* ObtAnt(){return ant;};
	
	//modificadores
	void setPtr(T* i){info= *i;}
	void ModifElem(const T &e){info=e;};
	void ModifSig(NODO<T>* sig){prox=sig;};
	void ModifAnt(NODO<T>* atras){ant=atras;};
};

#endif /*NODO_H_*/
