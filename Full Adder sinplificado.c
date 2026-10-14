#include <stdio.h>
#include <stdbool.h>

char Dato_Resivido[5];
bool Dato = false;
bool rebote = false;

int Cifra_A, Cifra_B, Cifra_S, CIn = 0, COut;


int main() {
    printf("Bienvenido al Full Adder sinplificado\n");
    printf("Para usarme es super facil: solo debes escribir tus cifras A, B y C-In de la siguiente manera: 100 (esto hara que la Cifra A valga 1, la Cifra B valga 0 y la Cifra C-in valga 0).\n");
    printf("Si introduces otro tipo de dato, puede provocar un error o dato inesperado.\n");
    printf("Introdusca su Cifra:");

    while(1) {
            scanf("%4s", Dato_Resivido);

        if (Dato_Resivido[0] != 0 && Dato_Resivido[1] != 0 && Dato_Resivido[2] != 0) {
            printf("dato resivido, %s\n", Dato_Resivido);
            if (rebote == false) {
                Dato = true;
                rebote = true;
            }
            
        } else {
            printf("Error lect\n");
            printf("Introdusca su Cifra:");
        }
            
        if (Dato) {

            if (Dato_Resivido[0] <= '1' && Dato_Resivido[1] <= '1' && Dato_Resivido[2] <= '1') {
                Cifra_A =(int) Dato_Resivido[0] - '0'; Cifra_B = (int) Dato_Resivido[1] - '0'; CIn = (int) Dato_Resivido[2] - '0';
                printf("Cifra A: %i, Cifra A: %i, C-In: %i\n", Cifra_A, Cifra_B, CIn);

                int resultXOR = 0; int resultadoAND = 0; int resultadoANDII = 0;
                resultXOR = Cifra_A ^ Cifra_B;
                Cifra_S = resultXOR ^ CIn;
                resultadoAND = Cifra_A & Cifra_B; resultadoANDII = CIn & resultXOR; COut =  resultadoAND | resultadoANDII;

                printf("Cifra S(Resultado): %i, Resto C-Out: %i\n", Cifra_S, COut);
                printf("Introdusca su Cifra:");

                Dato_Resivido[0] = 0; Dato_Resivido[1] = 0;
                Dato = false;
                rebote = false;

            } else {
                printf("Error Data\n");
                Dato = 0;
                Dato_Resivido[0] = 0; Dato_Resivido[1] = 0;
                rebote = false;
                printf("Introdusca su Cifra:");
            }

        }
    }
}