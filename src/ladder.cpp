#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cout << msg << "(" << word1 << ", " << word2 << ")" << std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // sizes can be one apart and still be neighbors
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){

}

// function generate_word_ladder(begin_word, end_word, word_list):
//     ladder_queue = queue of vector of strings
//     ladder_queue.push([begin_word])
//     visited = set of strings
//     visited.insert(begin_word)
//     while ladder_queue is not empty:
//         ladder = ladder_queue.pop_front()
//         last_word = last element of ladder
//         for word in word_list:
//             if is_adjacent(last_word, word):
//                 if word not in visited:
//                     visited.insert(word)
//                     new_ladder = copy of ladder
//                     new_ladder.push_back(word)
//                     if word equals end_word:
//                         return new_ladder
//                     ladder_queue.push(new_ladder)
//     return no ladder found
// end function

void load_words(set<string> & word_list, const string& file_name){

}

void print_word_ladder(const vector<string>& ladder){

}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder(){
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}