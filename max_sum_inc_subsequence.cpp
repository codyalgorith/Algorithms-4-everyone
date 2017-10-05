/*this problem is concerned with finding the maximum sum subsequence that can be found such that all 
the numbers in subsequence are in increasing order
thus two conditions are there

1. numbers choosen must be in increasing order
2. sum of these numbers has to maximised

approach is similar to LIS algorithm 


*/

#include<bits/stdc++.h>

using namespace std;



int maxSumIS( int arr[], int n ) // max sum inc subsequence 
{
    int i, j, max = 0;
    int sum[n];  //stores  value of max sum of inc subsequences
 
    /* Initialize sum values for all indexes */
    for ( i = 0; i < n; i++ )
        sum[i] = arr[i];   //since every single element can contribute as single element subsequence
 
    /* Compute maximum sum values in bottom up manner */
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && sump[i]<sum[j] + arr[i])  //checking both conditions
                sum[i] = sum[j] + arr[i];
 
    /* Pick maximum of all sum values */
    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
 
    return max;
}
