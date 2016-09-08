#include <stdio.h>

#define SIZE = 26

/* Function definitions */
char* removeDuplicates(char word[]);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE* inf, FILE* outf, char substitue[]);

int main(int argv, char argc[]) {
	// put word into array
	short bool = 0;
	short arrnum = 0;
	for (short x = 0; x < SIZE; x++) {
		for (short y = 0; y < SIZE; y++) {
			if (input[x] == alph[y]) {
				bool = 1;
			}
		}
		if (bool == 0) {
			alph[arrnum] = input[x];
			arrnum++;
		}
		bool = 0;
	}

	// fill in remainder of array
	for (char ch = 'a'; ch <= 'z'; ch++) {
		for (short i = 0; i < SIZE; i++) {
			if (alph[i] == ch) {
				alph[ch - 'a'] = ch;
			}
		}
	}
}

char* removeDuplicaes(char word[]) {
//remove dup words. return string
}

int targetFound(char charArray[], int num, char target) {
//search the first num characters in array chararray for character target
//return 1 if found otherwise 0
}

void initializeEncryptArray(char key[], char encrypt[]) {
//initialize encrypt array letters according to key
}

void initializeDecryptArray(char encrypt[], char decrypt[]) {
//initialize decrypt array with appropriate sub letters based on encrypt
}

void processInput(FILE* inf, FILE* outf, char substitue[]) {
//process data from input file and write to output
//pass enpass encrypt to sub if you want encrypt
//decrypt to sub otherwise
}
