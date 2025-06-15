#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Triple {
    int row;
    int col;
    int value;
};

void transposeSparseMatrix(const vector<Triple>& M, int rows, int cols, int nonZero, vector<Triple>& T) {
    // 统计转置后每行的非零元素个数（即原矩阵每列的非零元素个数）
    vector<int> numInCol(cols, 0);
    for (const auto& elem : M) {
        numInCol[elem.col]++;
    }

    // 计算转置后每行的起始位置
    vector<int> startPos(cols, 0);
    for (int i = 1; i < cols; ++i) {
        startPos[i] = startPos[i - 1] + numInCol[i - 1];
    }

    // 放置非零元素到转置矩阵中
    T.resize(nonZero);
    for (const auto& elem : M) {
        int pos = startPos[elem.col];
        T[pos].row = elem.col;
        T[pos].col = elem.row;
        T[pos].value = elem.value;
        startPos[elem.col]++;
    }
}

int main() {
    ifstream inFile("in.txt");
    ofstream outFile("abc.out");

    if (!inFile.is_open() || !outFile.is_open()) {
        cerr << "无法打开文件" << endl;
        return 1;
    }

    int rows, cols, nonZero;
    inFile >> rows >> cols >> nonZero;

    vector<Triple> M(nonZero);
    for (int i = 0; i < nonZero; ++i) {
        inFile >> M[i].row >> M[i].col >> M[i].value;
    }

    vector<Triple> T;
    transposeSparseMatrix(M, rows, cols, nonZero, T);

    // 输出转置矩阵
    outFile << cols << " " << rows << " " << nonZero << endl;
    for (const auto& elem : T) {
        outFile << elem.row << " " << elem.col << " " << elem.value << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}