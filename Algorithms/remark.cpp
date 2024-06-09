//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <unordered_map>
//
//using namespace std;
//
//
//long long getNumberOfGoodPairs(int n, const vector<int>& numbers) {
//    std::unordered_map<int, int> read_numbers;
//    long long number = 0;
//    for (int i = 0; i < n; i++) {
//        number += read_numbers[numbers.at(i) % 200];
//        read_numbers[numbers.at(i) % 200]++;
//    }
//    return number;
//}
//
//int readInt() {
//    int x;
//    cin >> x;
//    return x;
//}
//
//vector<int> readList(int n) {
//    vector<int> res(n);
//    for (int i = 0; i < n; i++) {
//        cin >> res[i];
//    }
//    return res;
//}
//
//int main() {
//    int n = readInt();
//    vector<int> numbers = readList(n);
//    cout << getNumberOfGoodPairs(n, numbers);
//}

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//
//void dfs(int i, int j, const int& n, const int& m, const vector<vector<int>>& matrixs, vector<vector<int>>& visited, int& max) {
//    visited[i][j] = 0;
//    if (i - 1 >= 0 && matrixs.at(i).at(j) < matrixs.at(i - 1).at(j)) {
//        if (visited.at(i - 1).at(j) == -1) {
//            dfs(i - 1, j, n, m, matrixs, visited, max);
//        }
//        if (visited.at(i).at(j) <= visited.at(i - 1).at(j)) {
//            visited[i][j] = visited.at(i - 1).at(j) + 1;
//        }
//    }
//    if (i + 1 < n && matrixs.at(i).at(j) < matrixs.at(i + 1).at(j)) {
//        if (visited.at(i + 1).at(j) == -1) {
//            dfs(i + 1, j, n, m, matrixs, visited, max);
//        }
//        if (visited.at(i).at(j) <= visited.at(i + 1).at(j)) {
//            visited[i][j] = visited.at(i + 1).at(j) + 1;
//        }
//    }
//    if (j - 1 >= 0 && matrixs.at(i).at(j) < matrixs.at(i).at(j - 1)) {
//        if (visited.at(i).at(j - 1) == -1) {
//            dfs(i, j - 1, n, m, matrixs, visited, max);
//        }
//        if (visited.at(i).at(j) <= visited.at(i).at(j - 1)) {
//            visited[i][j] = visited.at(i).at(j - 1) + 1;
//        }
//    }
//    if (j + 1 < m && matrixs.at(i).at(j) < matrixs.at(i).at(j + 1)) {
//        if (visited.at(i).at(j + 1) == -1) {
//            dfs(i, j + 1, n, m, matrixs, visited, max);
//        }
//        if (visited.at(i).at(j) <= visited.at(i).at(j + 1)) {
//            visited[i][j] = visited.at(i).at(j + 1) + 1;
//        }
//    }
//    if (max < visited[i][j]) {
//        max = visited[i][j];
//    }
//}
//
//int getLongestIncreasingPath(int n, int m, const vector<vector<int>>& matrixs) {
//    int max = 0;
//    vector<vector<int>> visited(n, vector<int>(m, -1));
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (visited.at(i).at(j) == -1) {
//                dfs(i, j, n, m, matrixs, visited, max);
//            }
//        }
//    }
//    return max + 1;
//}
//
//int readInt() {
//    int x;
//    cin >> x;
//    return x;
//}
//
//vector<int> readList(int n) {
//    vector<int> res(n);
//    for (int i = 0; i < n; i++) {
//        cin >> res[i];
//    }
//    return res;
//}
//
//vector<vector<int>> readMatrix(int n, int m) {
//    vector<vector<int>> matrix(n, vector<int>(m));
//    for (int i = 0; i < n; i++) {
//        matrix[i] = readList(m);
//    }
//    return matrix;
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> matrix = readMatrix(n, m);
//    cout << getLongestIncreasingPath(n, m, matrix);
//}


//¬вод: nums = [1, 1, 2, 2, 3, 5], k = 2

//#include <unordered_map>
//#include <algorithm>
//
//
//
//std::vector<int> function(const std::vector<int>&nums, const int& k) {
//    std::unordered_map<int, int> numbers;
//    for (const int& num : nums) {
//        numbers[num]++;   // 1:2, 2:2, 3:1, 5:1;
//    }
//    std::vector<std::pair<int, int>> pairs;
//    for (auto const& [key, value] : numbers) {
//        pairs.push_back({ value, key }); //(2:1, 2 : 2, 1 : 3, 1 : 5);
//    }
//    std::sort(pairs.rbegin(), pairs.rend()); //(2:2, 2 : 1, 1 : 5, 1 : 3)
//        std::vector<int> result;
//    for (int i = 0; i < std::min(k, int(pairs.size())); i++) {
//        result.push_back(pairs[i].second);
//    }
//    return result; 
//}
//
//int main() {
//    return 0;
//}

//#include <queue>
//
//struct Node {
//    int number;
//    Node* left;
//    Node* right;
//}
//
//std::vector<std::vector<int>> zigzag(const Node* root) {
//    std::queue<Node*> first_queue, second_queue;
//    std::vector<std::vector<int>> result;
//    first_queue.push(root); // 3
//    while (!first_queue.empty()) {
//        std::vector<int> part;
//        while (!first_queue.empty()) {
//            Node* node = first_queue.front();
//            first_queue.pop();
//            part.push_back(node->number);
//            second_queue.push(node->left);
//            second_queue.push(node->right);
//        }
//        result.push_back(part);
//        first_queue = second_queue;
//        second_queue.clear();
//    }
//    return result;
//}
//
//void read(std::vecotor<std::vector<int>>& result) {
//    for (int i = 0; i < result.size(); i++) {
//        if (i % 2 == 0) {
//            for (int j = 0; j < result.at(i).size(); j++) {
//                std::cout << result.at(i).at(j);
//            }
//        }
//        else {
//            for (int j = result.at(i).size() - 1; j >= 0; j--) {
//                std::cout << result.at(i).at(j);
//            }
//        }
//    }
//}
//#include <iostream>
//
//class A {
//public:
//    int value;
//
//    A(int v) : value(v) {
//        std::cout << "Constructor A called with value: " << value << std::endl;
//    }
//};
//
//class B {
//public:
//    int value;
//
//    B(int v) : value(v) {
//        std::cout << "Constructor B called with value: " << value << std::endl;
//    }
//};
//
//class C : public A, public B {
//public:
//    C(int a, int b) : A(a), B(b) {
//        std::cout << "Constructor C called" << std::endl;
//    }
//};
//
//int main() {
//    C obj(10, 20);
//    std::cout << "Value from A: " << obj.A::value << std::endl;
//    std::cout << "Value from B: " << obj.B::value << std::endl;
//
//    return 0;
//}