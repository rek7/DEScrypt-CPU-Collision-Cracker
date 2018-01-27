#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP

struct config_s{ string word_list, output_file, hash; int max_threads = 10; bool is_list = false, is_output = false; };
unique_ptr<config_s> config (new config_s);
atomic<int> active(0); // active number of threads
atomic<long int> attempted(0); // number of hashes tried

#endif // GLOBAL_VARS_HPP