#include <iostream>
#include "DialogueTree.h"


using namespace std;

int main()
{

    DialogueTree dialogueTree ;
    dialogueTree.init() ;
    int rv = dialogueTree.performDialogue() ;
    if (rv == 1) {
        cout << "\nMy Courageous Brave Warrior, Let start Then" << endl ;
    }
    return 0;
}
