#include <iostream>

/*
                Q. single element in sorted array

            explanation -  we have to find single occuring element in a sorted array
                            arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}

                        note - one element will always be single and othe elements are always in pairs(bcz arrya is sorted)

        Brute force -  at a particular index either 'n+1' or 'n-1' index has the same element, if this is not the case then 
                        that index contains single element

                        at '0' index - n+1 index has the same nmbr
                        at '1' index - n-1 index has the same nmbr
                        at '2' index - n+1 index has the same nmbr
                        at '3' index - n-1 index has the same nmbr
                            and so on...untill
                        at '6' index - neither 'n+1' index nor 'n-1' index has the same nmbr
                                so element at '6' index is the single element

    Pseudo code
if(n == 1)
    return arr[0];
for(i=0; i<n; i++)
{
    if(i == 0)
        if(arr[i] != arr[i+1])
            return arr[i];
        else if(i == n-1)
            if(arr[i] != arr[i-1])
                return arr[i];
        else
            if(arr[i] != arr[i+1] && arr[i] != arr[i-1])
                return arr[i];
}

    
        TC - O(N)



            Optimized sol -  apply binary search with elimination of other halves

                                    0  1  2  3  4  5  6  7  8  9  10
                           arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6}

                                lets take 4, 
                                    when we look in the left, we can find that the pairs are in (even, odd) index manner
                                    when we look in the right, we can find that the pairs are in (odd, even) index manner

                                we can say that
                                (even, odd) -> element is on the right half
                                (odd, even) -> element is on the left half

                                we have to take consideration of edge cases
                                i.e, for '0' index there is no left element
                                     for 'n-1' index there is no right element
                                so we have to trim down our search area from index '1' to 'n-2'

            // apply binary search, low = 1, high = n-2(9), mid = 5
            // at mid=5, element is '4'. just previous to mid the pairs were in (even, odd) manner so the element is in right half, eliminate left half
            // applying binary search to right half, low = 6, high = 9, mid = 7
            // at mid=7, element is '4',. just fwd to mid pairs are in (odd, even) manner, so the element is in left half, eliminating right half(i.e, 5, 5, 6)
            // applying binary search, low = 5, high = 5, mid = 5
            // at mid=5, element is '4'. here we search 'mid+1' & 'mid-1' if one of them is not equal to mid then mid is the single nmbr

    pseudo code
f(arr, n)
{
    if(n == 1)
        return arr[0];
    if(arr[0] != arr[1])
        return arr[0];
    if(arr[n-1] != arr[n-2])
        return arr[n-1];

    // apply binary search, low = 1, high = n-2(9), mid = 5
    // at mid=5, element is '4'. just previous to mid the pairs were in (even, odd) manner so the element is in right half, eliminate left half
    // applying binary search to right half, low = 6, high = 9, mid = 7
    // at mid=7, element is '4',. just fwd to mid pairs are in (odd, even) manner, so the element is in left half, eliminating right half(i.e, 5, 5, 6)
    // applying binary search, low = 5, high = 5, mid = 5
    // at mid=5, element is '4'. here we search 'mid+1' & 'mid-1' if one of them is not equal to mid then mid is the single nmbr

    low = 1, high = n-2;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];

        if((mid % 2) == 1 && arr[mid - 1] == arr[mid])                  // we are on left half and element is in right half
            eliminate left half
        or ((mid % 2) == 0 && arr[mid] == arr[mid+1])
            eliminate right half
    }
}


        Actual code
int singleNonDuplicate(vector<int> & arr)
{
    int n = arr.size();
    if(n == 1)
        return arr[0];
    if(arr[0] != arr[1])
        return arr[0];
    if(arr[n-1] != arr[n-2])
        return arr[n-1];

    int low = 1, high = n-2;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
        {
            return arr[mid];
        }
        
        // we are in left
        if((mid % 2) == 1 && arr[mid] == arr[mid + 1])
            || ((mid % 2) == 0 && arr[mid] == arr[mid + 1])
        {
            low = mid + 1;
        }

        // we are on right
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


            TC - O(log base2 N)
*/

int main()
{
    std::cout << "Hello World!\n";
}