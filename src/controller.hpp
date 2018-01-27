#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class controller : public attempt
{
public:
  void file_write(string data)
  {
    while(1)
    {
      if(hash_write.try_lock())
      {
        ofstream hash_output(config->output_file, ios::app);
        if(hash_output.is_open())
        {
          hash_output << data;
          hash_output.close();
          hash_write.unlock();    
          return;
        }
        else
        {
          cout << "\e[31m[" << time(0) << "] [-] Error Opening: '" << config->output_file << "' For writing\e[39m" << endl;
          exit(1);      
        }
      }
      this_thread::sleep_for(chrono::milliseconds(10));
    }
  }
  void crack_init(atomic<long int> &attempted, string hash)
  {
    ifstream word_list_read(config->word_list);
    string word;
    if(word_list_read.is_open())
    {
       while(getline(word_list_read, word))
       {
         ++attempted;
         if(try_crypt(hash, word))
         {
           if(config->is_output)
           {
             file_write(hash + ":" + word + "\n");
           }
           cout << "\e[32m[" << time(0) << "] [+] Cracked: '" << hash << "' Real Password: '" << word << "'\e[39m" << endl;
           return;
         }
       }
    }
    else
    {
      cout << "\e[31m[" << time(0) << "] [-] Error Opening: '" << config->word_list << "' For Reading\e[39m" << endl;
      exit(1);
    }
  }
  void thread_create(atomic<int> &counter, atomic<long int> &attempted, string hash)
  {
    ++counter;
    crack_init(ref(attempted), hash);
    --counter;
  }
  void file_read()
  {
    ifstream read_hashes(config->hash);
    string hash;
    if(read_hashes.is_open())
    {
      while(getline(read_hashes, hash))
      {
        while(active >= config->max_threads)
        {
          this_thread::sleep_for(chrono::milliseconds(20));
        } //attempted
        thread(&controller::thread_create, this, ref(active), ref(attempted), hash).detach();
        this_thread::sleep_for(chrono::milliseconds(5));
      }
      while (active != 0)
      {
        this_thread::sleep_for(chrono::milliseconds(20));
      }
    }
    else
    {
      cout << "\e[31m[" << time(0) << "] [-] Error Opening: '" << config->hash << "' For Reading\e[39m" << endl;
      exit(1);
    }
  } 
  controller()
  {
    if(config->is_list)
    {
      file_read();
    }
    else
    {
      crack_init(ref(attempted), config->hash);
    }
    cout << "\e[33m[" << time(0) << "] [!] [INFO] Total Number of Hashes Tried: '" <<  attempted << "'\e[39m" << endl;
  }
private:
  mutex hash_write; 
};

#endif // CONTROLLER_HPP