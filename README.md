# gnu-plotstream
Simple C++ interface for Gnuplot with stream ability like std::cout and so on.

Small but it supports the full functionality of Gnuplot.

For Linux only! Sorry.

Example:
```C++
#include <gnuplotstream.hpp>

using namespace std;
using namespace gpstr; // Namespace for Gnu-Plot-STReam

int main( void )
{
   cout << "Minimal test-program plotting the function si(x)" << endl;
   try
   {
      PlotStream plot;
      plot << "plot sin(x)/x" << endl;

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
```
Result:

![Result of example above](./plotstream_result.png)
