#ifndef LISTSTATUS_H
#define LISTSTATUS_H

#include <vector>
#include <memory>

template <typename T1, typename T2>
class UniquePtrList {
private:
	std::vector<std::unique_ptr<T1>> _data;
public:
	ListStatus() {}

	const std::unique_ptr<T1>& peekItem(int index) const { return _data.at(index); }
	const std::vector<std::unique_ptr<T1>>& getData() const { return _data; }
	int getSize() const { return _data.size(); }
	
	void push(std::unique_ptr<T1> item) { _data.push_back(std::move(item)); }
	std::unique_ptr<T1> extract(int index) {
		std::unique_ptr<T1> item = std::move(_data.at(index));
		_data.erase(_data.begin() + index);
		return std::move(item);
	}

	int getCount(T2 key, const std::function<T2(const std::unique_ptr<T1>&)>& check, ) const {
		int count = 0;
		for(const auto& item : _data) {
			if(check(item) == key) count++;
		}
		return count;
	}

	int sort(const std::function<bool(const std::unique_ptr<T1>&, const std::unique_ptr<T1>&)>& check) const {
		
	}
};

#endif