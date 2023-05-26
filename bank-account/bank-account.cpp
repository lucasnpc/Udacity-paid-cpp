#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string account{ "" };
    std::string agency{""};
    std::string user{""};

public:
    BankAccount(std::string ac, std::string ag, std::string usr) : account(ac), agency(ag), user(usr) {};
    std::string Account() const {
        return account;
    };
    std::string Agency() const {
        return agency;
    };
    std::string User() const {
        return user;
    };
};

std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
    os << "Account Number: " << account.Account() << std::endl;
    os << "Owner Name: " << account.User() << std::endl;
    os << "Agency: " << account.Agency() << std::endl;
    return os;
}

int main() {
    BankAccount bankAccount("0070", "1421", "CPFUUSER");

    std::cout << bankAccount;

    return 0;
}