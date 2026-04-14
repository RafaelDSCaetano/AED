#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

char* shift_string(char* str) {
    int string_len = strlen(str);
    char *result = malloc(string_len + 1); // aloca memoria para a nova string
    
    for (int i = 0; i < string_len; i++) {
        if(((str[i] >= 'a') && (str[i] <='z')) || ((str[i] >= 'A') && (str[i] <= 'Z'))){
            if (str[i] == 'z')
                result[i] = 'a';
            else if (str[i] == 'Z')
                result[i] = 'A';
            else
                result[i] = str[i] + 1; 
        } else {
            result[i] = str[i]; 
        }
    }
    result[string_len] = '\0'; // adiciona o caractere nulo de terminação
    return result;
}

int main() {
    char input[100];
    printf("Digite uma string: ");
    scanf("%99[^\n]", input); //usando deste modo ao inves de %s para o scanf pegar os espaços tbm
    
    char *shifted = shift_string(input);
    
    printf("String original: %s\n", input);
    printf("String com letras deslocadas: %s\n", shifted);
    
    free(shifted);
    
    return 0;
}
