typedef struct node
{
	void *item;
	struct node *next;
}node;

typedef struct linkedList
{
	struct node *head;
	int size;
	void(*printItem)(void *);
	int(*compare)(void *, void *);
}linkedList;

linkedList *create(void *, int, void(*)(void *), int(*)(void *, void *));
void add(linkedList *, void *, int);
void printList(linkedList *);
void removeItem(linkedList *, void *);
void *get(linkedList *, int);
int indexOf(linkedList *, void *);
