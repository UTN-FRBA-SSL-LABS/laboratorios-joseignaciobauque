CC := gcc
PROGRAMA := scanner2

$(PROGRAMA): scanner2.l
	flex scanner2.l
	$(CC) lex.yy.c -o $(PROGRAMA)

clean:
	rm -f $(PROGRAMA) lex.yy.c
