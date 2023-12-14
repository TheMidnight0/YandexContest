class GreaterAdapter : public IComparator {
    using func = void (*)(int a, int b, bool& verdict);
    func cmp;
public:
    GreaterAdapter(func cmp) : cmp(cmp) {
    }

    bool compare(int a, int b) const override {
        bool verdict;
        cmp(a, b, verdict);
        return verdict;
    }
};

class KeyFuncLessAdapter : public IComparator {
    using func = double (*)(int value);
    func cmp;
public:
    KeyFuncLessAdapter(func cmp) : cmp(cmp) {
    }

    bool compare(int a, int b) const override {
        return cmp(a) < cmp(b);
    }
};