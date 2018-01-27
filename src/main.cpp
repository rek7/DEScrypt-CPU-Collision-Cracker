#include "includes.hpp"
using namespace std;
#include "global_vars.hpp"
#include "crypto.hpp"
#include "controller.hpp"

int main(int argc, char **argv)
{
  cout << "\e[31m" << R"(#####  #####  ####     #   # ####    #   #   # #   # ##### ####  
 #  #  #     #         #   # #   #  # #  #   # #  #  #     #   # 
 #  #  ####  #          #### ####  #####  #### ###   ####  ####  
 ####  #     #             # #     #   #     # #  #  #     #     
#    # #####  ####         # #     #   #     # #   # ##### #)" << endl 
<< "\t\tDEScrypt CPU Collision Cracker V1.0\e[39m" << endl;
  cout << "For questions or bug fixes, either make a github commit or email, rek7@protonmail.com" << endl;
  if(argc >= 3)
  {
    string identifier;
    for(int i = 1; i < argc;i++)
    {
      if(sizeof(argv[i]) > 3)
      {
        identifier = string(argv[i]).substr(0, 3);
        if(identifier == "-l=")
        {
          config->is_list = true;
          config->hash = string(argv[i]).substr(3, string(argv[i]).size());
        }
        else if(identifier == "-w=")
        {
          config->word_list = string(argv[i]).substr(3, string(argv[i]).size());
        }
        else if(identifier == "-t=")
        {
          config->max_threads = stoi(string(argv[i]).substr(3, string(argv[i]).size()));
        }
        else if(identifier == "-o=")
        {
          config->is_output = true;
          config->output_file = string(argv[i]).substr(3, string(argv[i]).size());
        }
        else if(identifier == "-i=")
        {
          config->hash = string(argv[i]).substr(3, string(argv[i]).size());
        }
      }
    }
    cout << "\e[33m[" << time(0) << "] [!] [INFO] Wordlist: '" <<  config->word_list << "' Hash/Hash List: '" << config->hash <<  "' Output File: '" << (config->is_output ? config->output_file : "NONE") << "'\e[39m" << endl;
    cout << "\e[33m[" << time(0) << "] [!] [INFO] CPU Core(s) Detected: '" <<  thread::hardware_concurrency() << "' Current Threads '" <<config->max_threads << "'\e[39m" << endl;
    controller();
  }
  else
  {
    cout << "General Commands:" << endl;
    cout << "\tCommand\t\tDescription" << endl;
    cout << "\t-------\t\t-----------" << endl;
    cout << "\t-l=\t\tFile Location of HashList" << endl;
    cout << "\t-i=\t\tIndividual Hash" << endl;
    cout << "\t-w=\t\tFile Location of Wordlist" << endl;
    cout << "\t-o=\t\tFile Location of Output File" << endl;
    cout << "\t-t=\t\tNumber of Threads(Default is 10)" << endl;
    cout << "Example Usage: " <<  argv[0] << " -l=hashes.txt -w=dictonary.txt -t=20 -o=cracked.txt" << endl;
  }
  return 0;
}
