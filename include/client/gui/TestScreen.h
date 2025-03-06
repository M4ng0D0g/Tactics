
class TestScreen {
private:
	TestScreen(){}
public:
	TestScreen(const TestScreen&) = delete;
	TestScreen& operator=(const TestScreen&) = delete;

	static TestScreen& getInstance() {
		static TestScreen instance;
		return instance;
	}

	virtual void open() {}
};