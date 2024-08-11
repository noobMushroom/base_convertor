basec: args.o hex.o main.o bin.o decimal.o
	@gcc -o basec -lm args.o hex.o basec.o decimal.o  binary.o
	@rm *.o
	@echo "Finished cleaning and compiling"


debug: args.o main.o bin.o
	@gcc -o  basec -g -lm -g args.o basec.o decimal.o binary.o 
	@\rm *.o
	@echo "Finished cleaning and compiling for debugging"

main.o: basec.c args.h 
	@gcc -c basec.c -g

args.o: args.c args.h
	@gcc -c args.c -g

bin.o: binary.c
	@gcc -c binary.c -g

decimal.o: decimal.c
	@gcc -c decimal.c -g
hex.o: decimal.c
	@gcc -c hex.c -g
