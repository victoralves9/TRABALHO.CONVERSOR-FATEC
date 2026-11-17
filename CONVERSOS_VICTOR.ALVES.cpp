//VICTOR HUGO CAGNIN ALVES

#include <iostream>
#include <string>
using namespace std;

int main() {
    string numero;
    int origem, destino;
    int baseOrigem, baseDestino;

    //Pede o numero
    cout << "Digite o numero: ";
    cin >> numero;

    //Pede a base do numero digitado
    cout << "Esse numero esta em qual base?" << endl;
    cout << "1 - Binario" << endl;
    cout << "2 - Octal" << endl;
    cout << "3 - Decimal" << endl;
    cout << "4 - Hexadecimal" << endl;
    cin >> origem;

    //Qual base converter
    cout << "Converter para qual base?" << endl;
    cout << "1 - Binario" << endl;
    cout << "2 - Octal" << endl;
    cout << "3 - Decimal" << endl;
    cout << "4 - Hexadecimal" << endl;
    cin >> destino;

    // Transforma para a base escolhida
    if (origem == 1) baseOrigem = 2;
    if (origem == 2) baseOrigem = 8;
    if (origem == 3) baseOrigem = 10;
    if (origem == 4) baseOrigem = 16;

    if (destino == 1) baseDestino = 2;
    if (destino == 2) baseDestino = 8;
    if (destino == 3) baseDestino = 10;
    if (destino == 4) baseDestino = 16;

    // Achei mais fácil converter o numero para decimal
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
        //lê os dígitos da esquerda para a direita e, a cada dígito, multiplica o que já tem pela base e soma o dígito novo:
        decimal = decimal * baseOrigem + valor;
    }

    // Depois converte do decimal para a base escolhida
    string digitos = "0123456789ABCDEF"; //A string digitos transforma o resto em caractere: o resto 15 vira digitos[15], que é 'F'.
    string resultado = "";

    if (decimal == 0) {
        resultado = "0";
    }
    //% pega o resto e / pega o quociente:
    while (decimal > 0) {
        int resto = decimal % baseDestino;
        resultado = digitos[resto] + resultado;
        decimal = decimal / baseDestino;
    }

    cout << "Resultado: " << resultado << endl;

    return 0;
}
