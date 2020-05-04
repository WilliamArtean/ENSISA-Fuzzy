//
// Created by coscoy on 28/04/2020.
//

#include "fuzzy_driver.h"
#include "fuzzy_parser.tab.hh"

fuzzy_driver::fuzzy_driver ()
        : trace_scanning (false), trace_parsing (false)
{

}

fuzzy_driver::~fuzzy_driver ()
{
}

int
fuzzy_driver::parse (const std::string &f)
{
    file = f;
    scan_begin ();
    yy::fuzzy_parser parser (*this);
    parser.set_debug_level (trace_parsing);
    int res = parser.parse ();
    scan_end ();
    return res;
}

void
fuzzy_driver::error (const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void
fuzzy_driver::error (const std::string& m)
{
    std::cerr << m << std::endl;
}