#pragma once

#include <vector>
#include "PrintJob.h"

class Printer {
    public:
        Printer(int maxNumJobs, int maxNumPages);

        int queueLength() const;
        int queuePages() const;
        bool isEmpty() const;
        bool isFull() const;

        PrintJob next();
        bool push(const PrintJob& dato, bool force = false);

    protected:
        void heapify_down(int i);
        void heapify_up(int i);

        int parent(int index) const;
        int left(int index) const;
        int right(int index) const;

        void insert(const PrintJob& dato);
    protected:
        std::vector<PrintJob> jobs;
        int maxNumJobs;
        int maxNumPages;
};
