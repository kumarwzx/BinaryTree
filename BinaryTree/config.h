#pragma once

#include<utility>
#include<vector>

using namespace std;

typedef pair<char,unsigned int> Freq;

class Config{

public:
	static Config& getInstance() {
		static Config instance;
		return instance;
	};
	static vector<Freq>& getCharSet() { return getInstance().charset; }
	
private:
	vector<Freq> charset;
	Config();
	~Config() { charset.clear(); }
};
