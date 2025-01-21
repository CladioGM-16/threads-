#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

void calculator() {
    printf("Calculator Process ID: %d\n", getpid());
    printf("Calculator Thread ID: %ld\n", std::this_thread::get_id());

    while (true) {
        int num1, num2;
        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;
        std::cout << "Result: " << num1 + num2 << std::endl;
    }
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %ld\n", std::this_thread::get_id());

    std::thread thread1(calculator);
    std::thread thread2(calculator);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    thread1.join();
    thread2.join();

    return 0;
}
