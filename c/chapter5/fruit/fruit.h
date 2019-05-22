

typedef enum{
	COUNT, POUNDS, PINTS
} unit_of_measure;

typedef union{
	short count;
	float weight;
	float volume;
} quantity;

typedef struct {
	const char *name;
	const char *country;
	quantity amount;
	unit_of_measure units;
} fruit;

void display(fruit f);