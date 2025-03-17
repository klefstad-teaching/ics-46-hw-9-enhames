#include "ladder.h"

void error(string word1, string word2, string msg){
    std::cout << msg << "(" << word1 << ", " << word2 << ")" << std::endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    // sizes can be one apart and still be neighbors
    // this func checks if a letter has been changed, inserted, or deleted (?)
    int str1_size = str1.size();
    int str2_size = str2.size();
    if (abs(str1_size - str2_size) > d) return false;

    int count = 0, i = 0, j = 0;
    // count is for differences, i counts loops for str1, j counts loops for str2

    while (i < str1_size && j < str2_size){
        if (str1[i] != str2[j]){
            // mismatch found
            if (++count > d) return false;
            // too many differences, return immediately
            if (str1_size > str2_size) i++;
            else if (str1_size < str2_size) j++;
            else{
                i++;
                j++;
            }
        }
        else{
            i++;
            j++;
        }
    }

    count += (str1_size - i) + (str2_size - j);
    return count <= d;
    // check this line later
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    // uses bfs!!
    if (begin_word == end_word){
        // return right away boi,,., why the words the same.
        error(begin_word, end_word, "Words are the same.");
        return {};
    }

    if (word_list.find(end_word) == word_list.end()){
        // end word not in dict
        error(begin_word, end_word, "End word not in dictionary.");
        return {};
    }

    // queue of vector of strings
    queue<vector <string>> ladder_q; // queue of paths (ladders) as string vectors
    ladder_q.push({begin_word}); // ladder queue w only the begin word

    // visited = set of strings
    set<string> visited;
    visited.insert(begin_word); // mark begin word as visited

    // exploring all possible ladders using bfs
    while (!ladder_q.empty()){
        vector<string> ladder = ladder_q.front(); // retrieves the current ladder
        ladder_q.pop(); // removes it from queue for processing

        string last_word = ladder.back(); // get last word from the current ladder
        for (const string& word: word_list){
            // iterating through all words in the dictionary
            if (is_adjacent(last_word, word) && visited.find(word) == visited.end()){
                visited.insert(word); // mark word as visited
                vector <string> new_ladder = ladder; // copy current ladder
                new_ladder.push_back(word); // push our word into the new ladder
                if (word == end_word) return new_ladder; // reached the end word, return the new ladder
                ladder_q.push(new_ladder); // keep going, add ladder to queue for future exploration
            }
        }
    }

    return {};
    // no ladder found lolz
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
    ifstream f(file_name);
    string word;
    while (f >> word){
        word_list.insert(word);
    }

    f.close();
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.empty()){
        cout << "Ladder is empty." << endl;
        return;
    }

    for (size_t i = 0; i < ladder.size(); ++i){
        cout << ladder[i] << " ";
    }

    cout << endl;
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