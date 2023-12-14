#include <vector>

class OSUpdater: public IRunnable {
public:
    void run() override {
        std::cout << "OSUpdater";
    }
};

class Alarm : public IRunnable {
public:
    void run() override {
        std::cout << "Alarm";
    }
};

class ActivityChecker : public IRunnable {
public:
    void run() override {
        std::cout << "ActivityChecker";
    }
};

class Clock : public IClock, public IRunnable {
public:
    void run() override {
        while (saved.size() != 0) {
            next();
        }
    }
    void add(IRunnable* client, Time time) override {
        saved.push_back(std::make_pair(time, client));
    }
    bool next() override {
        if (saved.size() != 0) {
            if (saved[0].first.hours < 10) {
                std::cout << "0" << saved[0].first.hours << ":";
            }
            else {
                std::cout << saved[0].first.hours << ":";
            }
            if (saved[0].first.minutes < 10) {
                std::cout << "0" << saved[0].first.minutes << ":";
            }
            else {
                std::cout << saved[0].first.minutes << ":";
            }
            if (saved[0].first.seconds < 10) {
                std::cout << "0" << saved[0].first.seconds << " ";
            }
            else {
                std::cout << saved[0].first.seconds << " ";
            }
            saved[0].second->run();
            std::cout << std::endl;
            saved.erase(saved.begin());
            return true;
        }
        else {
            return false;
        }
    }
private:
    std::vector<std::pair<Time, IRunnable*>> saved;
};
