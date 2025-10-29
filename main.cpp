#include <iostream>
#include <string>
using namespace std;

class Conta {
private:
	int numero;
	double saldo;
	double limite;
	string nome;

public:
	Conta(int n, double s, double l, string nm) {
		numero = n;
		saldo = s;
		limite = l;
		nome = nm;
	}

	bool saca(double valor) {
		if (valor <= saldo + limite) {
			saldo -= valor;
			return true;
		} else {
			return false;
		}
	}

	void deposita(double valor) {
		saldo += valor;
	}

	bool transfere(Conta &destino, double valor) {
		if (saca(valor)) {
			destino.deposita(valor);
			return true;
		}
		return false;
	}

	void mostrarDados() {
		cout << "Conta: " << numero << " | Nome: " << nome
		     << " | Saldo: " << saldo << " | Limite: " << limite << endl;
	}
};

int main() {
	Conta c1(1, 1000, 500, "Ellen");
	Conta c2(2, 300, 200, "Lucas");

	c1.transfere(c2, 200);
	c1.mostrarDados();
	c2.mostrarDados();

	return 0;
}
