#include "Printer.h"

#include <numeric>


Printer::Printer(int maxNumJobs, int maxNumPages) 
    : maxNumJobs{maxNumJobs}, maxNumPages{maxNumPages} {}

int Printer::queueLength() const {
    return jobs.size();
}

int Printer::queuePages() const {
    return std::accumulate(jobs.begin(), jobs.end(), 0, [](int lhs, const PrintJob& job){
        return lhs + job.getPages();
    });
}

bool Printer::isEmpty() const {
    return jobs.empty();
}

bool Printer::isFull() const {
    return queueLength() >= maxNumJobs || queuePages() >= maxNumPages;
}

PrintJob Printer::next() {
    PrintJob top = jobs.at(0);

    // replace the root of the heap with the last element (and remove it)
    jobs[0] = jobs.back();
    jobs.pop_back();
 
    // call heapify-down on the root node
    heapify_down(0);

    return top;
}

bool Printer::push(const PrintJob& dato, bool force) {
    // Insert at the end:
    jobs.push_back(dato);
 
    // Get element index and call heapify-up procedure
    int index = jobs.size() - 1;
    heapify_up(index);
    return true;
}

int Printer::parent(int index) const {
    return (index-1) / 2;
}

int Printer::left(int index) const {
    return (index*2 + 1);
}

int Printer::right(int index) const {
    return (index*2 + 2);
}

// Recursive heapify-up algorithm
void Printer::heapify_up(int i) {
    if (i == 0) { return;}
 
    // check if the node at index `i` and its parent violate the heap property
    if (jobs.at(parent(i)) > jobs.at(i)) {
        // swap the two if heap property is violated
        std::swap(jobs[i], jobs[parent(i)]);
 
        // call heapify-up on the parent
        heapify_up(parent(i));
    }
}

// Recursive heapify-down algorithm.
void Printer::heapify_down(int i)
{
    // get left and right child of node at index `i`
    int idx_left = left(i);
    int idx_right = right(i);
 
    // Identify lowest element
    int idx_lowest = i;
    if (idx_left < jobs.size() && jobs.at(idx_lowest) > jobs.at(idx_left)) {
        idx_lowest = idx_left;
    }
    if (idx_right < jobs.size() && jobs.at(idx_lowest) > jobs.at(idx_right)) {
        idx_lowest = idx_right;
    }
 
    // swap with a child having lowest value and
    // call heapify-down on the child
    if (idx_lowest != i)
    {
        std::swap(jobs[i], jobs[idx_lowest]);
        heapify_down(idx_lowest);
    }
}
