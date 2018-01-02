#include <iostream>
#include <string>
#include <vector>
#include<string.h>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

static const size_t prime = 263;
unsigned long long hash_func(const string& s, size_t x) {

   //   static const size_t prime = 1000000007;
      unsigned long long hash = 0;
      for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
      {   hash = (hash * x + (int)s[i]) % prime;
     // std::cout << "s[i] is " << s[i] << "and int vALUE IS " << (int) s[i];
      }
    		  return hash;
}

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
  //  std::cout << "Query string is " << s;
    static const size_t multiplier = 17; // 263;
    // 1000000007;
    size_t y = 1;
    unsigned long long hash = hash_func(s, multiplier);

//    std::cout << "HASH value is " << hash << "\n" << "value";
    std::vector<int> ans;
    size_t plen = s.length();
    size_t tlen = t.length();

    if (plen < 1) {
    	//printf("\nFUCKKKKKKKKKKKKK");
//    	return 0;
    }
    string strh = t.substr(tlen - plen , tlen);
    string s2 = t.substr(0, tlen - plen);

   unsigned long long hash1 = hash_func(strh, multiplier);
 //  std::cout << "Hash value is " << hash1 << "string is" << strh << "\n";
  // std ::cout << "REmaining string is " << s2;

   //std::cout << "Char st position len" << s2.length() << "is " << s2[s2.length() - 1];

 //  unsigned long long temp;
   for (size_t i = 0; i < plen; i++)
   {
	   y = ( y * multiplier ) % prime;
   }
   //std::cout << "\nValue of  multiplier y is " << y  << "\n";
    char strtemp[tlen];
   strcpy(strtemp, t.c_str());
   //
   unsigned long long hasht[tlen - plen +1];
   hasht[tlen - plen] = hash1;
 //  tlen = tlen -1;
   //long long temphash = ((multiplier * hash1) + (int) strtemp[tlen - plen] - (y * (int)strtemp[ tlen] ));
   //% prime;
  // std::cout << "\npositive multipliers are " << (multiplier * hash1) + (int) strtemp[tlen - 1 - plen];
   //std::cout << "\nNegative multipliers are " << (y * (int)strtemp[ tlen - 1] );
   //std::cout << "\nTemphash is " << temphash;

   //temphash = temphash % prime;
  // std::cout << "\nFinal Temphash is " << temphash;

   //std::cout << "\nprecomputed hash is " << hasht[tlen - 1];
  // std::cout << "\nstrtemp at len - 2 is " << strtemp[tlen - 2];
   //std::cout << "\nZero value index char is " << strtemp[0];
   //std::cout << "\nCHAR IMPORTANT AT strtemp[tlen - 1 - plen] is " << strtemp[tlen - 1 - plen] << "value is " << (int)strtemp[tlen - 1 - plen] ;
  // std::cout << "\mLast char whose value is to be substracted is " << strtemp[ tlen - 1];

//   if ( temphash < 0)
	//   temphash = temphash + prime;

   //std::cout << "\ntemphash is " << temphash << "\n";


   // ARRAY index manipulation

     bool modres;
   for (size_t tindex = tlen - 1; tindex >= plen; tindex--)
   {
	  // size_t prehash = (multiplier * hasht[tindex + 1]);
	   //std::cout << "prehash is " << prehash;
	  // size_t subtract = (y * (int)strtemp[ tindex + plen]);
	   //std::cout << "subtract" << subtract;
	   long long temphash = (multiplier * hasht[tindex - plen + 1]) + (int) (strtemp[tindex - plen]) - (y * (int)strtemp[tindex]);
	  // std::cout << "";
	   if (temphash < 0)
       {
           modres = false;
           temphash = temphash * -1;
       }
	  temphash = temphash % prime;
	   if (!modres)
       {
           temphash = prime - temphash;
           modres = true;
       }
	   hasht[tindex - plen] = temphash;
	   // hasht[tindex - plen] = ((int) strtemp[tindex] + prehash - subtract) % prime ;
   }
   char stmp[plen];
   strcpy(stmp, s.c_str());

   for(size_t tindex = 0; tindex <= tlen - plen ; tindex++)
   {
	   if(hasht[tindex] != hash)
		   continue;
	   else {
		   size_t index;
		   size_t pind = 0;
		   for (index = tindex; index < tindex + plen -1; index++)
		   {

			//   std::cout << "\ntext char" << t[index] << "pattern char" << s[pind];
			   if (strtemp[index] != stmp[pind])
			   {
				   break;
			   }
			   pind++;
		   }
		   if (index == (tindex + plen - 1))
		   {
			   ans.push_back(tindex);
		   }
	   }
   }

  // std::cout << "\ntindex at o" << hasht[0];


   //std::cout << "Hash of very seoncd last  tring is " << hasht[tlen - 1 - plen];

   //for ()

 //  for (size_t i = plen; i )


   /* for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    */return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
