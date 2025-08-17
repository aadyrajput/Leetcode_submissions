class Solution {
public:
    int minSensors(int n, int m, int k) {
     int a=k*2+1;
     int n1=(n/a);
     int n2=(m/a);
     if(n%a!=0) n1++;
     if(m%a!=0) n2++;
    return n1*n2;
    }
};