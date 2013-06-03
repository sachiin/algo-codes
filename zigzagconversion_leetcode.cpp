class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result;
        if(nRows == 1)
         return s;;
        for(int i =0;i<nRows;i++)
        {
            bool flag = false;
            for(int j=i;j<s.size();flag=!flag)
            {
                result +=s[j];
                if((!flag || i==0) && i != nRows-1)
                {
                    j+=2*nRows-2-2*i;
                }
                else 
                j += 2*i;
                
            }
        }
        return result;
        
    }
};
