#include "PrintJob.h"


PrintJob::PrintJob(int timestamp, int pages, const std::string& title) 
    : nPages{pages}, timestamp{timestamp}, title{title} {}

int PrintJob::getPages() const {
    return nPages;
}

bool PrintJob::operator<(const PrintJob& other) const {
    if (nPages == other.nPages) {
        return timestamp < other.timestamp;
    }
    return nPages < other.nPages;
}

bool PrintJob::operator>(const PrintJob& other) const {
    if (nPages == other.nPages) {
        return timestamp > other.timestamp;
    }
    return nPages > other.nPages;
}

bool PrintJob::operator==(const PrintJob& other) const {
    return (nPages == other.nPages) && (timestamp == other.timestamp);
}


std::ostream& operator<<(std::ostream& os, const PrintJob& job) {
    os << "PrintJob:" << std::endl;
    os << " - timestamp: " << job.timestamp << std::endl;
    os << " - title:     " << job.title << std::endl;
    os << " - pages:     " << job.nPages << std::endl;
    return os;
}