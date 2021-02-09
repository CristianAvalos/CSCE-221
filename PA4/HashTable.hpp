#pragma once
#include <vector>
#include <list>
#include <utility>
using namespace std;

template<typename T>
class HashTable {
private:
	int _size;
	vector<list<pair<int, T>>> table;
    int hash(const int _key) {
        return _key % _size;
    }
public:
    HashTable(const int size) {
		table.resize(size);
		_size = size;
    }

    void insert(const int key, const T value) {
		int index = hash(key);
		pair <int, T> hashPair;
		hashPair.first = key;
		hashPair.second = value;
		table[index].push_back(hashPair);
    }
	
	int minChainLen(){
		int length = 0;
		int min = table[0].size();
		for (int i = 0; i < _size; i++) {
			length = table[i].size();
			if (length < min) {
				min = length;
			}
		}
		return min;
	}
	
	int maxChainLen(){
		int length = 0;
		int max = table[0].size();
		for (int i = 0; i < _size; i++) {
			length = table[i].size();
			if (length > max) {
				max = length;
			}
		}
		return max;
	}
	
	double averageChainLen(){
		int count = 0;
		for (int i = 0; i < _size; i++) {
			count += table[i].size();
		}
		double ans = count /(double)_size;
		return ans;
	}
    
    T search(int key) {
		int index = hash(key);
		for (auto j : table[index]) {
			if (j.first == key) {
				T val = j.second;
				return val;
			}
		}
		return "nullptr";
    }
};
