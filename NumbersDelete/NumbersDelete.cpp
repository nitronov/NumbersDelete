

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Открывает файлы для чтения и записи
    ifstream in1("input.txt");
    ofstream out1("input.txt.tmp");
    ifstream in2("input2.txt");
    ofstream out2("input2.txt.tmp");

    // чтение числа из первого файла и записывает нечетные во временный файл
    int num;
    while (in1 >> num) {
        if (num % 2 != 0) {
            out1 << num << " ";
        }
    }

    // Закрывает первый файл и временный файл
    in1.close();
    out1.close();

    // Переименовывает временный файл в первый файл
    remove("input.txt");
    rename("input.txt.tmp", "input.txt");

    // Читает числа из второго файла и записывает нечетные во временный файл
    while (in2 >> num) {
        if (num % 2 != 0) {
            out2 << num << " ";
        }
    }

    // Закрывает второй файл и временный файл
    in2.close();
    out2.close();

    // Переименовывает временный файл во второй файл
    remove("input2.txt");
    rename("input2.txt.tmp", "input2.txt");

    return 0;
}
// Думал сделать вывод результата сразу в терминал, но в условии требуется записать результат в текстовом файле, так же там не оговаривается в какой именно текстовый файл выводить результат - в тот же где даны числа с условия задачи или в отдельный файл output.txt. Сделал вывод результата в те же файлы (перезапись)