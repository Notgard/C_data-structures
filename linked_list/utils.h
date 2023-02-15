#define TRUE 1
#define FALSE 0

#define ERR_CLR "\033[0;31m"
#define CLR_CLEAR "\033[0m"

#define error(...) fprintf(stderr, ERR_CLR __VA_ARGS__ CLR_CLEAR)