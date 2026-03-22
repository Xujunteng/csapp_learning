/* Declaration of data type where 4 bytes are packed into an unsigned */

typedef unsigned packed_t;



/* Extract byte from word. Return as signed integer */

int xbyte(packed_t word, int bytenum){

    return ((int)(((word >> (bytenum << 3))<<24))>>24);

}

