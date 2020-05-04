//
// Created by coscoy on 28/04/2020.
//

#ifndef CLIONTEST_FUZZY_DRIVER_H
#define CLIONTEST_FUZZY_DRIVER_H

# include <string>
# include <map>
# include "fuzzy_parser.tab.hh"
// Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::fuzzy_parser::symbol_type yylex (fuzzy_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;
// Conducting the whole scanning and parsing of Calc++.
class fuzzy_driver
{
public:
    fuzzy_driver();
    virtual ~fuzzy_driver ();

    std::vector<std::string> result;
    // Handling the scanner.
    void scan_begin ();
    void scan_end ();
    bool trace_scanning;

    // Run the parser on file F.
    // Return 0 on success.
    int parse (const std::string& f);
    // The name of the file being parsed.
    // Used later to pass the file name to the location tracker.
    std::string file;
    // Whether parser traces should be generated.
    bool trace_parsing;
    // Error handling.
    void error (const yy::location& l, const std::string& m);
    void error (const std::string& m);
};
#endif //CLIONTEST_FUZZY_DRIVER_H
