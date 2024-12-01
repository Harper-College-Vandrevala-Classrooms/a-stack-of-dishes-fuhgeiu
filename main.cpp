#include <cassert>
#include "classcustvar_template.hpp"


class Dish {
private:
    std::string description;

public:
    Dish(std::string description) {
        this->description = description;
    }

    const std::string& get_description() const {
        return this->description;
    }
};


template <typename C>
class stack : public cstd::contdynamic<C> {

public:



};


int main () {

    // stack intiilize
//    stack<Dish> mystack1;
/*
 *      !!!WARNING, USING OBJECT POINTERS WILL PRODUCE UNDEFINED BAHVAIOR!!!
 *
 *      only use user defiend and primitive types
 *
 */

    cstd::contdynamic<Dish> cont1;

    Dish dish1("ugly");
    Dish dish2("pretty");
    Dish dish3("heavy");
    Dish dish4("light");

    cont1.append(dish1);
    cont1.append(dish2);
    cont1.append(dish3);
    cont1.append(dish4);

    assert(cont1[0].get_description() == "ugly");
    assert(cont1[1].get_description() == "pretty");
    assert(cont1[2].get_description() == "heavy");
    assert(cont1[3].get_description() == "light");

    cont1.popback();
    cont1.popback();


    // using derived class stack

    stack<Dish> dishes;

    dishes.append(dish1);

    dishes.append(dish2);

    dishes.append(dish3);

    dishes.append(dish4);

    assert(dishes[0].get_description() == "ugly");
    assert(dishes[1].get_description() == "pretty");
    assert(dishes[2].get_description() == "heavy");
    assert(dishes[3].get_description() == "light");

    assert(dishes.peek().get_description() == "light");

    dishes.popback();
    dishes.popback();

    // this will produce error, as we poped back
//    assert(dishes[2].get_description() == "heavy");
//    assert(dishes[3].get_description() == "light");

    assert(dishes.length() == 2);        // we popped back so size(number of used elements in container) = 2

    assert(dishes.peek().get_description() == "pretty");


}