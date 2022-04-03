mergeSort_reverse(a, r, m , n);
    number_of_executions+=1;
    mergeSort_reverse(a, m-1, l, n);
    number_of_executions+=1;
    merge_reverse(a, l, r, m);