#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ones[] = { "", "один", "два", "три", "четыре", "пять",
                 "шесть", "семь", "восемь", "девять", "десять",
                 "одиннадцать", "двенадцать", "тринадцать", "четырнадцать",
                 "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };

string tens[] = { "", "", "двадцать", "тридцать", "сорок", "пятьдесят",
                 "шестьдесят", "семьдесят", "восемьдесят", "девяносто" };

string hundreds[] = { "", "сто", "двести", "триста", "четыреста",
                     "пятьсот", "шестьсот", "семьсот", "восемьсот", "девятьсот" };

string rubleWord(int n) {
    if (n % 10 == 1 && n % 100 != 11) return "рубль";
    if (n % 10 >= 2 && n % 10 <= 4 && !(n % 100 >= 12 && n % 100 <= 14)) return "рубля";
    return "рублей";
}

string kopekWord(int n) {
    if (n % 10 == 1 && n % 100 != 11) return "копейка";
    if (n % 10 >= 2 && n % 10 <= 4 && !(n % 100 >= 12 && n % 100 <= 14)) return "копейки";
    if (n % 10 == 0 && n % 100 == 0) return "ноль копеек";
    return "копеек";
}

string numberToText(int n) {
    string result;
    if (n >= 100) {
        result += hundreds[n / 100] + " ";
        n %= 100;
    }
    if (n >= 20) {
        result += tens[n / 10] + " ";
        n %= 10;
    }
    if (n > 0) {
        result += ones[n] + " ";
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double R;
    cout << "Введите сумму (0.0 < R < 999999.99): ";
    cin >> R;

    int rub = static_cast<int>(R);
    int kop = round((R - rub) * 100);

    string text;
    if (rub >= 1000) {
        text += numberToText(rub / 1000);
        text += "тысяча ";
        rub %= 1000;
    }
    text += numberToText(rub);
    text += rubleWord(rub) + " ";

    text += numberToText(kop);
    text += kopekWord(kop);

    cout << text << endl;

    return 0;
}