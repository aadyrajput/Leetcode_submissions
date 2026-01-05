class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     long long sum=0;
    int ct=0;
    int mina=INT_MAX;
    for(int i=0;i<matrix.size(); i++){
        for(int j=0;j<matrix[0].size(); j++){
            sum+=abs(matrix[i][j]);
            if(matrix[i][j]<0)ct++;
            mina=min(mina,abs(matrix[i][j]));
        }
    }
    if(ct%2==0)return sum;
    long long res=sum-(2*mina);
    return res;

    }
};