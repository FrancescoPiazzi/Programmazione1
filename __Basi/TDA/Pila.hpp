#ifndef PILA_H
#define PILA_H

struct nodoPila {
	int value;
	nodoPila* next;
};
typedef nodoPila* listaPila;

void init();
bool push(int);
bool top(int &);
bool pop();
void deinit();
void print();

#endif
