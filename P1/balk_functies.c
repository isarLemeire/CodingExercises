#include "balk_functies.h"

int volume(balk balk){
    return balk.b*balk.h*balk.l;
}

int area(balk balk){
    return 2*(balk.b*balk.h + balk.b*balk.l + balk.l*balk.h);
}