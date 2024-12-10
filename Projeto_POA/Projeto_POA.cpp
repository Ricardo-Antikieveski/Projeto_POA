#include <iostream>
#include <string>

using std::string;

class Conta {
protected:
    double saldo;

public:
    Conta(double saldoInicial) : saldo(saldoInicial) {}

    double getSaldo() const {
        return saldo;
    }

    virtual void sacar(double valor) = 0;
};

class ContaCorrente : public Conta {
public:
    ContaCorrente(double saldoInicial) : Conta(saldoInicial) {}

    void sacar(double valor) override {
        if (verificarSaldo(valor)) {
            saldo -= valor;
            std::cout << "Saque de " << valor << " realizado com sucesso na Conta Corrente." << std::endl;
        }
    }

    bool verificarSaldo(double valor) {
        if (valor > saldo) {
            std::cout << "Saldo insuficiente na Conta Corrente." << std::endl;
            return false;
        }
        return true;
    }
};

class ContaSalario : public Conta {
public:
    ContaSalario(double saldoInicial) : Conta(saldoInicial) {}

    void sacar(double valor) override {
        if (verificarSaldo(valor)) {
            saldo -= valor;
            std::cout << "Saque de " << valor << " realizado com sucesso na Conta Salario." << std::endl;
        }
    }

    bool verificarSaldo(double valor) {
        if (valor > saldo) {
            std::cout << "Saldo insuficiente na Conta Salario." << std::endl;
            return false;
        }
        return true;
    }
};

int main() {
    char exit = 'N';
    string TipoConta = "";
    int ValorASacar = 0;

    Conta* contaCorrente = new ContaCorrente(1000);
    Conta* contaSalario = new ContaSalario(500);

    do {
        do {
            std::cout << "[System Bank] Nao esqueca de digitar um tipo valido! \n";
            std::cout << "[System Bank] Digite o tipo de conta para saque: [SALARIO] ou [CORRENTE] \n";
            std::cout << "[System Bank] Digite o tipo da conta para saque: ";
            std::cin >> TipoConta;
            system("cls");

        } while (!(TipoConta == "SALARIO" || TipoConta == "CORRENTE"));

        system("cls");

        if (TipoConta == "SALARIO") {
            std::cout << "[System Bank] Voce escolheu o tipo de conta: " << TipoConta << "\n";
            std::cout << "[System Bank] Digite o valor para saque: ";
            std::cin >> ValorASacar;
            contaSalario->sacar(ValorASacar);
        }
        else {
            std::cout << "[System Bank] Voce escolheu o tipo de conta: " << TipoConta << "\n";
            std::cout << "[System Bank] Digite o valor para saque: ";
            std::cin >> ValorASacar;
            contaCorrente->sacar(ValorASacar);
        }

        std::cout << "[System Bank] Voce deseja finalizar? [S/N]: ";
        std::cin >> exit;

        system("cls");

    } while (!(exit == 'S'));


    delete contaCorrente;
    delete contaSalario;

    return 0;
}