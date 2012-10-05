typedef struct
{
	void *item;
	struct node *next;
}node;

node *create(void *, int);
int size(node *);
void add(node *, void *, int);
void printList(node *);
