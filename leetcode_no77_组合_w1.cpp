/* ------------------------------------------------------------------|
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*  dfs
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.79%的用户
*	内存消耗：18.5 MB, 在所有 C++ 提交中击败了15.71%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

vector<int> tmp;
vector<vector<int>> res;

void dfs(int curr, int n,const int& k) {
    //填入符合长度的结果
    if (tmp.size() == k) {
        res.emplace_back(tmp);
        return;
    }
    //当剩下的数不能够组成合乎规则的结果时剪枝
    if (tmp.size() + (n - curr + 1) < k) {
        return;
    }
    //填入当前的数字继续递归
    tmp.emplace_back(curr);
    dfs(curr + 1, n, k);
    tmp.pop_back();
    //不填当前数字递归下一个数字
    dfs(curr + 1, n, k);
}

vector<vector<int>> combine(int n, int k) {
    dfs(1, n, k);
    return res;
}