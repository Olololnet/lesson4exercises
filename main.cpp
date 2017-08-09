#include <iostream>
#include <cstdlib> // only for std::srand
#include <ctime>   // only for std::srand

bool IsMatrixWinning(int* szMatrix3x3)
{
    // UL UC UR     0 1 2
    // CL CC CR     3 4 5
    // DL DC DR     6 7 8

    const int iUL = 0, iUC = 1, iUR = 2;
    const int iCL = 3, iCC = 4, iCR = 5;
    const int iDL = 6, iDC = 7, iDR = 8;

    int iDiagonalSumULDR = szMatrix3x3[iUL] + szMatrix3x3[iCC] + szMatrix3x3[iDR];
    int iDiagonalSumDLUR = szMatrix3x3[iDL] + szMatrix3x3[iCC] + szMatrix3x3[iUR];

    if ((!iDiagonalSumULDR) || (iDiagonalSumULDR == 3) || (!iDiagonalSumDLUR) || (iDiagonalSumDLUR == 3))
        return true;

    int iHorizontal1 = szMatrix3x3[iUL] + szMatrix3x3[iUC] + szMatrix3x3[iUR];
    int iHorizontal2 = szMatrix3x3[iCL] + szMatrix3x3[iCC] + szMatrix3x3[iCR];
    int iHorizontal3 = szMatrix3x3[iDL] + szMatrix3x3[iDC] + szMatrix3x3[iDR];

    if ((!iHorizontal1) || (iHorizontal1 == 3) || (!iHorizontal2) || (iHorizontal2 == 3) || (!iHorizontal3) || (iHorizontal3 == 3))
        return true;

    int iVertical1 = szMatrix3x3[iUL] + szMatrix3x3[iCL] + szMatrix3x3[iDL];
    int iVertical2 = szMatrix3x3[iUC] + szMatrix3x3[iCC] + szMatrix3x3[iDC];
    int iVertical3 = szMatrix3x3[iUR] + szMatrix3x3[iCR] + szMatrix3x3[iDR];

    if ((!iVertical1) || (iVertical1 == 3) || (!iVertical2) || (iVertical2 == 3) || (!iVertical3) || (iVertical3 == 3))
        return true;

    return false;
}

void Exercise9()
{
    // дана матрица 3х3 (аналог игры "Крестики-Нолики"). Требуется определить, имеется ли победитель в данной партии
    // 1 0 1            0 0 1
    // 0 1 0    - Да.   1 0 0   - Нет.
    // 1 0 0            0 1 1

    const int iMatrixSize = 9;
    int* szMatrix3x3 = new int[iMatrixSize];
    int iInput = 0;

    std::cout << "Please enter matrix 3x3, using only 0 or 1" << std::endl;

    std::cout << "Example: " << std::endl << std::endl;
    std::cout << "0 1 0 \n0 1 1 \n1 1 1" << std::endl << std::endl;

    std::cout << "Now enter the matrix to check, is it winning: " << std::endl << std::endl;

    for (int i = 0; i < 9; i++)
    {
        std::cin >> iInput;

        if (iInput == 0 || iInput == 1)
            szMatrix3x3[i] = iInput;
        else
        {
            std::cout << "Wrong input, number can be only 0 or 1" << std::endl;
            return;
        }
    }

    if (IsMatrixWinning(szMatrix3x3))
        std::cout << std::endl << "Winning" << std::endl;
    else
        std::cout << std::endl << "Not winning" << std::endl;
}

void DisplayArrays(int* szArrayA, int* szArrayB, int iElementCount)
{
    for (int i = 0; i < iElementCount; i++)
    {
        std::cout << szArrayA[i] << " ";
    }

    std::cout << std::endl;

    for (int i = 0; i < iElementCount; i++)
    {
        std::cout << szArrayB[i] << " ";
    }
}

void FindInputSum(int* szArrayA, int* szArrayB, int iElementCount, int iInput)
{
    bool bIndexesFound = false;
    int  iCurrentIndex = 0;

    while(iCurrentIndex <= iElementCount && !bIndexesFound)
    {
        for (int i = iCurrentIndex; i < iElementCount; i++)
        {
            if (szArrayA[iCurrentIndex] + szArrayB[i] == iInput)
            {
                std::cout << "Element from first array: "  << szArrayA[iCurrentIndex]  << std::endl;
                std::cout << "Element from second array: " << szArrayB[i] << std::endl << std::endl;

                bIndexesFound = true;
                break;
            }
        }
        iCurrentIndex++;
    }

    if (!bIndexesFound)
        std::cout << "This sum can`t be found in this arrays" << std::endl << std::endl;
}

void Exercise8()
{
    // даны два массива (a,b) одинаковой длины. требуется найти такие два элемента a[i] и b[j],
    // которые в сумме дают значение Х, введённое пользователем

    const int iElementCount = 15;
    int iInput = 0;

    int* szArrayA = new int[iElementCount];
    int* szArrayB = new int[iElementCount];

    for (int i = 0; i < iElementCount; i++)
    {
        szArrayA[i] = i + 1;
        szArrayB[i] = i + 2;
    }

    DisplayArrays(szArrayA, szArrayB, iElementCount);

    std::cout << std::endl << "Please enter sum to find 2 elements: ";
    std::cin >> iInput;
    std::cout << std::endl;

    FindInputSum(szArrayA, szArrayB, iElementCount, iInput);

    delete[] szArrayA;
    delete[] szArrayB;
}

void Exercise7()
{
    // перевернуть массив. вход: 4 3 9 8 1; выход: 1 8 9 3 4

    int iArr[] = {4, 3, 9, 8, 1};
    int iElementsCount = sizeof(iArr)/sizeof(int);

    int iArrReverse[iElementsCount];

    int iMaxIndexArray = iElementsCount - 1;
    for (int i = 0; i < iElementsCount; i++)
    {
        iArrReverse[i] = iArr[iMaxIndexArray - i];
        std::cout << iArrReverse[i] << " ";
    }

    std::cout << std::endl;
}

void Exercise6()
{
    // найти в массиве два элемента, которые в сумме дают наибольшее значение среди всех других пар

    std::srand(time(0));

    const int iCount = 2;
    int iSmallerMax = 0;
    int iBiggerMax = 0;

    if (iCount == 0 || iCount == 1)
    {
        std::cout << "Count can`t be 0 or 1" << std::endl;
        return;
    }

    int* szArray = (int*) malloc(iCount*sizeof(int));
    for (int i = 0; i < iCount; i++)
    {
        szArray[i] = std::rand() % 100;

        std::cout << szArray[i] << " ";

        if (szArray[i] > iBiggerMax)
        {
            iSmallerMax = iBiggerMax;
            iBiggerMax = szArray[i];
        }
        else if (szArray[i] > iSmallerMax && szArray[i] != iBiggerMax)
            iSmallerMax = szArray[i];
    }

    std::cout << std::endl << std::endl;
    std::cout << "Max sum gives: " << iSmallerMax << " " << iBiggerMax << std::endl;

    free(szArray);
}

void Exercise5()
{
    // найти среднее арифметическое всех элементов в массиве

    std::srand(time(0));

    const int iCount = 10;
    int iSum = 0;
    double dMean = 0.;

    if (iCount == 0)
    {
        std::cout << "Count can`t be null" << std::endl;
        return;
    }

    int* szArray = (int*) malloc(iCount*sizeof(int));
    for (int i = 0; i < iCount; i++)
    {
        szArray[i] = std::rand() % 100;
        iSum += szArray[i];
        std::cout << szArray[i] << " ";
    }

    dMean = (double) iSum/iCount;

    std::cout << std::endl << std::endl;

    std::cout << "The arithmetic mean is: " << dMean << std::endl;

    free(szArray);
}

void Exercise4()
{
    // распечать массив случайных числе в обратном порядке

    std::srand(time(0));

    int iCount = 10;

    if (iCount == 0)
    {
        std::cout << "Count can`t be null" << std::endl;
        return;
    }

    int* szArray = (int*) malloc(iCount*sizeof(int));
    for (int i = 0; i < iCount; i++)
    {
        szArray[i] = std::rand() % 100;
        std::cout << szArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    while(iCount)
    {
        std::cout << szArray[iCount - 1] << " ";
        --iCount;
    }

    std::cout << std::endl;

    free(szArray);
}

void Exercise3()
{
    // найти позицию минимального и максимального элемента

    std::srand(time(0));

    const int iCount = 10;

    if (iCount == 0)
    {
        std::cout << "Count can`t be null" << std::endl;
        return;
    }

    int iMinimumIntIndex = 0;
    int iMaximumIntIndex = 0;

    int* szArray = (int*) malloc(iCount*sizeof(int));
    for (int i = 0; i < iCount; i++)
    {
        szArray[i] = std::rand() % 100;
        std::cout << szArray[i] << " ";

            if (szArray[i] < szArray[iMinimumIntIndex])
                iMinimumIntIndex = i;
            else if (szArray[i] > szArray[iMaximumIntIndex])
                iMaximumIntIndex = i;
    }
    std::cout << std::endl << std::endl;
    std::cout << "Minimum index is: " << iMinimumIntIndex << "; Maximum index is: " << iMaximumIntIndex << std::endl;

    free(szArray);
}

void Exercise2()
{
    // заполнить массив случайными числами и найти минимальный в нём

    std::srand(time(0));

    const int iCount = 10;
    int iMinimum = 0;

    if (iCount == 0)
    {
        std::cout << "Count can`t be null" << std::endl;
        return;
    }

    int* szArray = (int*) malloc(iCount*sizeof(int));
    for (int i = 0; i < iCount; i++)
    {
        szArray[i] = std::rand() % 100;
        std::cout << szArray[i] << " ";

        if (!i)
        {
            iMinimum = szArray[i];
            continue;
        }

        if (iMinimum > szArray[i])
            iMinimum = szArray[i];
    }
    std::cout << std::endl << std::endl;
    std::cout << "Minimum is: " << iMinimum << std::endl;

    free(szArray);
}

void Exercise1()
{
    // заполнить массив: 9 8 7 6 5 4 3 2 1

    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << sizeof(arr) << std::endl; //remove "unused" warning
}

int main()
{
//    Exercise1();
//    Exercise2();
//    Exercise3();
//    Exercise4();
//    Exercise5();
//    Exercise6();
//    Exercise7();
//    Exercise8();
//    Exercise9();

    return 0;
}
