%pointer
%option noyywrap

%%

 /* ── Reglas ya implementadas ────────────────────────── */
0[0-7]*         { printf("constante octal: %s\n", yytext); }
 /* Ignorar espacios, tabs y saltos de línea */
[ \t\n]         { }
[1-9][0-9]*         { printf("constante decimal: %s\n", yytext); }
0[x|X][0-9a-fA-F]+         { printf("constante hexadecimal: %s\n", yytext); }
[_a-zA-Z][_a-zA-Z0-9]*         { printf("identificador: %s\n", yytext); }
.         { printf("caracter no reconocido: %s\n", yytext); }
 
%%

int main(void) {
    yylex();
    return 0;
}
