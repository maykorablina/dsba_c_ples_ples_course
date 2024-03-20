#include <iostream>


int HowManyMines(char **arr, int i, int j, int n, int m){

    int counter = 0;

    /* * 0 0
       0 1 0
       0 0 0 */
    if (i > 0 && j > 0 && arr[i - 1][j - 1] == '*') counter++;

    /* 0 0 0
       * 1 0
       0 0 0 */
    if (j > 0 && arr[i][j - 1] == '*') counter++;

    /* 0 0 0
       0 1 0
       * 0 0 */
    if (i < n && j > 0 && arr[i + 1][j - 1] == '*') counter++;

    /* 0 0 0
       0 1 0
       0 * 0 */
    if (i < n && arr[i + 1][j] == '*') counter++;

    /* 0 0 0
       0 1 0
       0 0 * */
    if (i < n && j < m && arr[i + 1][j + 1] == '*') counter++;

    /* 0 0 0
       0 1 *
       0 0 0 */
    if (j < m && arr[i][j + 1] == '*') counter++;

    /* 0 0 *
       0 1 0
       0 0 0 */
    if (i > 0 && j < m && arr[i - 1][j + 1] == '*') counter++;

    /* 0 * 0
       0 1 0
       0 0 0 */
    if (i > 0 && arr[i - 1][j] == '*') counter++;

    return counter;
}

int main() {
    int n, m, k, x, y;
    std::cin >> n >> m >> k;

    char **arr;
    arr = new char * [n];
    for (int i = 0; i < n; i++)
        arr[i] = new char [m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            arr[i][j] = '0';
        }
    }

    for (int i = 0; i < k; i++){
        std::cin >> x >> y;
        arr[x - 1][y - 1] = '*';
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] != '*'){
                arr[i][j] = '0' + HowManyMines(arr, i, j, n - 1, m - 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) std::cout << arr[i][j] << ' ';
        std::cout << '\n';

        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
