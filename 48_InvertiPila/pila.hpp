#ifndef PILA_HPP
#define PILA_HPP
 
struct nodo {
    int value;
    nodo* next;
};
typedef nodo* lista;
 
void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();
 
#endif
