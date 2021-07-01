#pragma once

#include <string>
#include <ostream>

class PrintJob {
    public:
        PrintJob(int timestamp, int pages, const std::string& title);
        int getPages() const;
        bool operator<(const PrintJob&) const;
        bool operator>(const PrintJob&) const;
        bool operator==(const PrintJob&) const;
        friend std::ostream& operator<<(std::ostream& os, const PrintJob& job);
    private:
        int nPages;
        int timestamp;
        std::string title;
};

std::ostream& operator<<(std::ostream& os, const PrintJob& job);
