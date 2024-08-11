#ifndef HEX_H
#define HEX_H
#define BIN_BUFFER 10000

#include "args.h"

void conv_hex(char *value, base_t base);
int hex_dec(char *value);
char *hex_bin(char *value);

#endif // !HEX_H
