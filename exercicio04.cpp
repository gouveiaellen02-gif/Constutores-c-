#include <iostream>
#include <string>
using namespace std;

class Aluno {
private:
    string nome;
    int matricula;
    string telefone;

public:
   
    Aluno() {
        nome = "";
        matricula = 0;
        telefone = "";
    }

  
    Aluno(string n, int m, string t) {
        nome = n;
        matricula = m;
        telefone = t;
    }

    void mostrarDados() {
        cout << "Nome: " << nome 
             << " | Matrícula: " << matricula 
             << " | Telefone: " << telefone << endl;
    }

  
    void mostrarDois(Aluno outro) {
        cout << "\n--- Dados dos dois alunos ---" << endl;
        mostrarDados();
        outro.mostrarDados();
    }
};

int main() {
    Aluno a1("Ellen", 123, "99999-9999");
    Aluno a2("Lucas", 456, "88888-8888");

    a1.mostrarDois(a2);

    return 0;
}




