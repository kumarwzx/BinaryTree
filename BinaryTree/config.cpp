#include "config.h"

Config::Config() {
	charset.clear();
	charset.push_back(Freq(' ', 186));
	charset.push_back(Freq('A', 64));
	charset.push_back(Freq('B', 13));
	charset.push_back(Freq('C', 22));
	charset.push_back(Freq('D', 32));
	charset.push_back(Freq('E', 103));
	charset.push_back(Freq('F', 21));
	charset.push_back(Freq('G', 15));
	charset.push_back(Freq('H', 47));
	charset.push_back(Freq('I', 57));
	charset.push_back(Freq('J', 1));
	charset.push_back(Freq('K', 5));
	charset.push_back(Freq('L', 32));
	charset.push_back(Freq('M', 20));
	charset.push_back(Freq('N', 57));
	charset.push_back(Freq('O', 63));
	charset.push_back(Freq('P', 15));
	charset.push_back(Freq('Q', 1));
	charset.push_back(Freq('R', 48));
	charset.push_back(Freq('S', 51));
	charset.push_back(Freq('T', 80));
	charset.push_back(Freq('U', 23));
	charset.push_back(Freq('V', 8));
	charset.push_back(Freq('W', 18));
	charset.push_back(Freq('X', 1));
	charset.push_back(Freq('Y', 16));
	charset.push_back(Freq('Z', 1));

	charset.push_back(Freq('a', 64));
	charset.push_back(Freq('b', 13));
	charset.push_back(Freq('c', 22));
	charset.push_back(Freq('d', 32));
	charset.push_back(Freq('e', 103));
	charset.push_back(Freq('f', 21));
	charset.push_back(Freq('g', 15));
	charset.push_back(Freq('h', 47));
	charset.push_back(Freq('i', 57));
	charset.push_back(Freq('j', 1));
	charset.push_back(Freq('k', 5));
	charset.push_back(Freq('l', 32));
	charset.push_back(Freq('m', 20));
	charset.push_back(Freq('n', 57));
	charset.push_back(Freq('o', 63));
	charset.push_back(Freq('p', 15));
	charset.push_back(Freq('q', 1));
	charset.push_back(Freq('r', 48));
	charset.push_back(Freq('s', 51));
	charset.push_back(Freq('t', 80));
	charset.push_back(Freq('u', 23));
	charset.push_back(Freq('v', 8));
	charset.push_back(Freq('w', 18));
	charset.push_back(Freq('x', 1));
	charset.push_back(Freq('y', 16));
	charset.push_back(Freq('z', 1));

}