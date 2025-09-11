class Solution {
public:
    string sortVowels(string s) {
        vector<char>t;
        for(char&c:s)
        {
            if((c=='a'|| c=='e' || c=='i' ||c=='o'||c=='u') ||(c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U')) t.push_back(c);

        }
        sort(t.begin(),t.end(),greater<char>());
        for(char&c:s)
        {
             if((c=='a'|| c=='e' || c=='i' ||c=='o'||c=='u') ||(c=='A' || c=='E'|| c=='I'|| c=='O'|| c=='U'))
             {
                c=t[t.size()-1];
                t.pop_back();
             }
        }
        return s;
    }

};