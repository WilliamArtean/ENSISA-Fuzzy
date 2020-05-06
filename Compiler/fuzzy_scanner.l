%{ /* -*- C++ -*- */
# include <cerrno>
# include <climits>
# include <cstdlib>
# include <string>
# include <cstring>
# include "fuzzy_driver.h"
# include "fuzzy_parser.tab.hh"

// Work around an incompatibility in flex (at least versions
// 2.5.31 through 2.5.33): it generates code that does
// not conform to C89.  See Debian bug 333231
// <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.
# undef yywrap
# define yywrap() 1

// The location of the current token.
static yy::location loc;
%}

%option noyywrap nounput batch debug never-interactive

id    [-a-zA-Z0-9][a-zA-Z_.0-9]*
blank [ \t]

%{
  // Code run each time a pattern is matched.
  # define YY_USER_ACTION  loc.columns (yyleng);
%}

%%

%{
  // Code run each time yylex is called.
  loc.step ();
%}

{blank}+   loc.step ();
[\n]+      loc.lines (yyleng); loc.step ();

"is"           return yy::fuzzy_parser::make_IS(loc);
"if"           return yy::fuzzy_parser::make_IF(loc);
"agg"          return yy::fuzzy_parser::make_AGG(loc);
"not"          return yy::fuzzy_parser::make_NOT(loc);
"and"          return yy::fuzzy_parser::make_AND(loc);
"or"           return yy::fuzzy_parser::make_OR(loc);
"then"         return yy::fuzzy_parser::make_THEN(loc);
"defuzz"       return yy::fuzzy_parser::make_DEFUZZ(loc);
"membership"   return yy::fuzzy_parser::make_MEMBERSHIP(loc);
"triangle"     return yy::fuzzy_parser::make_TRIANGLE(loc);
"values"       return yy::fuzzy_parser::make_VALUES(loc);
"operators"    return yy::fuzzy_parser::make_OPERATORS(loc);
"gaussian"     return yy::fuzzy_parser::make_GAUSS(loc);
"gbellmf"      return yy::fuzzy_parser::make_GBELLMF(loc);
"("            return yy::fuzzy_parser::make_LPAREN(loc);
")"            return yy::fuzzy_parser::make_RPAREN(loc);
"{"            return yy::fuzzy_parser::make_LEMBR(loc);
"}"            return yy::fuzzy_parser::make_REMBR(loc);
"="            return yy::fuzzy_parser::make_EQUAL(loc);

{id}       return yy::fuzzy_parser::make_IDENTIFIER(yytext, loc);

.          driver.error (loc, "invalid character");
<<EOF>>    return yy::fuzzy_parser::make_END(loc);
%%



void
fuzzy_driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      error ("cannot open " + file + ": " + strerror(errno));
      exit (EXIT_FAILURE);
    }
}

void
fuzzy_driver::scan_end ()
{
  fclose (yyin);
}
