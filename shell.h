#ifndef SHELL_H
#define SHELL_H
/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/wait.h>
#include <signal.h>
/* Macros */
#define BUFFER_SIZE 5024
#define MAX_ARGS 1024
#define MAX_NUM_Aliases 100
#define UNUSED  __attribute__((unused))
static char *cmd __attribute__((unused));
extern char **environ UNUSED;
extern int ex_code;
/* Function Prototypes */
int main(void);
char *read_command(void);
void hash_handler(char *buff);
int _c_strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
int _strncpy(char *dest, char *src, int size);
void *_memcpy(void *dest, const void *src, size_t n);
void *_realloc(void *ptr, size_t size);
char *findExecutablePath(char *command);
char *_strtok(char *str, char const *delim);
char *_getenv(char *str);
int _strncmp(const char *str1, const char *str2, size_t len);
int _strcpy(char *dest, char *src);
char *_strchr(const char *str, int character);
char *_strdup(const char *s);
void trim_spaces(char *str);
void tokenize_string(char *input, char *tokens[MAX_TOKENS]);
int count_arguments(char *args[]);
void _exec(char **_argum, char *av, int count);
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag);
int _atoi(const char *str);
int cd(const char *path);
int process_command(char **argv);
/**
* struct Node - singly linked list
* @str: string - (malloc'ed string)
* @next: points to the next node
*/
struct Node
{
	char *str;
	struct Node *next;
};

static struct Node *new_node(char *str) UNUSED;
/**
 * new_node - Creates a new node for a linked list
 * @str: String value to be stored in the new node
 * Return: Pointer to the newly created node
 */
static struct Node *new_node(char *str)
{
	struct Node *node = malloc(sizeof(struct Node));
if (node == NULL)
return (NULL);
node->str = str;
node->next = NULL;
return (node);
}
static void add_node(struct Node **head, struct Node *node) UNUSED;
/**
 * add_node - Adds a node to the end of a linked list
 * @head: Pointer to the head of the linked list
 * @node: Node to be added to the linked list
 */
static void add_node(struct Node **head, struct Node *node)
{
if (*head == NULL)
*head = node;
else
{
struct Node *current = *head;
while (current->next != NULL)
current = current->next;
current->next = node;
}
}
void display_list(struct Node *current);
void release_memory(struct Node *start);
int show_environment(void);
int set_environment_variable(const char *var_name, const char *var_value);
int unset_environment_variable(const char *target_name);
int populate_env_list(info_t *info);
void add_env_var(struct Node **head, const char *name, const char *value);
void update_environ(struct Node *head);
void handle_segmentation_fault(int signo __attribute__((unused)));
void remwspaces(char *s);
int wspace(char s);
/**
 * struct alias_s - a structure representing an alias
 * @name: the name of the alias
 * @value: the value of the alias
 * @next: a pointer to the next alias in the linked list
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;
void init_aliases(alias_t **aliases);
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)));
char *_strchr(const char *str, int character);
void print_alias(alias_t *alias);
void set_alias(alias_t **aliases, char *name, char *value);
void print_all_aliases(alias_t *aliases);
void displayAllAliases(alias_t *aliases);
void _perror(char *err, int count, char *c);
void _print(char *s);
void _pnumber(int n);
int _putchar(char c);
int access_check(char **arg, char *cmd, char *err, int c, char **e);
void _perrore(char *err, int count, char *c, char *arg);
#endif /* SHELL_H */
