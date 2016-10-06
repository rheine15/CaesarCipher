#include <stdio.h>
#include <stdlib.h>

#define SIZE  128

/* Function definitions */
char* removeDuplicates(char word[]);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE* inf, FILE* outf, char substitue[]);

/* Global Variables */
char *input;
char encrypt[26];
char decrypt[26];

int main(int argc, char *argv[]) {
	// put word into array
    if(argc < 5) {
        printf("err");
        exit(0);
    }
    input = (char*)malloc(sizeof(argv)/sizeof(argv[1]));
    for(int ch = 0; *(argv[1]+ch) != '\0'; ch++) {
        *(input+ch) = *(argv[1]+ch);
    }
    
    FILE *in = fopen(argv[3], "r");
    FILE *out = fopen(argv[4], "w");
	input = removeDuplicates(input);
    initializeEncryptArray(input, encrypt);
    initializeDecryptArray(encrypt, decrypt);
    if(!argv[2]) { //if 0 encrypt
        processInput(in, out, encrypt);
    } else { //else decrypt
        processInput(in, out, decrypt);
    }
	return 1;
}

char* removeDuplicates(char word[]) {
//remove dup words. return string
	char* out = malloc(SIZE * sizeof(char));
    int counter = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (!targetFound(out, counter, word[i])) {
            *(out+counter) = word[i];
            counter++;
        }
    }
	return out;
}

int targetFound(char charArray[], int num, char target) {
//search the first num characters in array chararray for character target
//return 1 if found otherwise 0
    for (int i = 0; i < num; i++) {
        if(charArray[i] == target) {
            printf("FOUND %c\n", charArray[i]);
            return 1;
        }
    }
    return 0;
}

void initializeEncryptArray(char key[], char encrypt[]) {
//initialize encrypt array letters according to key
    int e = 0;
    char filler = 'Z';
    while(*(input+e) != '\0') {
        encrypt[e] = *(input+e);
        e++;
    }
    while (e < 26) {
        if(!targetFound(encrypt, e, filler)) {
            encrypt[e] = filler;
            e++;
        }
        filler--;
    }
    for(char l = 'A'; l <= 'Z'; l++){
    printf("ENCRYPT ARRAY: %c -> %c\n", l, encrypt[(l-65)]);
    }
}

void initializeDecryptArray(char encrypt[], char decrypt[]) {
//initialize decrypt array with appropriate sub letters based on encrypt
    for(int d = 0; d < 26; d++) {
        decrypt[encrypt[d]-65] = (d+65);
    }
}

void processInput(FILE* inf, FILE* outf, char substitute[]) {
//process data from input file and write to output
//pass enpass encrypt to sub if you want encrypt
//decrypt to sub otherwise
    char cipher;
    while(cipher != EOF) {
        cipher = fgetc(inf);
        fputc(substitute[cipher-65], outf);
    }
}
