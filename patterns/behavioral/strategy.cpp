

#include <iostream>
#include <string>
#include <algorithm>


// The Strategy interface
class Strategy {
public:
    virtual ~Strategy() {}


    virtual std::string doAlgorithm(const std::string& data) const = 0;
};


// Concrete strategies
class UppercaseStrategy : public Strategy {
public:
    std::string doAlgorithm(const std::string& data) const override {
        std::string result(data);
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};


class ReverseStrategy : public Strategy {
public:
    std::string doAlgorithm(const std::string& data) const override {
        std::string result(data);
        std::reverse(result.begin(), result.end());
        return result;
    }
};


class IdentityStrategy : public Strategy {
public:
    std::string doAlgorithm(const std::string& data) const override {
        return data;
    }
};


// Context class
class Context {
private:
    const Strategy* strategy;  // Raw pointer, not owning


public:
    Context() : strategy(nullptr) {}


//Context() {
  //  strategy = nullptr;
//}




    void setStrategy(const Strategy* strat) {
        strategy = strat;
    }


    void executeStrategy(const std::string& input) const {
        if (strategy) {
            std::cout << "Result: " << strategy->doAlgorithm(input) << '\n';
        } else {
            std::cout << "No strategy set.\n";
        }
    }
};


int main() {
    Context context;


    UppercaseStrategy upper;
    ReverseStrategy reverse;
    IdentityStrategy identity;


    context.setStrategy(&upper);
    context.executeStrategy("hello world");  // HELLO WORLD


    context.setStrategy(&reverse);
    context.executeStrategy("hello world");  // dlrow olleh


    context.setStrategy(&identity);
    context.executeStrategy("hello world");  // hello world


    return 0;
}
