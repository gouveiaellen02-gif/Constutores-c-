#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdio>
using namespace std;

class Data {
public:
    int dia, mes, ano;
    Data(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), ano(a) {}
    int idadeEm(const Data& referencia) const {
        int idade = referencia.ano - ano;
        if (referencia.mes < mes || (referencia.mes == mes && referencia.dia < dia)) {
            idade--;
        }
        return idade;
    }
    string toString() const {
        char buf[11];
        sprintf(buf, "%02d/%02d/%04d", dia, mes, ano);
        return string(buf);
    }
};

class EntradaDeCinema {
private:
    int diaFilme;
    float horario;
    int sala;
    double valorBase;

public:
    EntradaDeCinema(int dFilme, float hr, int s, double valor)
        : diaFilme(dFilme), horario(hr), sala(s), valorBase(valor) {}

    double calculaDescontoPorIdade(const Data& dataNascimento, const Data& dataReferencia) const {
        int idade = dataNascimento.idadeEm(dataReferencia);
        if (idade < 12) return valorBase * 0.50;
        return valorBase;
    }

    double calculaDescontoEstudante(const Data& dataNascimento, int carteiraEstudante, const Data& dataReferencia) const {
        double valor = valorBase;
        int idade = dataNascimento.idadeEm(dataReferencia);
        if (carteiraEstudante <= 0) return valor;
        if (idade >= 12 && idade <= 15) valor = valorBase * 0.60;
        else if (idade >= 16 && idade <= 20) valor = valorBase * 0.70;
        else if (idade > 20) valor = valorBase * 0.80;
        return valor;
    }

    double aplicaDescontoHorario(double valorAtual) const {
        if (horario < 16.0f) return valorAtual * 0.90;
        return valorAtual;
    }

    double precoFinal(const Data& dataNascimento, const Data& dataReferencia, int carteiraEstudante = 0) const {
        double valorAposDesconto;
        if (carteiraEstudante != 0) {
            valorAposDesconto = calculaDescontoEstudante(dataNascimento, carteiraEstudante, dataReferencia);
            int idade = dataNascimento.idadeEm(dataReferencia);
            if (idade < 12) {
                double valorInfantil = valorBase * 0.50;
                if (valorInfantil < valorAposDesconto) valorAposDesconto = valorInfantil;
            }
        } else {
            valorAposDesconto = calculaDescontoPorIdade(dataNascimento, dataReferencia);
        }
        double valorFinal = aplicaDescontoHorario(valorAposDesconto);
        return valorFinal;
    }

    string toString(const Data& dataNascimento, const Data& dataReferencia, int carteiraEstudante = 0) const {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "Dia do filme: " << diaFilme << "\n";
        oss << "Horario: " << horario << "h\n";
        oss << "Sala: " << sala << "\n";
        oss << "Valor base: R$ " << valorBase << "\n";
        oss << "Data de nascimento do cliente: " << dataNascimento.toString() << "\n";
        if (carteiraEstudante != 0) oss << "Carteira de estudante: " << carteiraEstudante << "\n";
        oss << "Valor final: R$ " << precoFinal(dataNascimento, dataReferencia, carteiraEstudante) << "\n";
        return oss.str();
    }
};

int main() {
    Data hoje(28, 10, 2025);
    Data nascimento1(1, 1, 2016);
    Data nascimento2(15, 6, 2010);
    Data nascimento3(10, 11, 2002);

    EntradaDeCinema ingresso1(28, 15.30f, 5, 20.0);
    cout << "== Ingresso 1 (crianca) ==\n";
    cout << ingresso1.toString(nascimento1, hoje, 0) << endl;

    cout << "== Ingresso 2 (estudante 15 anos) ==\n";
    cout << ingresso1.toString(nascimento2, hoje, 12345) << endl;

    cout << "== Ingresso 3 (22 anos, estudante) ==\n";
    EntradaDeCinema ingresso2(28, 18.00f, 2, 30.0);
    cout << ingresso2.toString(nascimento3, hoje, 88888) << endl;

    return 0;
}




