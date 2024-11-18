
#ifndef TASK2_DARRAY_DARRAY_H
#define TASK2_DARRAY_DARRAY_H
include<iostream>
using namespace std;

template<typename T>
class DaynamicArray
{
private:
    T* myArray;
    size_t current_index;
    size_t arr_size;

public:
    DaynamicArray(size_t size)
    {
        arr_size = size;
        myArray = new T[arr_size];
        current_index = 0;
    };

    ~DaynamicArray()
    {
        delete[] myArray;
    }

    // append function for adding item at the end off an array
    void append(const T& value)
    {
        if(current_index >= arr_size)
        {
            resize(arr_size + 5);
        }
        myArray[current_index++] = value;
        cout << "the " << value <<" appended at the end Successfully" << endl;
    }

    // insert function to add item in a specific index
    void insert (const T& value, const size_t index)
    {
        if(current_index >= arr_size)
        {
            resize(arr_size + 5);
        }

        if(index >= arr_size)
        {
            throw out_of_range("Index out of range");
        }

        if(index > current_index)
        {
            throw out_of_range("Index out of data");
        }

        for(size_t i = current_index; i > index; i--)
        {
            myArray[i] = myArray[i-1];
        }

        myArray[index] = value;

        current_index++;

        cout << "the " << value << " appended Successfully at " << index << " index" << endl;
    }

    //remove function to delete the last item in the array
    T remove()
    {
        if(current_index == 0)
        {
            throw out_of_range("Empty array");
        }
        return myArray[--current_index];
    }

    //delete function to delete the item at specific index in the array
    T delet(const size_t index)
    {
        if(current_index == 0)
        {
            throw out_of_range("Empty array");
        }

        if(index >= current_index)
        {
            throw out_of_range("out of data");
        }

        T removed = myArray[index];

        for(size_t i = index; i < current_index - 1; i++)
        {
            myArray[i] = myArray[i+1];
        }

        current_index--;
        return removed;
    }

    // get function to Access/Return an element at specific index
    T& get(const size_t index)
    {
        if(index >= arr_size)
        {
            throw out_of_range("Index out of range");
        }

        if(index > current_index)
        {
            throw out_of_range("Index out of data");
        }

        return myArray[index];
    }

    // getSize function to Return the current size of the array
    size_t getSize() const
    {
        return current_index;
    }


    void resize(size_t new_size)
    {
        T* newArray = new T[new_size];
        for(size_t i =0; i < current_index; i++)
        {
            newArray[i] = myArray[i];
        }

        delete[] myArray;
        myArray = newArray;
        arr_size = new_size;

        cout << endl << "Array size resized to "<< new_size << endl;
    }

    // print function to display the array elements
    void display() const
    {
        cout << endl << "Array elements : ";
        for (size_t i = 0; i < current_index; ++i)
        {
            cout << myArray[i] << " ";
        }
        cout << endl << endl;;
    }


};
#endif //TASK2_DARRAY_DARRAY_H
