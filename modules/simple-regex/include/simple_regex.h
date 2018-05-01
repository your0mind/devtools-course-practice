// Copyright 2018 Kiselev Denis

// Класс позволяет использовать упрощенные регулярные
// выражения. Доступны следующие метасимволы:
// "\\d" - любая цифра
// "\\D" - любой символ кроме цифр
// "\\w" - любая цифра, любая буква (в диапазонах a-z, A-Z) и символ "земли"
// "\\W" - любой символ кроме символов, включенных в "\\w"

#ifndef MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_
#define MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_

class SimpleRegex {
 public:
    SimpleRegex(const char* regex);
 
    const char* getRegex() const;
    void  setRegex(const char* regex);

    bool isMatch(const char* str);
    void getMatch(char* buffer, size_t size);
    int getMatchIndex() const;

 private: 
    const char* regex_;
    const char* str_;
    int matchBegin_;
    int matchEnd_;
};

#endif  // MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_
