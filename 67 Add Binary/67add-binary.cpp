class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.length();
        int m=b.length();
        int carry=0;
        string ans="";
        int sum=0;
        int i=0;
        while(i<max(n,m)) {
            if (i<n && i<m){
                sum=a[n-1-i]-'0'+b[m-1-i]-'0'+carry;
            } else if(i<n) {
                sum=a[n-1-i]-'0'+carry;
            } else {
                sum=b[m-1-i]-'0'+carry;
            }
            if(sum==2) {
                carry=1;
                sum=0;
            } else if(sum==3) {
                carry=1;
                sum=1;
            } else {
                carry=0;
            }
            ans+=sum+'0';
            i++;
        }
        if(carry==1){
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};