//
// Created by shingesa on 29/03/25.
//

#ifndef RSA_H
#define RSA_H
#include <utility>


class RSA {
private:
  int p,q,n,phi,e,d;

  void calculatePrivateKey();

public:

  RSA(int p_val = 3, int q_val = 11, int e_val = 7);

  std::pair<int,int> getPublicKey() const;

  std::pair<int ,int> getPrivateKey() const;

  int encrypt (int message) const;
  int decrypt (int cipher) const;

  static int powerMod(int base,int exponent, int mod);

};



#endif //RSA_H
