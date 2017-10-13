// Fig. 6.30: fig06_30.cpp
// Fibonacci function with iteration and less memory space.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <limits>
unsigned long  max_unsigned_int = std::numeric_limits<unsigned long>::max();

unsigned long fibonacci( unsigned long ); // function prototype
bool flag = 1; // check whether data overflow

int main()
{
   // Mohan Test Large value
   unsigned long a;
   cout << "Enter a value to calculate the fibonacci number: " ;
   cin >> a;

   unsigned long b = fibonacci( a ); // store result to variable b
   if (flag == 1)
   {
      cout << "fibonacci("<< a << ") = " << b << endl;
      return 0; // indicates successful termination
   }
   else
      return -1; // indicates unsuccessful termination
} // end main

// recursive method fibonacci
unsigned long fibonacci( unsigned long number )
{
   unsigned long last[ 2 ] = {0,1}; // Initialize the fibonacci series
   unsigned long tmp; // Temperary variable

   if ( ( number == 0 ) || ( number == 1 ) ) // base cases
      return number;
   else
   {
      for ( unsigned long i = 2; i <= number; i++ )
      {
         tmp = last[1];
         if ( max_unsigned_int - last[1] < last[0] ) // check whether overflow
         {
            cout << "Maximum value reached!" << endl;
            flag = 0;
            return -1;
         }
         last[1] += last[0];
         last[0] = tmp;
      }
   }

   // check the whether the ratio is converged to golden value
   cout << "ratio of current over previous is " 
        << static_cast<double>(last[1])/last[0] << endl;
   return last[1];
} // end function fibonacci
