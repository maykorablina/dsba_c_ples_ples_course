#include <iostream>


int HowManyMines(char **arr, int i, int j, int n, int m){

    int counter = 0;

    /* * 0 0
       0 1 0
       0 0 0 */
    if (arr[i - 1][j - 1] == '*') counter++;

    /* 0 0 0
       * 1 0
       0 0 0 */
    if (arr[i][j - 1] == '*') counter++;

    /* 0 0 0
       0 1 0
       * 0 0 */
    if (arr[i + 1][j - 1] == '*') counter++;

    /* 0 0 0
       0 1 0
       0 * 0 */
    if (arr[i + 1][j] == '*') counter++;

    /* 0 0 0
       0 1 0
       0 0 * */
    if (arr[i + 1][j + 1] == '*') counter++;

    /* 0 0 0
       0 1 *
       0 0 0 */
    if (arr[i][j + 1] == '*') counter++;

    /* 0 0 *
       0 1 0
       0 0 0 */
    if (arr[i - 1][j + 1] == '*') counter++;

    /* 0 * 0
       0 1 0
       0 0 0 */
    if (arr[i - 1][j] == '*') counter++;

    return counter;
}

int main() {
    int n, m, k, x, y;
    std::cin >> n >> m >> k;

    char **arr;
    arr = new char * [n + 2];
    for (int i = 0; i < n + 2; i++)
        arr[i] = new char [m + 2];

    for (int i = 0; i < n + 2; i++){
        for (int j = 0; j < m + 2; j++){
            arr[i][j] = '0';
        }
    }

    for (int i = 0; i < k; i++){
        std::cin >> x >> y;
        arr[x][y] = '*';
    }

    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            if (arr[i][j] != '*'){
                arr[i][j] = '0' + HowManyMines(arr, i, j, n, m);
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) std::cout << arr[i][j] << ' ';
        std::cout << '\n';

        delete[] arr[i];
    }

    delete[] arr[0];
    delete[] arr[n + 1];
    delete[] arr;

    return 0;
}
