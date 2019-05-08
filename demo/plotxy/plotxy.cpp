/*!
 *  @file plotxy.cpp
 *  @brief  Test program plotting X/Y coordinates
 *
 *  @date 07.05.2019
 *  @copyright (C) 2019 GSI Helmholtz Centre for Heavy Ion Research GmbH
 *
 *  @author Ulrich Becker <u.becker@gsi.de>
 *
 *  @see gnuplotstream.hpp
 ******************************************************************************
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************
 */
#include <gnuplotstream.hpp>

using namespace std;
using namespace gpstr;

int main( void )
{
   cout << "Minimal test-program plotting X/Y coordinates" << endl;
   try
   {
      PlotStream plot( "-noraise" );
      plot << "set terminal X11 title \"XY-Test\"" << endl;
      plot << "set grid" << endl;
      plot << "plot '-' title \"Test\" with lines" << endl;
      for( int i = 0; i <= 100; i++ )
         plot << i << ' ' << i << endl;
      plot << 'e' << endl;
      cout << "Press the enter key to end." << endl;
      ::fgetc( stdin );
   }
   catch( Exception& e )
   {
      cerr << e.what() << endl;
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

//================================== EOF ======================================
