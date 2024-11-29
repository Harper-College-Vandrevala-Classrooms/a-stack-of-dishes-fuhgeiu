#include <cassert>
#include "simple_stack.hpp"


class Dish {
private:
    std::string description;

public:
    Dish(std::string description) {
        this->description = description;
    }

    std::string get_description() {
        return this->description;
    }
};


int main () {

    // stack intiilize
//    stack<Dish> mystack1;

    contdynamic<Dish> vector1;




    // empty



    // to get size/number of elements

    // pushback

    // popback

    // peek




}