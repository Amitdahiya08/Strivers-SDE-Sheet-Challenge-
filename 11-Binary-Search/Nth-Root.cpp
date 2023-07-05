int NthRoot(int n, int m) {
    if(m == 1 || n == 1)
      return m;
    int start = 2, end = m - 1,mid = 0;
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(pow(mid, n) == m)
          return mid;
        else if(pow(mid, n) > m)
          end = mid - 1;
        else  
          start = mid + 1;
    }
    return -1;
}
