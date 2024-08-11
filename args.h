#ifndef ARGS_H
#define ARGS_H

typedef enum BASES { Bin, Hex, Dec } base_t;

void usage(void);
void check_args(int argc, char **argv);
void parse_args(int argc, char **argv);
base_t parse_base(char *argv);

#endif // !ARGS_H
