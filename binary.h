#ifndef BINARY_H

#define BUFFER 120
#define BINARY_H

#include "args.h"

void conv_bin(char *value, base_t base);
char *bin_hex(char *value);
int bin_dec(char *value);
int add_zeros(char *from, char *to, int length);
char bin_to_hex_digit(char *nibble);

#endif // !BINARY_H
