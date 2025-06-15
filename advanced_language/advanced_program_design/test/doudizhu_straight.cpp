#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 3-K: 3-13
// A: 14
// 2: 16
// Joker: 18, 19

bool compareStraight(int myCards[], int nMyCard, int target[], int nTarget)

{
    if (myCards[nMyCard - 2] == 18) return true;
    
    // 找炸弹
    if (nMyCard >= 4) {
        for (int i = 0; i < nMyCard - 3; i++) {
            if (myCards[i] == myCards[i + 1] && myCards[i] == myCards[i + 2] && myCards[i] == myCards[i + 3]) {
                return true;
            }

        }
    }

    vector<int> myCardsVec(myCards, myCards + nMyCard);
    // 找顺子
    // 去重
    auto last = unique(myCardsVec.begin(), myCardsVec.end());
    myCardsVec.erase(last, myCardsVec.end());

    bool straight_flag = false;
    if (myCardsVec.size() < nTarget) return false;
    for (int i = 0; i < myCardsVec.size() - nTarget; i++) {
        for (int j = 0; j < nTarget - 1; j++) {
            if (myCardsVec[i + j] != myCardsVec[i + j + 1] - 1) {
                break;      // 不连续
            }
            if (j == nTarget - 2) {
                straight_flag = true;   // 找到顺子
            }
        }
       if (straight_flag && myCardsVec[i] > target[0]) return true;
    }
    return false;


}

 

int main()

{

    int nTarget;
    cin >> nTarget;
    int *target = new int[nTarget];
    for (int i = 0; i < nTarget; i++)
        cin >> target[i];

    int nMyCard;
    cin >> nMyCard;
    int *myCards = new int[nMyCard];
    for (int i = 0; i < nMyCard; i++)
        cin >> myCards[i];

    cout << (compareStraight(myCards, nMyCard, target, nTarget) ? "yes" : "no") << endl;

 

    return 0;

}

/* 【输入形式】

1）输入上家出牌的数量（>=5）
2）输入上家出的每张牌（从小到大排序）
3）输入我方剩余牌的数量
4）输入我方剩余的每张牌（从小到大排序）*/