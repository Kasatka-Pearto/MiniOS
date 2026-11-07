#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

void wait(int sec) {
    this_thread::sleep_for(chrono::seconds(sec));
}
void clear() {
    for(int i = 0; i < 100; i++) {
        cout << endl;
    }
}

class OS {
private:
    string ver = "0.2.0";
public:
    void boot() {
        cout << "================================" << endl;
        cout << "         MiniOS v" << ver << endl;
        cout << "================================" << endl;
        cout << "Initializing MiniOS kernel..." << endl;
        cout << "Kernel loaded succefully!" << endl;
        cout << "Type `help` for list of commands!" << endl;
    }
    void shutdown(bool& job) {
        cout << "Shutting down MiniOS..." << endl;
        job = false;
    }
    void reboot() {
        cout << "Rebooting MiniOS..." << endl;
        wait(3);
        clear();
        boot();
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
        if(cmd == "help") {
            cout << "help - list of commands" << endl;
            cout << "poweroff - powersoff MiniOS" << endl;
            cout << "reboot - reboots MiniOS" << endl;
            cout << "echo - echoes text" << endl;
            cout << "clear - clears console" << endl;
            cout << "ver - shows current version" << endl;
            cout << "wait - waits n seconds" << endl;
        }
        else if(cmd == "poweroff") {
            minios.shutdown(work);
        }
        else if(cmd == "reboot") {
            minios.reboot();
        }
        else if(cmd == "echo") {
            string text;
            getline(cin, text);
            cout << text << endl;
        }
        else if(cmd == "clear") {
            clear();
        }
        else if(cmd == "ver") {
            cout << minios.get_ver() << endl;
        }
        else if(cmd == "wait") {
            int sec;
            cin >> sec;
            wait(sec);
        }
        else {
            cout << "Unknown command: " << cmd << "! Type `help` for list of commands!" << endl;
        }
    }
    return 0;
}