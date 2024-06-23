#include "ProgressBar.h"
#include <iostream>
#include <algorithm>

ProgressBar::ProgressBar(int minValue, int maxValue, char placeholder)
    : minValue(minValue), maxValue(maxValue), currentValue(minValue), placeholder(placeholder) {}

void ProgressBar::setMinValue(int minValue) {
    this->minValue = minValue;
    if (currentValue < minValue) {
        currentValue = minValue;
    }
}

void ProgressBar::setMaxValue(int maxValue) {
    this->maxValue = maxValue;
    if (currentValue > maxValue) {
        currentValue = maxValue;
    }
}

void ProgressBar::setCurrentValue(int currentValue) {
    this->currentValue = std::clamp(currentValue, minValue, maxValue);
}

void ProgressBar::setPlaceholder(char placeholder) {
    this->placeholder = placeholder;
}

void ProgressBar::display() const {
    int progress = calculateProgress();
    std::cout << "\033[?25l";
    std::cout << "\r[";

    for (int i = 0; i < progress; ++i) {
        std::cout << placeholder;
    }
    for (int i = progress; i < 100; ++i) {
        std::cout << " ";
    }
    std::cout << "] " << progress << "%" << std::flush;
    std::cout << "\033[?25h";
}

int ProgressBar::calculateProgress() const {
    if (maxValue == minValue) {
        return 100;
    }
    return (static_cast<double>(currentValue - minValue) / (maxValue - minValue)) * 100;
}
