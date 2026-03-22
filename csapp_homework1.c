int A(int x) {
    return !(~x );
}

int B(int x) {
    return !x;
}

int C(int x) {
    return !(~(x<<(sizeof(int)<<3)-8)&(0xFF<<(sizeof(int)<<3)-8));
}

int D(int x) {
    return !(x>>((sizeof(int)<<3)-8));
}

