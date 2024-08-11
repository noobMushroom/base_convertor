# BaseC - Base Conversion Utility

BaseC is a command-line tool for converting numerical values between different bases, including hexadecimal (hex), binary (bin), and decimal (dec). It's simple to use and can convert from any of these bases to another with just a few commands.

## Features

* Convert numbers between hexadecimal, binary, and decimal.
* Simple command-line interface.
* Support for standard base formats:
    * Hexadecimal (hex): 0x100, 100, etc.
    * Binary (bin): 0100000
    * Decimal (dec): 100
* Built-in help and version display.

## Usage

The basic syntax for using BaseC is:

```bash
basec --from <base> <value> --to <base>
```

## Command-Line Options

* `-i, --from` : Specifies the base of the input value.
* `-o, --to` : Specifies the base for the output.
* `-h, --help` : Displays help information about the tool.
* `-v, --version` : Displays the current version of BaseC.

## Supported Bases

* hex: Hexadecimal value (e.g., 0x100, 100)
* bin: Binary value (e.g., 0100000)
* dec: Decimal value (e.g., 100)

## Examples
1. Convert hexadecimal `0x1F4` to binary:

```bash
basec --from hex 0x1F4 --to bin
```

2. Convert binary `0100000` to decimal:

```bash
basec --from bin 0100000 --to dec
```
3. Convert decimal `100` to hexadecimal:

```bash
basec --from dec 100 --to hex
```
## Compilation

To compile BaseC, a Makefile is provided. This Makefile contains two targets: one for regular compilation and one for compiling with debugging information.

### Building the Project

To compile the project, run:

```
make
```
This will generate the `basec` executable and clean up the object files afterward.

## Debugging

To compile the project with debugging information (useful for debugging with `gdb`), run:

```
make debug
```

## Getting Help

To see a summary of the available options and usage information, you can use the help flag:

```bash
basec --help
```

## Version Information

To see the current version of BaseC, you can use the version flag:

```bash
basec --version
```

## License

This project is open source and available under the [GNU-v3 License](https://github.com/noobMushroom/base_convertor/blob/main/LICENSE).

