# TRABALHO.CONVERSOR-FATEC
Conversor de bases numéricas em C++ que converte números entre binário, octal, decimal e hexadecimal. O usuário digita o número, escolhe a base de origem e a de destino, e o programa mostra o resultado. Projeto de estudo feito só com o básico da linguagem: cin, cout, if, for e while.

-----------------------------------------------------------


Conversor de Bases Numéricas em C++

Programa simples em C++ que converte números entre binário, octal, decimal e hexadecimal.

Feito como projeto de estudo de C++, usando apenas o básico da linguagem: entrada e saída com cin e cout, condicionais (if), laços (for e while) e strings.

Como funciona
O usuário digita o número.
Escolhe em qual base o número está.
Escolhe para qual base quer converter.
O programa mostra o resultado.

A conversão é feita em duas etapas:

O número é convertido da base de origem para decimal.
O decimal é convertido para a base de destino, dividindo pela base e guardando os restos.
Como compilar e executar

É necessário ter um compilador C++ instalado (por exemplo, o g++).

bash
g++ conversor.cpp -o conversor
./conversor

No Windows, execute conversor.exe.

Exemplo de uso
Digite o numero: 255
Esse numero esta em qual base?
1 - Binario
2 - Octal
3 - Decimal
4 - Hexadecimal
3
Converter para qual base?
1 - Binario
2 - Octal
3 - Decimal
4 - Hexadecimal
4
Resultado: FF
Exemplos de conversões
Número	Base de origem	Base de destino	Resultado
1010	Binário	Decimal	10
255	Decimal	Hexadecimal	FF
FF	Hexadecimal	Binário	11111111
Limitações
Funciona apenas com números inteiros positivos.
Não valida a entrada (por exemplo, digitar 2 como número binário gera um resultado incorreto).
Possíveis melhorias
Validar se os dígitos digitados pertencem à base escolhida.
Permitir converter vários números sem reiniciar o programa.
Aceitar números negativos.
Tecnologias
C++
