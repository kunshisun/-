#include<iostream>
using namespace std;
class Rectangle {
private:
	double length, width;
public:
	Rectangle(double l = 0, double w = 0) :length(l), width(w){}
	double area() const {
		return length * width;
	}
	Rectangle operator>(const Rectangle& x) const {
		if (this->area() > x.area())
			return *this;
		else
			return x;
	  }
	void display() {
		cout << "较大矩形的面积为:" << area() << endl;
	}
};
int main() {
	double l1, w1, l2, w2;
	cin >> l1 >> w1;
	cin >> l2 >> w2;
	Rectangle r1(l1,w1), r2(l2,w2);
	Rectangle big = r1 > r2;
	big.display();
	return 0;
}