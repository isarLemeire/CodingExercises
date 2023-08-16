#include <stdio.h>

// Berekent de dosis Propofol (mg) nodig om een patient 
// met het gegeven lichaamsgewicht (kg) onder volledige
// narcose te brengen.
void bereken_anesthesie_dosis(double gewicht, double dosering) {
    dosering = 1.5 * gewicht;
}

int main() {
    double g = 82.3; // Gewicht van de patient
    double d = 0;    // Dosering nodig voor anesthesie
    bereken_anesthesie_dosis(g, d);
    printf("Een patient die %.2f kg weegt heeft een dosering van %.2f mg nodig.\n", g, d);
    return 0;
}
