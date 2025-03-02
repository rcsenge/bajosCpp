ez a hibaüzi:
rcsng@192 Nem_OO % make      
g++    -pedantic -Wall -Werror -g  -DMEMTRACE -std=c++98   -c -o nem_oo_teszt.o nem_oo_teszt.cpp
In file included from nem_oo_teszt.cpp:39:
In file included from ./nem_oo.h:14:
./memtrace.h:225:9: error: keyword is hidden by macro definition [-Werror,-Wkeyword-macro]
#define new new(__LINE__, __FILE__)
        ^
./memtrace.h:226:9: error: keyword is hidden by macro definition [-Werror,-Wkeyword-macro]
#define delete memtrace::set_delete_call(__LINE__, __FILE__),delete
        ^
2 errors generated.
make: *** [nem_oo_teszt.o] Error 1
