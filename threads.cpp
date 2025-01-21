#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
using namespace std;

void cpu_waster() {
    cout << "CPU Waster Process ID: " << getpid() << endl;
    cout << "CPU Waster Thread ID: " << this_thread::get_id() << endl;
    while (true) continue;
}

int main() {
    cout << "Main Process ID: " << getpid() << endl;
    cout << "Main Thread ID: " << this_thread::get_id() << endl;
    // Crear 6 hilos
    thread thread1(cpu_waster);
    thread thread2(cpu_waster);
    thread thread3(cpu_waster);
    thread thread4(cpu_waster);
    thread thread5(cpu_waster);
    thread thread6(cpu_waster);

    while (true) {
        this_thread::sleep_for(chrono::seconds(1));
    }
    system("Pause");
    return 0;
}
