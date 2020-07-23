#ifndef __VETERANDECORATOR_HPP__
#define __VETERANDECORATOR_HPP__

#include "../base.hpp"

class VeteranDecorator : public Base {
        private:
                Base* b;
        public:
                VeteranDecorator(Base* b){this->b = b;}
                virtual double price(){return b->price() - (0.2 * b->price());}
                virtual std::string receipt(){return "Veteran Order:\n" + b->receipt();}
};

#endif // __VETERANDECORATOR_HPP__
