#include "adfgx.h"
#define EOS '\0'
/************************************************************
 * Implementation by [John Doe]
 * *********************************************************/

/*****************
* Help functions *
*****************/

// Checks if memory allocation or file opening was successful
void validation_check(void* input, char* description) {
	if(!input){
		printf("%s is null", description);
		getchar();
	}
}

// Allocates memory for a string, checks if this allocation was successful and terminates with EOS
char* allocate_strlen(unsigned long strlen) {
	char* r = malloc((strlen + 1));
	validation_check(r, "Allocated string");
	r[strlen] = EOS;
	return r;
}

// Makes a deep copy of a string
char* deep_copy(const char* s) {
	char* copy = allocate_strlen(strlen(s));
	strcpy(copy, s);
	return copy;
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
	for(int i = 0; i < strlen(s); i++){
		if (c == s[i])
			return i;
	}
	return -1;
}

// Returns a filtered, uppercase version of the specified message
char* filter(const char* alphabet, char* text) {
	char* filtered = deep_copy(text);
	int i = 0;
	for (int j = 0; j < strlen(text); j++)
	{
		char c = toupper(text[j]);
		if(get_index(c, alphabet) >= 0){
			filtered[i++] = c;
		}
	}
	filtered[i++] = EOS;
	filtered = realloc(filtered, i*sizeof(char));
	return filtered;
}

int countOccurrences(const char *string, const char *substring) {
    int count = 0;
    size_t substringLength = strlen(substring);

    while ((string = strstr(string, substring)) != NULL) {
        count++;
        string += substringLength;
    }

    return count;
}

// Returns the content of a given file
char* read_from_file(const char* filename) {

	char * buffer;
	long length;

    FILE* file = fopen(filename, "r");
    assert(file);

    fseek(file, 0, SEEK_END);
    length = ftell(file);
	fseek(file, 0, SEEK_SET); 

	buffer = malloc(length + 1);
    assert(buffer);

    fread(buffer, 1, length, file);
	int enters = countOccurrences(buffer, "\n");
	realloc(buffer, length + 1 - enters);
    buffer[length - enters] = EOS;

	
    fclose(file);
    return buffer;
}

// Writes text to a given file
void write_to_file(const char* filename, const char* text) {
	FILE* file = fopen(filename, "w");
	assert(file);
	fprintf(file, "%s", text);
	fclose(file);
}

/*****************
* Main functions *
*****************/

// Creates a new ADFGX machine
adfgx* create_adfgx(const char* alphabet, const char* symbols, const char* dictionary, const char* transposition) {
	adfgx* adfgx = malloc(sizeof(adfgx));
	adfgx->alphabet = deep_copy(alphabet);
	adfgx->symbols = deep_copy(symbols);
	adfgx->dictionary = deep_copy(dictionary);
	adfgx->transposition = deep_copy(transposition);
	return adfgx;
}

// Sets the transposition for a given ADFGX machine
void set_transposition(adfgx* m, const char* transposition) {
	free(m->transposition);
	m->transposition = deep_copy(transposition);
}

// Encodes a message using a given ADFGX machine
char* encode_simple(adfgx* m, const char* text) {
	char* encoded = malloc(2 * strlen(text) + 1);
	encoded[2 * strlen(text)] = EOS;

	for (size_t i = 0; i < strlen(text); i++)
	{
		encoded[2*i] = m->dictionary[2 * get_index(text[i], m->alphabet)];
		encoded[2*i +1] = m->dictionary[2 * get_index(text[i], m->alphabet) + 1];
	}
	return encoded;
}

// Returns the first index of a character in a given string, -1 if the character cannot be found
int get_index_pair(const char a, const char b, const char* s) {
	for(size_t i = 0; i + 1 < strlen(s); i+=2){
		if (a == s[i] && b == s[i+1]){
			return i/2;
		}
	}
	return -1;
}

// Decodes a message using a given ADFGX machine
char* decode_simple(adfgx* m, const char* encoded) {

	char* decoded = malloc(strlen(encoded)/2 + 1);

	for (size_t i = 0; i < strlen(encoded); i+=2)
	{
		decoded[i/2] = m->alphabet[get_index_pair(encoded[i], encoded[i + 1], m->dictionary)];
		
	}

	decoded[strlen(encoded)/2] = EOS;

	return decoded;
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
	int l = strlen(encoded);
	char* decoded = allocate_strlen(l);
	char* transp_sorted = sort(m->transposition);
	int width = strlen(m->transposition);
	int div = strlen(encoded)/ width + 1;
	int offset = 0;

	for (size_t i = 0; i < 8; i++)
	{
		int index = get_index(transp_sorted[i], m->transposition);
		for (size_t j = 0; index + j*width < l; j++)
		{
			decoded[index + j*width] = encoded[j + i*div - offset];
		}
		offset += (strlen(encoded)% width < index + 1);
	}
	
	char* fully_decoded = decode_simple(m, decoded);
	free(decoded);
	return fully_decoded;
}

// Finds the transposition for a given ADFGX machine
char* brute_force(adfgx* m, const char* encoded, const char* start) {

	char* fileContent = read_from_file("data/permutations.txt");
	
	

	char* line = strtok(fileContent, "\n");  // Split by newline characters
	line = strtok(NULL, "\n");
    while (line != NULL) {
		set_transposition(m, line);
        char* decoded = decode_hard(m, encoded);
		// printf("%s\n", decoded);
		if(strstr(decoded, start)){
			return decoded;
		}
		free(decoded);
        line = strtok(NULL, "\n");
    }
	free(fileContent);
	return "Could not decode the message";
}

// Frees allocated memory of a given ADFGX machine
void free_adfgx(adfgx* m) {
	free(m->alphabet);
	free(m->dictionary);
	free(m->symbols);
	free(m->transposition);
	free(m);
}
