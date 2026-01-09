exam_2024
#include <string>
#include <algorithm>
#include <vector>
#include <list>

//q1 
//a 

void multiplybytwo(std::list<double> &l1) {
	for (auto &p : l1) {
		p *=2;
	}
}

//b 
//i

int numberofzeroes(const std::list<double> &l1) {
	return std::count(l1.cbegin(),l1.cend(),0); // we can put nubmbers in it yippy
}

//ii 

int numberofzeroesbeforeone(const std::list<double> &l1) {
	auto first = std::find(l1.cbegin(),l1.cend(),1);
	if (first == l1.cend())
		return 0;
	else
		return std::count(l1.begin(),first,0);
}

//iii

void replaceonebyzero(std::list<double> &l1) {
	for (auto &p : l1){
		if (p == 1){
			p = 0;
			break;
		}
	}
}

//c
//i 

class loggable {
public:
	virtual void log(const std::string &s, int n) const = 0;
	virtual ~loggable() {}
};

//ii 

class logging : public loggable {
public:
	logging() {}
	void log(const std::string &s, int n) const override {
		std::cout << "test";
	}
	~logging() {}

};


//q2
//a
class item {
	std::string desc;
	int value;
public:
	item(const std::string &d ,int v) : desc(d), value(v) {}
	const std::string& Description() const {
		return desc;
	}
	int itemValue() const {
		return value;
	}
};

//b

void sortDescending(std::vector<item> &l1) {
	std::sort(l1.begin(),l1.end(),[](item &x, item&y){return x.itemValue() > y.itemValue();}); 
	// IMPORTANT NOT NEXT(X).VALUE 
	// SORT JUST TAKE X AND Y AND OCMPARES IT BUY IT SELF
}

//c

class sack {
private:
	std::vector<item> items;
public:
	sack() {}
	void add_item (const item &entry) {
		items.push_back(entry);
	}
	int totalValue() const {
		int total = 0;
		for (const auto &p: items) {
			total += p.itemValue();
		}
		return total;
	}
	const bool descfind(const std::string &s) const {
		for (const auto& p : items) {
			if (p.Description() == s)
				return true;
		}
		return false; // its here because if its inside of loop it stops after first iteration
	}	
	//d

	int greaterthan(int n) {
		return std::count_if(items.begin(),items.end(),[&n](item &x){return x.itemValue() > n;});
	}


};
