#include <climits>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include "vector"


using UnixTS = unsigned int;

const unsigned short TRANSACTION_COL_N = 6;
const unsigned short ACCOUNT_COL_N = 3;

struct Transaction {
    std::string id;
    UnixTS date;
    std::string type;
    std::string from;
    std::string to;
    double amount;
    bool operator<(const Transaction& other) const;
};

class Account
{
public:
    Account();// default constructor
    Account(const std::string& id, const std::string& name, UnixTS validity_dt = UINT_MAX);
    void addTransaction(const Transaction& transaction);
    double getBalance(UnixTS = UINT_MAX) const;
    void printInfo() const;
    size_t getTransactionsCount() const;

private:
    std::string id;
    std::string name;
    std::set<Transaction> transactions;
    UnixTS validity_dt;
};

void Account::printInfo() const
{
    std::cout << "--------------------------------\n"
              << "id: " << id << '\n'
              << "name: " << name << '\n'
              << "validity datetime: " << validity_dt << '\n'
              << "--------------------------------\n";
}

size_t Account::getTransactionsCount() const
{
    return transactions.size();
}

Account::Account()
{
    id = "00000000-0000-0000-0000-000000000000";
    name = "Noname";
    validity_dt = 0;
}
// Task 1 (5 points)
// Implement Account constructor with arguments
Account::Account(const std::string& id,
                 const std::string& name,
                 UnixTS validity_dt)
{
    this->id = id;
    this->name = name;
    this->validity_dt = validity_dt;
}

// Task 2 (10 points)
// Implement operator< overloading for Transaction
bool Transaction::operator<(const Transaction& other) const
{
    if (date != other.date) return date < other.date;

    int type_1 = 0, type_2 = 0;

    if (type == "withdraw") type_1 = 1;
    else if (type == "transfer") type_1 = 2;

    if (other.type == "withdraw") type_2 = 1;
    else if (other.type == "transfer") type_2 = 2;

    return type_1 < type_2;
}

// Task 3 (10 points)
// Implement get balance to date method (default max value)
double Account::getBalance(UnixTS timestamp) const
{
    double balance = 0;

    for (auto trans: transactions){
        if (trans.date <= timestamp){
            if (trans.from != trans.to) {
                if (trans.type == "deposit" || (trans.type == "transfer" && trans.to == id)) balance += trans.amount;
                else balance -= trans.amount;
            }
        }
    }

    return balance;
}

// Task 4 (15 points)
// Implement adding transaction to Account
void Account::addTransaction(const Transaction& transaction)
{
    transactions.insert(transaction);
    validity_dt = transaction.date;
}


// Task 5 (20 points)
// Implement transaction and account reading from csv and fill accounts by transactions
using AccountContainer = std::unordered_map<std::string, Account>;
using TransactionContainer = std::set<Transaction>;

std::vector<std::string> split(std::string str, char separator) {
    std::vector<std::string> ans;
    int index_start = 0;
    int length = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == separator) {
            ans.push_back(str.substr(index_start, length - 1));
            index_start = i + 1;
            length = 0;
        }
        length += 1;
    }
    ans.push_back(str.substr(index_start));
    return ans;
}

TransactionContainer readTransactions(std::ifstream& fileStream)
{
    TransactionContainer transactions;

    std::string line;
    std::getline(fileStream, line);
    size_t transactionsCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < transactionsCount; ++i)
    {
        std::getline(fileStream, line);

        std::vector<std::string> ss = split(line, ';');
        Transaction transaction;

        transaction.id = ss[0];
        transaction.date = std::stoi(ss[1]);
        transaction.type = ss[2];
        transaction.from = ss[3];
        transaction.to = ss[4];
        transaction.amount = std::stod(ss[5]);

        transactions.insert(transaction);
    }


    return transactions;
}

AccountContainer readAccounts(std::ifstream& fileStream)
{
    AccountContainer accounts;

    std::string line;
    std::getline(fileStream, line);
    size_t accCount = std::stoul(line);
    std::getline(fileStream, line);

    for (size_t i = 0; i < accCount; ++i)
    {
        std::getline(fileStream, line);

        std::vector<std::string> ss = split(line, ';');
        Account account(ss[0], ss[1], std::stoul(ss[2]));

        accounts[ss[0]] = account;
    }

    return accounts;
}

void fillAccounts(AccountContainer& accounts, const TransactionContainer& transactions)
{
    for (auto trans: transactions){
        for (auto& acc: accounts){
            if (trans.to == acc.first || trans.from == acc.first) acc.second.addTransaction(trans);
        }
    }
}
