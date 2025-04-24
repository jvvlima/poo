#include <iostream>
#include <string>

using namespace std;
class MyDate {
private:
    int dia;
    int mes;
    int ano;
public:
    bool validaData(string data, int& ano, int& mes, int& dia) {
        if (data.size() != 10 || data[4] != '-' || data[7] != '-') {
            return false; 
        }
        try {
            ano = stoi(data.substr(0, 4));
            mes = stoi(data.substr(5, 2));
            dia = stoi(data.substr(8, 2));
        } catch (...) {
            return false;
        }
        return true;
    }
    bool verificaData(int dia, int mes, int ano) {
        if (ano < 1000 || ano > 2025) {
            return false;
        }
        if (mes < 1 || mes > 12) {
            return false;
        }
        int diasNoMes[] = {31, (eBissexto(ano) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (dia < 1 || dia > diasNoMes[mes - 1]) {
            return false;
        }
        return true;
    }
    bool eBissexto(int ano) {
        return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    }
    void setData(const string& data) {
        int dia, mes, ano;
        if (validaData(data, ano, mes, dia) && verificaData(dia, mes, ano)) {
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        } else {
            this->dia = this->mes = this->ano = 0;
            cout << "Data invalida!" << endl;
        }
    }
    string dataExtenso() const {
        const string meses[] = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

        if (dia == 0 || mes == 0 || ano == 0) {
            return "Data invalida!";
        }

        return to_string(dia) + " de " + meses[mes - 1] + " de " + to_string(ano);
    }
    MyDate(string data) {
        setData(data); 
    }
};