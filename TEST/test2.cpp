#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return string("aeiouAEIOU").find(c) != string::npos;
}

int main() {
	int t;
	cin>>t;
	while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool hardToPronounce = false;
        int consonantCount = 0;
        for (int i = 0; i < n; ++i) {
            if (!isVowel(s[i])) {
                consonantCount++;
                if (consonantCount >= 4) {
                    hardToPronounce = true;
                    break;
                }
            } else {
                consonantCount = 0;
            }
        }

        cout << (hardToPronounce ? "NO" : "YES") << endl;
    }
    return 0;
}
