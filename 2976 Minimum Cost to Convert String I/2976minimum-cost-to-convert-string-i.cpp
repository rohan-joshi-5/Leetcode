class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        set<char>s1;
        for(auto ch: original)
        {
            s1.insert(ch);
        }
        for(auto ch:changed)
        {
            s1.insert(ch);
        }
        for(auto ch : source)
        {
            s1.insert(ch);
        }
        for(auto ch : target)
        {
            s1.insert(ch);
        }
        unordered_map<char,int>CI;
        int size = s1.size();
        int i=0;
        for(auto ch : s1)
        {
            CI[ch] = i;
            i++;
        }
        vector<vector<long long>>arr(size,vector<long long>(size,INT_MAX));
        int sizeog = original.size();
        for(int i=0;i<size;i++)
        {
            arr[i][i] = 0;
        }
        for(int i =0;i<sizeog;i++)
        {
            arr[CI[original[i]]][CI[changed[i]]] =
    min(arr[CI[original[i]]][CI[changed[i]]], (long long)cost[i]);

        }


        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(j == i) continue;
                for(int k=0;k<size;k++)
                {
                    if(k==i) continue;
                    if(j==k) continue;
                    if(arr[j][i] == INT_MAX || arr[i][k] == INT_MAX) continue;
                    else
                    arr[j][k] = min(arr[j][k] , ((long long) arr[j][i] + (long long) arr[i][k]));
                }
            }
        }
        long long  ans =0;
        sizeog = source.size();
        for(int i=0;i<sizeog;i++)
        {
            
            if(arr[CI[source[i]]][CI[target[i]]] == INT_MAX) return -1;
            else ans+=arr[CI[source[i]]][CI[target[i]]];
        }      
        return ans;
    }
};