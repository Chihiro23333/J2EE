
typedef struct exercise{
	float duration;
	const char *desc;
} exercise;

typedef union{
	int count;
	float weight;
} amount;

typedef struct fish{
	char *name;
	char *species;
	int teeth;
	int age;
	exercise exerc;
	amount num;
} fish;




void printfish(fish f);

void printfishbowl(fish f);

void happybirthday(fish *f);

void printnum(fish *f);