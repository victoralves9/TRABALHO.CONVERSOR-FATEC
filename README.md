# TRABALHO.CONVERSOR-FATEC - ALUNO VICTOR HUGO CAGNIN ALVES
Conversor de bases numéricas em C++ que converte números entre binário, octal, decimal e hexadecimal. O usuário digita o número, escolhe a base de origem e a de destino, e o programa mostra o resultado. Projeto de estudo feito só com o básico da linguagem: cin, cout, if, for e while.

-----------------------------------------------------------


# Conversor de Bases Numéricas em C++

Programa simples em C++ que converte números entre **binário**, **octal**, **decimal** e **hexadecimal**.

Projeto de estudo feito só com o básico da linguagem: `cin`, `cout`, `if`, `for`, `while` e strings.

## Como compilar e executar

É necessário ter um compilador C++ instalado (por exemplo, o `g++`).

```bash
g++ conversor.cpp -o conversor
./conversor
```

No Windows, execute `conversor.exe`.

## Exemplo de uso

```
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
```

## Como o código funciona

A ideia principal é fazer a conversão em **duas etapas**, usando o decimal como ponto de passagem:

```
base de origem  ->  decimal  ->  base de destino
```

Assim o programa não precisa de uma lógica para cada combinação possível (binário para octal, hexadecimal para binário etc.). São só uma conversão de ida e uma de volta.

### 1. Variáveis

```cpp
string numero;
int origem, destino;
int baseOrigem, baseDestino;
```

- `numero` é uma string, e não um `int`, porque o hexadecimal tem letras (A a F).
- `origem` e `destino` guardam a opção escolhida no menu (de 1 a 4).
- `baseOrigem` e `baseDestino` guardam o valor real da base (2, 8, 10 ou 16).

### 2. Entrada de dados

O programa pede o número e depois mostra dois menus com `cout`, um para a base do número e outro para a base do resultado. As respostas são lidas com `cin`.

### 3. Transformando a opção em base

```cpp
if (origem == 1) baseOrigem = 2;
if (origem == 2) baseOrigem = 8;
if (origem == 3) baseOrigem = 10;
if (origem == 4) baseOrigem = 16;
```

O menu usa 1, 2, 3 e 4, mas a conta precisa de 2, 8, 10 e 16. Esses `if` fazem essa tradução. O mesmo é feito para o destino.

### 4. Etapa 1: da base de origem para decimal

```cpp
int decimal = 0;
for (int i = 0; i < numero.size(); i++) {
    char c = numero[i];
    int valor = 0;

    if (c >= '0' && c <= '9') {
        valor = c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        valor = c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        valor = c - 'a' + 10;
    }

    decimal = decimal * baseOrigem + valor;
}
```

O `for` percorre o número **da esquerda para a direita**, um caractere por vez.

**Transformando o caractere em valor:**

- Para dígitos, `c - '0'` dá o valor numérico. Exemplo: `'7' - '0'` resulta em 7.
- Para letras, `c - 'A' + 10` dá o valor da letra. Exemplo: `'C' - 'A'` é 2, e somando 10 resulta em 12.
- As letras minúsculas também são aceitas.

**Montando o decimal:**

A linha `decimal = decimal * baseOrigem + valor;` multiplica o que já foi lido pela base e soma o dígito novo. Exemplo com `1010` na base 2:

| Dígito | Conta   | decimal |
|--------|---------|---------|
| 1      | 0×2 + 1 | 1       |
| 0      | 1×2 + 0 | 2       |
| 1      | 2×2 + 1 | 5       |
| 0      | 5×2 + 0 | 10      |

### 5. Etapa 2: de decimal para a base de destino

```cpp
string digitos = "0123456789ABCDEF";
string resultado = "";

if (decimal == 0) {
    resultado = "0";
}

while (decimal > 0) {
    int resto = decimal % baseDestino;
    resultado = digitos[resto] + resultado;
    decimal = decimal / baseDestino;
}
```

Aqui o número é dividido pela base de destino várias vezes, e os **restos** formam o resultado.

- `%` pega o resto da divisão.
- `/` pega o quociente, que é usado na próxima volta.
- O `while` repete até o número chegar a 0.
- `digitos[resto]` transforma o resto em caractere. O resto 15, por exemplo, vira `'F'`.
- `digitos[resto] + resultado` coloca o dígito novo **na frente** do resultado. Como os restos precisam ser lidos de trás para frente, isso já deixa a string na ordem certa.
- O `if (decimal == 0)` existe porque, para o número 0, o `while` nunca roda e o resultado ficaria vazio.

Exemplo: 255 para hexadecimal.

| Divisão   | Quociente | Resto   |
|-----------|-----------|---------|
| 255 ÷ 16  | 15        | 15 (F)  |
| 15 ÷ 16   | 0         | 15 (F)  |

Resultado: `FF`.

### 6. Saída

```cpp
cout << "Resultado: " << resultado << endl;
```

Mostra o resultado na tela.

## Exemplos de conversões

| Número | Base de origem | Base de destino | Resultado |
|--------|----------------|-----------------|-----------|
| 1010   | Binário        | Decimal         | 10        |
| 255    | Decimal        | Hexadecimal     | FF        |
| FF     | Hexadecimal    | Binário         | 11111111  |

## Limitações

- Funciona apenas com números inteiros positivos.
- Não valida a entrada (por exemplo, digitar `2` como número binário gera um resultado incorreto).
- Usa `int`, então números muito grandes podem estourar o limite.

## Possíveis melhorias

- Validar se os dígitos digitados pertencem à base escolhida.
- Permitir converter vários números sem reiniciar o programa.
- Aceitar números negativos.
