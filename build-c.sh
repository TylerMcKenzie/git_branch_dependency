haxe build-c.hxml && gcc -O3 -std=c11 -o main -I bin/hl_c /hashlink/src bin/hl_c/main.c /hashlink/src/hlc_main.c -lhl -lm
#gcc bin/hl_c/main.c -o main -I bin/hl_c /hashlink/src -lhl -lm
