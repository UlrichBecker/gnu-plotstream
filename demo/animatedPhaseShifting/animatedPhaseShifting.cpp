/*!
 *  @file animatedPhaseShifting.cpp
 *  @brief  Minimal test program for animating phase shifting of a
 *          sinus function.
 *
 *  @date 09.05.2019
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
#include <unistd.h>
#include <gnuplotstream.hpp>

using namespace std;
using namespace gpstr;

constexpr double PI = 3.14159;

int main( void )
{
   try
   {
      PlotStream plot( "-noraise" );
      cout << "Press the keys Ctrl and C to end." << endl;
      double phase = 0.0;
      while( true )
      {
         plot << "plot sin(x-" << phase << ")" << endl;
         ::usleep( 100000 );
         if( phase >= (2 * PI - PI / 100.0) )
            phase = 0.0; 
         else
            phase += (PI / 100.0) ;
      }
   }
   catch( Exception& e )
   {
      cerr << e.what() << endl;
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

//================================== EOF ======================================
