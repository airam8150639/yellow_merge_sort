#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if ( (range_end - range_begin) == 1) return;
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt it = elements.begin() + (elements.end() - elements.begin()) / 2;
    MergeSort(elements.begin(), it);
    MergeSort(it, elements.end());
    merge(elements.begin(), it, it, elements.end(), range_begin);
}*/

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if ((range_end - range_begin) == 1) return;
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    RandomIt it_1 = elements.begin() + (elements.end() - elements.begin()) / 3;
    RandomIt it_2 = it_1 + (elements.end() - elements.begin()) / 3;

    MergeSort(elements.begin(), it_1);
    MergeSort(it_1, it_2);
    MergeSort(it_2, elements.end());

    vector<typename RandomIt::value_type> tmp_v;
    merge(elements.begin(), it_1, it_1, it_2, back_inserter(tmp_v));
    merge(tmp_v.begin(), tmp_v.end(), it_2, elements.end(), range_begin);
}

/*int main() {
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 2 };
    MergeSort(begin(v), end(v));
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}*/