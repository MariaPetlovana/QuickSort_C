#include <iostream>

using std::cin;
using std::cout;

struct Pair
{
    int StartPartition;
    int EndPartition;
};

template<typename T>
Pair Partition(T* ArrayToSort, int BeginOfArray, int EndOfArray)
{
    Pair ResultPair;
    ResultPair.StartPartition = BeginOfArray;
    ResultPair.EndPartition = EndOfArray;
    int IndexBaseElement = (BeginOfArray + EndOfArray) >> 1;

    do
    {
        while(ArrayToSort[ResultPair.StartPartition] < ArrayToSort[IndexBaseElement])
        {
            ++ResultPair.StartPartition;
        }

        while(ArrayToSort[ResultPair.EndPartition] > ArrayToSort[IndexBaseElement])
        {
            --ResultPair.EndPartition;
        }

        if(ResultPair.StartPartition <= ResultPair.EndPartition)
        {
            if(ResultPair.StartPartition < ResultPair.EndPartition)
            {
                int temporary = ArrayToSort[ResultPair.StartPartition];
                ArrayToSort[ResultPair.StartPartition] = ArrayToSort[ResultPair.EndPartition];
                ArrayToSort[ResultPair.EndPartition] = temporary;
            }

            ++ResultPair.StartPartition;
            --ResultPair.EndPartition;
        }
    }while(ResultPair.StartPartition <= ResultPair.EndPartition);

    return ResultPair;
}

template <class T>
void QuickSort(T* ArrayToSort, int BeginOfArray, int EndOfArray)
{
    Pair Boards = Partition(ArrayToSort, BeginOfArray, EndOfArray);

	if(Boards.StartPartition < EndOfArray)
	{
	    QuickSort(ArrayToSort, Boards.StartPartition, EndOfArray);
	}
	if(Boards.EndPartition > BeginOfArray)
	{
	    QuickSort(ArrayToSort, BeginOfArray, Boards.EndPartition);
	}

	return;
}

int main()
{
    size_t ElementsCount = 0;
    cout << "Enter number of elements in the array:\n";
    cin >> ElementsCount;

    int ArrayToSort[ElementsCount];
    cout << "Enter elements:\n";

    for(size_t i = 0; i < ElementsCount; ++i)
    cin >> ArrayToSort[i];

    QuickSort(ArrayToSort, 0, ElementsCount - 1);

    cout << "Sorted array:\n";
    for(size_t i = 0; i < ElementsCount; ++i)
    cout << ArrayToSort[i] << ' ';
    cout << "\n";

    return 0;
}
