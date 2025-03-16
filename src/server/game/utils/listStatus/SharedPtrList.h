#ifndef LISTSTATUS_H
#define LISTSTATUS_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <type_traits>

template <typename T1, typename T2>
class UniquePtrList {
private:
	std::vector<std::unique_ptr<T1>> _data;
public:
	ListStatus() {}

	const T1& peekItem(int index) const { return _data.at(index).first; }
	std::vector<std::pair<T1, T2>>& getDataChangable() const { return _data; }
	int getSize() const { return _data.size(); }
	int getCount(T2 key) const { return _count[key]; }

	void push(T1 item, T2 key) {
		if(std::is_same<T1, std::unique_ptr<T1>>)
		_data.emplace_back(item, key);
		_count[key]++;
	}
	void push(std::unique_ptr<T1> item, const T2& key) {
		_data.emplace_back(std::move(item), key);
		_count[key]++;
	}
	void push(std::shared_ptr<T1> item, const T2& key) {
		_data.push_back(std::make_pair(item, key));
		_count[key]++;
	}

	T1 extract(int index) {
		std::pair<T1, T2> item = _data.at(index);
		_data.erase(_data.begin() + index);
		_count[item.second]--;
		return item.first;
	}
	std::unique_ptr<T1> extract(int index) {
		std::pair<std::unique_ptr<T1>, T2> item = std::move(_data.at(index));
		_data.erase(_data.begin() + index);
		_count[item.second]--;
		return std::move(item.first);
	}
	std::shared_ptr<T1> extract(int index) {
		std::pair<std::shared_ptr<T1>, T2> item = _data.at(index);
		_data.erase(_data.begin() + index);
		_count[item.second]--;
		return item.first;
	}
};

#endif