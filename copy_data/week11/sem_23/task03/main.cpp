/*
Реализуйте систему обработки заказов, которая проверяет 
корректность введенного количества товаров и их стоимости. 
Если количество товаров отрицательное или стоимость товара 
ниже допустимого предела, система должна генерировать исключения.

Требования к реализации:
Определение класса исключения: Создайте класс исключения 
OrderException, который наследуется от std::exception. 
Класс должен содержать два поля: сообщение об ошибке и код ошибки.
 Реализуйте конструктор, принимающий эти параметры, и методы для их 
 извлечения.

Функция обработки заказа: Реализуйте функцию processOrder, 
которая принимает количество товаров и их стоимость как аргументы. 
Функция должна проверять, что количество товаров не отрицательно 
 что стоимость товара не ниже минимально допустимой. В случае
  обнаружения ошибки, функция должна генерировать исключение 
  OrderException с соответствующим сообщением об ошибке и кодом ошибки.

Обработка исключений: В функции main, вызовите processOrder с
 различными параметрами для демонстрации работы системы. 
 Используйте блоки try-catch для обработки исключений, 
 генерируемых функцией processOrder. При перехвате исключения, 
  выводите информацию об ошибке и код ошибки.
*/

#include <iostream>
#include <exception>
#include <string>

class OrderException: public std::exception {
private:
    std::string message;
    int error_code;

public:
    OrderException(std::string m, int code): message(m), error_code(code) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

    int getErrorCode() const{
        return error_code;
    }
};

void processOrderAmount(int amount){
    if (amount < 0){
        throw OrderException("Количество товара меньше нуля", 234);
    }
}

void processOrderPrice(double price){
    double min_price = 10;

    if (price < min_price){
        throw OrderException("Стоимость товара меньше минимальной", 235);
    }
}

void processOrder(int amount, double price){
    bool flag = true;

    std::cout << "Всего " << amount << " единиц товара. Стоимость каждого: " << price << " рублей." << "\n";

    try {
        processOrderAmount(amount);
    }
    catch (const OrderException& e) {
        std::cout << "\033[1;31m" << "Исключение: " << e.what()
                    << "\nКод ошибки: " << e.getErrorCode() << "\033[0m" << "\n\n";
        flag = false;
    }

    try {
        processOrderPrice(price);
    }
    catch (const OrderException& e) {
        std::cout << "\033[1;31m" << "Исключение: " << e.what()
                    << "\nКод ошибки: " << e.getErrorCode() << "\033[0m" << "\n\n";
        flag = false;
    }

    if (flag) {
        std::cout << "\033[1;32m" << "Товар подходит по всем критериям!" << "\033[0m" << '\n';
    }
}

int main() {

    processOrder(-99, 12.0);

    processOrder(10, 5.0);
}