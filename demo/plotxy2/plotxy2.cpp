/*!
 *  @file plotxy2.cpp
 *  @brief  Test program plotting two graphs in X/Y coordinates
 *
 *  @date 20.08.2019
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
   cout << "Minimal test-program plotting two graphs in X/Y coordinates" << endl;
   try
   {
      constexpr int maxXY = 100;
      PlotStream plot( "-noraise" );
      plot << "set terminal X11 title \"XY-Test\"" << endl;
      plot << "set grid" << endl;
      plot << "set xrange [0:" << maxXY << ']' << endl;
      plot << "set yrange [0:" << maxXY << ']' << endl;
      plot << "plot '-' title 'rising' with lines,"
                  " '-' title 'falling' with lines" << endl;
 
      // Plotting rising line.
      for( int i = 0; i <= maxXY; i++ )
         plot << i << ' ' << i << endl;
      plot << 'e' << endl;

      // Plotting falling line.
      for( int i = 0; i <= maxXY; i++ )
         plot << i << ' ' << maxXY-i << endl;
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
