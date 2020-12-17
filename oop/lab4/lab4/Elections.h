#pragma once
#include <string>

class Elections {
private:
    std::string fullName;
    std::string birthDate;
    std::string work;
    double rating;
public:
    Elections(std::string fullname, std::string birthDate, std::string work, const std::string &rating);

    std::string toString();

    bool operator<(const Elections &e);

    std::string getFullName();

    std::string getWork();

    std::string getBirthDate();

    double getRating();
};
