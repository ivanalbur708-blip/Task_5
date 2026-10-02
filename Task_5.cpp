#include <iostream>


using namespace std;

void PrintArray(const int array[], int size)
{
    for (int i = 0; i < size; i++) cout << array[i] << ' ';
    cout << '\n';
}

void ShellSort(int array[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            int value = array[i];
            int j = i;
            while (j >= gap && array[j - gap] > value)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = value;
        }
    }
}

void CocktailSort(int array[], int size)
{
    bool swapped = true;
    int begin = 0;
    int end = size - 1;

    while (swapped)
    {
        swapped = false;
        for (int i = begin; i < end; i++)
        {
            if (array[i] > array[i + 1])
            {
                int temporary = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temporary;
                swapped = true;
            }
        }
        end--;

        if (!swapped) break;

        swapped = false;
        for (int i = end; i > begin; i--)
        {
            if (array[i - 1] > array[i])
            {
                int temporary = array[i - 1];
                array[i - 1] = array[i];
                array[i] = temporary;
                swapped = true;
            }
        }
        begin++;
    }
}

void QuickSort(int array[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];

    while (i <= j)
    {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i <= j)
        {
            int temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(array, left, j);
    if (i < right) QuickSort(array, i, right);
}

void SelectionSortPart(int array[], int begin, int end)
{
    for (int i = begin; i < end - 1; i++)
    {
        int minimumIndex = i;
        for (int j = i + 1; j < end; j++)
        {
            if (array[j] < array[minimumIndex]) minimumIndex = j;
        }

        int temporary = array[i];
        array[i] = array[minimumIndex];
        array[minimumIndex] = temporary;
    }
}

void ReversePart(int array[], int begin, int end)
{
    int left = begin;
    int right = end - 1;
    while (left < right)
    {
        int temporary = array[left];
        array[left] = array[right];
        array[right] = temporary;
        left++;
        right--;
    }
}

int main()
{


    // Task 1
    {
        const int size = 10;
        int shellArray[size] = { 19, 2, 30, 4, -5, 17, 8, 1, 11, 6 };
        int cocktailArray[size];
        for (int i = 0; i < size; i++) cocktailArray[i] = shellArray[i];

        ShellSort(shellArray, size);
        CocktailSort(cocktailArray, size);

        cout << "Shell sort: ";
        PrintArray(shellArray, size);
        cout << "Cocktail sort: ";
        PrintArray(cocktailArray, size);
    }

    // Task 2
    {
        const int size = 10;
        double marks[size];
        int choice;

        cout << "Enter 10 student marks: ";
        for (int i = 0; i < size; i++) cin >> marks[i];

        do
        {
            cout << "1 - show marks\n2 - retake exam\n3 - scholarship\n0 - exit\nChoice: ";
            cin >> choice;

            if (choice == 1)
            {
                for (int i = 0; i < size; i++) cout << marks[i] << ' ';
                cout << '\n';
            }
            else if (choice == 2)
            {
                int index;
                double newMark;
                cout << "Element number (1-10) and new mark: ";
                cin >> index >> newMark;
                marks[index - 1] = newMark;
            }
            else if (choice == 3)
            {
                double sum = 0;
                for (int i = 0; i < size; i++) sum += marks[i];
                if (sum / size >= 10.7) cout << "Scholarship is awarded.\n";
                else cout << "Scholarship is not awarded.\n";
            }
        } while (choice != 0);
    }

    // Task 3
    {
        const int size = 10;
        int numbers[size] = { 8, 3, 1, 7, 0, 10, 2, 9, 4, 6 };

        QuickSort(numbers, 0, size - 1);
        cout << "Quick sort: ";
        PrintArray(numbers, size);
    }

    // Task 4
    {
        const int size = 12;
        int numbers[size] = { 9, -3, 5, 8, 1, 6, 2, 0, 7, 4, 11, -2 };
        double sum = 0;
        for (int i = 0; i < size; i++) sum += numbers[i];

        int sortedCount;
        if (sum / size > 0) sortedCount = size * 2 / 3;
        else sortedCount = size / 3;

        SelectionSortPart(numbers, 0, sortedCount);
        ReversePart(numbers, sortedCount, size);

        cout << "Result: ";
        PrintArray(numbers, size);
    }

    return 0;
}

