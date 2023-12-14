class ScreenPrintStrategy : public PrintStrategy {
public:
    void print(const Document& document) override {
        std::cout << document.get() << std::endl;
    }
};

class StringPrintStrategy : public PrintStrategy {
    std::string bufer = "";
    int num = 1;
public:
    void print(const Document& document) override {
        bufer += "--- doc " + std::to_string(num) + " ---\n" + document.get() + "\n";
        num++;
    }
    std::string getPrintedDocuments() const {
        return bufer;
    }
};

class MockPrintStrategy : public PrintStrategy {
    int count = 0;
public:
    void print(const Document& document) override {
        count++;
    }
    int getPrintedDocumentsCount() const {
        return count;
    }
};