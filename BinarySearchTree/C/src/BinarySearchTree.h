typedef struct node
{
	void *item;
	struct node *parent;
	struct node *left;
	struct node *right;	
}node;

typedef struct tree
{
	struct node *root;
	void(*printItem)(void *);
	int(*compare)(void *, void *);
}tree;

void add(tree *, void *, int);