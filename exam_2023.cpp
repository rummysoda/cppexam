exam_2023

#include <vector>
#include <string>
#include <algorithm>


//q1 
//a 
24
x = 3, y = 16

//b

void printdob(const std::list<double> &l1){
	for ( auto& p : l1){
	std::cout << p << std::endl;
	}
}

//c

int numbofs(const std::list<std::string> &l1) {
	return std::count_if(l1.cbegin(),l1.cend(),[](const std::string &y){return y.size() >= 6;});
}

//d
//i

bool isithere(const std::list<std::string> &l1, const std::string &s) {
	auto p = std::find(l1.begin(),l1.end(),s);
	if (p == l1.end())
		return false;
	else
		return true;
}

//ii

void replace(std::list<std::string> &l1,std::string &s, std::string &r) {
	auto p = std::find(l1.begin(),l1.end(),s);
	if (p != l1.end()) 
		*p = r;
	else
		std::cout << "no " << s << " found" << std::endl;
}

//iii
void replaceall(std::list<std::string> &l1, std::string &r , std::string &s) {
	for (auto &p : l1) {
		if (p ==s)
			p = r;
	}
}


//2
//a

class character {
private:
	std::string name;
	int start_hp;
	int curr_hp;
public:
	character(const std::string &n, int hp) : name(n), start_hp(hp), curr_hp(hp) {}
	int getHp() const {return curr_hp;}
	const std::string &getName() const {return name;}
	void decreaseHP() {
		if(curr_hp > 0)
			curr_hp--;
	}
	void increaseHP() {
		if (curr_hp >= start_hp)
			std::cout << "character has max health" << "\n";
		else if (curr_hp == 0) 
			std::cout << "character is dead" << "\n";
		else
			curr_hp++;
	}
};

// b

class world {
private:
	std::vector<character> c;
public:
	world() {}
	void addCharacter(character &c1){ // we can add const to character
		c.push_back(c1);
	}
	void increaseallhp() {
		for (auto &p : c) {
			p.increaseHP();
		}
	}
	void decreaseallhp(const std::string &s) { // same here add ocnst
		for (auto &p : c) {
			if (p.getName() == s)
				p.decreaseHP();
		}
	}
	int aliveCharacters() const {
		return std::count_if(c.cbegin(),c.cend(),[](const character &z){return z.getHp() > 0 ;}); 
	}
};

//3
//a fisrt const for vector makes sure the function doesnt change whats inside the vector and and the second const is to make sure the function only reads

// best : The first const ensures that the vector passed as an argument is not modified.
The second const indicates that the member function does not modify the state of the object and can be called on const instances.

//b

class average : public scorer {
public:
	average() {}
	double score(const std::vector<double> &v) const override {
		double avg = 0;
		for (auto &p : v) {
			avg +=p;
		}
		return avg/(v.size());
	}
};

//c

class largest : public scorer {
public:
	largest() {}
	double score(const std::vector<double> &v) const override {
		double max = 0;
		for (auto &p : v) {
			if(p > max)
				max = p;
		}
		return max;
	}	
};

//d

void sum(scorer &s , std::map<std::string, std::vector<double>> &m) {
	for(auto &p : m{
		std::cout << p.first() << ": " << s.score(p.second()) << std::endl;
	}
}