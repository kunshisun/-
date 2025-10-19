#include<iostream>
#include<string>
using namespace std;
class Spaceship {
public:
    string model = "δ����";
    int speed = 0;
    int energy = 0;
    virtual void shouStats() {
        cout << "ģ�ͣ�" << model << endl;
        cout << "�ٶȣ�" << speed << endl;
        cout << "������" << energy << endl;
    }
    virtual void action() = 0 {}
};
class CargoShip :public Spaceship {
private:
    double cargoCapacity;
public:
    int sum = 0;
    void action()override {
        cout << "����װ�ػ���..." << endl;
    }
    void loadCargo() {
        int cargo;
        cin >> cargo;
        sum += cargo;
        cout << sum << endl;
    }
};
class BattleShip :public Spaceship {
private:
    float weaponPower;
public:
    void action() {
        cout << "�������伤��..." << endl;
    }
    double fireLaser() {
        energy -= 10;
        return energy;
    }
};
class ExplorerShip :public Spaceship {
private:
    double scanRange;
public:
    void action() {
        cout << "����ɨ������..." << endl;
    }
    double scanPlanet() {
        energy -= 10;
        return energy;
    }
};
class SpaceshipFleet :public Spaceship {
public:
    void action() {
    }
    void printtt() {
        cout << "�˵���" << endl << "���޷ɴ�" << endl << "���ӷɴ�" << endl
            << "�鿴�ɴ�" << endl << "�����������ѡ��" << endl;
    }
};
int main() {
    int C_num = 0;
    int B_num = 0;
    int E_num = 0;
    while (true) {
        SpaceshipFleet name;
        name.printtt();
        string s, s1;
        cin >> s;
        if (s == "���޷ɴ�") {
            cout << "������ɴ����ͣ�Ӣ�ģ���" << endl;
            cin >> s1;
            if (s1 == "CargoShip") {
                CargoShip name;
                name.action();
                int x;
                cout << "�������������" << endl;
                
                name.loadCargo();
            }
            else if (s1 == "BattleShip") {
                BattleShip name;
                name.action();
                name.fireLaser();
            }
            else if (s1 == "ExplorerShip") {
                ExplorerShip name;
                name.action();
                name.scanPlanet();
            }
            else cout << "�������" << endl;
        }
        if (s == "���ӷɴ�") {
            cout << "������ɴ����ͣ�Ӣ�ģ���" << endl;
            cin >> s1;
            if (s1 == "CargoShip") {
                CargoShip name;
                name.shouStats();
                cout << "���ʼ�����ֱ������ַ��������֣�����(�ո���)����"
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                C_num += 1;
            }
            else if (s1 == "BattleShip") {
                BattleShip name;
                name.shouStats();
                cout << "���ʼ�����ֱ������ַ��������֣�����(�ո���)����"
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                B_num += 1;
            }
            else if (s1 == "ExplorerShip") {
                ExplorerShip name;
                name.shouStats();
                cout << "���ʼ�����ֱ������ַ��������֣�����(�ո���)����" 
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                E_num += 1;
            }
            else cout << "�������" << endl;
        }
        if (s == "�鿴�ɴ�") {
            cout <<"CargoShip������Ϊ��"<< C_num<<endl
                << "BattleShip������Ϊ��" << B_num <<endl
                << "ExplorerShip������Ϊ��"<< E_num << endl;
        }
        cout << "��q�˳������������������" << endl;
        char esc;
        cin >> esc;
        if (esc == 'q')
            break;
    }
    return 0;
}