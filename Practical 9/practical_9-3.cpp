 #include <iostream>
 #include <cmath>
 using namespace std;

 int main(int ac, char *av[])
 {
     int step;
     while (cin >> step, step)
     { // determines the column or row in which the step number is located.
          int column = (int)ceil(sqrt(step));
          //Determine the number on the diagonal:column * (column - 1) + 1.
           int diagonal = column * (column - 1) + 1;
           //Positions are determined based on diagonal numbers and the relationship of step numbers to diagonal numbers.
           if (column & 1)
            { if (step >= diagonal)
                cout << (column - (step - diagonal)) << " " << column << endl;
              else cout << column << " " << (column - (diagonal - step)) << endl;
            }
            else
            {
                if (step >= diagonal)
                    cout << column << " " << (column - (step - diagonal)) << endl;
                else
                    cout << (column - (diagonal - step)) << " " << column << endl;
            }
      }
      return 0;
 }
