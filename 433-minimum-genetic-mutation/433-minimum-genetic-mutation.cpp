class Solution {
    class Trie{
        bool isWord;
        Trie *next[4];
    public:
        Trie(){
            isWord=false;
            for(int i=0;i<4;++i)next[i]=nullptr;
        }

        void add(string s){
            Trie* t=this;
            for(char c:s){
                int i=getIndex(c);
                if(t->next[i]==nullptr)t->next[i]=new Trie();
                t=t->next[i];
            }
            t->isWord=true;
        }

        bool find(string s){
            Trie *t=this;
            for(char c:s){
                int i=getIndex(c);
                if(t->next[i]==nullptr) return false;
                t = t->next[i];
            }
            bool b = t->isWord;
            t->isWord=false;//mark as visited
            return b;
        }

        int getIndex(char c){
            if(c=='A') return 0;
            if(c=='C') return 1;
            if(c=='G') return 2;
            return 3;
        }
    };
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int steps=0;
        Trie *t = new Trie();
        for(string s:bank)t->add(s);
        queue<string> q;
        q.push(startGene);
        string AUX="ACGTACG";
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;++i){
                string s = q.front();q.pop();
                if(s==endGene)return steps;
                for(int j=0;j<8;++j){
                    string aux=s;
                    int index =t->getIndex(s[j]);
                    aux[j]=AUX[index+1];
                    if(t->find(aux))q.push(aux);
                    aux[j]=AUX[index+2];
                    if(t->find(aux))q.push(aux);
                    aux[j]=AUX[index+3];
                    if(t->find(aux))q.push(aux);
                }
            }
            steps++;
        }
        return -1;
    }
};