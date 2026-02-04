exam 2022
#include <vector>
#include <string>
#include <algorithm>

# 2022
// q1 
//a

double sumlist(const std::list<double> &l1) {
	double sum = 0;
	for (auto &p : l1) {
	sum += p;
	}
	return sum;
}

//b

void zrtowan (std::list<double> &l1) {
	for (auto &p: l1) {
	if (p == 0)
		p = 1;
	}
}

// c i)

int occurence(const std::list<int> &l1, const int &x) {
	return std::count(l1.cbegin(),l1.cend(),x);
}

// c ii

auto numbofzero(const std::list<int> &l1) {
	auto first = std::find_if(l1.begin(),l1.end(),[](const int& x){return x > 0;});
	if (first == l1.end()){
		return 0;
	}

	auto second = std::find_if(std::next(first),l1.end(),[](const int& x){return x > 0;});

	if (second == l1.end())
		return std::count(std::next(first),l1.end(),0);

	else
		return std::count(std::next(first),second,0);
}

// q2

class song {
private:
	std::string song;
	std::string singer;
	int length;
public:
	song(const std::string& s, const std::string& as,int sec) : song(s), singer(as), length(sec) {};
	const std::string& getSong() const {
		return song;
	} 
	const std::string& getSinger() const {
		return singer;
	}
	int getLength() const {
		return length;
	}
	
};

class playlist {
private:
	std::vector<song> p;
public:
	playlist() {};
	 void addSong(const song& s) {
		p.push_back(s);
	}
	int playlistSize() const {
		return p.size();
	}
	int totalLength() const {
		int tl = 0;
		for (auto& x: this->p) {
			tl += x.getLength();
		}
		return tl;
	}
	int singersongs(const std::string &s) const {
		return std::count_if(this->p.begin(),this->p.end(),[&s](song &x){return x.getSinger() == s;};
	}
}

//q3 

//a. event is an abstract class.

//b

class daily_event : public event {
public:
	daily_event(const std::string& d) : event(d) {}
	bool on_day(int day, int month, int year) const override {
	return true;
	}
};

class annual_event : public event {
	int de;
	int m;
public:
	annual_event(const std::string &d, int day, int month) : event(d),de(day),m(month) {}
	bool on_day(int day, int month, int year) const override {
		return(de == day && m == month);
	}
	
};

// d

std::vector<event*> events; //event * poitners because we cant use abstract types NOW I GET IT

events.push_back(new daily_event("Take medication"));
events.push_back(new annual_event("Birthday", 14, 2));


for (event& e : events) {
    if (e->on_day(day, month, year)) {
        std::cout << e->description() << std::endl;
    }
}
