#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> longest_sequence(std::vector<int>& arr) {
    std::unordered_map<int, bool> map;
    for (int num : arr) {
        map[num] = true;
    }
    
    int longest_length = 0;
    int start = 0;
    int end = 0;
    for (int num : arr) {
        if (map[num]) {
            int left = num;
            int right = num;
            while (map.count(left - 1) && map[left - 1]) {
                left--;
                map[left] = false;
            }
            while (map.count(right + 1) && map[right + 1]) {
                right++;
                map[right] = false;
            }
            
            int current_length = right - left + 1;
            if (current_length > longest_length || (current_length == longest_length && left < start)) {
                longest_length = current_length;
                start = left;
                end = right;
            }
        }
    }
    
    return {start, end};
}

int main() {
    std::vector<int> arr = {3, 7, 2, 1, 9, 8, 41};
    std::vector<int> result = longest_sequence(arr);
    std::cout << "Start: " << result[0] << " End: " << result[1] << std::endl;
    return 0;
}
