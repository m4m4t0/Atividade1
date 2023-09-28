# Atividade1

O projeto possuí 3 funções as quais, cada uma, tem seu arquivo fonte e header (.c e .h). As funções são randArray1(), randArray10() e randArray100(), estas 
recebem um inteiro 'n' e retornam um array de double float com n elementos, a primeira função retorna um valor de 0 a 1, a segundam, de 0 a 10 e a última de 0 a
100. O funcionamento dessas funções faz uso da função drand(), a qual retorna um double float aleatório com a seed time(NULL) (para retornar valores aleatórios
a todo momento) e as limitações de valores a depender da função.

Dito isso a função main, chama os headers das funções geradoras de arrays aleatórios e recebe 3 inteiros os quais determinarão o tamanho dos arrays das funções
randArray1(), randArray10() e randArray100(), respectivamente, e armazena os resultados em um ponteiro para em seguida ser printado no terminal para o leitor.
