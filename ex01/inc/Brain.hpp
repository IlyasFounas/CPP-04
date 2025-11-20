#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    public:
        Brain();
        Brain(const Brain &copy);
        ~Brain();
        Brain &operator=(const Brain &copy);

        void add(const std::string idea);
        std::string get(int nbIndex);

    private:
        int index;
        std::string ideas[100];
} ;

#endif