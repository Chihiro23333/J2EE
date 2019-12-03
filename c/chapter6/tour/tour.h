typedef struct island{
	char *name;
	char *open;
	char *close;
	struct island *next;
}island;

void display(island *start);

island* createIsland(char *name);
	