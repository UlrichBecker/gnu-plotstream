# gnu-plotstream
Simple C++ interface for Gnuplot with stream ability like std::cout and so on.

For Linux only! Sorry.

Example:
```
#include <gnuplotstream.hpp>

using namespace std;
using namespace gps;

int main( void )
{
   cout << "Minimal test-program plotting the function si(x)" << endl;
   try
   {
      PlotStream plot;
      plot << "plot sin(x)/x" << endl;
      cout << "Press any key and the enter key to end." << endl;
      int x;
      cin >> x;
   }
   catch( Exception& e )
   {
      cerr << e.what() << endl;
      return EXIT_FAILURE;
   }
   return EXIT_SUCCESS;
}

```
