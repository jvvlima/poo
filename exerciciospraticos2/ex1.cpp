#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int nmrLinhas;
    string nomeArquivo;
    string linha;
    int i = 0;
    cout << "insira o nome do arquivo: " << endl;
    getline(cin, nomeArquivo);
    cout << "insira o numero de linhas que deseja ler: " << endl;
    cin >> nmrLinhas;
    ifstream arquivo(nomeArquivo);
    while (i < nmrLinhas && getline(arquivo, linha)) {
        cout << linha << endl;
        i++;
    }
    return 0;
}