#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

namespace {

double readMark(const std::string& prompt, double maximum) {
    double mark{};
    while (true) {
        std::cout << prompt << " (0-" << maximum << "): ";
        if (std::cin >> mark && mark >= 0.0 && mark <= maximum) {
            return mark;
        }

        std::cout << "Please enter a valid number between 0 and "
                  << maximum << ".\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::string letterGrade(double percentage) {
    if (percentage >= 90.0) return "A+";
    if (percentage >= 80.0) return "A";
    if (percentage >= 70.0) return "B";
    if (percentage >= 60.0) return "C";
    if (percentage >= 50.0) return "D";
    return "F";
}

}  // namespace

int main() {
    std::cout << "Weighted Grade Calculator\n"
              << "Enter the marks for the assessment components.\n\n";

    std::array<double, 4> quizzes{};
    std::array<double, 4> assignments{};

    for (std::size_t i = 0; i < quizzes.size(); ++i) {
        quizzes[i] = readMark("Quiz " + std::to_string(i + 1), 10.0);
    }

    for (std::size_t i = 0; i < assignments.size(); ++i) {
        assignments[i] = readMark("Assignment " + std::to_string(i + 1), 10.0);
    }

    const double lab = readMark("Lab", 20.0);
    const double midterm = readMark("Midterm", 25.0);
    const double finalExam = readMark("Final exam", 40.0);

    double quizAverage = 0.0;
    double assignmentAverage = 0.0;
    for (double mark : quizzes) quizAverage += mark;
    for (double mark : assignments) assignmentAverage += mark;
    quizAverage /= static_cast<double>(quizzes.size());
    assignmentAverage /= static_cast<double>(assignments.size());

    // The original coursework weights are preserved: 10/10/20/20/40 percent.
    const double weightedPercentage =
        (quizAverage / 10.0 * 100.0 * 0.10) +
        (assignmentAverage / 10.0 * 100.0 * 0.10) +
        (lab / 20.0 * 100.0 * 0.20) +
        (midterm / 25.0 * 100.0 * 0.20) +
        (finalExam / 40.0 * 100.0 * 0.40);

    const std::string grade = letterGrade(weightedPercentage);

    std::cout << std::fixed << std::setprecision(2)
              << "\nWeighted percentage: " << weightedPercentage << "%\n"
              << "Letter grade: " << grade << "\n";

    std::ofstream results("results.txt", std::ios::app);
    if (!results) {
        std::cerr << "Warning: could not open results.txt; the result was not saved.\n";
        return 1;
    }
    results << std::fixed << std::setprecision(2)
            << "Weighted percentage: " << weightedPercentage << "%\n"
            << "Letter grade: " << grade << "\n"
            << "------------------------------\n";

    std::cout << "Result appended to results.txt.\n";
    return 0;
}
