#pragma once

#include <vector>
#include "Avion.h"


class PriorityQueue {
    public:
        PriorityQueue();

        int size() const;
        bool empty() const;

        const Avion& top() const;

        void push(const Avion& dato);
        void pop();

    private:
        // This functions are private
        void heapify_down(int i);
        void heapify_up(int i);
        int parent(int index) const;
        int left(int index) const;
        int right(int index) const;

    private:
        std::vector<Avion> _data;
};
