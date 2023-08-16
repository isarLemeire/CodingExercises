#include "adfgx.h"

/************************************************************
 * Implementation by [John Doe]
 * *********************************************************/

/*****************
* Help functions *
*****************/

// Checks if memory allocation or file opening was successful
void validation_check(void* input, char* description) {
	
}

// Allocates memory for a string, checks if this allocation was successful and terminates with EOS
char* allocate_strlen(unsigned long strlen) {
	
}

// Makes a deep copy of a string
char* deep_copy(const char* s) {
	
}

// Alphabetically sorts a given string
char* sort(const char* s) {
	char* sorted = deep_copy(s);
	for (int i = 1, l = strlen(sorted); i < l + 1; i++) {
		for (int j = 0; j < l - i; j++) {
			if (sorted[j] > sorted[j + 1]) {
				char c = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = c;
			}
		}
	}
	return sorted;
}

// Returns the first index of a character in a given string, -1 if the character cannot be found
int get_index(const char c, const char* s) {
	
}

// Returns a filtered, uppercase version of the specified message
char* filter(const char* alphabet, char* text) {
	
}

// Returns the content of a given file
char* read_from_file(const char* filename) {
	
}

// Writes text to a given file
void write_to_file(const char* filename, const char* text) {
	
}

/*****************
* Main functions *
*****************/

// Creates a new ADFGX machine
adfgx* create_adfgx(const char* alphabet, const char* symbols, const char* dictionary, const char* transposition) {
	
}

// Sets the transposition for a given ADFGX machine
void set_transposition(adfgx* m, const char* transposition) {
	
}

// Encodes a message using a given ADFGX machine
char* encode_simple(adfgx* m, const char* text) {
	
}

// Decodes a message using a given ADFGX machine
char* decode_simple(adfgx* m, const char* encoded) {
	
}

// Encodes and transposes a message using a given ADFGX machine
char* encode_hard(adfgx* m, const char* text) {
	char* encoded_simple = encode_simple(m, text);
	char* transp_sorted = sort(m->transposition);
	char* encoded = allocate_strlen(strlen(encoded_simple));
	for (int i = 0, x = 0, width = strlen(m->transposition); i < width; i++) {
		int j = get_index(transp_sorted[i], m->transposition);
		for (int k = j, l = strlen(encoded_simple); k < l; k += width) {
			encoded[x++] = encoded_simple[k];
		}
	}
	free(encoded_simple);
	free(transp_sorted);
	return encoded;
}

// Transposes and decodes a message using a given ADFGX machine
char* decode_hard(adfgx* m, const char* encoded) {
	
}

// Finds the transposition for a given ADFGX machine
char* brute_force(adfgx* m, const char* encoded, const char* start) {
	
}

// Frees allocated memory of a given ADFGX machine
void free_adfgx(adfgx* m) {
	
}
