#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void wait(int sec) {
    this_thread::sleep_for(chrono::seconds(sec));
}

class OS {
private:
    string ver = "0.1.0";
public:
    void boot() {
        cout << "================================" << endl;
        cout << "         MiniOS v0.1.0          " << endl;
        cout << "================================" << endl;
        cout << "Initializing MiniOS kernel..." << endl;
        cout << "Kernel loaded succefully!" << endl;
        cout << "Type `help` for list of commands!" << endl;
    }
    void shutdown(bool& job) {
        cout << "Shutting down MiniOS..." << endl;
        job = false;
    }
    string get_ver() { return ver; }
};

int main() {
    OS minios;
    minios.boot();
    bool work = true;
    while(work) {
        string cmd;
        cout << "user@MiniOS>";
        cin >> cmd;
    }
    return 0;
}