#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
private:
    string name;
public:
    void inputName() {
        cout << "Masukkan nama anda: ";
        getline(cin, name);
    }
    string getName() { return name; }
};

struct Activity {
    string name;
    int jammulai;
    int jamselesai;
};

class Schedule {
private:
    vector<vector<Activity>> activities; // 7 hari
    const string days[7] = {"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};

public:
    Schedule() {
        activities.resize(7);
    }

    void inputSchedule() {
        for (int i = 0; i < 7; i++) {
            cout << "\n=== " << days[i] << " ===\n";
            int count;
            cout << "Masukkan jumlah kegiatan hari " << days[i] << ": ";
            cin >> count;
            cin.ignore();

            for (int j = 0; j < count; j++) {
                Activity act;
                cout << "  Nama kegiatan " << j+1 << ": ";
                getline(cin, act.name);

                cout << "  Jam mulai (0-23): ";
                cin >> act.jammulai;
                cout << "  Jam selesai (0-23): ";
                cin >> act.jamselesai;
                cin.ignore();

                activities[i].push_back(act);
            }
        }
    }

    void displaySchedule() {
        cout << "\n=========== Jadwal Mingguan ===========\n";
        for (int i = 0; i < 7; i++) {
            cout << "\n" << days[i] << ":\n";
            if (activities[i].empty()) {
                cout << " (Tidak ada kegiatan)\n";
            } else {
                for (auto &act : activities[i]) {
                    cout << "- " << act.name 
                         << " | " << act.jammulai << ":00"
                         << " - " << act.jamselesai << ":00" << endl;
                }
            }
        }
    }
};

class Program {
private:
    User user;
    Schedule schedule;
public:
    void run() {
        user.inputName();

        int pilihan;
        while (true) {
            cout << "\n===== MENU =====\n";
            cout << "1. Input jadwal kegiatan selama seminggu\n";
            cout << "2. Tampilkan jadwal\n";
            cout << "0. Keluar\n";
            cout << "Pilih menu: ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan) {
                case 1:
                    schedule.inputSchedule();
                    break;
                case 2:
                    schedule.displaySchedule();
                    break;
                case 0:
                    cout << "Sampai jumpa, " << user.getName() << "!" << endl;
                    return;
                default:
                    cout << "Pilihan tidak valid.\n";
            }
        }
    }
};

int main() {
    Program program;
    program.run();
    return 0;
}