#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name) {
    if (!checkGrade(grade)) {
        throw;
    }
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    this->grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (!checkGrade(grade - 1)) {
        throw;
    }
    grade--;
}

void Bureaucrat::decrementGrade() {
    if (!checkGrade(grade + 1)) {
        throw;
    }
    grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

bool Bureaucrat::checkGrade(int grade) const {
    if (grade < 1) {
        throw GradeTooHighException();
        return false;
    } else if (grade > 150) {
        throw GradeTooLowException();
        return false;
    }
    return true;
}

void Bureaucrat::signForm(Form& form) {
    if (form.beSigned(*this)) {
        std::cout << name << " signed " << form.getName() << std::endl;
    } else {
        std::cout << name << " couldn't sign " << form.getName() << " because ";
        throw GradeTooLowException();
    }
}