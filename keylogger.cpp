#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    char words[N] = "";
    map<string, char> keys = {
        {"whack", ' '},
        {"clank", 'a'},
        {"bong", 'b'},
        {"click", 'c'},
        {"tap", 'd'},
        {"poing", 'e'},
        {"clonk", 'f'},
        {"clack", 'g'},
        {"ping", 'h'},
        {"tip", 'i'},
        {"cloing", 'j'},
        {"tic", 'k'},
        {"cling", 'l'},
        {"bing", 'm'},
        {"pong", 'n'},
        {"clang", 'o'},
        {"pang", 'p'},
        {"clong", 'q'},
        {"tac", 'r'},
        {"boing", 's'},
        {"boink", 't'},
        {"cloink", 'u'},
        {"rattle", 'v'},
        {"clock", 'w'},
        {"toc", 'x'},
        {"clink", 'y'},
        {"tuc", 'z'}
    };
    bool capslock = false;
    bool shift = false;
    int words_index = 0;
    for(int i = 0; i < N; i += 1){
        string sound;
        cin >> sound;
        if(sound == "bump"){
            capslock = !capslock;
        }
        else if(sound == "dink" || sound == "thumb"){
            shift = !shift;
        }
        else if(sound == "pop"){
            if(words_index != 0){
                words_index -= 1;
                words[words_index] = 0;
            }
        }
        else{
            if((capslock && !shift) || (!capslock && shift)){ //if uppercaps
                words[words_index] = char(toupper(keys[sound]));
            }
            else{ //if lowercaps
                words[words_index] = keys[sound];
            }
            words_index += 1;
        }
    }
    for(int i = 0; i < words_index; i += 1){
        cout << words[i];
    }
}