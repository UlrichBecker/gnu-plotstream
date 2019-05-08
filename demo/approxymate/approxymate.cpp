/*!
 *  @file multiplot.cpp
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
   try
   {
      PlotStream plot;
      plot << "set terminal X11 title \"Approximate\"" << endl;

      plot << "approx_1(x) = x - x**3/6" << endl;
      plot << "approx_2(x) = x - x**3/6 + x**5/120" << endl;
      plot << "approx_3(x) = x - x**3/6 + x**5/120 - x**7/5040" << endl;

      plot << "label1 = \"x - {x^3}/3!\"" << endl;
      plot << "label2 = \"x - {x^3}/3! + {x^5}/5!\"" << endl;
      plot << "label3 = \"x - {x^3}/3! + {x^5}/5! - {x^7}/7!\"" << endl;

      plot << "set termoption enhanced" << endl;
      plot << "save_encoding = GPVAL_ENCODING" << endl;
      plot << "set encoding utf8" << endl;

      plot << "set title \"Polynomial approximation of sin(x)\"" << endl;
      plot << "set key Left center top reverse" << endl;
      plot << "set xrange [ -3.2 : 3.2 ]" << endl;
      plot << "set xtics (\"-π\" -pi, \"-π/2\" -pi/2, 0, \"π/2\" pi/2, \"π\" pi)" << endl;
      plot << "set format y \"%.1f\"" << endl;
      plot << "set samples 500" << endl;
      plot << "set style fill solid 0.4 noborder" << endl;

      plot << "plot '+' using 1:(sin($1)):(approx_1($1)) with filledcurve title label1 lt 3, "
              "'+' using 1:(sin($1)):(approx_2($1)) with filledcurve title label2 lt 2, "
              "'+' using 1:(sin($1)):(approx_3($1)) with filledcurve title label3 lt 1, "
              "sin(x) with lines lw 1 lc rgb \"black\"" << endl;

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
