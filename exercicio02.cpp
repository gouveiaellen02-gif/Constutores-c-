


#include <iostream>
using namespace std;

class Comparavel {
private:
    int valor;

public:
    Comparavel(int v) : valor(v) {}

    bool éMaiorOuIgual(int outro) const {
        return valor >= outro;
    }

    bool éMenorOuIgual(int outro) const {
        return valor <= outro;
    }

    bool éDiferenteDe(int outro) const {
        return valor != outro;
    }
};

int main() {
    Comparavel c(10);

    cout << "10 é maior ou igual a 5? " << c.éMaiorOuIgual(5) << endl;
    cout << "10 é menor ou igual a 15? " << c.éMenorOuIgual(15) << endl;
    cout << "10 é diferente de 10? " << c.éDiferenteDe(10) << endl;

    return 0;
}




