/** tutorial_pba_0.cpp
 *
 * (C) Copyright 2011 François Mauger, Christian Pfligersdorffer
 *
 * Use, modification and distribution is subject to the Boost Software
 * License, Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 */

 /**
  * The intent of this program is to serve as a tutorial for
  * users of the portable binary archive in the framework of
  * the Boost/Serialization library.
  *
  * This quick start example shows how to store some variables
  * of basic types (bool, integer, floating point numbers, STL string)
  * using the portable binary archive format associated to a
  * standard output file stream.
  *
  */
/*
* Test load and save cross x64 and x86 build. by jb2020-super
* This is the only way that I found work.
*/
#include <string>
#include <fstream>

#include <boost/cstdint.hpp>
//#include <boost/archive/portable_binary_oarchive.hpp>
#include "portable_oarchive.hpp"
#include "portable_iarchive.hpp"

int main(void)
{
    // The name for the example data file :  
    std::string filename = "pba_0.data";
#if defined _WIN64
    // Some variables of various primitive types :
    bool        b = true;
    char        c = 'B';
    uint32_t    answer = 42;
    float       computing_time = 7.5e6;
    double      e = 2.71828182845905;
    std::string slogan = "DON'T PANIC";

    // Open an output file stream in binary mode :
    std::ofstream fout(filename.c_str(), std::ios_base::binary);

    {
        // Create an output portable binary archive attached to the output file :
        //boost::archive::portable_binary_oarchive opba(fout);
        eos::portable_oarchive opba(fout);

        // Store (serializing) variables :
        opba& b& c& answer& computing_time& e& slogan;
    }
#else
    std::ifstream ifs(filename.c_str(), std::ios_base::binary);
    {
        eos::portable_iarchive ipba(ifs);
        bool        b{};
        char        c{};
        uint32_t    answer{};
        float       computing_time{};
        double      e{};
        std::string slogan;
        ipba& b& c& answer& computing_time& e& slogan;
    }
#endif
    return 0;
}

// end of tutorial_pba_0.cpp
