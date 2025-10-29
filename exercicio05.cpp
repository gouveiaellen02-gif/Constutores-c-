#include <iostream>
using namespace std;

class Calendario {
private:
    int dia, mes, ano;

public:
  
    Calendario(int d, int m, int a) {
        dia = d;
        mes = m;
        ano = a;
    }

    bool ehBissexto() {
        return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
    }

   
   
    void adicionarDias(int qtd) {
        dia += qtd;
        while (dia > 30) { 
            dia -= 30;
            mes++;
            if (mes > 12) {
                mes = 1;
                ano++;
            }
        }
    }

    
    void mostrarData() {
        cout << (dia < 10 ? "0" : "") << dia << "/"
             << (mes < 10 ? "0" : "") << mes << "/"
             << ano << endl;
    }
};

int main() {
    Calendario hoje(28, 10, 2025);
    
    cout << "Data inicial: ";
    hoje.mostrarData();
    
    cout << "É bissexto? " << (hoje.ehBissexto() ? "Sim" : "Não") << endl;

    hoje.adicionarDias(5);
    cout << "Após adicionar 5 dias: ";
    hoje.mostrarData();

    return 0;
}




