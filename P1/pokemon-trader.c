#include <stdio.h>

char *pokemon_id_to_string(int pokemon_id){
    if (pokemon_id == 1){
        return "Pikachu";
    } else if (pokemon_id == 2){
        return "squirtle";
    } else {
        return "?";
    }
}

void trade(int first_pokemon, int second_pokemon) {
    int temp = second_pokemon;
    second_pokemon = first_pokemon;
    first_pokemon = temp;
}

int main() {
    int pokemon_alice = 1;
    int pokemon_bob = 2;

    printf("Before the trade:\n");
    printf("\tAlice her pokemon: %s\n", pokemon_id_to_string(pokemon_alice));
    printf("\tBob his pokemon: %s\n", pokemon_id_to_string(pokemon_bob));

    trade(pokemon_alice, pokemon_bob);

    printf("After the trade:\n");
    printf("\tAlice her pokemon: %s\n", pokemon_id_to_string(pokemon_alice));
    printf("\tBob his pokemon: %s\n", pokemon_id_to_string(pokemon_bob));

    return 0;
}
