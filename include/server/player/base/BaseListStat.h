//待修改
#include <vector>
using namespace std;

template <typename T>
class BaseListStat {
protected:
    vector<T> container;
public:
    //getter
    //virtual int getDefault() { return defaultValue; }
    virtual T getItem(int index) {}
    virtual int getSize() { return container.size(); }

    //setter
    /*virtual void setDefault(int newDefault) {
        defaultValue = newDefault;
    }*/
    virtual void addItem(T item) {
    }
    virtual void removeItem(int index) {
    }
    virtual void setItem(int index, T item) {
    }
    virtual void clear() {
    }

    //logic
    virtual bool isDepleted() { return (value <= lowerLimit); };
    virtual bool isFull() { return (value == upperLimit); };
    virtual bool isExceed() { return (value > upperLimit); };
    virtual bool isEnough(int requirement) { return (value >= requirement); };

    //distructor
    virtual ~BaseValueStat() = default;
};