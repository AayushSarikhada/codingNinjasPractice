double geometricSum(int k){
    if( k == 0 ){
        return 1;
    }

    return (1+(geometricSum(k-1)/2));
}