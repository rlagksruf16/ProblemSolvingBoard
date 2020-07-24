#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; // 질문 개수
    bool arr [1000];
    int num, q, r;
    int counts = 0;
    memset(arr, true, sizeof(arr));
    // 성립안되는거 삭제
    for(int i = 123; i < 999; i++) {
        string temp = to_string(i);
        if(temp[0] == temp[1] || temp[1] == temp[2] || temp[0] == temp[2])
            arr[i] = false;
        if(temp[0] == '0' || temp[1] == '0' || temp[2] == '0')
            arr[i] = false;
    }
    
    cin >> N;
    
    // 질문
    for(int i = 1; i <= N; i++) {
        cin >> num >> q >> r;
        for(int i = 123; i < 999; i++) {
            string a = to_string(i);
            string b = to_string(num);
            int strike = 0; // strike
            int ball = 0; // ball
            
            if(arr[i]) {
                for(int x = 0; x < 3; x++) {
                    for(int y = 0; y < 3; y++) {
                        if(x == y && a[x] == b[y])
                            strike++;
                        if(x != y && a[x] == b[y])
                            ball++;
                    }
                }
                if(strike != q || ball != r)
                    arr[i] = false;
            }
        }
    }
    for(int i = 123; i < 999; i++) {
        if(arr[i])
            counts++;
    }
    
    cout << counts << endl;
    
    return 0;
}
