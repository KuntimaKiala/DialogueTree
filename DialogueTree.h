#ifndef DIALOGUETREE_H
#define DIALOGUETREE_H
#include<string>
#include<vector>
using namespace std ;


class DialogueNode ;
class DialogueOption {
    public :
        DialogueOption(string Text, int ReturnCode, DialogueNode* NextNode) ;
        string text ;
        int returnCode ;
        DialogueNode *nextNode ;
} ;

class DialogueNode{
    public :
        DialogueNode( string Text) ;
        string text;
        vector <DialogueOption> dialogueOptions ;


} ;

class DialogueTree{
    public:
        DialogueTree();

        void init() ;
        void destroyTree();
        int performDialogue() ;

    private:
        vector<DialogueNode *> dialogueNodes;
};

#endif // DIALOGUETREE_H
