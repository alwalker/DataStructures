typedef struct
{
	void *item;
	struct node *next;
}node;

node *create(void *);
int size(node *);
void add(node *, void *);
void printList(node *);
