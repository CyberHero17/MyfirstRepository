#include <iostream>
using namespace std;

// Выводим бинарное разложение числа в простом обратном порядке
void PrintBinarySimple (unsigned int a)
{
    cout << a << " = ";
    for(unsigned int i=0; i<8*sizeof(a); i++) //Будем выводить все 8*4=32 бита
    {
        //Было так:
        //  if(a % 2 == 0) cout << 0;
        //  else cout << 1;
        //  a = a / 2;
        //Но давайте сделаем по-новому.
        cout << !(a >> 1 << 1 == a); //магия, которую нужно освоить                       1101 --> 1011
          //                                                                              0001
        a = a >> 1;//                                                                      11
    }
    cout<< "    (PrintBinarySimple)" << endl;
}

//Теперь попробуем то же самое, но в правильном порядке
void PrintBinarySimpleForward (unsigned int a)
{
    cout << a << " = ";
    for(unsigned int i=0; i<8*sizeof(a); i++)
    {
        cout << !(a << 1 >> 1 == a); //Если раньше нам нужно было выдумывать сложный алгоритм,       1101  --> 1011 - запись в двоичной сис.с.
                                      //                                                             0101
        a = a << 1;                  //то теперь достаточно чуть подправить наше колдунство          1
    }
    cout<< "    (PrintBinarySimpleForward)" << endl;
}

//Сделаем то же самое с помощью "битовой матрицы"
void PrintBinaryMatrix(unsigned int a)
{
    cout << a << " = ";
    unsigned int m = 1; //это наша матрица вида 000...001 (32 цифры)
    for(unsigned int i=0; i<8*sizeof(a); i++)
    {
        cout << (bool)(a & m); //оператор & - битовое И, а (bool) упрощает результат до 0 или 1
        m = m << 1; //сдвиаем матрицу, теперь это 000...010 (32 цифры)
    }
    cout<< "    (PrintBinaryMatrix)" << endl;
}

//А теперь меняем порядок
void PrintBinaryMatrixForward(unsigned int a)
{
    cout << a << " = ";
    unsigned int m = 1 << 31; // матрица теперь 100...000 (32 цифры)
    for(unsigned int i=0; i<8*sizeof(a); i++)
    {
        cout << (bool)(a & m);
        m = m >> 1; //после сдвига 010...000 (32 цифры)
    }
    cout<< "    (PrintBinaryMatrixForward)" << endl;
}

int main()
{
    unsigned int a=1459;
    PrintBinarySimple (a);
    PrintBinarySimpleForward (a);
    PrintBinaryMatrix (a);
    PrintBinaryMatrixForward (a);
    return 0;
}



