#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

void say_hello() {
    std::cout << "Hello Thread Process ID: " << getpid() << std::endl;
    std::cout << "Hello Thread Thread ID: " << std::this_thread::get_id() << std::endl;

    // Bucle cada 500 ms
    while (true) {
        std::cout << "Hello" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void say_goodbye() {
    std::cout << "[Goodbye Thread] Process ID: " << getpid() << std::endl;
    std::cout << "[Goodbye Thread] Thread ID: " << std::this_thread::get_id() << std::endl;

    // Bucle cada 500 ms
    while (true) {
        std::cout << "Goodbye" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    std::cout << "[Main Thread] Process ID: " << getpid() << std::endl;
    std::cout << "[Main Thread] Thread ID: " << std::this_thread::get_id() << std::endl;

    // Crear dos hilos: uno para "Hello" y otro para "Goodbye"
    std::thread thread_hello(say_hello);
    std::thread thread_goodbye(say_goodbye);


    while (true) {
        std::cout << "Greet" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    thread_hello.join();
    thread_goodbye.join();

    return 0;
}
// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.