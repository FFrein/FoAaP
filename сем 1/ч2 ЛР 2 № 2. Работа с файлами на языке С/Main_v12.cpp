#include <fstream>
#include <stdio.h>
#include <iostream>
int main()
{
    using namespace std;
    setlocale(LC_ALL, "");
    int elements, elements2, elements3;
    errno_t errNameA;
    FILE* NameA;
    errNameA = fopen_s(&NameA, "NameA.txt", "w");
    if (errNameA != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    printf("Введите кол символов\n");
    cin >> elements;
    elements2 = elements3 = elements;
    fprintf(NameA, "%d\n", elements3);

    int* massiveA;
    srand((unsigned)time(NULL));
    massiveA = new int [elements];
    for (int numb = 0; numb < elements; numb++) {
            massiveA[numb] = rand() % 10;
            fprintf(NameA, "%d ", massiveA[numb]);
    }

    fclose(NameA);

    errno_t errNameB;
    FILE* NameB;
    errNameB = fopen_s(&NameB, "NameB.txt", "w");
    if (errNameB != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    fprintf(NameB, "%d\n", elements2);
    for (int numb = 0; numb < elements; numb++) {
        massiveA[numb] = rand() % 10;
        fprintf(NameB, "%d ", massiveA[numb]);
    }
    fclose(NameB);


    errno_t errNameC;
    FILE* NameC;
    errNameC = fopen_s(&NameC, "NameC.txt", "w");
    if (errNameC != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    fprintf(NameC, "%d\n", elements);
    for (int numb = 0; numb < elements; numb++) {
        massiveA[numb] = rand() % 10;
        fprintf(NameC, "%d ", massiveA[numb]);
    }
    fclose(NameC);
    // 2 независамая часть

    ifstream input_one("NameA.txt");
    ifstream input_two("NameB.txt");
    ifstream input_three("NameC.txt");
    int elements21, elements22, elements23;
    float ch_one, ch_two, ch_three;
    int Count_one = 0, Count_two = 0, Count_three = 0;
    while (input_one >> ch_one)
        Count_one++;
    while (input_two >> ch_two)
        Count_two++;
    while (input_three >> ch_three)
        Count_three++;
    cout << "Чисел в файле 1 : " << Count_one << endl;
    cout << "Чисел в файле 2 : " << Count_two << endl;
    cout << "Чисел в файле 3 : " << Count_three << endl;
    input_one.close();
    input_two.close();
    input_three.close();

    ifstream file_one("NameA.txt");
    file_one >> elements21; 

    cout << "Количество эллементов в файлe 1 = " << elements21 << endl;
    int* massive_one = new int[Count_one];
    for (int i = 0; i < (Count_one - 1); i++) {
        file_one >> massive_one[i];
        fprintf(NameA, "%d ", massive_one[i]);
    }
    fclose(NameA);

    ifstream file_two("NameB.txt");
    file_two >> elements22;

    cout << "Количество эллементов в файлe 1 = " << elements22 << endl;
    int* massive_two = new int[Count_two];
    for (int i = 0; i < (Count_two - 1); i++) {
        file_two >> massive_two[i];
        fprintf(NameB, "%d ", massive_two[i]);
    }
    fclose(NameB);

    ifstream file_three("NameC.txt");
    file_three >> elements23;

    cout << "Количество эллементов в файлe 1 = " << elements23 << endl;
    int* massive_three = new int[Count_three];
    for (int i = 0; i < (Count_three - 1); i++) {
        file_three >> massive_three[i];
        fprintf(NameC, "%d ", massive_three[i]);
    }
    fclose(NameC);

    /*Создание файла*/

    errno_t errNameFinal;
    FILE* Final;

    errNameFinal = fopen_s(&Final, "NameFinal.txt", "w");
    if (errNameFinal != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    // где то ошибка, или в массивах записи или в сравнении
    int max = 0;
    for (int i = 0; i < (Count_one - 1); i++) {
        for (int g = 0; g < 2; g++) {
            if (max < massive_one[i]) {
                max = massive_one[i];
            }
            if (max < massive_two[i]) {
                max = massive_two[i];
            }
            if (max < massive_three[i]) {
                max = massive_three[i];
            }
            
        }
     
        fprintf(Final, "%d ", max);
        max = 0;
    }
    cout << endl;
    fclose(Final);
    printf("Данные записаны в файл Final.txt\n");

    return 0;
}