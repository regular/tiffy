#include <functional>
#include <vector>

template<typename... Args>
class LambdaList {
public:
    using Lambda = std::function<void(Args...)>;

    void addLambda(Lambda lambda) {
        lambdaList.push_back(lambda);
    }

    void invokeAll(Args... args) {
        for (const auto& lambda : lambdaList) {
            lambda(args...);
        }
    }

private:
    std::vector<Lambda> lambdaList;
};

/*
int main() {
    LambdaList<int> myList;

    // Adding lambdas to the list
    myList.addLambda([](int x) {
        std::cout << "Lambda 1: " << x << std::endl;
    });

    myList.addLambda([](int x) {
        std::cout << "Lambda 2: " << x * 2 << std::endl;
    });

    myList.addLambda([](int x) {
        std::cout << "Lambda 3: " << x + 10 << std::endl;
    });

    // Invoking all the lambdas sequentially
    myList.invokeAll(5);

    return 0;
}
*/
