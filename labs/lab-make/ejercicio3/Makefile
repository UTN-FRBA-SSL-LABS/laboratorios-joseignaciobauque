CC := gcc
PROGRAMA := calc3

$(PROGRAMA): parser3.y scanner3.l
	bison -d parser3.y
	flex scanner3.l
	$(CC) lex.yy.c parser3.tab.c -o $(PROGRAMA)

clean:
	rm -f $(PROGRAMA) parser3.tab.c parser3.tab.h lex.yy.c
