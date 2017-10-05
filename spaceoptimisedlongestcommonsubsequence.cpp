/*we all know that our native DP lcs solution requires O(m*n) memory if the strings have length m and n respectively
in this method , we will need only O(n or m) memory*/
/*idea is for a update in lcs algorithm we need only info about current row and previous row 
i.e. in update step
    if(X[i-1]==Y[j-1)
    {
    t[i][j]= 1+ t[i-1][j-1];
    }
    else{
    
    t[i][j]= max(t[i-1][j],t[i][j-1]);   
    }

we need only current row and previous row
so we are here using only 2 rows  ,thus after each cycle we will change their role and thus find the 
whole solution using these 2 rows only

*/
#include<bits/stdc++.h>
int lcs(string X, string Y)
{
    // Find lengths of two strings
    int m = X.length(), n = Y.length();
 
    int L[2][n+1];  // y has length n here  
 memset(L,0,sizeof(L)); // to set L to zero 
    int mode=1; // mode  stores current row number being updated 0 or 1
 
    for (int i=1; i<=m; i++)
    {
        // Compute current binary index
        
 
        for (int j=1; j<=n; j++)
        {
            
 
            else if (X[i-1] == Y[j-1])
                L[mode][j] = L[1-mode][j-1] + 1; // if mode =0 then another row is mode=1 ,similarly if mode=1 another row is mode=0
 
            else
                L[mode][j] = max(L[1-mode][j], L[mode][j-1]);
        }
        mode=1-mode; //changing roles of the rows
    }
 
    /* Last filled entry contains length of LCS
       for X[0..n-1] and Y[0..m-1] */
    return L[mode][n];
}
