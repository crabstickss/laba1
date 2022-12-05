#include <iostream>
using namespace std;
template <typename T> // Шаблон функции printArray
void printArray(const T * arr, int N){
    cout << " New array: ";

    for (int k=0; k<N; k++) { // выводятся элементы массива до тех пор, пока не выведутся полностью
        cout<<arr[k]<<" ";
    }
}
//сортировка вставками
void insertionSort(int arr[], int N){
    cout << " "<< endl;

    for (int i = 1; i < N; i++) //проходим по массиву, начиная со второго элемента
    {
       int  j = i; //j будем присваивать значение числа, по которому проходим
        do{ //если элемент массива меньше, чем предыдущий, меняем их местами
            if (arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
                j--;
            }
            else { // выходим из цикла после 1 итерации
                break;
            }
        }
        while (j > 0);
    }

    printArray(arr, N); //вызываем функцию printArray


}
// функция для сортировки массива пузырьком
void bubbleSort(int arr[], int N) {
    // проходим по массиву и сравниваем элементы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // если элемент больше следующего, то меняем их местами
                swap(arr[j], arr[j+1]);
            }
        }
    }

        printArray(arr, N);

}

    void selectionSort(int arr[], int N) {
        int i, j, a, b;
        for (i = 0; i < N - 1; i++) {
            a = i; //а элемент нового массива, который будет принимать текущие минимальные значения

            for (j = i + 1; j < N; j++) { //проходим по массиву со второго числа
                if (arr[j] < arr[a]) //если число больше, чем предыдущее минимальное, то записываем его вместо него
                    a = j;
            }

            if (a != i)//делаем проверку
                b = arr[i];
            arr[i] = arr[a];
            arr[a] = b;

        }
        printArray(arr, N);
    }


    int main() {
        srand(time(NULL));
        const int N = 6; //задаем размер массива
        int i;
        int arr[N];
        cout<< "Array: ";
        for (i = 0; i < N; i++)     //массив заполняется числами
        {
            arr[i] = rand()%100;      //задание элемента рандомным числом

            cout << " " << arr[i] ; //вывод элемента
        }
        cout << " "<< endl;



        selectionSort(arr, N); //вызов функции сортировки выбором
        insertionSort(arr, N); //вызов функции сортировки вставкой
        bubbleSort(arr, N); //вызов функции сортировки пузырьком

        return 0;
    }
