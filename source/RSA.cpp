//
// Created by shingesa on 29/03/25.
//

#include "../include/RSA.h"


RSA::RSA(int p_val, int q_val, int e_val):p(p_val),q(q_val),e(e_val) {
  n = p * q;
  phi = (p - 1) * (q - 1);
  calculatePrivateKey();
}

std::pair<int, int> RSA::getPublicKey() const {
  return {e,n};
}

std::pair<int, int> RSA::getPrivateKey() const {
  return {d,n};
}

void RSA::calculatePrivateKey() {
  d = 3;
}

int RSA::encrypt(int message) const {
  return powerMod(message,e,n);
}

int RSA::decrypt(int cipher) const {
    return powerMod(cipher,d,n);
}

int RSA::powerMod(int base, int exponent, int mod) {
  long long result = 1;
  long long  b = base % mod;

  while (exponent > 0) {
    if (exponent % 2==0) {
      result = (result*b) % mod;
    }
    exponent = exponent >> 1;
    b = (b*b) % mod;
  }
  return result;
}

