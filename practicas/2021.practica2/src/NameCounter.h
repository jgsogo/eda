#pragma once

#include <string>
#include <functional>

#include "Queue.h"

struct NameCount {
    int repeats;
    std::string name;
};

class ElementListaSimple {
    public:
        NameCount dato;
        std::shared_ptr<ElementListaSimple> next = nullptr;
    public:
        ElementListaSimple(const NameCount& dato_);
};

class NameCounter {
    public:
        NameCounter();

        void add_name(const std::string& name);
        void sort();
        void for_each(std::function<void (const NameCount&)> action) const;
    private:
	int size() const;
        NameCount& at(int pos) const;
        void push_back(const NameCount& dato);
    protected:
        std::shared_ptr<ElementListaSimple> front = nullptr;
};

NameCounter count_names(Queue& joy_slava);
