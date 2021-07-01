#include <iostream>
#include <fstream>

#include "src/PrintJob.h"
#include "src/Printer.h"

int main() {
    Printer printer{20, 1000};

    std::ifstream input{"../jobs.txt"};
    if (input.is_open()) {
        std::string line;
        int timestamp, pages;
        while (std::getline(input,line)) {
            int found = line.find(' ');
            int timestamp = std::stoi(line.substr(0, found));
            
            int found2 = line.find(' ', found+1);
            int pages = std::stoi(line.substr(found+1, found2));

            PrintJob job{timestamp, pages, line.substr(found2+1)};
            bool inserted = printer.push(job, true);
            if (!inserted) {
                std::cout << "Failed to insert " << line << std::endl;
            }
        }
        input.close();
    }
    else {
        std::cout << "Unable to open file";
    }

    // Show me all the jobs
    std::cout << "\n\nAll jobs:" << std::endl;
    while (!printer.isEmpty()) {
        std::cout << printer.next();
    }
}
