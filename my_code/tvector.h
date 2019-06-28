#pragma once

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;

template <typename T>

class MyVec {
public:
	MyVec() : sz(0) {
		capacity = DEF_CAPACITY;
		data = new T[DEF_CAPACITY];
	}

	MyVec(int size, T val) : sz(size), capacity(2 * size) {
		data = new T[capacity];
		for (int i = 0; i < sz; ++i) {
			data[i] = val;
		}
	}
	
	MyVec(const MyVec& v2) {
		copy(v2);
	}

	MyVec& operator=(const MyVec& v2) {
		if (this != &v2) {
			delete[] data;
			copy(v2);
		}
		return *this;
	}
	
	void push_back(T val) {
		sz++;
		if (sz > capacity) {
			std::cout << "Increasing capacity\n";
			T* old_data = data;
			data = new T[capacity * CAPACITY_MULT];
			for (int i = 0; i < sz; i++) {
				data[i] = old_data[i];
			}
			capacity *= CAPACITY_MULT;
			delete[] old_data;
		}
		data[sz - 1] = val;
	}

	void copy(const MyVec& v2) {
		sz = v2.sz;
		capacity = v2.capacity;
		data = new T[capacity];
		for (int i = 0; i < sz; i++) {
			data[i] = v2.data[i];
		}
	}

	void print_vector(const MyVec& v) {
		for (T t : v) {
			std::cout << t << " ";
		}
		std::cout << std::endl;
	}

	int size() {
		return sz;
	}

	T operator[](int i) const {
		return data[i];
	}

	T& operator[](int i) {
		return data[i];
	}

	bool operator==(MyVec& v1, MyVec& v2) {
		if (v1.size() != v2.size()) return false;
		else {
			for (int i = 0; i < v2.size(); ++i) {
				if (v1[i] != v2[i]) return false;
			}
		}
		return true;
	}

private:
	T* data;
	int sz;
	int capacity;
};