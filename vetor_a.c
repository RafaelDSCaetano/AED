#include <stdio.h>


int main(){

int vetor_a[n]

for(int i = 0; i<= n; i++){  
    if ( i == vetor_a[n]){
        printf("Valor = encontrado!");
        return 1;
    }
}
printf("Valor n encontrado.");
return 0;
}

// O pior caso será quando o valor nao for encontrado, percorrendo todo laço. 2n + 3 do loop e +1 do printf. 
// Totalizando F(n) = 2n+4


''' ex2 


f3(f1(f4(f5(f2(n)))))

f3> f1> f4> f5> f2


f3(n) = O(f1(n))
f1(n) = O(f4(n))
f4(n) = O(f5(n))
f5(n) = O(f2(n))
'''