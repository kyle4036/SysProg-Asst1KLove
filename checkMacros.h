#ifndef CHECKMACROS_H
#define CHECKMACROS_H

#define CHECKREAD(x) do{\
    if((x) == -1){\
        printf("In - %s\nFunction - %s\nLine# %d",__FILE__,__func__,(__LINE__)-1);\
        printf(":\n\tCannot Read File: ");\
        switch(errno){\
            case EINVAL: printf("File unsuitable for reading.\n"); exit(1);\
            default : printf("Kernel or program error.\n"); exit(1);\
        }\
    }\
}while(0)\

#define CHECKMALLOC(x) do{\
    if((x) == NULL){\
        printf("In - %s\nFunction - %s\nLine# %d",__FILE__,__func__,(__LINE__)-1);\
        printf(":\n\tCouldn't malloc() on line %d! Exiting...",(__LINE__)-1);\
        exit(1);\
    }\
}while(0)\

#endif
