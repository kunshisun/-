#include<iostream>
#include<string>
using namespace std;
int sum = 0;
class Spaceship {
public:
    string model = "未定义";
    int speed = 100;
    int energy = 100;
    virtual void shouStats() {
        cout << "模型：" << model << endl;
        cout << "速度：" << speed << endl;
        cout << "能量：" << energy << endl;
    }
    virtual void action() = 0 {}
};
class CargoShip :public Spaceship {
private:
    double cargoCapacity;
public:
    void action()override {
        cout << "正在装载货物..." << endl;
    }
    void loadCargo() {
        int cargo;
        cin >> cargo;
        sum += cargo;
        cout << "当前载货量为：" << sum << endl;
    }
};
class BattleShip :public Spaceship {
private:
    float weaponPower;
public:
    void action() {
        cout << "即将发射激光..." << endl;
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
        cout << "正在扫描星球..." << endl
            << "剩余能量：" << energy << endl;
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
        cout << "菜单：" << endl << "租赁飞船" << endl << "增加飞船" << endl
            << "查看飞船" << endl << "（请输入你的选择）" << endl;
    }
};
int main() {
    int C_num = 1;
    int B_num = 1;
    int E_num = 1;
    while (true) {
        SpaceshipFleet name;
        name.printtt();
        string s, s1;
        cin >> s;
        if (s == "租赁飞船") {
            cout << "请输入飞船类型（英文）：" << endl;
            cin >> s1;
            if (s1 == "CargoShip") {
                CargoShip name;
                name.action();
                cout << "请输入货物量：" << endl;
                name.loadCargo();
                cout << "输入s展示飞船基本信息" << endl << "按任意键继续：" << endl;
                char s;
                cin >> s;
                if (s == 's') name.shouStats();
            }
            else if (s1 == "BattleShip") {
                BattleShip name;
                name.action();
                name.fireLaser();
                cout << "输入s展示飞船基本信息" << endl << "按任意键继续：" << endl;
                char s;
                cin >> s;
                if (s == 's') name.shouStats();
            }
            else if (s1 == "ExplorerShip") {
                ExplorerShip name;
                name.action();
                name.scanPlanet();
                cout << "输入s展示飞船基本信息" << endl << "按任意键继续：" << endl;
                char s;
                cin >> s;
                if (s == 's') name.shouStats();
            }
            else cout << "输入错误" << endl;
        }
        else if (s == "增加飞船") {
            cout << "请输入飞船类型（英文）：" << endl;
            cin >> s1;
            if (s1 == "CargoShip") {
                CargoShip name;
                name.shouStats();
                cout << "请初始化（分别输入字符串，数字，数字(空格间隔)）："
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                C_num += 1;
            }
            else if (s1 == "BattleShip") {
                BattleShip name;
                name.shouStats();
                cout << "请初始化（分别输入字符串，数字，数字(空格间隔)）："
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                B_num += 1;
            }
            else if (s1 == "ExplorerShip") {
                ExplorerShip name;
                name.shouStats();
                cout << "请初始化（分别输入字符串，数字，数字(空格间隔)）："
                    << endl;
                cin >> name.model >> name.speed >> name.energy;
                name.shouStats();
                E_num += 1;
            }
            else cout << "输入错误" << endl;
        }
        else if (s == "查看飞船") {
            cout << "CargoShip的数量为：" << C_num << endl
                << "BattleShip的数量为：" << B_num << endl
                << "ExplorerShip的数量为：" << E_num << endl;
        }
        else cout << "输入错误" << endl;
        cout << "按q退出，按其他任意键返回菜单" << endl;
        char esc;
        cin >> esc;
        if (esc == 'q')
            break;
    }
    return 0;
}