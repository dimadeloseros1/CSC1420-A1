int main() {
}


void simpleFunc() {
    int temp1 = 0;
    int temp2 = 0;
    int num = 0;
    int n = 100;
    /*
     *  The time complexity of the code below is of O(n^3)
     */
    for (int c = 1; c <= n; c++) {
        temp1 = 0;
        for (int b = 1; b <= n; b++) {
            for (int a = 1; a <= b; a++) {
                temp1 += 1;
            }
        }
        num += temp1;
    }

    /*
     *  The time complexity of the code below is the same as of the above code block, O(n^3)
     */
    for (int c = 1; c <= n; c++) {
        temp2 = 0;
        for (int b = 1; b <= n; b++) {
            for (int a = 1; a <= b; a++) {
                temp2 += 1;
            }
        }
        num += temp2;
    }

    /*
     *  And when we do the following summation O(n^3) + O(n^3) the result is simplified to O(n^3)
     */
}
