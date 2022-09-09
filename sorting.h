#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
using vec1D = std::vector<T>;
template<typename T>
using vec2D = std::vector<vec1D<T> >;



/*----------Bubble Sort----------*/
template<typename T>
void Bubble_Sort(vec1D<T> &sort_list){
    bool ifswap = false;
    for(size_t i = 1; i < sort_list.size(); ++i){
        for(size_t j = 0; j < sort_list.size() - i; ++j){
            if(sort_list[j] > sort_list[j + 1]){
                std::swap(sort_list[j], sort_list[j + 1]);
                ifswap = true;
            }
        }
        if(!ifswap) break;
    }
}
/*----------Selection Sort----------*/
template<typename T>
void Selection_Sort(vec1D<T> &sort_list){
    for(size_t i = 0; i < sort_list.size(); ++i){
        T temp_min = sort_list[i];
        size_t temp_index = i;
        for(size_t j = i + 1; j < sort_list.size(); ++j){
            if(sort_list[j] < temp_min){
                temp_min = sort_list[j];
                temp_index = j;
            }
        }
        std::swap(sort_list[i], sort_list[temp_index]);
    }
}
/*----------Insertion Sort----------*/
template<typename T>
void Insertion_Sort(vec1D<T> &sort_list){
    size_t list_size = sort_list.size();
    for(size_t i = 1; i < list_size; ++i){
        if(sort_list[i] >= sort_list[i - 1]) continue;

        bool wrong_order = false;
        size_t position = i;
        for(size_t j = i - 1; j > 0; --j){
            if(sort_list[i] > sort_list[j - 1]){
                wrong_order = true;
                position = j;
                break;
            }
        }
        T number = sort_list[i];
        if(!wrong_order){
            sort_list.erase(sort_list.begin() + i);
            sort_list.insert(sort_list.begin(), number);
        }
        else{
            sort_list.erase(sort_list.begin() + i);
            sort_list.insert(sort_list.begin() + position, number);
        }
    }
}
/*----------Shell Sort----------*/
template<typename T>
void Shell_Sort(vec1D<T> &sort_list){
    size_t gap = sort_list.size() / 2;
    while(gap >= 1){
        for(size_t i = 0; i + gap < sort_list.size(); ++i){
            size_t j = i - (i / gap);

            for(size_t k = i + gap; k > j; k -= gap){
                if(sort_list[k] < sort_list[k - gap]){
                    std::swap(sort_list[k], sort_list[k - gap]);
                }
                else break;
            }
        }
        gap /= 2;
    }
}