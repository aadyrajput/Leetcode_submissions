class Solution {
public:
        int res(vector<int>&ch,vector<int>&notch){
            int mina1=*min_element(ch.begin(),ch.end());
            int maxa1=*max_element(ch.begin(),ch.end());
            int mina2=*min_element(notch.begin(),notch.end());
            int maxa2=*max_element(notch.begin(),notch.end());
            int mina=min(mina2,mina1+1);
            int maxa=max(maxa2,maxa1-1);
            if(mina1==maxa1 && mina2==maxa2){
                int diff=abs(mina1-mina2);
                 if(diff==0)return 1;
                return diff-1;
            }

        return abs(mina-maxa);
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return {0,0};

        int ct=0;
        vector<int> notch1,ch1;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(nums[i]%2!=0){ct++; ch1.push_back(nums[i]);}
                else notch1.push_back(nums[i]);
            }
            else{
                 if(nums[i]%2==0){ct++; ch1.push_back(nums[i]);}
                  else notch1.push_back(nums[i]);
            }
        }


        int ct2=0;
        vector<int> notch2,ch2;
        for(int i=0;i<n;i++){
            if(i%2==0){
                if(nums[i]%2==0){ct2++; ch2.push_back(nums[i]);}
                else notch2.push_back(nums[i]);
            }
            else{
                 if(nums[i]%2!=0){ct2++; ch2.push_back(nums[i]);}
                  else notch2.push_back(nums[i]);
            }
        }

        if(ct==0){
            int z=*min_element(notch1.begin(),notch1.end());
            int zz=*max_element(notch1.begin(),notch1.end());
            return {0,abs(z-zz)};
        }
         if(ct2==0){
            int z=*min_element(notch2.begin(),notch2.end());
            int zz=*max_element(notch2.begin(),notch2.end());
            return {0,abs(z-zz)};
        }

        int res1=res(ch1,notch1);
        int res2=res(ch2,notch2);

        if(ct<ct2)return {ct,res1};
        if(ct>ct2)return {ct2,res2};
        int aa=min(res1,res2);
        return {ct,aa};
    }
};