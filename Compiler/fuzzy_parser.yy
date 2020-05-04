%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define parser_class_name {fuzzy_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%code requires
{
# include <string>
class fuzzy_driver;
}
// The parsing context.
%param { fuzzy_driver& driver }
%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};
%define parse.trace
%define parse.error verbose
%code
{
# include "fuzzy_driver.h"
}
%define api.token.prefix {TOK_}
%token
  END  0        "end of file"
  IF            "if"
  IS            "is"
  AND           "and"
  OR            "or"
  THEN          "then"
  DEFUZZ        "defuzz"
  MEMBERSHIP    "membership"
  TRIANGLE      "triangle"
  VALUES        "values"
  OPERATORS     "operators"
  LEMBR         "{"
  REMBR         "}"
  LPAREN        "("
  RPAREN        ")"
  EQUAL         "="
  AGG           "agg"
  NOT           "not"
;
%token <std::string> IDENTIFIER "identifier"
%type  <std::string>
  Operator
  Not
%printer { yyoutput << $$; } <*>;

%%
%start File;

File 	: "identifier" "identifier" "{" System "}" {driver.result.push_back($1);}
		;

System 	: Operators Membership Values Phrases   {}
		;

Operators 	: "operators" "{" And Or Then Defuzz Agg "}" {}
			;

And	: %empty                {driver.result.push_back("default");}
	| "and" "=" Operator    {driver.result.push_back($3);}
	;

Agg	: %empty                {driver.result.push_back("default");}
    | "agg" "=" Operator    {driver.result.push_back($3);}
    ;

Or	: %empty                {driver.result.push_back("default");}
	| "or" "=" Operator     {driver.result.push_back($3);}
	;

Then	: %empty                {driver.result.push_back("default");}
	    | "then" "=" Operator   {driver.result.push_back($3);}
	    ;

Defuzz	: %empty                {driver.result.push_back("default");}
	    | "defuzz" "=" Operator {driver.result.push_back($3);}
	    ;

Operator    : "identifier"  { $$ = $1; }
            ;

Membership	: "membership" "{" Curves "}"   {}
			;

Curves  : %empty        {}
        | Curve Curves  {}
        ;

Curve   : "identifier" "=" Shape {driver.result.push_back($1);}
        ;

Shape   : "triangle"  "identifier" "identifier" "identifier" {driver.result.push_back("triangle");
                                                                    driver.result.push_back($2);
                                                                    driver.result.push_back($3);
                                                                    driver.result.push_back($4);
                                                              }
        ;

Values  : %empty                    {}
        | Value Values              {}
        | "values" "{" Values "}"   {}
        ;

Value   : Name OptAs {}
        ;

Name    : "identifier" {driver.result.push_back($1);}
        ;

OptAs   : "=" "identifier"  {driver.result.push_back($2);}
        | %empty            {driver.result.push_back("0");}
        ;

Phrases : %empty            {}
        | Phrase Phrases    {}
        ;

Phrase  : If Inputs       {}
        ;

If      : "if"             {driver.result.push_back("newphrase");}
        ;

Inputs  : Input Link Inputs       {}
        | Thenphrase Input             {}
        ;

Thenphrase    :   "then"  {driver.result.push_back("then");}
        ;

Input   :  "identifier" "is" Not "identifier" {driver.result.push_back($1);driver.result.push_back($3);driver.result.push_back($4);}
        ;

Not     : %empty    {$$ = "notnot";}
        | "not"     {$$ ="not";}
        ;

Link    : "and"     {driver.result.push_back("and");}
        | "or"      {driver.result.push_back("or");}
        | %empty    {}
        ;
%%

void
yy::fuzzy_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
