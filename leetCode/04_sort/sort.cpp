#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 打印辅助函数
void printArray(const vector<int>& nums) {
    for (int x : nums) cout << x << " ";
    cout << endl;
}

// ==========================================
// 1. 冒泡排序 (Bubble Sort)
// 时间复杂度: O(N^2) | 空间复杂度: O(1) | 稳定
// ==========================================
void bubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; ++j) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // 优化：如果一轮没有交换，说明已经有序
    }
}

// ==========================================
// 2. 选择排序 (Selection Sort)
// 时间复杂度: O(N^2) | 空间复杂度: O(1) | 不稳定
// ==========================================
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] < nums[minIdx]) {
                minIdx = j;
            }
        }
        swap(nums[i], nums[minIdx]);
    }
}

// ==========================================
// 3. 插入排序 (Insertion Sort)
// 时间复杂度: O(N^2) | 空间复杂度: O(1) | 稳定
// ==========================================
void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

// ==========================================
// 4. 希尔排序 (Shell Sort)
// 时间复杂度: O(N log N) ~ O(N^2) 取决于增量 | 空间复杂度: O(1) | 不稳定
// ==========================================
void shellSort(vector<int>& nums) {
    int n = nums.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个 gap 进行插入排序
        for (int i = gap; i < n; ++i) {
            int key = nums[i];
            int j = i;
            while (j >= gap && nums[j - gap] > key) {
                nums[j] = nums[j - gap];
                j -= gap;
            }
            nums[j] = key;
        }
    }
}

// ==========================================
// 5. 归并排序 (Merge Sort)
// 时间复杂度: O(N log N) | 空间复杂度: O(N) | 稳定
// ==========================================
void merge(vector<int>& nums, int l, int mid, int r) {
    vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) tmp[k++] = nums[i++];
        else tmp[k++] = nums[j++];
    }
    while (i <= mid) tmp[k++] = nums[i++];
    while (j <= r) tmp[k++] = nums[j++];
    
    for (int p = 0; p < tmp.size(); ++p) {
        nums[l + p] = tmp[p];
    }
}

void mergeSortRecursive(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSortRecursive(nums, l, mid);
    mergeSortRecursive(nums, mid + 1, r);
    merge(nums, l, mid, r);
}

void mergeSort(vector<int>& nums) {
    if (nums.empty()) return;
    mergeSortRecursive(nums, 0, nums.size() - 1);
}

// ==========================================
// 6. 快速排序 (Quick Sort)
// 时间复杂度: O(N log N) | 空间复杂度: O(log N) | 不稳定
// ==========================================
void quickSortRecursive(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int x = nums[l + (r - l) / 2];
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (nums[i] < x);
        do j--; while (nums[j] > x);
        if (i < j) swap(nums[i], nums[j]);
    }
    quickSortRecursive(nums, l, j);
    quickSortRecursive(nums, j + 1, r);
}

void quickSort(vector<int>& nums) {
    if (nums.empty()) return;
    quickSortRecursive(nums, 0, nums.size() - 1);
}

// ==========================================
// 7. 堆排序 (Heap Sort)
// 时间复杂度: O(N log N) | 空间复杂度: O(1) | 不稳定
// ==========================================
void heapify(vector<int>& nums, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && nums[l] > nums[largest]) largest = l;
    if (r < n && nums[r] > nums[largest]) largest = r;

    if (largest != i) {
        swap(nums[i], nums[largest]);
        heapify(nums, n, largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();
    // 建堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(nums, n, i);
    }
    // 排序
    for (int i = n - 1; i > 0; i--) {
        swap(nums[0], nums[i]);
        heapify(nums, i, 0);
    }
}

// ==========================================
// 8. 计数排序 (Counting Sort)
// 时间复杂度: O(N+K) | 空间复杂度: O(K) | 稳定
// 限制：适用于整数且范围较小的情况
// ==========================================
void countingSort(vector<int>& nums) {
    if (nums.empty()) return;
    int maxVal = nums[0], minVal = nums[0];
    for (int x : nums) {
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }
    
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);
    vector<int> output(nums.size());

    for (int x : nums) count[x - minVal]++;
    for (int i = 1; i < range; ++i) count[i] += count[i - 1];
    
    // 倒序遍历以保证稳定性
    for (int i = nums.size() - 1; i >= 0; --i) {
        output[count[nums[i] - minVal] - 1] = nums[i];
        count[nums[i] - minVal]--;
    }
    nums = output;
}

// ==========================================
// 9. 桶排序 (Bucket Sort)
// 时间复杂度: O(N+K) | 空间复杂度: O(N+K) | 稳定
// ==========================================
void bucketSort(vector<int>& nums) {
    if (nums.empty()) return;
    int maxVal = nums[0], minVal = nums[0];
    for(int x : nums) {
        maxVal = max(maxVal, x);
        minVal = min(minVal, x);
    }

    int bucketNum = nums.size() / 2 + 1; // 桶的数量可调
    vector<vector<int>> buckets(bucketNum);
    double range = (double)(maxVal - minVal + 1) / bucketNum;

    for(int x : nums) {
        int idx = (int)((x - minVal) / range);
        if (idx >= bucketNum) idx = bucketNum - 1; // 边界保护
        buckets[idx].push_back(x);
    }

    int k = 0;
    for(auto& bucket : buckets) {
        if (!bucket.empty()) {
            sort(bucket.begin(), bucket.end()); // 桶内通常使用快排或插入
            for(int x : bucket) {
                nums[k++] = x;
            }
        }
    }
}

// ==========================================
// 10. 基数排序 (Radix Sort)
// 时间复杂度: O(N*d) | 空间复杂度: O(N+K) | 稳定
// ==========================================
void countSortForRadix(vector<int>& nums, int exp) {
    int n = nums.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    for (int i = 0; i < n; i++)
        count[(nums[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(nums[i] / exp) % 10] - 1] = nums[i];
        count[(nums[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        nums[i] = output[i];
}

void radixSort(vector<int>& nums) {
    if (nums.empty()) return;
    int maxVal = nums[0];
    for (int x : nums) maxVal = max(maxVal, x);

    // 对每一位进行计数排序
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSortForRadix(nums, exp);
    }
}

// ==========================================
// 测试主函数
// ==========================================
int main() {
    vector<int> original = {64, 34, 25, 12, 22, 11, 90, 5, 1, 100};
    
    auto testSort = [&](string name, void(*sortFunc)(vector<int>&)) {
        vector<int> arr = original;
        sortFunc(arr);
        cout << "[" << name << "]: ";
        printArray(arr);
    };

    testSort("Bubble Sort", bubbleSort);
    testSort("Selection Sort", selectionSort);
    testSort("Insertion Sort", insertionSort);
    testSort("Shell Sort", shellSort);
    testSort("Merge Sort", mergeSort);
    testSort("Quick Sort", quickSort);
    testSort("Heap Sort", heapSort);
    testSort("Counting Sort", countingSort);
    testSort("Bucket Sort", bucketSort);
    testSort("Radix Sort", radixSort);

    return 0;
}