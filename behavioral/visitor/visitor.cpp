/**
 * @file visitor.cpp
 * @author Tanner Broaddus (broaddustanner@gmail.com)
 * @brief Demonstrates the visitor pattern
 *
 */
#include <iostream>
#include <vector>

class WheelElement;
class EngineElement;
class BodyElement;

// Beginning of operational hierarchy
class CarElementVisitor
{
    public:
        virtual void visit(WheelElement&) = 0;
        virtual void visit(EngineElement&) = 0;
        virtual void visit(BodyElement&) = 0;
};

// Beginning of object hierarchy
class CarElement
{
    public:
        virtual void accept(CarElementVisitor& r_visitor) = 0;
};

class WheelElement : public CarElement
{
    public:
        void accept(CarElementVisitor& r_visitor) override
        {
            r_visitor.visit(*this);
        }
};

class EngineElement : public CarElement
{
    public:
        void accept(CarElementVisitor& r_visitor) override
        {
            r_visitor.visit(*this);
        }
};

class BodyElement : public CarElement
{
    public:
        void accept(CarElementVisitor& r_visitor) override
        {
            r_visitor.visit(*this);
        }
};

class CarElementPrintVisitor : public CarElementVisitor
{
    public:
        void visit(WheelElement& r_wheel_element)
        {
            std::cout << "This is a wheel element" << std::endl;
        }

        void visit(EngineElement& r_engine_element)
        {
            std::cout << "This is an engine element" << std::endl;
        }

        void visit(BodyElement& r_body_element)
        {
            std::cout << "This is a body element" << std::endl;
        }
};

int main(int argc, char** argv)
{
    std::vector<CarElement*> car_element_ptr_vec;
    car_element_ptr_vec.push_back(new WheelElement());
    car_element_ptr_vec.push_back(new EngineElement());
    car_element_ptr_vec.push_back(new BodyElement());
    CarElementPrintVisitor visitor;

    for (auto& r_car_element_ptr : car_element_ptr_vec)
    {
        r_car_element_ptr->accept(visitor);
    }

    return 0;
}
