#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
class leguma {
protected:
	std::string nume;

public:
	friend std::ostream& operator<<(std::ostream&os, const leguma &a);
	leguma(std::string a) :nume{ a } {}
	

	virtual void afisare() {
		std::cout << nume << "\n";
	}

	 std::string  get_nume()const {
		return nume;
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


bool comparator(leguma *a, leguma *b) {
	if (a->get_nume().compare(b->get_nume()) < 1)
		return 1;
	else
		return 0;
}

int main() {
	
	leguma* l1=new leguma{ "leguma 1" };
	leguma* l2=new leguma{ "leguma 2" };
	mar *m1=new mar{ "mar 1",1 };
	mar *m2=new mar{ "mar 2",2 };
	para *p1=new para{ "para 1",3,3 };
	para *p2=new para{ "para 2",4,4 };





	/*std::string a = "af4asdasdga1";

	std::sort(a.begin(), a.end());
	std::cout << a;
*/

	std::vector<leguma*> vect = { m1,l2,p1,p2,l1,m2 };


	//std::sort(vect.begin(), vect.end(), [=](const leguma *a,const leguma *b) {
	//	if (a->get_nume().compare(b->get_nume()) < 1)
	//		return 1;
	//	else
	//		return 0;
	//});

	std::sort(vect.begin(), vect.end(),comparator);


	//std::sort(vect.begin(), vect.end());

	for (auto x : vect)
		x->afisare();


	int x;
	std::cin >> x;

}