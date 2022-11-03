#include <stdio.h>
#include <stdlib.h>

extern void rgb_to_black_and_white(char*,char*);
int main(int argc, char *argv[]) {
	rgb_to_black_and_white(argv[1],argv[2]);
}
