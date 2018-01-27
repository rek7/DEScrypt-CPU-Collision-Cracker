#ifndef CRYPTO_HPP
#define CRYPTO_HPP

class attempt
{
public:
  bool try_crypt(string hash, string word)
  {
    return (crypt(word.c_str(), (hash.substr(0,2)).c_str()) == hash ? true : false);
  }
};

#endif // CRYPTO_HPP