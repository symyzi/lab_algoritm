#include <iostream>
#include <fstream>

using namespace std;

struct tree {
    int key;
    int left;
    int right;
};

bool check(tree arr[], int i, int max, int min) {
    if (arr[i].key <= min || max <= arr[i].key) {
        return false;
    }
    if (arr[i].left != 0) {
        check(arr, arr[i].left-1, arr[i].key, min);
    }
    if (arr[i].right != 0) {
        check(arr, arr[i].right-1, max, arr[i].key);
    }
    return true;
}

int main() {
    //ifstream cin("check.in");
    //ofstream cout("check.out");
    int n;
    cin >> n;
    if (n == 0) {
        cout << "YES";
        return 0;
    }
    struct tree arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].key >> arr[i].left >> arr[i].right;
    }
    if (check(arr, 0, 1000000001, -1000000001)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
