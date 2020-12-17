#include "Elections.h"

Elections::Elections(std::string fullname, std::string birthDate, std::string work, const std::string &rating) {
    this->fullName = std::move(fullname);
    this->birthDate = std::move(birthDate);
    this->work = std::move(work);
    this->rating = std::stod(rating);
}

double Elections::getRating() const {
    return rating;
}

std::string Elections::getBirthDate() {
    return birthDate;
}

std::string Elections::getWork() {
    return work;
}

std::string Elections::getFullName() {
    return fullName;
}

bool Elections::operator<(const Elections &e) {
    if (rating > e.rating) {
        return true;
    } else {
        if (rating == e.rating && fullName > e.fullName) {
            return true;
        } else {
            if (rating == e.rating && fullName == e.fullName && work > e.work) {
                return true;
            } else {
                if (rating == e.rating && fullName == e.fullName && work == e.work && birthDate > e.birthDate) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::string Elections::toString() {
    return "Elections { "
           "fullName: '" + fullName +
           "', birthDate: '" + birthDate +
           "', work: '" + work +
           "', rating: '" + std::to_string(rating) +
           "' }";
}
