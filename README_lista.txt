*los "const" son muy importante, no les voy a explicar mucho de como funciona
el const porque los puedo enredar, pero basicamente es algo asi, cualquier metodo o atributo
que sean invocados o pasados como const NO PODRAN SER MODIFICADOS, los metodos que tienen
const al final de su cabecera, no podran modificar a quien los esta invocando

*para pasar parametros por referencia; lo pueden hacer como siempre (en la invocacion
ponen &, y en la cabecera del que recibe ponen *), pero tambien lo pueden hacer usando
solo & en la cabecera del que recibe, si ven los metodos de las clases, en muchos de
ellos antes de algunas variables va un &, eso quiere decir que esa variable va por
referencia (no se si se podia hacer asi en C), la ventaja de esto esq no tienes que estar
poniendo & cuando invocas y * cuando recibes, solo con poner & al recibir (en la cabecera)
es suficiente, ademas, cuando usas una variable por referencia de este modo, no es necesario
estar poniendo * cada vez que la usas dentro del metodo, ejemplo.
-esto:
int main()
{
	int a;
	sub(&a);//invocacion por referencia
	...
	return 0;
}
void sub(int *a)//recibe por referencia
{
	int x;
	cin>> x;
	*a=x;//deben indicar que 'a' esta por referencia
	...
}

-es igual a esto:
int main()
{
	int a;
	sub(a);//sin necesidad de invocar por referencia
	...
	return 0;
}
void sub(int &a)//recibe por referencia
{
	int x;
	cin>> x;
	a=x;//no es necesario indicar que 'a' esta por referencia
	...
}


*operador ternario:
en eld desarrollo de als clases (especialmente de la clase arbolbinario) van a encontrar cosas asi:
(algo)?algo:algo;
esto es un operador ternario, que en realidad funciona asi:
(condicion)?retorno1 : retorno2;
-si se cumple la condicion : "(condicion)?"
-retorna esto: "retorno1"
-sino : ":"
-retorno eso: "retorno2"
es una forma de hacer un si, sino, en una sola linea :D
///////////////////////////////////////////////////
clase Lista:
*la posiciones las trabajo desde 1, es decir si hay un elemento, entonces la cantidad
sera 1 NO 0.
*esta doblemente enlazada y la pueden trabajar con iteradores o con indices..
osea, pueden usar metodos que trabajan de forma directa con los nodos de las litas
(iteradores) asi como en la clase list (list es la clase "lista" definida por c++)
los metodos que usan iteradores son:
	void eliminarPtr(NODO<T>* ptr);	
	NODO<T>* estaPtr(const T& e) const;
	NODO<T>* consultarPtr(int pos) const;
	NODO<T>* first()const {return prim;}
	NODO<T>* last()const {return ult;}
	void insertarPtr(NODO<T>* ptr, const T& e);
osea el chiste esq en vez de usar un numero o un "elemento" para acceder a alguna
posicion de la lista mejor se usan los apuntadores directos a esa posicion de la lista

NODO<T>* first()const {return prim;}
- retorna un apuntador al primer elemento de la lista, si no hay elemento retrna NULL

NODO<T>* last()const {return ult;}
- retorna un apuntador al ultimo elemento de la lista, si no hay elemento retrna NULL

void insertarPtr(NODO<T>* ptr, const T& e);
- igual que el insertar tipico que siempre usan, pero ahora le van a mandar es un
apuntador, el apuntador debe estar apuntando a la posicion en donde quieren insertar
ejemplo:
tienen: [a][k][m][p]; y quieren insertar [w] en la posicion 3, entonces mandan 'w'
(como elemento), y un apuntador a [m] ([m] en ese momento seria el de la posicion 3)
la lista va a quedar asi [a][k][w][m][p].
si quieren insertar en la ultima posicion mandan un apuntador a NULL

void eliminarPtr(NODO<T>* ptr);	
- sencillo, elimina al elemento al que se esta apuntando, ejemplo:
[a][k][w][m][p]; si envian un apuntador a [w], entonces la lista quedaria asi:
[a][k][w][p].

NODO<T>* consultarPtr(int pos) const;
- aqui si le mandan un entero, pero ahora les va a retornar un apuntador al nodo de esa
posicion, si es una posicion invalidad va a retornar NULL, ejemplo:
[a][k][w][p]; si mandan como entero un 3, va a retornar un apuntadores al nodo [w]
ojo, ES UN APUNTADOR AL NODO, no una copia del nodo, ni una copia del elemento, es decir,
si modifican loq esta adentro de ese apuntador, entonces modificaran directamente el
elemento de la lista original, cuidado con eso.

NODO<T>* estaPtr(const T& e) const;
-funciona parecido al anterior, pero ahora va a recibir es un elemento, lo buscara y
retornara un apuntador al nodo en donde esta el elemento, ejemplo:
[a][k][w][p], si mandan p, entonces devolvera un apuntador al nodo [p], si envian un
elemento que no esta, ejmplo, 'q', entonces retornara NULL, si el elemento que mandan
a buscar esta repetido, retornara el primer elemento que encuentre (que cumpla la igualdad
claro), ejmeplo:
[a][k][w][j][k][p]; si se manda a buscar 'k', el metodo retornara un apuntar al nodo[k],
pero el nodo [k] alq estara apuntando sera al primero que se encuentra en la lista, es
decir, al de la posicion 2
...

bueno, ya ahi terminan los metodos con iteradores(les digo asi porque asi los tratan
en la libreria "list"), la cosa con los iteradores es un pelin delicada, asi que tengan
cuidado, porque cuando tienen iteradores estan accediendo DIRECTAMENTE A LA CLASE, osea 
a la lista, si usan un iterador que este apuntando algun nodo de la lista, y luego
deciden hacer alguna modificacion, esa modificacion se va a hacer tambien en la lista
orginal, un ejemplo sencillo:
si tienen [a][k][w][p], y tienen un apuntador ptr apuntando al nodo [k] y modifican el
contenido de ese nodo [k], asi, ptr->modifElement('r');
entonces el apuntador ptr estara apuntando al mismo nodo, solo que ahora este nodo tendra
adentro una 'r', osea asi, [r]. ademas, la lista original quedara asi: [a][r][w][p]

AHORA, los metodos que usan indices:
*TODO EL RESTO DE LA CLASE* xD
hay metodos muy basicos asi que solo explicare los mas "confusos", entonces:

void insertar(const T& e, int pos);
void insertar(const T& e);
-vean que ambos se llaman exactamente igual, eso se puede hacer en c++ (creo que a eso
se le dice polimorfismo), siempre y cuando los parametros sean diferentes, vean que en
el primer insertar hay dos parametro, en el segundo hay solo uno. en mis listas, el que
tiene un solo parametro hace un insertar ordenado, por eso no necesita la posicion, el
otro insertar (el de dos parametros) si es el insertar comun y corriente que conocemos

-OJO, para usar el insertar de un solo parametro se debe estar seguro que el elemento con
que se esta trabajando tiene la sobrecarga de >, sino les dara error cuando corran el
programa

void invertirL();
-invierte una lista entera, es de orden N

void invertirSubL(const T& a, const T& b);
-dado dos elementos a, b, se va a invertir la sublista que este en el rango de [a,b],
si la posicion de a es mayor o igual a la posicion de b (pos(a)>=pos(b)), la lista queda
igual, si a o b no existen el metodo hace nada (la lista queda igual)
-OJO, si en la lista hay elementos repetidos, esta trabajara con el primer elemento que
encuentre, ejemplo
[5][8][7][4][8][5][1]; si se pasan a=7 y b=8, el metodo hara nada, y la lista quedara
igual, esto pasa porque el metodo va a encontrar que el "a" esta en la posicion 3, pero
el "b" lo encontrar en la posicion 2(NO en la posicion 5), entonces a>=b, por lo tanto,
no cumplen la PreCondicion (funciona como una pre condicion)

void invertSubLint(int a, int b);
-funciona igual que el invertir anterior, pero esta vez no recibe elementos, sino posiciones
por lo tanto es mas especifico.

int esSubL(const LISTA<T> &x)const;
-se pasa una lista y si es subLista de la lista original, entonces retorna la posicion
donde comienza esa subLista, si no es subLista entonces retorna -1, una lista vacia NO
ES CONSIDERADA UNA SUBLISTA(segun yo) xD

int ocurrencia(const LISTA &x) const;
-recibe una lista e indica cuantas veces aparece esta como SubLista en la lista original.

LISTA<T> generarSL(const T& a, const T& b);
LISTA<T> generarSLint(int x, int y);
-basicamente funcionan como los invertirSubListas, las mismas condiciones para cuando
los parametros son elementos (generarSL), pero ahora si a=b, entonces retorna una subLista
con un unico elemento (ya que a y b son iguales retorna una lista con ese elemento)
-si los parametros son enteros (generarSLint), entonces es mas sencillo aun, solo genera
una lista en el rango [x,y] que se ha pasado

int estaOrdenada() const;
-retorna 1 si esta ordenada ascendentemente, 2 si esta ordenada descendentemente, -1 si
no esta ordenada

T menorElem() const;
T mayorElem() const;
-retornan el menor y mayor elemento de la lista, respectivamente
int menorPos() const;
int mayorPos() const;
-retornan la posicion del menor y mayor elemento de la lista, respectivamente.
si el elemento (menor o mayor) se repite, entonces retorna la posicion del primer mayor
o menor que encuentre

void mayorElem(T *mayor,int *n);
-se le pasa una variable tipo "T" por referencia para que guarde el mayor elemento de la
lista, y una variable tipo int, tambien por referencia, donde se guaradara las veces que
encuentre el elemento mayor, este metodo en realidad solo recibe las variables e invoca a
un metodo estatico(este es el que hace todo, el metodo recursivo):
(*) static void mayoRecursivo(NODO<T>* aux,T *e, int *n);
-el estatico recibe un apuntador a un nodo de la lista que se va moviendo al siguiente en
cada llamada recursiva, y dos atributos por referencia, en el tipo "T" se guardara el 
elemento, en el entero se guardara cuantas veces aparece (los mismos dos parametros que
se habian rebido antes en "void mayorElem(T *mayor,int *n)" )

LISTA<T> intersecion(const LISTA &l2);
-retorna una lista, resultante de la interseccion entre la lista original y l2

void mezclarL(const LISTA<T> &l1, const LISTA<T> &l2);
-La lista orginal queda con los elementos de ambas listas (l1, l2) ordenados

void mezclarL2(const LISTA<T> &l1, const LISTA<T> &l2);
-funciona igual que el mezclarL, pero esta es con listas ordenadas. la primera en orden
ascendente, la segunda en orden descendente

void swap(int i1, int i2)const;
-recibe dos enteros i1, i2. Intercambia el elemento de la posicion i1, con el de i2.

void ordenar();
-Ordena la lista con quicksort B-)

*ademas, estan TODAS las sobrecargas de operadores para lista:
OPERADOR: ==
OPERADOR: !=
OPERADOR: +
OPERADOR: - //retona una lista con todos los elementos de la lista original, menos, los elementos de la lista que esta restando, que esten en esa lista original
OPERADOR: =
OPERADOR: >>
OPERADOR: <<

*tambien tiene su respectivo constructor y destructor, y el constructor copia

///////////////////////////////////////////////////
clase pila y cola
*estan muy basicas, lo unico fuera de lo normal seria que para usar pila hay que incluir
la libreria de cola y viceversa, explico el por que:
en la clase pila hay un metodo llamado:
void ajustarCola(const COLA<T> &c);
-este metodo recibe una cola y transforma una copia(de esa cola) en una pila (la cola queda
intacta), la pila resultante se guarda en la pila que por defecto invoca al metodo

en la clase cola hay un metodo llamado:
void ajustarPila(const PILA<T> &c);
-este metodo recibe una pila y transforma una copia(de esa pila) en una cola (la pila queda
intacta), la cola resultante se guarda en la cola que por defecto invoca al metodo

ahora, como podran ver, la estructura se comporta de manera recursiva (recursion indirecta)
la estructura A necesita a la estructura B y la B a su vez necesita a la estructura A.

por eso es que se tiene que incluir la libreria de cola en la clase pila y viceversa, ademas,
luego de incluirlas, justo despues del "using namespace", ven algo asi en la clase pila:
template <class T>
class COLA;
y algo asi en la clase cola:
template <class T>
class PILA;

no les voy a explicar mucho esto porque es enredado, el chiste es que si borran eso les da error!.
ahora, si quieren trabajar con pilas y colas SIN DEPENDER UNA DE LA OTRA (sin que las estructuras
sean recursiva) deberan comentar en la clase cola:
1) #include "pila"
2) template <class T>
class PILA;

3) void ajustarPila(const PILA<T> &p);
 y su desarrollo claro

y en la clase pila:
1) #include "cola"
2) template <class T>
class COLA;

3) void ajustarCola(const COLA<T> &c);
 y su desarrollo claro

los metodos:
NODO<T>* ptrprim() const {return prim;}
NODO<T>* ptrult() const {return ult;}
-funcionan como el first() y last() de la clase lista (solo retornan un apuntador al primer y ultimo
nodo, respectivamente)

*en pila siempre apilo en el comienzo, entonces cuando hago el tope retorna el primer elemento de la
pila(creo que mejor es apilando al final y el tope haciendolo al final tambien), no se por que lo hice
asi, bueh igual da!

*el resto esta muy sencillo , tiene sus sobre cargas y los constructores copias y destructores, no tienen
la sobrecarga de la resta (-) porque me dio ladilla hacerla


////////////////////////////////////////////////
arboles Binarios :G
clase Arbol Bianrio:
*primero, TODOS o casi todos los metodos usan un metodo estatico, ch indica la cantidad
de nodos que tiene el arbol, funcionan con MI clase lista(creo que tambien hay que tener
mi clase pila)
*tiene un coñazo de metodos, muy basicos todos.
les dire como funcionan los que creo que pueden no entender muy bien.

int peso()const
-retorna el peso del arbol, pero tambien existe un metodo:
int pesarArbol()const
-calcula el peso del arbol, es lo mismo, solo que el de arriba retorna de una vez el peso,
en cambio este lo va calculando nodo a nodo

LISTA<T> getHojas()const ;
-retorna una lista con las hojas del arbol (MI CLASE LISTA)

NodoB<T>* localizar(const T &e)const
-retorna un apuntador al nodo donde esta el elemento (funciona asi como los iteradores
de la clase lista), si no encontro el nodo retorna NULL

NodoB<T>* hermanos(const T &e1, const T &e2)const
-recibe dos elementos, si son hermanos entonces retorna un apuntador al nodo del padre
de esos dos elemento, si no son hermanos retorna null

los metodos:
isomorfos, semejantes, ocurrencia:
-funcionan bien, el concepto esta en la guia del entorno, igual creo que se los dan en
clase

LISTA<T> getCaminoNodos(const T &e1, const T &e2)const;
-retorna una lista (DE MI CLASE LISTA) con los nodos que forman el camino entre e1 y e2
para esto, e2 debe ser hijo(nieto, tatara nieto, pues tiene que esta por debajo) de e1

int diametro() const ;
-este concepto no se si esta en la guia del entorno, el diametro de un arbol es la mayor
distancia que puede existit entre par de nodos cualquiera pertenecientes al mismo arbol

NodoB<T>* padre(const T &e)const
-recibe un elemento y retorna el apuntador al nodo de su padre, si no existe o no tiene
padre, retorna null

NodoB<T>* getHermano(const T &e)const
-recibe un elemento y retorna el apuntador al nodo de su hermano, si no existe o no tiene
hermano, retorna null

void niveles()const;
-muestra el recorrido por niveles, pero el mio es ineficiente xD

void insertarSubArbolBin(const ArbolBin<T> &arbol);
-esto es lo mas inutil que he hecho!, este no lo consideren!
si quieren modifiquenlo y haganlo de otra forma xD
este lo unico que hace es recibir un arbol y si alguno de los hijos de la raiz esta null,
entonces lo inserta alli(en el hijo que esta vacio pues), si no estan en null ninguno de
los dos hijos, entonces hace nada

*tiene sobrecarga de asignacion y comparacion que son las que necesitaran

/////////////////////////////////////////
clase nodo binario:
*es la clase nodo comun y silvestre, pero le agg unos metodos pa facilitar la clase arbol

bool nodoHoja()const
-si no tiene ni hijo izquierdo ni hijo derecho, retorna verdad, sino falso

bool fullNode()const
-si tiene ambos hijos retonar verdad, sino(si le falta almenos un hijo) retorna falso

int	grade()const
-retorna la cantidad de hijos del nodo (grado)

bool adn(const T &e1, const T &e2)const
-retorna verdad si e1 y e2 son hijos del nodo origen(el que invoca el metodo)

int EsPadre(const T &e) const 
-retorna 1 si el elemento e esta en el hijo izq del nodo, 2 si esta en el hijo derecho
y 0 si no esta
