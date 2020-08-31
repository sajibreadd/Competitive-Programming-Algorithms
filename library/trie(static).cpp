/*************trie array implementation**************/
#include <bits/stdc++.h>
#define ALPHABET 26
#define SZ 100010
using namespace std;
int nodeCnt = 1;
struct node{
    ///cnt is number of nodes that ends at this node
    ///subtree is number of node under this node including this
    ///nos is number of string has gone through this node
    int link[ALPHABET], cnt, subtree, nos;
    void clr(){
        memset(link, -1, sizeof(link));
        cnt = 0;
        subtree = 1;
        nos = 0;
    }
};
node trie[SZ];
///scaling should be according to the problem
inline int scale(char ch){return (ch - 'a');}
///len is the length of the string
///pos is the intermidiate position of character of the string in the recursion
///st is the state of the trie
void insert(int st, char s[], int pos, int len){
    trie[st].nos++;
    if(pos == len){
        trie[st].cnt++;
        return;
    }
    int i, j;
    bool f = false;
    int v = scale(s[pos]);
    if(trie[st].link[v] == -1){
        nodeCnt++;
        trie[nodeCnt - 1].clr();
        trie[st].link[v] = nodeCnt - 1;
        f = true;
    }
    if(!f){trie[st].subtree -= trie[trie[st].link[v]].subtree;}
    insert(trie[st].link[v], s, pos + 1, len);
    trie[st].subtree += trie[trie[st].link[v]].subtree;
}
bool exist(int st, char s[], int pos, int len){
    if(pos == len){
        trie[st].cnt > 0;
    }
    int i, j;
    int v = scale(s[pos]);
    if(trie[st].link[v] != -1){
        return exist(trie[st].link[v], s, pos + 1, len);
    }
    else{
        return false;
    }
}
void remove(int st, char s[], int pos, int len){
    trie[st].nos--;
    if(pos == len){
    }
    int i, j;
    int v = scale(s[pos]);
    remove(trie[st][v], s, pos + 1, len);
}
int main(){

}
