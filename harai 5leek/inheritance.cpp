#include <string>
#include <iostream>
class leguma {
protected:
	std::string nume;

public:
	friend std::ostream& operator<<(std::ostream&os, const leguma &a);
	leguma(std::string a) :nume{ a } {}
	

	virtual void afisare() {
		std::cout << this;
	}
};

std::ostream& operator<<(std::ostream&os, const leguma &a) {
	os << a.nume << " \n";
	return os;
}

class mar : public leguma {
protected:
	int x;
public:
	mar(std::string  a, int x) :leguma::leguma(a) , x{ x } {
	}

	
	void afisare()override {
		std::cout << nume << " " << x << "\n";
	}
};

class para: public mar{
protected:
	int y;
public:
	para(std::string  a, int x,int y) :mar::mar(a,x), y{ y } {}


	void afisare() {
		std::cout << nume << " " << x <<" "<< y<<"\n";
	}
};
int main() {
	leguma l1{ "leguma 1" };
	leguma l2{ "leguma 2" };
	mar m1{ "mar 1",1 };
	mar m2{ "mar 2",2 };
	para p1{ "para 1",3,3 };
	para p2{ "para 2",4,4 };


	std::cout << l1 << " " << l2;


	int x;
	std::cin >> x;

}