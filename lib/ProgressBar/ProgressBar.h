#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <string>

class ProgressBar {
public:
    ProgressBar(int minValue = 0, int maxValue = 100, char placeholder = '#');
    void setMinValue(int minValue);
    void setMaxValue(int maxValue);
    void setCurrentValue(int currentValue);
    void setPlaceholder(char placeholder);
    void display() const;

private:
    int minValue;
    int maxValue;
    int currentValue;
    char placeholder;
    int calculateProgress() const;
};

#endif // PROGRESSBAR_H
