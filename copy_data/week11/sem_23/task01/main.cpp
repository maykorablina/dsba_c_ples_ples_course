/*
В рамках организации благотворительного марафона, необходимо 
создать программу для регистрации участников, которая строго 
проверяет возрастные ограничения. Марафон открыт для участников 
в возрасте от 18 до 60 лет включительно. Программа должна запросить 
у пользователя его возраст и выбранную дистанцию, а затем проверить, 
удовлетворяет ли возраст условиям участия в марафоне. 
Если условия нарушены, программа должна сгенерировать исключение.

Задачи:
Определить класс исключения AgeRestrictionException, 
который должен содержать сообщение об ошибке, указывающее на
 то, что возраст участника не соответствует требованиям.
Создать функцию registerParticipant, которая принимает возраст
 участника и выбранную дистанцию. Функция должна проверять, 
 соответствует ли возраст ограничениям. Если нет, функция должна 
 бросить исключение AgeRestrictionException.
В функции main реализовать запрос на ввод возраста и дистанции
 от пользователя, вызов функции registerParticipant и обработку
 возможного исключения, выводящую сообщение об ошибке, если возраст
  участника не попадает в допустимый диапазон.
Требования:
Использовать механизм исключений C++ для обработки ошибок, 
связанных с возрастными ограничениями.
Предусмотреть корректную обработку пользовательского ввода, включая
 ввод нечисловых значений.
Вывести подтверждение успешной регистрации, если возраст участника 
соответствует требованиям.

Введите ваш возраст: 25
Выберите дистанцию (5km, 10km, 21km): 10km
Регистрация успешно завершена!

Введите ваш возраст: 17
Выберите дистанцию (5km, 10km, 21km): 5km
Ошибка: Ваш возраст не соответствует требованиям для участия в
 марафоне.

*/

#include <iostream>
#include <exception>


class AgeRestrictionException: public std::exception {
private:
    std::string message;

public:
    AgeRestrictionException(std::string m): message(m) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

void registerParticipantAge(int age){
    if (age < 18 or age > 60){
        throw AgeRestrictionException("Ваш возраст не соответствует требованиям для участия в марафоне.");
    }
}

void registerParticipantDistance(int distance){
    if (!(distance == 5 or distance == 10 or distance == 21)){
        throw AgeRestrictionException("Вы можете выбрать только 5км, 10км или 21 км.");
    }
}

int main() {
    int age = 0, distance = 0, amount, counter = 0;
    std::cout << "Введите кол-во участников: ";
    std::cin >> amount;
    std::cout << '\n';

    for (int i =0; i < amount; i++){
        std::cout << "Введите ваш возраст: ";
        std::cin >> age;
        std::cout << "Выберите дистанцию (5km, 10km, 21km): ";
        std::cin >> distance;

        bool flag = true;
        try {
            registerParticipantAge(age);
        }
        catch (AgeRestrictionException& e) {
            std::cout << "\033[1;31m" << "Ошибка: " << e.what() << "\033[0m" << '\n';
            flag = false;
        }

        try {
            registerParticipantDistance(distance);
        }
        catch (AgeRestrictionException& e) {
            std::cout << "\033[1;31m" << "Ошибка: " << e.what() << "\033[0m" << '\n';
            flag = false;
        }

        if (flag){
            std::cout << "\033[1;32m" << "Участник успешно зарегистрирован!" << "\033[0m" << '\n';
            counter++;
        }

        std::cout << '\n';
    }

    if (counter >= amount * 0.9){
        std::cout << "\033[1;32m" << counter << " участников из " << amount << " были зарегистрированы" << "\033[0m" << '\n';
    }
    else{
        std::cout << "\033[1;31m" << counter << " участников из " << amount << " были зарегистрированы" << "\033[0m" << '\n';
    }

    return 0;
}