/*!
 *  @file surface3D.cpp
 *  @brief  Test program plotting 3D surface from a function
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
#include <gnuplotstream.hpp>

using namespace std;
using namespace gpstr;

int main( void )
{
   try
   {
      PlotStream plot;
      plot << "set grid nopolar" << endl;
      plot << "set grid xtics nomxtics ytics nomytics noztics nomztics nortics "
              "nox2tics nomx2tics noy2tics nomy2tics nocbtics nomcbtics" << endl;
      plot << "set grid layerdefault   lt 0 linecolor 0 linewidth 0.500,  "
              "lt 0 linecolor 0 linewidth 0.500" << endl;
      plot << "set label 1 \"This is the surface boundary\" "
              "at -10.0000, -5.00000, 150.000 center norotate back nopoint" << endl;
      plot << "set arrow 1 from -10.0000, -5.00000, 120.000 to -10.0000, 0.00000, 0.00000 "
              "nohead back nofilled linewidth 1.000" << endl;
      plot << "set arrow 2 from -10.0000, -5.00000, 120.000 to 10.0000, 0.00000, 0.00000 "
              "nohead back nofilled linewidth 1.000" << endl;
      plot << "set arrow 3 from -10.0000, -5.00000, 120.000 to 0.00000, 10.0000, 0.00000 "
              "nohead back nofilled linewidth 1.000" << endl;
      plot << "set arrow 4 from -10.0000, -5.00000, 120.000 to 0.00000, -10.0000, 0.00000 "
              "nohead back nofilled linewidth 1.000" << endl;
      plot << "set style increment default" << endl;
      plot << "set samples 21, 21" << endl;
      plot << "set isosamples 11, 11" << endl;
      plot << "set style data lines" << endl;
      plot << "set title \"3D surface from a function\"" << endl;
      plot << "set xlabel \"X axis\"" << endl;
      plot << "set xlabel  offset character -3, -2, 0 font \"\" textcolor lt -1 norotate" << endl;
      plot << "set xrange [ -10.0000 : 10.0000 ] noreverse nowriteback" << endl;
      plot << "set x2range [ * : * ] noreverse writeback" << endl;
      plot << "set ylabel \"Y axis\"" << endl;
      plot << "set ylabel  offset character 3, -2, 0 font \"\" textcolor lt -1 rotate" << endl;
      plot << "set yrange [ -10.0000 : 10.0000 ] noreverse nowriteback" << endl;
      plot << "set y2range [ * : * ] noreverse writeback" << endl;
      plot << "set zlabel \"Z axis\"" << endl;
      plot << "set zlabel  offset character -5, 0, 0 font \"\" textcolor lt -1 norotate" << endl;
      plot << "set zrange [ * : * ] noreverse writeback" << endl;
      plot << "set cbrange [ * : * ] noreverse writeback" << endl;
      plot << "set rrange [ * : * ] noreverse writeback" << endl;
      // Last datafile plotted: "$grid"
      plot << "splot x*y" << endl;

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
