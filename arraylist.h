#ifndef ArrayList_h
#define ArrayList_h

typedef struct ArrayList ArrayList;

ArrayList *createList(void);

void append(ArrayList * l, void * data);
void push(ArrayList * l, void * data, int i);
void* pop(ArrayList * l, int i);
void* get(ArrayList * l, int i);
int get_size(ArrayList * l);
void clean(ArrayList * list);

#endif /* List_h */