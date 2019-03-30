#define SEPARATEUR " \n\r\a\t"
#define SIZE_CMD 200


void init_cimp();
void prompt();
char **split_line(char *);
int execArgs(char *[]);
int exec_cmd(char *[]);
int args_length(char *[]);