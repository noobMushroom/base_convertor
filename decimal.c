#include "decimal.h"
#include "args.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void conv_dec(char *value, base_t base) {
  int result;
  if (base == Hex) {
    result = dec_hex(value);
    printf("Decimal: %s\nHex: %d\n", value, result);
  } else if (base == Bin) {
    result = dec_bin(value);
    printf("Decimal: %s\nBin: %d\n", value, result);
  }
}

int dec_hex(char *value) {
  int base, num, i;
  num = atoi(value);
  i = base = 0;

  while (num) {
    base += (num % 16) * pow(10, i++);
    num /= 16;
  }

  return base;
}

int dec_bin(char *value) {
  int base, num, i;
  num = atoi(value);
  i = base = 0;

  while (num) {
    base += (num % 2) * pow(10, i++);
    num /= 2;
  }

  return base;
}
