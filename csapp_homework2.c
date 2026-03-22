unsigned srl(unsigned x, int k) {

    /* Perform shift arithmetically */

    unsigned xsra = (int) x >> k ;
    
   // 补全代码
    xsra = xsra & (((1<<((sizeof(int)<<3)-k)))-1);


    return xsra;



}



int sra(int x, int k) {

    /* Perform shift logically */ 

    int xsrl = (unsigned) x >> k ;

    // 补全代码
    int sign = !!(x & (1<<((sizeof(int)<<3)-1)));

    int sign_full = ~sign+1;

    int mask = sign_full<<((sizeof(int)<<3)-k);

    xsrl = xsrl | mask;

    return xsrl;



}