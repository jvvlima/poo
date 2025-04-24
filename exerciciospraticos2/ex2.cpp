#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int main()
{
    string nomeArquivo = "arquivo.txt";
    string linha;
    vector<string> linhasArquivo;
    do
    {
        cout << "informe uma linha: " << endl;
        getline(cin, linha);
        if (linha != "fim")
        {
            linhasArquivo.push_back(linha);
        }
    } while (linha != "fim");
    ofstream arquivo(nomeArquivo);
    for (int i = 0; i < linhasArquivo.size(); i++)
    {
        arquivo << linhasArquivo[i] << endl;
    }
    return 0;
}