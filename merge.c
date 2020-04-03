
void mergesort(int arr[], int p, int r) {
    int q;
    if(p<r) {
        q = (p+r)/2;
        mergesort(arr, p , q);
        mergesort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}
void merge(int arr[], int p, int q, int r) {
    int i = p, j = q+1, k = p;

	int * tmp = (int*)malloc(sizeof(int)*num);
    
	while(i<=q && j<=r) {
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else tmp[k++] = arr[j++];
    }

    while(i<=q) tmp[k++] = arr[i++];
    while(j<=r) tmp[k++] = arr[j++];

    for(int a = p; a<=r; a++)
		arr[a] = tmp[a];

	free(tmp);
}

