#define SEPARATEUR " \n\r\a\t"
#define SIZE_CMD 200
#define MAX_WIN 100


void init_cimp();
void cimp();
char **split_line(char *);
int args_length(char *[]);
int parse();
