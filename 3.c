// Объявление переменных password, length, upper, lower, digit, other и i
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
char password[15];
int length, upper, lower, digit, other, i;

// Запрос пароля у пользователя
printf("Введите пароль: ");
scanf("%s", password);

// Проверка длины пароля
length = strlen(password);
if (length < 8 || length > 14) {
    printf("Пароль должен быть не короче 8 символов и не длиннее 14\n");
    return 0;
}

// Проверка наличия различных классов символов
upper = lower = digit = other = 0; // объявляем и инициализируем переменные
for (i = 0; i < length; i++) {
    if (isupper(password[i])) { // проверяем символ на наличие возводимым в верхний регистр
        upper = 1; // если есть символы в верхнем регистре, то upper становится равным 1
    } else if (islower(password[i])) { // проверяем символ на наличие возводимым в нижний регистр
        lower = 1; // если есть символы в нижнем регистре, то lower становится равным 1
    } else if (isdigit(password[i])) { // проверяем символ на наличие цифры
        digit = 1; // если есть цифры, то digit становится равным 1
    } else if (password[i] >= 33 && password[i] <= 126) { // проверяем символ на принадлежность к символьному классу ASCII
        other = 1; // если есть символы из ASCII, то other становится равным 1
    } else {
        printf("Некорректные символы в пароле\n"); // если найдены символы, не принадлежащие ни одному классу, выводится сообщение о некорректности символов
        return 0;
    }
}
if (upper + lower + digit + other < 3) { // проверяем, есть ли символы из трех разных классов
    printf("Пароль должен содержать  большие буквы, маленькие буквы, цифры\n");
    return 0;
}

// Если пароль прошел все проверки, выводим сообщение о том, что пароль принят
printf("пароль принят\n");
return 0;
