#include "DialogueTree.h"
#include <string>
#include <iostream>
#include<memory>

using namespace std ;

DialogueOption::DialogueOption(string Text, int ReturnCode, DialogueNode* NextNode) {

    text = Text;
    returnCode = ReturnCode ;
    nextNode = NextNode ;

}


DialogueTree::DialogueTree(){

}


DialogueNode::DialogueNode(string Text) {
    text = Text ;
}

void DialogueTree::init() {

    ///smart pointer
    ///shared_ptr<DialogueNode> snode0 = make_shared<DialogueNode>("Hello brave warrior") ;
    //unique_ptr<DialogueNode> snode1 = make_unique<DialogueNode>("Hello brave warrior") ;

    /// creating the Dialogue Node on the Heap
    DialogueNode *node0 = new DialogueNode("Hello brave warrior ") ;
    DialogueNode *node1 = new DialogueNode("I do not want to talk to you ") ;
    DialogueNode *node2 = new DialogueNode("I got a quest for you");
    DialogueNode *node3 = new DialogueNode("You will be gratefully rewarded, 1000Kg of goal and dimond ");
    DialogueNode *node4 = new DialogueNode("To go kill the Hydra ") ;

    //(*node0).dialogueOptions.push_back(DialogueOption("Hello brave warrior !", 0, node1)) ;
    ///Node 0
    node0->dialogueOptions.push_back(DialogueOption("Sup !", 0, node1)) ;
    node0->dialogueOptions.push_back(DialogueOption("Hello Sir !", 0, node2)) ;
    dialogueNodes.push_back(node0) ;

    ///Node 1
    node1->dialogueOptions.push_back(DialogueOption("Aww!", 0, nullptr)) ;
    dialogueNodes.push_back(node1) ;

    ///Node 2
    node2->dialogueOptions.push_back(DialogueOption("Not interested!", 0, nullptr)) ;
    node2->dialogueOptions.push_back(DialogueOption("Let me know about it", 0, node4)) ;
    node2->dialogueOptions.push_back(DialogueOption("What's for me ? !", 0, node3)) ;
    dialogueNodes.push_back(node2) ;

    ///Node 3
    node3->dialogueOptions.push_back(DialogueOption("Ok, What is it ?", 0, node4)) ;
    node3->dialogueOptions.push_back(DialogueOption("Humm, Not worth it ", 0,nullptr)) ;
    dialogueNodes.push_back(node3) ;

    ///Node 4
    node4->dialogueOptions.push_back(DialogueOption("Let do it", 1, nullptr)) ;
    node4->dialogueOptions.push_back(DialogueOption("Hum, Not interested ", 0,nullptr)) ;
    dialogueNodes.push_back(node4) ;

}


void DialogueTree::destroyTree(){
    for (int i =0 ; i < dialogueNodes.size(); i++){
        delete dialogueNodes[i] ;


    }
    dialogueNodes.clear() ;
}

int DialogueTree::performDialogue(){
    if (dialogueNodes.empty()){ //<==dialogueNodes.size() == 0 ;
        return 0 ;
    }

    DialogueNode *currentNode = dialogueNodes[0] ;

    while( true ){
        cout << currentNode->text << endl << endl ;
        for (int i = 0 ; i < currentNode->dialogueOptions.size(); i++){
            cout  << i + 1 << ": "<< currentNode->dialogueOptions[i].text << endl ;

        }
        cout << endl ;
        int input ;
        cin >> input ;
        input-- ;
        if (input < 0 or input > currentNode->dialogueOptions.size()){
            cout << "WRONG INPUT!!!\n " ;

        }
        else {
            if (currentNode->dialogueOptions[input].nextNode == nullptr){

            return currentNode->dialogueOptions[input].returnCode;

            }
            currentNode = currentNode->dialogueOptions[input].nextNode ;

        }

        cout << endl ;

    }
    return 0 ;
}
