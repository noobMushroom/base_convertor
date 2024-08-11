#include "args.h"
#include "binary.h"
#include "decimal.h"
#include "hex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage(void) {
  printf("USAGE: basec --from <base> <value> --to <base>\n\n\
-i, --from : The base you want to convert\n\
-o, --to : The base for the output\n\
base:\n\
    hex: Hexadecimal value ex: 0x100, 100 etc\n\
    bin: Binary value ex: 0100000\n\
    dec: Decimal Value ex: 100\n\n\
-h, --help : Prints this\n\
-v, --version : Prints the version\n");
}

void check_args(int argc, char **argv) {

  if (argc != 2 && argc != 6) {
    usage();
    exit(EXIT_FAILURE);
  }

  if ((strcmp(*(argv + 1), "--from")) && (strcmp(*(argv + 1), "-i"))) {
    printf("Wrong input %s\n\n", *(argv + 1));
    usage();
    exit(EXIT_FAILURE);
  }

  else if ((strcmp(*(argv + 2), "hex")) && (strcmp(*(argv + 2), "bin")) &&
           (strcmp(*(argv + 2), "dec"))) {
    printf("Wrong input %s\n\n", *(argv + 2));
    usage();
    exit(EXIT_FAILURE);
  }

  else if ((strcmp(*(argv + 4), "--to")) && (strcmp(*(argv + 4), "-o"))) {
    printf("Wrong input %s\n\n", *(argv + 4));
    usage();
    exit(EXIT_FAILURE);
  }

  else if ((strcmp(*(argv + 5), "hex")) && (strcmp(*(argv + 5), "bin")) &&
           (strcmp(*(argv + 5), "dec"))) {
    printf("Wrong input %s\n\n", *(argv + 5));
    usage();
    exit(EXIT_FAILURE);
  }
}

base_t parse_base(char *argv) {
  if (!strcmp(argv, "hex"))
    return Hex;
  else if (!strcmp(argv, "bin")) {
    return Bin;
  } else if (!strcmp(argv, "dec"))
    return Dec;

  exit(EXIT_FAILURE);
}

void parse_args(int argc, char **argv) {
  /* Checking if all the args are correct*/
  check_args(argc, argv);

  if (argc == 2 && (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help"))) {
    usage();
    exit(EXIT_SUCCESS);
  }

  base_t from_base, to_base;
  char *value;

  from_base = parse_base(*(argv + 2));
  to_base = parse_base(*(argv + 5));
  value = *(argv + 3);

  switch (from_base) {
  case Hex:
    conv_hex(value, to_base);
    break;
  case Bin:
    conv_bin(value, to_base);
    break;
  case Dec:
    conv_dec(value, to_base);
    break;
  }
}
