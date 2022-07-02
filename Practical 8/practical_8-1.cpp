//  Distinct Subsequences

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAXZ 101

using namespace std;

class integer
{
  friend ostream & operator << (ostream&, const integer & );

  public:
    integer() {};
  integer(unsigned int orginal) {
    do {
      digits.push_back(orginal % base);
      orginal /= base;
    } while (orginal);
  };

  ~integer() {};

  integer operator + (const integer & );
  integer & operator += (const integer & );

  private:
    vector < unsigned int > digits;
  static unsigned int
  const base = 10000;
  static unsigned int
  const width = 4;
};

ostream & operator << (ostream & os,
  const integer & number) {
  os << number.digits[number.digits.size() - 1];
  for (int i = number.digits.size() - 2; i >= 0; i--)
    os << setw(number.width) << setfill('0') << number.digits[i];
  return os;
}

integer & integer::operator += (const integer & b) {
  return *this = * this + b;
}

integer integer::operator + (const integer & b) {
  integer c;

  int carry = 0;
  for (int i = 0; i < digits.size() || i < b.digits.size() || carry; i++) {
    if (i < digits.size())
      carry += digits[i];
    if (i < b.digits.size())
      carry += b.digits[i];

    c.digits.push_back(carry % base);
    carry /= base;
  }

  return c;
}

void distinctSubsequences(string x, string z) {
  integer occurrences[MAXZ];

  int xLength = x.length();
  int zLength = z.length();

  occurrences[0] = integer(1);
  for (int i = 1; i <= zLength; i++) occurrences[i] = integer(0);

  for (int i = 1; i <= xLength; i++)
    for (int j = zLength; j >= max(int(zLength - xLength + i), 1); j--)
      if (x[i - 1] == z[j - 1])
        occurrences[j] += occurrences[j - 1];

  cout << occurrences[z.length()] << endl;
}

int main(int ac, char * av[]) {
  string x, z;
  int cases;

  cin >> cases;
  while (cases--) {
    cin >> x >> z;

    if (x.length() < z.length()) cout << 0 << endl;
    else
      distinctSubsequences(x, z);
  }

  return 0;
}
