#include "binary.h"
#include "args.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conv_bin(char *value, base_t base) {
  int result;
  char *hex;
  result = 0;
  if (base == Hex) {
    hex = bin_hex(value);
    printf("Binary: %s\nHex: %s\n", value, hex);
    free(hex);
  } else if (base == Dec) {
    result = bin_dec(value);
    printf("Binary: %s\nDecimal: %d\n", value, result);
  }
}

char *bin_hex(char *value) {
  int length, temp_length, i, hex_index = 0;
  char temp[BUFFER], *hex;

  hex = (char *)malloc(sizeof(char) * BUFFER);

  if (!hex) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  // Skip '0b' or '0B' if present
  if (value[0] == '0' && (value[1] == 'b' || value[1] == 'B'))
    value += 2;

  length = strlen(value);
  temp_length = add_zeros(value, temp, length);

  // Convert binary string to hexadecimal
  for (i = 0; i < temp_length; i += 4) {
    hex[hex_index++] = bin_to_hex_digit(temp + i);
  }
  hex[hex_index] = '\0';

  return hex;
}

char bin_to_hex_digit(char *nibble) {
  int decimal_value = 0;

  // Convert 4-bit binary string to decimal
  for (int i = 0; i < 4; i++) {
    if (nibble[i] >= '0' && nibble[i] <= '1') {
      decimal_value = (decimal_value << 1) | (nibble[i] - '0');
    } else {
      fprintf(stderr, "Invalid Binary character: %c\n", nibble[i]);
      exit(EXIT_FAILURE);
    }
  }

  // Convert decimal to hexadecimal character
  if (decimal_value < 10)
    return '0' + decimal_value;
  else
    return 'A' + (decimal_value - 10);
}

int add_zeros(char *from, char *to, int length) {
  int remainder = length % 4;
  int temp_index = 0;

  // Add leading zeros to make length a multiple of 4
  if (remainder != 0) {
    int zeros_to_add = 4 - remainder;
    while (zeros_to_add--) {
      to[temp_index++] = '0';
    }
  }

  // Copy the original binary string
  strcpy(to + temp_index, from);

  return temp_index + length; // Return the new length
}

int bin_dec(char *value) {
  int base, i, length;

  base = i = length = 0;

  if (value[0] == '0' && (value[1] == 'b' || value[1] == 'B'))
    value += 2;

  length = strlen(value);

  for (i = 0; i < length; i++) {
    if (isdigit(*(value + i)) && (*(value + i)) >= '0' &&
        (*(value + i)) <= '1') {
      base = (base << 1) | (value[i] - '0');
    } else {
      fprintf(stderr, "Invalid Binary character: %c\n", value[i]);
      exit(EXIT_FAILURE);
    }
  }

  return base;
}
