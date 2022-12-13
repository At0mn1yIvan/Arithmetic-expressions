#pragma once
template <typename T1, typename T2>
class Table
{
private:
	T1* Key;
	T2* Value;
	size_t size, curIndex;

public:
	Table(size_t _size = 10): size(_size), curIndex(0) {
		Key = new T1[size];
		Value = new T2[size];
	}
	~Table(){
		delete[] Key;
		delete[] Value;
		Key = nullptr;
		Value = nullptr;
	}
	void Append(const T1& key, const T2& value) {
		if (curIndex >= size) {
			return;
		}
		Key[curIndex] = key;
		Value[curIndex++] = value;
	}

	T2 & operator[](const T1& key){
		for (size_t i = 0; i < curIndex; i++) {
			if (Key[i] == key)
				return Value[i];
		}
		throw "Expression not found";
	}

	const T2 & operator[](const T1& key) const {
		for (size_t i = 0; i < curIndex; i++) {
			if (Key[i] == key)
				return Value[i];
		}
		throw "Expression not found";
	}
};

