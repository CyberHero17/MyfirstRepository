#include <iostream>
using namespace std;

#define L 10 //определим длину массивов заранее

struct task // Эта простая структура нужна для демонстрации работы с ней
{
    int priority_high;
    int priority_low;
};

int main()
{
    // Неумелой работой с индексами можно испортить значения других переменных (а можно и не испортить)
    cout<<endl<<"\tData corruption"<<endl<<endl;

    int a=22;
    int b=33;
    int m[10];
    int c=44;
    int d=55;
    cout<<"It was:"<<endl;
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<endl;
    for(int i=-8;i<L;i++)
        m[i]=i;
    cout <<"...but then:"<<endl;
    cout<<"a="<<a<<" b="<<b<<" c="<<c<<" d="<<d<<endl;

    cout<<". . . . . . . . . . . . . . . . . ."<<endl;


    //Массив - это...
    cout<<endl<<"\tWho are You mr. m?"<<endl<<endl;
    cout<<"m = "<<m<<endl;
    cout<<"Can we do something weird?"<<endl;
    for(int i=0; i<L; i++)
        cout<<(m+i)[0]<<' ';
    cout<<endl<<"Yes we can!"<<endl;
    //m=m+1; //Так нельзя. Менять само m нам пока не разрешают.
    cout<<". . . . . . . . . . . . . . . . . ."<<endl;

    //Базовый метод сортировки
    cout<<endl<<"\tBasic bubble"<<endl<<endl;
    int arr[L] = {4,2,5,2,1,0,3,8,0,1}; //Исходный массив
    cout<<"Initial:"<<endl;
    for (int i=0; i<L; i++)
        cout<< arr[i] << " ";

    cout<<endl<<"Sorting..."<<endl;
    for (int i=0; i<L; i++)   //Вложенные циклы
    {
        for (int j=0; j<L-i-1; j++)
            if (arr[j]>arr[j+1])    //Меняем местами, если выполнено условие
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        for (int i=0; i<L; i++)
            cout<< arr[i] << " ";
        cout<<endl;
    }
    cout<<"Finaly:"<<endl;
    for (int i=0; i<L; i++)
        cout<< arr[i] << " ";

    cout<<endl<<". . . . . . . . . . . . . . . . . ."<<endl;

    //Сортировка с более сложным условием:
    //Сделать сначала четные по возрастанию, а затем нечетные по убыванию
    cout<<endl<<"\tAdvanced sorting"<<endl<<endl;
    cout<<"Initial:"<<endl;
    for (int i=0; i<L; i++)
        cout<< arr[i] << " ";
    cout<<endl<<"Sorting..."<<endl;
    for (int i=0; i<L-1; i++)   //Вложенные циклы
    {
        for (int j=0; j<L-i-1; j++)
        {
            bool doSwap=false; //Можно разбивать булевские операции на отдельные выражения, чтобы не запутаться в сложной конструкции
            if (arr[j]%2!=0 && arr[j+1]%2==0) doSwap=true; //нечетное с четным всегда меняем местами
            if (arr[j]%2==0 && arr[j+1]%2==0 && arr[j]>arr[j+1]) doSwap=true; //если оба четные, то проверяем возрастание
            if (arr[j]%2!=0 && arr[j+1]%2!=0 && arr[j]<arr[j+1]) doSwap=true; //если оба нечетные, то проверяем убывание
            if(doSwap) //Любое ДА приводит нас к перестановке элементов
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
        for (int i=0; i<L; i++)
            cout<< arr[i] << " ";
        cout<<endl;
    }
    cout<<"Finaly:"<<endl;
    for (int i=0; i<L; i++)
        cout<< arr[i] << " ";
    cout<<endl<<". . . . . . . . . . . . . . . . . ."<<endl;

    //Аналогично можно сортировать массивы структур
    cout<<endl<<"\tSorting structs"<<endl<<endl;
    task task_arr[L] = {{0,4}, {7,2}, {1,1}, {5,8}, {9,0}, {1,3}, {4,7}, {2,1}, {0,9}, {0,4}};

    cout<<"Initial:"<<endl;
    cout << "HP: ";
    for (int i=0; i<L; i++)
        cout << task_arr[i].priority_high << " ";
    cout << endl<< "LP: ";
    for (int i=0; i<L; i++)
        cout << task_arr[i].priority_low << " ";
    cout << endl;
    for (int i=0; i<L-1; i++)   //Вложенные циклы
        for (int j=0; j<L-i-1; j++)
            if (task_arr[j].priority_high > task_arr[j+1].priority_high        //высокий приоритет требует сортировки ИЛИ
                || (task_arr[j].priority_high == task_arr[j+1].priority_high   //высокий приоритет не определен и нужно обратиться к...
                    && task_arr[j].priority_low > task_arr[j+1].priority_low)) //низкому приоритету
            {
                task tmp = task_arr[j];
                task_arr[j] = task_arr[j+1];
                task_arr[j+1] = tmp;
            }

    cout<<"Finaly:"<<endl;
    cout << "HP: ";
    for (int i=0; i<L; i++)
        cout << task_arr[i].priority_high << " ";
    cout << endl<< "LP: ";
    for (int i=0; i<L; i++)
        cout << task_arr[i].priority_low << " ";
    cout << endl<<". . . . . . . . . . . . . . . . . ."<<endl;

    return 0;
}
