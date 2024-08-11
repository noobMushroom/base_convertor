#include "hex.h"
#include "args.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conv_hex(char *value, base_t base) {
  int result;
  char *bin;
  if (base == Dec) {
    result = hex_dec(value);
    printf("Hex: %s\nDecimal: %d\n", value, result);
  } else if (base == Bin) {
    bin = hex_bin(value);
    printf("%s\n", bin);
    free(bin);
  }
}

int hex_dec(char *value) {
  int i, base, len, power;
  char temp;
  base = power = 0;

  if (value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
    value += 2;

  len = strlen(value);

  for (i = len - 1; i >= 0; i--) {
    temp = tolower(value[i]);
    if (isalpha(temp) && temp >= 'a' && temp <= 'f') {
      base += ((temp - 'a') + 10) * pow(16, power);
    } else if (isdigit(temp)) {
      base += (value[i] - '0') * pow(16, power);
    } else {
      fprintf(stderr, "Invalid hexadecimal character: %c\n", value[i]);
      exit(EXIT_FAILURE);
    }
    power++;
  }

  return base;
}

char *hex_bin(char *value) {
  static const char *bin_lookup[] = {
      "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
      "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
  int len, bin_index = 0;
  char *binary_string;

  binary_string = (char *)malloc(sizeof(char) * BIN_BUFFER);
  if (!binary_string) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  // Skip '0x' or '0X' if present
  if (value[0] == '0' && (value[1] == 'x' || value[1] == 'X'))
    value += 2;

  len = strlen(value);

  for (int i = 0; i < len; i++) {
    char lower = tolower(value[i]);
    if (lower >= '0' && lower <= '9') {
      strcpy(binary_string + bin_index, bin_lookup[lower - '0']);
    } else if (lower >= 'a' && lower <= 'f') {
      strcpy(binary_string + bin_index, bin_lookup[lower - 'a' + 10]);
    } else {
      fprintf(stderr, "Invalid hexadecimal character: %c\n", value[i]);
      free(binary_string);
      exit(EXIT_FAILURE);
    }
    bin_index += 4;
  }
  binary_string[bin_index] = '\0';

  return binary_string;
}
