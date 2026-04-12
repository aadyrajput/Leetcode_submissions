class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        if(sides[0]+sides[1]<=sides[2] || sides[0]+sides[2]<=sides[1]
             || sides[2]+sides[1]<=sides[0])return {};

        double a=(double)sides[0], b=(double)sides[1], c=(double)sides[2];

        double first=acos(((a*a)+ (c*c)- (b*b))/(2.000000*a*c));
        double sec=acos(((a*a)+ (b*b)- (c*c))/(2.000000*a*b));
        double third=acos(((b*b)+ (c*c)- (a*a))/(2.000000*b*c));

        double pie=acos(-1.0);
        double conv=180.0/pie;
        first=first*conv;
        sec=sec*conv;
        third=third*conv;

        vector<double>ans= {first,sec,third};
        sort(ans.begin(),ans.end());
        return ans;
    }
};