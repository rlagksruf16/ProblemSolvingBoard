/*
    DP문제
    가장 짧은 펠린드롬 만들기
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio();
    cin.tie(NULL);
    
    string s; // 문자열
    int left, right;
    int counts = 0;
    
    // 문자열 입력
    cin >> s;
    
    // 처음부터 끝과 계속 비교
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == s[s.length()-1]) {
            left = i;
            right = s.length()-1;
            
            for(int j = 0; j < (s.length()-i)/2; j++) {
                if(s[left] == s[right]) {
                    left++;
                    right--;
                }
                else {
                    counts++;
                    break;
                }
                if(left > right || left == right) {
                    i = s.length()-1;
                    break;
                }
            }
        }
        else
            counts++;
    }
    
    int total = s.length() + counts;
    
    cout << total;
    
    return 0;
}
