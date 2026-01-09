exam_2025
#include <vector>
#include <string>
#include <list>
#include <algorithm>

// IMPORTANT ABSTRACT CLASSES
// If there is a single method inside the class that is =0 and virtual then it is an abstract class


//1
//a
//i

void incrementing(std::list<int> &l1) {
	for (auto &p : l1) {
		++p;	
	}
}

//i

int smallest(const std::list<int> &l1) {
	int smallest = *(l1.begin()); // l1.begin is an iterator cant do l1[0] cause not vector or array // mistake 2
	for ( auto  &p : l1) {
		if(p < smallest)
			smallest = p;
	}
	return smallest;
}

//b
//i

void replaceodd(std::list<int> &l1) {
	auto odd = std::find_if(l1.begin(),l1.end(),[](int& x){return x %2 != 0;}); // odd is a iterator here and add if for any case
	if (odd != l1.end())
		*odd = 1;
}

//ii

int oddcount(const std::list<int> &l1) {
	auto first  = std::find_if(l1.begin(),l1.end(),[](int& x){return x % 2 == 0;});
	if (first == l1.end())
		return 0;
	return std::count_if(next(first),l1.end(),[](int &x){return x % 2 != 0;});
}

//c
//i

class music : public multimedia {
public:
	music(const string&s) : mutlimedia(s) {}
	void play() const override {
		std::cout<< "This is music:" << _title << "\n";
	}

	~music() override {}
};

//ii

std::vector<multimedia*> song; // not * music but multimedia to show polymorphism // mistake one
song.push_back(new music("this december"));

for (music* e : song) { // prolly owuldnt figure it out my self
	std::cout << e->play();
}


//2
//a

class vehicle {
private:
	std::string name;
	std::string color;
	int value;
public:
	vehicle(const std::string &n, const std::string &c, int v) : namne(n), color(c), value(v) {}
	const std::string& Name() const {
		return name;
	}
	const std::string &Color() const {
		return color;
	}
	int Value() const {
		return value;
	}
	
};


//b

class parking {
private:
	std::vector<vehicle> v;
pbulic:
	void addVehicle(vehicle& v1) {
		v.push_back(v1);
	}
	int vehicles() const {
		return v.size();
	}
	int vehiclesValue() const {
		int value = 0;
		for (auto &p : v) {
			value += p.Value();
		}
		return value;
	}
	int vehiclewithcolor(const std::string& s) const {
		return std::count_if(v.cbegin(),v.cend(),[&s](vehicle &vc){return vc.Color() == s;});
	}

};