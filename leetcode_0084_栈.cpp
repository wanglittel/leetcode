#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int rt = 0;
        // ��������������
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            int j = i;
            // �����½�
            while (!s.empty() && heights[s.top()] > heights[i]) {
                // ջ��ֵ�����
                int val = heights[s.top()] * (i - s.top());
                rt = rt > val ? rt : val;
                j = s.top();
                s.pop();
            }
            s.push(j);
            // �޸�����
            heights[j] = heights[i];
        }
        while (!s.empty()) {
            // ջ��ֵ�����
            int val = heights[s.top()] * (heights.size() - s.top());
            rt = rt > val ? rt : val;
            s.pop();
        }
        return rt;
    }
};

    // int largestRectangleArea(vector<int> &heights)
    // {
    //     int rt = 0;
    //     // ��������������
    //     stack<int> s;
    //     for (int i = 0; i < heights.size(); i++) {
    //         int j = i;
    //         // �����½�
    //         while (!s.empty() && heights[s.top()] > heights[i]) {
    //             // ջ��ֵ�����
    //             int val = heights[s.top()] * (i - s.top());
    //             rt = rt > val ? rt : val;
    //             j = s.top();
    //             s.pop();
    //         }
    //         s.push(j);
    //         // �޸�����
    //         heights[j] = heights[i];
    //     }
    //     while (!s.empty()) {
    //         // ջ��ֵ�����
    //         int val = heights[s.top()] * (heights.size() - s.top());
    //         rt = rt > val ? rt : val;
    //         s.pop();
    //     }

    //     return rt;
    // }