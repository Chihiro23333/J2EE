
enum response_type{DUMP, SECOND_CHANGE, MARRIED};

typedef struct response{
	char *name;
	enum response_type type;
} response;

void sayDump(response r);
void saySecondChange(response r);
void sayMarried(response r);