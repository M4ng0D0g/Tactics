class IStats {
protected:
    //int defaultValue;
    int value;
    //可以實作valueMap 用來儲存特殊狀態 -> 交給子類
    int upperLimit;
    int lowerLimit;
public:
    //getter
    //virtual int getDefault() { return defaultValue; }
    virtual int getValue() { return value; }
    virtual int getUpperLimit() { return upperLimit; }
    virtual int getLowerLimit() { return lowerLimit; }

    //setter
    /*virtual void setDefault(int newDefault) {
        defaultValue = newDefault;
    }*/
    virtual void addValue(int val) {
        value += val;
    }
    virtual void removeValue(int val) {
        value -= val;
    }
    virtual void setValue(int newValue) {
        value = newValue;
    }
    /*virtual void resetValue() {
        value = defaultValue;
    }*/
    virtual void setUpperLimit(int newUpperLimit) {
        upperLimit = newUpperLimit;
    }
    virtual void setLowerLimit(int newLowerLimit) {
        lowerLimit = newLowerLimit;
    }
    virtual void correct() {
        if(value < lowerLimit) value = lowerLimit;
        if(value > upperLimit) value = upperLimit;
    }

    //logic
    virtual bool isDepleted() { return (value <= lowerLimit); };
    virtual bool isFull() { return (value == upperLimit); };
    virtual bool isExceed() { return (value > upperLimit); };
    virtual bool isEnough(int requirement) { return (value >= requirement); };

    //distructor
    virtual ~IStats() = default;
};